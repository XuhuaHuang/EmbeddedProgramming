#include <iostream>

class door_t {
public:
  virtual ~door_t() = default;

  virtual void lock()          = 0;
  virtual void unlock()        = 0;
  virtual bool is_open() const = 0;
};

class timer_client_t {
public:
  virtual ~timer_client_t() = default;
  virtual void timeout()    = 0;
};

class timer {
public:
  void register_client(timer_client_t& client, int seconds) {
    std::cout << "Timer started for " << seconds << " seconds\n";

    // Simulated timeout
    client.timeout();
  }
};

class timed_door_t : public door_t, public timer_client_t {
public:
  void lock() override {
    std::cout << "Timed door locked\n";
    locked = true;
  }

  void unlock() override {
    std::cout << "Timed door unlocked\n";
    locked = false;
  }

  bool is_open() const override { return !locked; }

  void timeout() override {
    std::cout << "Timed door auto-locking after timeout\n";
    lock();
  }

private:
  bool locked{true};
};

class glass_door_t : public door_t {
public:
  void lock() override {
    std::cout << "Glass door locked\n";
    locked = true;
  }

  void unlock() override {
    std::cout << "Glass door unlocked\n";
    locked = false;
  }

  bool is_open() const override { return !locked; }

private:
  bool locked{true};
};

int main() {
  timer timer;

  timed_door_t timed_door;
  glass_door_t glass_door;

  timed_door.unlock();
  timer.register_client(timed_door, 5); // Works

  glass_door.unlock();
  // timer.register_client(glass_door, 5); // ❌ compile-time error (correct!)
}
