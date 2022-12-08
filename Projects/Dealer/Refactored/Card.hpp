/*****************************************************************//**
 * \file   Card.hpp
 * \brief  Class Card definition.
 * 
 * \author Xuhua Huang
 * \date   December 06, 2022
 *********************************************************************/

#ifndef CARD_HPP
#define CARD_HPP

#include <type_traits>

enum class Rank {
    ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
};

enum class Suit {
    CLUBS, DIAMONDS, SPADES, HEARTS
};

class Card {
public:
    Card() = default;
    Card(const Rank rank, const Suit suit) : m_rank(rank), m_suit(suit) {}
    Card(const Card& rhs) {
        m_rank = rhs.rank(); m_suit = rhs.suit();
    }

    // copy assignment operator
    Card operator=(const Card& rhs) {
        return Card(rhs.rank(), rhs.suit());
    }

    // move assignment operator
    Card operator=(Card&& rhs) noexcept {
        return Card(std::move(rhs.rank()), std::move(rhs.suit()));
    }

    // comparison operator
    inline bool operator==(const Card& rhs) const {
        return (this->rank() == rhs.rank()) && (this->suit() == rhs.suit());
    }

    inline constexpr Rank rank() const { return m_rank; }
    inline constexpr Suit suit() const { return m_suit; }

private:
    Rank m_rank;
    Suit m_suit;
};

#endif
