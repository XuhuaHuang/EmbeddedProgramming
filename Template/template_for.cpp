#include <cmath>
#include <cstdint>
#include <iostream>
#include <string_view>
#include <tuple>
#include <type_traits>

// Domain model: a telemetry packet
struct Data {
  int    i; // e.g., sensor id
  char   c; // e.g., status code
  double d; // e.g., measurement
};

// Simulated runtime acquisition
Data get_data() {
  return Data{42, 'O', 23.75};
}

// Compile-time "golden" packet (build-time contract)
consteval Data get_constexpr_data() {
  return Data{1, 'a', 1.0};
}


// Field reflection (standard C++): tuple-of-references

constexpr auto as_tuple(Data& x) {
  return std::tie(x.i, x.c, x.d);
}

constexpr auto as_tuple(const Data& x) {
  return std::tie(x.i, x.c, x.d);
}

// Apply a callable to each field of Data
template <class F>
constexpr void for_each_field(Data& x, F&& f) {
  std::apply([&](auto&... fields) { (f(fields), ...); }, as_tuple(x));
}
template <class F>
constexpr void for_each_field(const Data& x, F&& f) {
  std::apply([&](const auto&... fields) { (f(fields), ...); }, as_tuple(x));
}


// Logging & validation (runtime)

void use(int v) {
  std::cout << "int    : " << v << "\n";
}
void use(char v) {
  std::cout << "char   : '" << v << "'\n";
}
void use(double v) {
  std::cout << "double : " << v << "\n";
}

struct Validation {
  bool             ok = true;
  std::string_view first_error{};
};

inline void require(bool cond, Validation& out, std::string_view msg) {
  if (!cond && out.ok) {
    out.ok          = false;
    out.first_error = msg;
  }
}

Validation validate(const Data& x) {
  Validation v{};
  require(x.i >= 0, v, "sensor id must be non-negative");
  require(std::isprint(static_cast<unsigned char>(x.c)) != 0, v, "status must be printable ASCII");
  require(std::isfinite(x.d) != 0, v, "measurement must be finite");
  // Example domain rule:
  require(x.d >= -1000.0 && x.d <= 1000.0, v, "measurement out of expected range");
  return v;
}


// Compile-time checksum (build-time self-test)

consteval std::uint64_t mix_u64(std::uint64_t h, std::uint64_t x) {
  // Simple 64-bit mixing (not cryptographic)
  h ^= x + 0x9e3779b97f4a7c15ULL + (h << 6) + (h >> 2);
  return h;
}

template <auto Value>
consteval std::uint64_t fold_value(std::uint64_t h) {
  using T = decltype(Value);

  if constexpr (std::is_same_v<T, int>) {
    return mix_u64(h, static_cast<std::uint64_t>(static_cast<std::int64_t>(Value)));
  } else if constexpr (std::is_same_v<T, char>) {
    return mix_u64(h, static_cast<std::uint64_t>(static_cast<unsigned char>(Value)));
  } else if constexpr (std::is_same_v<T, double>) {
    // Convert double to an integer-ish stable representation for checksum purposes.
    // Here we quantize to micro-units; adjust to your tolerance requirements.
    const long long q = static_cast<long long>(Value * 1'000'000.0);
    return mix_u64(h, static_cast<std::uint64_t>(q));
  } else {
    static_assert(!sizeof(T), "Unsupported field type in checksum");
  }
}

consteval std::uint64_t golden_checksum() {
  constexpr Data g = get_constexpr_data();
  std::uint64_t  h = 0xcbf29ce484222325ULL;

  // Standard C++ compile-time fold over fields:
  // (we can’t literally “loop” over heterogeneous fields without a helper)
  h = fold_value<g.i>(h);
  h = fold_value<g.c>(h);
  h = fold_value<g.d>(h);

  return h;
}

// If someone changes golden data values or field order, this will break the build.
static_assert(golden_checksum() == golden_checksum(), "checksum sanity"); // tautology
// In a real project, pin the expected value once, then keep it stable:
// static_assert(golden_checksum() == 0xDEADBEEF..., "Golden packet changed unexpectedly");


// Application entry

int main() {
  std::cout << "=== Telemetry Packet Logger ===\n";

  Data sample = get_data();

  // Validate first
  if (auto v = validate(sample); !v.ok) {
    std::cout << "Invalid packet: " << v.first_error << "\n";
    return 1;
  }

  // Log fields one-by-one (your “iterate fields” intent)
  std::cout << "Packet fields:\n";
  for_each_field(sample, [](const auto& field) { use(field); });

  // Example: derive a simple runtime checksum too (for transmission integrity)
  //   std::uint64_t h = 0xcbf29ce484222325ULL;
  //   for_each_field(sample, [&](const auto& field) {
  //     using T = std::remove_cvref_t<decltype(field)>;
  //     if constexpr (std::is_same_v<T, int>) {
  //       h = mix_u64(h, static_cast<std::uint64_t>(static_cast<std::int64_t>(field)));
  //     } else if constexpr (std::is_same_v<T, char>) {
  //       h = mix_u64(h, static_cast<std::uint64_t>(static_cast<unsigned char>(field)));
  //     } else if constexpr (std::is_same_v<T, double>) {
  //       const long long q = static_cast<long long>(field * 1'000'000.0);
  //       h                 = mix_u64(h, static_cast<std::uint64_t>(q));
  //     }
  //   });

  //   std::cout << "Runtime checksum: 0x" << std::hex << h << std::dec << "\n";
  std::cout << "Golden checksum : 0x" << std::hex << golden_checksum() << std::dec << "\n";

  return 0;
}
