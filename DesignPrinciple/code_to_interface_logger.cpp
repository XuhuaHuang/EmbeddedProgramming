#include <chrono>
#include <iomanip>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

inline std::string current_time_string() {
  // using namespace std::chrono;

  const std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

  const std::time_t time = std::chrono::system_clock::to_time_t(now);

  std::ostringstream oss;
  oss << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S");
  return oss.str();
}

enum class log_level_t { info, warning, error };

inline std::string to_string(log_level_t level) {
  switch (level) {
  case log_level_t::info:
    return "INFO";
  case log_level_t::warning:
    return "WARNING";
  case log_level_t::error:
    return "ERROR";
  }
  return "UNKNOWN";
}

class logger_t {
public:
  virtual ~logger_t() = default;

  virtual void log(const std::string& msg, log_level_t level = log_level_t::info) const = 0;
};

class console_logger_t : public logger_t {
public:
  void log(const std::string& msg, log_level_t level = log_level_t::info) const override {
    std::cout << "[" << current_time_string() << "] " << "[" << to_string(level) << "] " << "[console] " << msg << '\n';
  }
};

class file_logger_t : public logger_t {
public:
  void log(const std::string& msg, log_level_t level = log_level_t::info) const override {
    std::cout << "[" << current_time_string() << "] " << "[" << to_string(level) << "] " << "[file] " << msg << '\n';
  }
};

class multi_logger_t : public logger_t {
public:
  void add_logger(std::unique_ptr<logger_t> logger) { loggers.push_back(std::move(logger)); }

  void log(const std::string& msg, log_level_t level = log_level_t::info) const override {
    for (const auto& logger : loggers) {
      logger->log(msg, level);
    }
  }

private:
  std::vector<std::unique_ptr<logger_t>> loggers;
};

class application_t {
public:
  explicit application_t(std::unique_ptr<logger_t> logger_in)
    : logger(std::move(logger_in)) {}

  void run() const {
    logger->log("application starting");
    perform_task();
    logger->log("application finished", log_level_t::info);
  }

private:
  void perform_task() const {
    logger->log("processing data...");
    logger->log("minor issue detected", log_level_t::warning);
    logger->log("critical failure avoided", log_level_t::error);
  }

private:
  std::unique_ptr<logger_t> logger;
};

int main() {
  auto root_logger = std::make_unique<multi_logger_t>();

  root_logger->add_logger(std::make_unique<console_logger_t>());
  root_logger->add_logger(std::make_unique<file_logger_t>());

  application_t app(std::move(root_logger));
  app.run();

  return 0;
}
