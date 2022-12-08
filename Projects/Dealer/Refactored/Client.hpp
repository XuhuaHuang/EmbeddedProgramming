/*****************************************************************//**
 * \file   Client.hpp
 * \brief  A utility method to draw up to pNumber cards from the source.
 * Mostly a demonstration of how to access an object through 
 * an interface using polymorphism.
 * 
 * \author Xuhua Huang
 * \date   December 06, 2022
 *********************************************************************/

#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <vector>
#include "Card.hpp"
#include "ICardSource.hpp"

class Client {
public:
    static std::vector<Card> draw_cards(ICardSource* src, int num) {
        std::vector<Card> cards {};
        for (int i = 0; i < num && !src->is_empty(); i++) {
            cards.push_back(src->draw());
        }
        return cards;
    }
};

#endif
