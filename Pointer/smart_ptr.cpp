// clang-format off
/*****************************************************************//**
 * \file   smart_pointers.cpp
 * \brief  contains notes on smart pointers in C++
 * Highlight member function in <memory>:
 * 1) make_unique<T>
 * 2) make_shared
 * 3) weak_ptr
 * 
 * \author Xuhua Huang
 * \date   May 2021
 *********************************************************************/
// clang-format on

#include <cassert>
#include <iostream>
#include <memory>

class Entity {
public:
  inline Entity() { std::cout << "[DFCONST] Creating Entity..." << "\n"; }
  inline ~Entity() { std::cout << "[DFDEST] Destroying Entity..." << "\n"; }

  inline void printEntity() { std::cout << "[fn] Printing Entity..." << "\n"; }
};

int main(void) {
  /**
   * Create a new scope and verify the output in the terminal.
   * Expecting constructor, destructor get called sequentially.
   * \return
   */
  {
    std::unique_ptr<Entity> entity_ptr(new Entity()); // not exception safe
    // better approach: make_unique<Entity>
    // equivalent to: std::unique_ptr<Entity> entity_ptr =
    // std::make_unique<Entity>();
    entity_ptr->printEntity(); // using pointer as how normally it is used
  } // destructor gets called automatically when pointer goes out of scope

  {
    // reference counted pointer
    // shared pointers are traditionally initialized to be null by the compiler
    // when declared if they are not assigned something on creation
    // when the reference count drops to zero, the pointer gets deleted
    // automatically
    std::shared_ptr<int> sp = nullptr;
    sp                      = std::make_shared<int>(); // exception safe
    assert(sp != nullptr);
    assert(*sp == 0); // default initialized to 0
    *sp = 1;
    assert(*sp == 1);
    std::cout << "Value of shared pointer: " << *sp << "\n";

    std::shared_ptr<int> sp2 = sp; // reference count increases to 2
    std::cout << "Value of shared pointer 2: " << *sp2 << "\n";
    assert(sp.use_count() == 2);
  }

  {
    std::unique_ptr<int> up1 = std::make_unique<int>(42);
    // std::unique_ptr<int> up2 = up1; // error: cannot copy
    std::unique_ptr<int> up2 = std::move(up1); // transfer ownership
    assert(up1 == nullptr);
    assert(*up2 == 42);
  }

  // share_ptr uses reference count approach to determine when to delete the
  // pointer
  std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
  std::weak_ptr<Entity>   weakEntity   = sharedEntity; // does not increase reference count

  return 0;
}
