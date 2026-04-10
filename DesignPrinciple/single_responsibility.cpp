/**
 * @file single_responsibility.cpp
 * @author Xuhua Huang
 * @brief Every object in a system should have a single responsibility, and all the object’s services should be focused
 * on carrying out that single responsibility.
 * @version 0.1
 * @date 2026-04-09
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>

class report {
public:
  report(std::vector<int> data)
    : data(std::move(data)) {}

  double compute_average() const { return std::accumulate(data.begin(), data.end(), 0.0) / data.size(); }

  void print() const { std::cout << "Average: " << compute_average() << '\n'; }

  void save_to_file(const std::string& filename) const {
    std::ofstream file(filename);
    file << "Average: " << compute_average() << '\n';
  }

private:
  std::vector<int> data;
};

class statistics_t {
public:
  explicit statistics_t(std::vector<int> data)
    : data(std::move(data)) {}

  double average() const { return std::accumulate(data.begin(), data.end(), 0.0) / data.size(); }

private:
  std::vector<int> data;
};

class report_formatter_t {
public:
  static std::string format_average(double value) { return "Average: " + std::to_string(value); }
};

class console_printer_t {
public:
  void print(const std::string& text) const { std::cout << text << '\n'; }
};

class file_writer_t {
public:
  void write(const std::string& filename, const std::string& text) const {
    std::ofstream file(filename);
    file << text << '\n';
  }
};

int main() {
  statistics_t stats({1, 2, 3, 4, 5});

  double      avg    = stats.average();
  std::string report = report_formatter_t::format_average(avg);

  console_printer_t printer;
  printer.print(report);

  file_writer_t writer;
  writer.write("report.txt", report);
}