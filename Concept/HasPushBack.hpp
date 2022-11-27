/*****************************************************************//**
 * \file   HasPushBack.hpp
 * \brief  Concept that requires a enric type T implements push_back()
 * 
 * \author Xuhua Huang
 * \date   November 15, 2022
 *********************************************************************/

#ifndef HASPUSHBACK_HPP
#define HASPUSHBACK_HPP

#ifndef _IOSTREAM_
#include <iostream>
#endif

#include <concepts>

template<typename Coll>
concept HasPushBack = requires (Coll c, typename Coll::value_type v) {
    c.push_back(v);
};

#endif
