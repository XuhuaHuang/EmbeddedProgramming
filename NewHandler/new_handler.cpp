/*****************************************************************//**
 * \file   new_handler.cpp
 * \brief  settings custom lambda to handle failing new operator calls;
 * add custom new handler support class.
 * 
 * \code set_new_handler allows you to specify a function to be called
 * when memory allocation requests can not be satisfied.
 * 
 * \author Xuhua Huang (xuhua.huang.io@gmail.com)
 * \date   November 2022
 *********************************************************************/

#include <iostream>
#include <string>

class Widget {
public:
    static std::new_handler set_new_handler(std::new_handler p) throw();
    static void* operator new(std::size_t size) throw(std::bad_alloc);
private:
    static std::new_handler current_handler;
};

// initialize static member of class Widget
std::new_handler Widget::current_handler = 0;

/**
 * The standard version of set_new_handler.
 * 
 * \param p of type std::new_handler
 * \return 
 */
std::new_handler Widget::set_new_handler(std::new_handler p) throw() {
    std::new_handler old_handler = current_handler;
    current_handler = p;
    return old_handler;
}

class NewHandlerHolder {
public:
    explicit NewHandlerHolder(std::new_handler nh) : handler(nh) {}
    virtual ~NewHandlerHolder() {
        std::set_new_handler(handler);
    }
private:
    std::new_handler handler;
    // prevent copying
    NewHandlerHolder(const NewHandlerHolder&) = delete;
    NewHandlerHolder& operator=(const NewHandlerHolder&) = delete;
};

/**
 * With the support of class NewHandlerHolder,
 * the implementation of Widget::new becomes simpler.
 * 
 * \return 
 */
void* Widget::operator new(std::size_t size) throw(std::bad_alloc) {
    NewHandlerHolder h(std::set_new_handler(current_handler));
    return ::operator new(size);
} // once the NewHandlerHolder h goes out of scope of this function
// the global new handler is restored.

/* Note */
// at this point, we realized that this scheme could be implemented regardless of the class
// so a reasonable goal will be to reuse it in other classes.
template<typename T>
class NewHandlerSupport {
public:
    static std::new_handler set_new_handler(std::new_handler p) throw();
    static void* operator new(std::size_t size) throw(std::bad_alloc);
private:
    static std::new_handler current_handler;
};

// initialized static private member
template<typename T>
std::new_handler NewHandlerSupport<T>::current_handler = 0;

// provide set_new_handler function definition
template<typename T>
std::new_handler NewHandlerSupport<T>::set_new_handler(std::new_handler p) throw() {
    std::new_handler old_handler = current_handler;
    current_handler = p;
    return old_handler;
}

// provide new operator definition
template<typename T>
void* NewHandlerSupport<T>::operator new(std::size_t size) throw(std::bad_alloc) {
    NewHandlerHolder h(std::set_new_handler(current_handler));
    return ::operator new(size);
}

namespace demo {
    // this is all class Widget needs to do
    // to provide a class-specific NewHandlerSupport
    class Widget : public NewHandlerSupport<Widget> {

    };
}

int main(void) {
    std::cout << "Hello, world!" << "\n";
    return EXIT_SUCCESS;
}
