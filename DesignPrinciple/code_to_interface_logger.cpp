#include <iostream>
#include <memory>
#include <string>

class ILogger {
public:
  virtual ~ILogger()                             = default;
  virtual void log(const std::string& msg) const = 0;
};

class FileLogger : public ILogger {
public:
  void log(const std::string& msg) const override { std::cout << "[File] " << msg << '\n'; }
};

class ConsoleLogger : public ILogger {
public:
  void log(const std::string& msg) const override { std::cout << "[Console] " << msg << '\n'; }
};

class Application {
public:
  explicit Application(std::unique_ptr<ILogger> logger_in)
    : logger(std::move(logger_in)) {}

  void run() const { logger->log("App is running"); }

private:
  std::unique_ptr<ILogger> logger;
};

int main() {
  std::unique_ptr<ILogger> logger = std::unique_ptr<ILogger>(new ConsoleLogger());

  Application app(std::move(logger));
  app.run();
  return 0;
}
