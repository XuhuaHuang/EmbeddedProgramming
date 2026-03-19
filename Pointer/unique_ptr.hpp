#include <memory>
#include <utility> // std::exchange

template <typename T, typename Deleter = std::default_delete<T>>
class unique_ptr {
private:
  T*      ptr;
  Deleter deleter;

public:
  // Constructors
  explicit unique_ptr(T* p = nullptr) noexcept
    : ptr(p) {}

  // Destructor
  ~unique_ptr() {
    if (ptr) {
      deleter(ptr);
    }
  }

  // Delete copy semantics
  unique_ptr(const unique_ptr&)            = delete;
  unique_ptr& operator=(const unique_ptr&) = delete;

  // Move constructor
  unique_ptr(unique_ptr&& other) noexcept
    : ptr(std::exchange(other.ptr, nullptr)) {}

  // Move assignment
  unique_ptr& operator=(unique_ptr&& other) noexcept {
    if (this != &other) {
      delete ptr; // clean up current resource
      ptr = std::exchange(other.ptr, nullptr);
    }
    return *this;
  }

  // Observers
  T* get() const noexcept { return ptr; }

  T& operator*() const noexcept { return *ptr; }

  T* operator->() const noexcept { return ptr; }

  explicit operator bool() const noexcept { return ptr != nullptr; }

  // Modifiers
  T* release() noexcept { return std::exchange(ptr, nullptr); }

  void reset(T* p = nullptr) noexcept {
    delete ptr;
    ptr = p;
  }
};

template <typename T, typename... Args>
unique_ptr<T> make_unique(Args&&... args) {
  return unique_ptr<T>(new T(std::forward<Args>(args)...));
}
