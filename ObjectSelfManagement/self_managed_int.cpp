/*****************************************************************//**
 * \file   self_managed_int.cpp
 * \brief  Use case of enable_shared_from_this to obtain this pointer
 * in the form of a std::shared_ptr<typename T>.
 *
 * \author Xuhua Huang
 * \date   December 03, 2022
 *********************************************************************/

#include <iostream>
#include <iomanip>
#include <memory>
#include <stdlib.h>

class self_managed_int : public std::enable_shared_from_this<self_managed_int> {
public:
    /**
     * Default and overloaded constructor
     * Copy constructor and virtual destructor.
     */
    self_managed_int() = default;
    self_managed_int(const int value) : m_value(value) {}
    self_managed_int(const self_managed_int& rhs) {
        value() = rhs.value();
    }
    virtual ~self_managed_int() = default;

    /**
     * Overloaded int() and spaceship comparison operator.
     */
    operator int() { return m_value; }
    inline int operator <=>(const self_managed_int& rhs) {
        return (value() <=> rhs.value())._Value;
    }

    /* Mutator and accessor */
    [[nodiscard]] inline int value() const { return m_value; }
    [[nodiscard]] inline int& value() { return m_value; }

    void print() const {
        std::cout << std::quoted("self_managed_int::print()") << " -> this->value() = " << m_value << "\n";
    }

    [[nodiscard]] std::shared_ptr<self_managed_int> get_shared() {
        return shared_from_this();
    }

private:
    int m_value;
};

auto main(void) -> int {
    // test utility print function
    std::shared_ptr<self_managed_int> shared_int = std::make_shared<self_managed_int>(12);
    shared_int->print();

    // test shared_from_this()
    auto p_shared_int = shared_int->get_shared();
    // equivalent to the following:
    // p = shared_int->shared_from_this();
    p_shared_int->value() = 24;
    p_shared_int->print();

    system("pause");
    return EXIT_SUCCESS;
}
