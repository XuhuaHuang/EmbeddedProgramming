/**
 * @file observer.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2026-04-12
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class spreadsheet_t;

class graph_t {
public:
  virtual ~graph_t() = default;

  virtual void update(const spreadsheet_t& sheet) = 0;
};

class spreadsheet_t {
public:
  using observer_ptr_t = std::shared_ptr<graph_t>;

  void attach(observer_ptr_t observer) { observers.push_back(std::move(observer)); }

  void detach(const observer_ptr_t& observer) {
    std::erase_if(observers, [&](const observer_ptr_t& o) { return o == observer; });
  }

  void notify() {
    for (auto& observer : observers) {
      observer->update(*this);
    }
  }

  // Example dataset API (pull-based model)
  const std::vector<int>& data() const { return values; }

  void set_data(std::vector<int> new_data) {
    values = std::move(new_data);
    notify();
  }

private:
  std::vector<observer_ptr_t> observers;

  std::vector<int> values;
};

class pie_chart_t : public graph_t {
public:
  void update(const spreadsheet_t& sheet) override {
    const auto& data = sheet.data();

    std::cout << "[PieChart] updating with data size: " << data.size() << "\n";
  }
};

class bar_chart_t : public graph_t {
public:
  void update(const spreadsheet_t& sheet) override {
    const auto& data = sheet.data();

    std::cout << "[BarChart] sum = ";

    int sum = 0;
    for (int v : data)
      sum += v;

    std::cout << sum << "\n";
  }
};

class line_chart_t : public graph_t {
public:
  void update(const spreadsheet_t& sheet) override {
    const auto& data = sheet.data();

    std::cout << "[LineChart] last value = " << (data.empty() ? 0 : data.back()) << "\n";
  }
};

int main() {
  spreadsheet_t sheet;

  auto pie  = std::make_shared<pie_chart_t>();
  auto bar  = std::make_shared<bar_chart_t>();
  auto line = std::make_shared<line_chart_t>();

  sheet.attach(pie);
  sheet.attach(bar);
  sheet.attach(line);

  sheet.set_data({1, 2, 3, 4, 5});
  sheet.set_data({10, 20, 30});

  return 0;
}
