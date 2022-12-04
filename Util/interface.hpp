/*****************************************************************//**
 * \file   interface.hpp
 * \brief  Declaration of interface Printable and Uncopyable.
 *
 * $ g++ -c interface.hpp -std=c++2a
 * [[optional]] $ g++ -c interface.hpp -save-temps -std=c++2a
 *
 * \author Xuhua Huang (xuhua.huang.io@gmail.com)
 * \date   September 25, 2022
 *********************************************************************/

#ifndef _IOSTREAM_
#include <iostream>
#endif

#ifndef _STRING_
#include <string>
#endif

/**
* preprocessing directive below requires gcc 12.0 and standard C++23
* https://en.cppreference.com/w/cpp/preprocessor/conditional
*/
//#ifndef _IOSTREAM_
//#include <iostream>
//#elifndef _STRING_
//#include <string>
//#endif

namespace util {
    namespace interface {

        class Uncopyable;

        template<typename T>
        class Comparable
        {
        public:
            Comparable() = default;
            virtual ~Comparable() = default;
        protected:
            virtual bool operator< (const Comparable&) = 0;
            virtual bool operator<=(const Comparable&) = 0;
            virtual bool operator==(const Comparable&) = 0;
            virtual bool operator> (const Comparable&) = 0;
            virtual bool operator>=(const Comparable&) = 0;
        };

        class Printable
        {
        public:
            inline virtual std::string getClassName() = 0;
            inline virtual std::string getClassName() const = 0;
            virtual ~Printable() = default;
        };

        inline void print_class_name(Printable* const printable) {
            std::cout << "util::interface::print_class_name(): "
                << __FILE__ << " " << __LINE__ << printable->getClassName() << "\n";
        }

        class Uncopyable
        {
        protected:
            // allow construction and destruction of derived class objects
            Uncopyable() = default;
            virtual ~Uncopyable() = default;

        private:
            // compiler sees these function, will attempt to call
            // declared as private, will not be called succesfully
            Uncopyable(const Uncopyable&) {};
            Uncopyable(Uncopyable&&) noexcept {};
            Uncopyable(const Uncopyable&&) {};
            Uncopyable& operator=(const Uncopyable&) {};
            Uncopyable& operator=(Uncopyable&&) noexcept {};
            Uncopyable& operator=(const Uncopyable&&) {};
            bool operator==(const Uncopyable&) {};
        };

    } // end util::interface
} // end util
