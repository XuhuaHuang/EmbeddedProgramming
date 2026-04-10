// High-level modules should not depend upon low-level modules. Both should depend upon abstractions.
// Abstractions should not depend upon details. Details should depend upon abstractions.

/**
 * @file dependency_inversion.cpp
 * @author Xuhua Huang
 * @brief Demonstration of the Dependency Inversion Principle (DIP)
 *
 * High-level modules should not depend on low-level modules.
 * Both should depend on abstractions.
 *
 * @version 0.1
 * @date 2026-04-09
 */

#include <iostream>
#include <memory>
#include <string>

// Abstractions
class data_source_t {
public:
  virtual ~data_source_t()         = default;
  virtual std::string read() const = 0;
};

class report_format_t {
public:
  virtual ~report_format_t()                        = default;
  virtual void write(const std::string& data) const = 0;
};

// Low-Level Implementations (Depend on Abstractions)
class database_source_t : public data_source_t {
public:
  std::string read() const override { return "data from database"; }
};

class text_file_source_t : public data_source_t {
public:
  std::string read() const override { return "data from text file"; }
};

class html_report_writer_t : public report_format_t {
public:
  void write(const std::string& data) const override { std::cout << "<html><body>" << data << "</body></html>\n"; }
};

class pdf_report_writer_t : public report_format_t {
public:
  void write(const std::string& data) const override { std::cout << "PDF Report: " << data << '\n'; }
};

// High-Level Module (Depends Only on Abstractions)
class report_generator_t {
public:
  report_generator_t(std::unique_ptr<data_source_t> source, std::unique_ptr<report_format_t> formatter)
    : source(std::move(source))
    , formatter(std::move(formatter)) {}

  void generate_report() const {
    std::string data = source->read();
    formatter->write(data);
  }

private:
  std::unique_ptr<data_source_t>   source;
  std::unique_ptr<report_format_t> formatter;
};

// Composition Root (Client Code)
int main() {
  // Example 1: Database + HTML
  report_generator_t generator(std::make_unique<database_source_t>(), std::make_unique<html_report_writer_t>());

  generator.generate_report();

  std::cout << "------------------------\n";

  // Example 2: Text File + PDF
  report_generator_t generator2(std::make_unique<text_file_source_t>(), std::make_unique<pdf_report_writer_t>());

  generator2.generate_report();

  return 0;
}
