#include <iostream>
#include <memory>
#include <string>

// forward declaration
class line_of_credit_t;

class line_of_credit_state_t {
public:
  explicit line_of_credit_state_t(line_of_credit_t* loc)
    : loc(loc) {}

  virtual ~line_of_credit_state_t() = default;

  virtual void apply(float) {}
  virtual void approve() {}
  virtual void withdraw(float) {}
  virtual void make_payment(float) {}
  virtual void cancel() {}

  virtual std::string name() const = 0;

protected:
  line_of_credit_t* loc;
};

class line_of_credit_t {
public:
  line_of_credit_t();

  void set_state(std::unique_ptr<line_of_credit_state_t> new_state) {
    state = std::move(new_state);
    std::cout << "State changed to: " << state->name() << "\n";
  }

  void apply(float amount) { state->apply(amount); }
  void approve() { state->approve(); }
  void withdraw(float amount) { state->withdraw(amount); }
  void make_payment(float amt) { state->make_payment(amt); }
  void cancel() { state->cancel(); }

  float get_balance() const { return balance; }
  void  set_balance(float amt) { balance = amt; }

private:
  std::unique_ptr<line_of_credit_state_t> state;

  float balance = 0.0f;
};

class applied_state_t : public line_of_credit_state_t {
public:
  using line_of_credit_state_t::line_of_credit_state_t;

  void apply(float amount) override {
    std::cout << "Application submitted for $" << amount << "\n";
    loc->set_balance(amount);
  }

  void approve() override;

  std::string name() const override { return "Applied"; }
};

class approved_state_t : public line_of_credit_state_t {
public:
  using line_of_credit_state_t::line_of_credit_state_t;

  void withdraw(float amount) override;

  std::string name() const override { return "Approved"; }
};

class withdrawn_state_t : public line_of_credit_state_t {
public:
  using line_of_credit_state_t::line_of_credit_state_t;

  void make_payment(float amount) override;

  std::string name() const override { return "Withdrawn"; }
};

class closed_state_t : public line_of_credit_state_t {
public:
  using line_of_credit_state_t::line_of_credit_state_t;

  std::string name() const override { return "Closed"; }
};

void applied_state_t::approve() {
  std::cout << "Credit approved\n";
  loc->set_state(std::make_unique<approved_state_t>(loc));
}

void approved_state_t::withdraw(float amount) {
  std::cout << "Withdrawing $" << amount << "\n";
  loc->set_balance(loc->get_balance() - amount);
  loc->set_state(std::make_unique<withdrawn_state_t>(loc));
}

void withdrawn_state_t::make_payment(float amount) {
  std::cout << "Payment of $" << amount << "\n";

  float new_balance = loc->get_balance() + amount;
  loc->set_balance(new_balance);

  if (new_balance >= 0) {
    std::cout << "Loan fully repaid\n";
    loc->set_state(std::make_unique<closed_state_t>(loc));
  }
}

line_of_credit_t::line_of_credit_t() {
  state = std::make_unique<applied_state_t>(this);
}

int main() {
  line_of_credit_t loc;

  loc.apply(1000);       // Applied
  loc.approve();         // -> Approved
  loc.withdraw(500);     // -> Withdrawn
  loc.make_payment(600); // -> Closed

  return 0;
}
