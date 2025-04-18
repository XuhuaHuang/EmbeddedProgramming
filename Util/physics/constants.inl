
#pragma once
#ifndef PHYSICS_CONSTANTS_INL
#define PHYSICS_CONSTANTS_INL

inline namespace physics_constants {
// pi -- Pi
constexpr inline double pi = 3.1415926535897932385;

// e  -- Euler's Constant
constexpr inline double e = 2.7182818284590452354;

// sqrt_2 -- The square root of 2
constexpr inline double sqrt_2 = 1.4142135623730950488;

// sqrt_3 -- The square root of 3
constexpr inline double sqrt_3 = 1.7320508075688772935;

// log10_2 -- The logarithm base 10 of two
constexpr inline double log10_2 = 0.30102999566398119521;

// light_spd -- The speed of light in vacuum in meters per second
constexpr inline double light_spd = 2.99792458e8;

// newton_G  -- Newton's gravitational constant (in metric units of m^3/(kg*s^2))
constexpr inline double newton_G = 6.67384e-11;

// std_acceleration -- standard acceleration due to gravity (in units of m/(s^2))
constexpr inline double std_acceleration = 9.80665;

// planck_cst -- Planck's constant (in units of Joules * seconds)
constexpr inline double planck_cst = 6.62606957e-34;

// golden_ratio -- The Golden Ratio
constexpr inline double golden_ratio = 1.6180339887498948482;

// euler_gamma -- The Euler Mascheroni Constant
constexpr inline double euler_gamma = 0.5772156649015328606065;

// catalan -- Catalan's Constant
constexpr inline double catalan = 0.91596559417721901505;

// glaisher -- Glaisher Kinkelin constant
constexpr inline double glaisher = 1.2824271291006226369;

// khinchin -- Khinchin's constant
constexpr inline double khinchin = 2.6854520010653064453;

// apery -- Apery's constant
constexpr inline double apery = 1.2020569031595942854;
} // namespace physics_constants

#endif
