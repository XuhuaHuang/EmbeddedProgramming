/*****************************************************************//**
 * \file   Deck.hpp
 * \brief  Class Deck definition.
 * 
 * \author Xuhua Huang
 * \date   December 06, 2022
 *********************************************************************/

#ifndef DECK_HPP
#define DECK_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#include "Card.hpp"
#include "ICardSource.hpp"

class Deck : public ICardSource {
public:
    Deck() = default;

    void shuffle() {
        m_cards.clear();

        for (int rank = 0; rank < 4; rank++) {
            for (int suit = 0; suit < 13; suit++) {
                m_cards.push_back(Card(static_cast<Rank>(rank), static_cast<Suit>(suit)));
            }
        }

        std::random_device rd;
        std::default_random_engine rng(rd());
        std::shuffle(m_cards.begin(), m_cards.end(), rng);
    }

    void sort() {
        std::sort(m_cards.begin(), m_cards.end());
    }

    void push(Card&& card) {
        m_cards.push_back(std::move(card));
    }

    Card draw() noexcept {
        Card cardToReturn;
        if (!m_cards.empty()) {
            cardToReturn = m_cards.back();
            m_cards.pop_back();
        }
        return cardToReturn;
    }

    inline bool is_empty() const {
        return m_cards.empty();
    }

private:
    std::vector<Card> m_cards;
};

#endif
