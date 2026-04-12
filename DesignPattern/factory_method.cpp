/**
 * @file factory_method.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2026-04-10
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <string>

class registrar_t {
public:
  virtual ~registrar_t() = default;

  virtual void admit_student(const std::string& name) const = 0;
};

class computer_science_registrar_t : public registrar_t {
public:
  void admit_student(const std::string& name) const override { std::cout << "CS registrar admitting " << name << "\n"; }
};

class engineering_registrar_t : public registrar_t {
public:
  void admit_student(const std::string& name) const override {
    std::cout << "Engineering registrar admitting " << name << "\n";
  }
};

class math_registrar_t : public registrar_t {
public:
  void admit_student(const std::string& name) const override {
    std::cout << "Math registrar admitting " << name << "\n";
  }
};

class registrar_factory_t {
public:
  virtual ~registrar_factory_t() = default;

  // factory method
  virtual std::unique_ptr<registrar_t> create() const = 0;
};

class cs_factory_t : public registrar_factory_t {
public:
  std::unique_ptr<registrar_t> create() const override { return std::make_unique<computer_science_registrar_t>(); }
};

class eng_factory_t : public registrar_factory_t {
public:
  std::unique_ptr<registrar_t> create() const override { return std::make_unique<engineering_registrar_t>(); }
};

class math_factory_t : public registrar_factory_t {
public:
  std::unique_ptr<registrar_t> create() const override { return std::make_unique<math_registrar_t>(); }
};

void enroll_students(
  const std::map<std::string, std::unique_ptr<registrar_factory_t>>& factories,
  const std::map<std::string, std::string>&                          students_to_enroll
) {
  for (const auto& [student, program] : students_to_enroll) {
    auto it = factories.find(program);
    if (it != factories.end()) {
      std::unique_ptr<registrar_t> registrar = it->second->create(); // factory method
      registrar->admit_student(student);
    }
  }
}

using registrar_factory_fn_t = std::function<std::unique_ptr<registrar_t>()>;

int main() {
  std::map<std::string, std::unique_ptr<registrar_factory_t>> factories;

  // std::map<std::string, registrar_factory_fn_t> factories;
  // factories["cs"]  = [] { return std::make_unique<computer_science_registrar_t>(); };
  // factories["eng"] = [] { return std::make_unique<engineering_registrar_t>(); };

  factories["cs"]   = std::make_unique<cs_factory_t>();
  factories["eng"]  = std::make_unique<eng_factory_t>();
  factories["math"] = std::make_unique<math_factory_t>();

  std::map<std::string, std::string> students_to_enroll{
    {"jeff", "cs"  },
    {"bob",  "eng" },
    {"jane", "math"}
  };

  enroll_students(factories, students_to_enroll);
}
