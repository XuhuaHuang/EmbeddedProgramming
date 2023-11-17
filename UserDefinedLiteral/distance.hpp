/**
 * @file distance.hpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-02-26
 *
 * @copyright ueg (c) 2023
 *
 */

#ifndef DISTANCE_HPP
#define DISTANCE_HPP

struct Distance
{
private:
    explicit Distance(long double val)
        : kilometers(val)
    {
    }

    friend Distance operator"" _km(const long double val);
    friend Distance operator"" _mi(const long double val);

    long double kilometers{0};

public:
    static inline constexpr long double km_per_mile = 1.609344L;

    long double get_kilometers() { return kilometers; }

    Distance operator+(Distance other) { return Distance(get_kilometers() + other.get_kilometers()); }
};

Distance operator"" _km(const long double val)
{
    return Distance(val);
}

Distance operator"" _mi(const long double val)
{
    return Distance(val * Distance::km_per_mile);
}

#endif // !DISTANCE_HPP
