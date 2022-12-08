/*****************************************************************//**
 * \file   ICardSource.hpp
 * \brief  Interface representing a source of Cards objects.
 * 
 * \author Xuhua Huang
 * \date   December 06, 2022
 *********************************************************************/

#ifndef ICARDSOURCE_HPP
#define ICARDSOURCE_HPP

#include "Card.hpp"

class ICardSource {
public:
    virtual Card draw() = 0;
    virtual bool is_empty() = 0;
};

#endif
