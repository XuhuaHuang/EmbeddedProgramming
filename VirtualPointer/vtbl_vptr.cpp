/*****************************************************************//**
 * \file   vtbl_vptr.cpp
 * \brief  Virtual table and virtual pointer.
 * 
 * \author Xuhua Huang
 * \date   December 04, 2022
 *********************************************************************/

#include <iostream>
#include <stdio.h>

/**
 * Function pointer type definition.
 * A pointer pointing to a function that
 * does not take any arguments, does not return.
 */
typedef void (*fn_ptr)();

class Base
{
protected:
    Base(const Base&) = default;

public:
    Base() = default;
    virtual ~Base() = default;

    virtual void fn1() {
        std::cout << "Base::fn1()" << "\n";
    }

    virtual void fn2() {
        std::cout << "Base::fn2()" << "\n";
    }

    virtual void fn3() {}
};

class Derived : public Base
{
public:
    Derived() : Base() {};
    ~Derived() override = default;

    void fn1() override {
        std::cout << "Derived::fn1()" << "\n";
    }

    void fn2() override {
        std::cout << "DerivedClass::fn2()" << "\n";
    }
};

/**
 * @brief Obtain the address of vptr and member functions
 * vptr points to the memory that stores all the addresses of the virtual functions
 * such block of address is what we called virtual table (vtable)
 *
 * @param obj
 * @param offset
 *
 * @return
 */
fn_ptr get_vfn_ptr(void* obj, const unsigned long offset)
{
    /**
     * @brief access virtual table through vptr
     * each element in the virtual table (pointer to virtual functions) occupy 8 bytes on a 64-bit machine
     * access the first 8 bytes through: *(unsigned long *)vptr_addr
     * add offset to access address of another virtual function
     */

    std::cout << "=======================" << "\n";

    void* vptr_addr = (void*)*(unsigned long*)obj;
    printf("vptr_addr:%p\n", vptr_addr);

    void* vfn_addr = (void*)*((unsigned long*)vptr_addr + offset);
    printf("vfn_addr :%p\n", vfn_addr);
    return (fn_ptr)vfn_addr;
}

auto main(void) -> int
{
    Base base;
    Derived derived;

    // Base class pointer pointing to Derived class instance
    Base* pBaseToDerived = new Derived();

    // Base class reference referencing Base class instance
    Base& rBase = base;

    // Base class reference referencing Derived class instance
    Base& rBaseToDerived = derived;

    std::cout << "Base object calling member function directly" << "\n";
    base.fn1();

    std::cout << "Base class reference invoking Base class member function" << "\n";
    rBase.fn1();

    std::cout << "Base class pointer pointing to Derived class instance, invoking override member function" << "\n";
    pBaseToDerived->fn1();

    std::cout << "Base class reference referencing Derived class instance, invoking override member function" << "\n";
    rBaseToDerived.fn1();

    // manually look up vptr and vtable
    fn_ptr f1 = get_vfn_ptr(pBaseToDerived, 0);
    (*f1)();

    fn_ptr f2 = get_vfn_ptr(pBaseToDerived, 1);
    (*f2)();

    delete pBaseToDerived;

    system("pause");
    return EXIT_SUCCESS;
}
