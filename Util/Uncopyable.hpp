/*****************************************************************//**
 * \file   Uncopyable.hpp
 * \brief
 *
 * \author Xuhua Huang
 * \date   November 29, 2022
 *********************************************************************/

#ifndef UNCOPYABLE_HPP
#define UNCOPYABLE_HPP

namespace util {
    namespace type {

        class Uncopyable
        {
        protected:
            // allow construction and destruction of derived class objects
            Uncopyable() {}
            virtual ~Uncopyable() {}

        private:
            // compiler sees these function, will attempt to call
            // declared as private, will not be called succesfully
            Uncopyable(const Uncopyable&) {}
            Uncopyable(Uncopyable&&) noexcept {}
            Uncopyable& operator=(const Uncopyable&) {}
            Uncopyable& operator=(Uncopyable&&) noexcept {}
            bool operator==(const Uncopyable&) {}
        };

    } // end util::type
} // end util

#endif
