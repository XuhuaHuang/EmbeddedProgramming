#include <tuple>

std::tuple<int, char, double> get_tuple();

struct Data {
  int    a;
  char   b;
  double c;
};

Data get_data();

void use(double);
void use(char);
void use(int);

int main() {
  template for (const auto& element : get_tuple()) {
    // Do something with element
    use(element);
  }
  return 0;
}
