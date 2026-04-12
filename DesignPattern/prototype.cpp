/**
 * @file prototype.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2026-04-12
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <iostream>
#include <map>
#include <memory>
#include <string>

class app_config_t {
public:
  virtual ~app_config_t() = default;

  // Prototype interface
  virtual std::unique_ptr<app_config_t> clone() const = 0;

  virtual void save_config() const = 0;

  inline const std::string& operator[](const std::string& key) const { return config.at(key); }

protected:
  std::map<std::string, std::string> config;
};

class file_config_t : public app_config_t {
public:
  explicit file_config_t(const std::string& path) {
    std::cout << "Loading config from file: " << path << "\n";

    // simulate loading
    config["source"] = "file";
    config["path"]   = path;
  }

  // copy constructor used by clone
  file_config_t(const file_config_t&) = default;

  std::unique_ptr<app_config_t> clone() const override { return std::make_unique<file_config_t>(*this); }

  void save_config() const override { std::cout << "Saving file config\n"; }
};

class database_config_t : public app_config_t {
public:
  database_config_t() {
    std::cout << "Loading config from database\n";

    config["source"]     = "database";
    config["connection"] = "localhost";
  }

  database_config_t(const database_config_t&) = default;

  std::unique_ptr<app_config_t> clone() const override { return std::make_unique<database_config_t>(*this); }

  void save_config() const override { std::cout << "Saving database config\n"; }
};

std::unique_ptr<app_config_t> load_config() {
  std::cout << "Loading config (expensive operation)...\n";

  // simulate expensive operation
  return std::make_unique<file_config_t>("/mnt/fileserver/app.conf");
}

int main() {
  std::unique_ptr<app_config_t> cfg1 = load_config();

  std::cout << "\nCloning config...\n";
  std::unique_ptr<app_config_t> cfg2 = cfg1->clone();

  std::cout << "\nOriginal source: " << (*cfg1)["source"] << "\n";
  std::cout << "Cloned source: " << (*cfg2)["source"] << "\n";

  return 0;
}
