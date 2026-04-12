#include <iostream>
#include <memory>

class monster_t {
public:
  virtual ~monster_t() = default;

  virtual void attack() const = 0;
};

class wall_t {
public:
  virtual ~wall_t() = default;

  virtual void build() const = 0;
};

class fire_monster_t : public monster_t {
public:
  void attack() const override { std::cout << "Fire monster attacks with flames\n"; }
};

class fire_wall_t : public wall_t {
public:
  void build() const override { std::cout << "Building a fire wall\n"; }
};

class ice_monster_t : public monster_t {
public:
  void attack() const override { std::cout << "Ice monster attacks with frost\n"; }
};

class ice_wall_t : public wall_t {
public:
  void build() const override { std::cout << "Building an ice wall\n"; }
};

class game_object_factory_t {
public:
  virtual ~game_object_factory_t() = default;

  virtual std::unique_ptr<monster_t> create_monster() const = 0;
  virtual std::unique_ptr<wall_t>    create_wall() const    = 0;
};

class fire_game_object_factory_t : public game_object_factory_t {
public:
  std::unique_ptr<monster_t> create_monster() const override { return std::make_unique<fire_monster_t>(); }

  std::unique_ptr<wall_t> create_wall() const override { return std::make_unique<fire_wall_t>(); }
};

class ice_game_object_factory_t : public game_object_factory_t {
public:
  std::unique_ptr<monster_t> create_monster() const override { return std::make_unique<ice_monster_t>(); }

  std::unique_ptr<wall_t> create_wall() const override { return std::make_unique<ice_wall_t>(); }
};

class game_level_t {
public:
  explicit game_level_t(const game_object_factory_t& factory) {
    monster = factory.create_monster();
    wall    = factory.create_wall();
  }

  void play() const {
    monster->attack();
    wall->build();
  }

private:
  std::unique_ptr<monster_t> monster;
  std::unique_ptr<wall_t>    wall;
};

int main() {
  std::cout << "=== Fire Level ===\n";
  fire_game_object_factory_t fire_factory;
  game_level_t               fire_level(fire_factory);
  fire_level.play();

  std::cout << "\n=== Ice Level ===\n";
  ice_game_object_factory_t ice_factory;
  game_level_t              ice_level(ice_factory);
  ice_level.play();

  return 0;
}
