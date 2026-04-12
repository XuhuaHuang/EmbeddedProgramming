/**
 * @file strategy.cpp
 * @author Xuhua Huang
 * @brief 
 * https://compiler-explorer.com/z/eKfjKscPv
 *
 * @version 0.1
 * @date 2026-04-12
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <iomanip>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

class date_t;

class date_formatter_t {
public:
  virtual ~date_formatter_t() = default;

  virtual std::string to_string(const date_t& date) const = 0;
};

class date_t {
public:
  date_t(int y, int m, int d, int h, int min, int s, std::unique_ptr<date_formatter_t> formatter)
    : m_year(y)
    , m_month(m)
    , m_day(d)
    , m_hour(h)
    , m_minute(min)
    , m_second(s)
    , m_formatter(std::move(formatter)) {}

  void set_formatter(std::unique_ptr<date_formatter_t> formatter) { m_formatter = std::move(formatter); }

  std::string to_string() const { return m_formatter->to_string(*this); }

  inline int year() const { return m_year; }
  inline int month() const { return m_month; }
  inline int day() const { return m_day; }
  inline int hour() const { return m_hour; }
  inline int minute() const { return m_minute; }
  inline int second() const { return m_second; }

private:
  int m_year;
  int m_month;
  int m_day;
  int m_hour;
  int m_minute;
  int m_second;

  std::unique_ptr<date_formatter_t> m_formatter;
};

class date_only_formatter_t : public date_formatter_t {
public:
  std::string to_string(const date_t& date) const override {
    std::ostringstream os;
    os << std::setw(2) << std::setfill('0') << date.month() << "-" << std::setw(2) << std::setfill('0') << date.day()
       << "-" << date.year();
    return os.str();
  }
};

class date_time_formatter_t : public date_formatter_t {
public:
  std::string to_string(const date_t& date) const override {
    std::ostringstream os;
    os << std::setw(2) << std::setfill('0') << date.month() << "-" << std::setw(2) << std::setfill('0') << date.day()
       << "-" << date.year() << " " << std::setw(2) << std::setfill('0') << date.hour() << ":" << std::setw(2)
       << std::setfill('0') << date.minute() << ":" << std::setw(2) << std::setfill('0') << date.second();
    return os.str();
  }
};

class time_only_formatter_t : public date_formatter_t {
public:
  std::string to_string(const date_t& date) const override {
    std::ostringstream os;
    os << std::setw(2) << std::setfill('0') << date.hour() << ":" << std::setw(2) << std::setfill('0') << date.minute()
       << ":" << std::setw(2) << std::setfill('0') << date.second();
    return os.str();
  }
};

int main() {
  date_t d(2011, 11, 5, 9, 52, 0, std::make_unique<date_only_formatter_t>());

  std::cout << "date: " << d.to_string() << "\n";

  d.set_formatter(std::make_unique<time_only_formatter_t>());
  std::cout << "time: " << d.to_string() << "\n";

  d.set_formatter(std::make_unique<date_time_formatter_t>());
  std::cout << "datetime: " << d.to_string() << "\n";

  return 0;
}
