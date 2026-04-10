// Open for extension, closed for modification
#include <iostream>
#include <memory>

class payment_method_t {
public:
  virtual ~payment_method_t()               = default;
  virtual void process(double amount) const = 0;
};

class credit_card_t : public payment_method_t {
public:
  void process(double amount) const override { std::cout << "Processing credit card payment: " << amount << '\n'; }
};

class paypal_t : public payment_method_t {
public:
  void process(double amount) const override { std::cout << "Processing PayPal payment: " << amount << '\n'; }
};

class crypto_t : public payment_method_t {
public:
  void process(double amount) const override { std::cout << "Processing crypto payment: " << amount << '\n'; }
};

class payment_processor_t {
public:
  explicit payment_processor_t(std::unique_ptr<payment_method_t> method)
    : method(std::move(method)) {}

  void process(double amount) const { method->process(amount); }

private:
  std::unique_ptr<payment_method_t> method;
};

int main() {
  payment_processor_t processor(std::make_unique<credit_card_t>());

  processor.process(100.0);

  // Swap behavior without modifying processor
  processor = payment_processor_t(std::make_unique<crypto_t>());

  processor.process(250.0);
}

// Extending functionality by adding new payment methods does not require modifying existing code, adhering to the
// Open/Closed Principle.
class apple_pay_t : public payment_method_t {
public:
  void process(double amount) const override { std::cout << "Processing Apple Pay payment: " << amount << '\n'; }
};
payment_processor_t processor(std::make_unique<apple_pay_t>());
