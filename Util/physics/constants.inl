
#pragma once
#ifndef PHYSICS_CONSTANTS_INL
#define PHYSICS_CONSTANTS_INL

inline namespace physics_constants {
    // pi -- Pi
    inline constexpr double pi = 3.1415926535897932385;

    // e  -- Euler's Constant
    inline constexpr double e = 2.7182818284590452354;

    // sqrt_2 -- The square root of 2
    inline constexpr double sqrt_2 = 1.4142135623730950488;

    // sqrt_3 -- The square root of 3
    inline constexpr double sqrt_3 = 1.7320508075688772935;

    // log10_2 -- The logarithm base 10 of two
    inline constexpr double log10_2 = 0.30102999566398119521;

    // light_spd -- The speed of light in vacuum in meters per second
    inline constexpr double light_spd = 2.99792458e8;

    // newton_G  -- Newton's gravitational constant (in metric units of m^3/(kg*s^2))
    inline constexpr double newton_G = 6.67384e-11;

    // std_acceleration -- standard acceleration due to gravity (in units of m/(s^2))
    inline constexpr double std_acceleration = 9.80665;

    // planck_cst -- Planck's constant (in units of Joules * seconds) 
    inline constexpr double planck_cst = 6.62606957e-34;

    // golden_ratio -- The Golden Ratio
    inline constexpr double golden_ratio = 1.6180339887498948482;

    // euler_gamma -- The Euler Mascheroni Constant 
    inline constexpr double euler_gamma = 0.5772156649015328606065;

    // catalan -- Catalan's Constant
    inline constexpr double catalan = 0.91596559417721901505; 

    // glaisher -- Glaisher Kinkelin constant
    inline constexpr double glaisher = 1.2824271291006226369;

    // khinchin -- Khinchin's constant
    inline constexpr double khinchin = 2.6854520010653064453;

    // apery -- Apery's constant
    inline constexpr double apery = 1.2020569031595942854;
}

#endif
