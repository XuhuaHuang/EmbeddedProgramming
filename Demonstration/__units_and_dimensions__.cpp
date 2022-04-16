/**
 * @file __units_and_dimensions__.cpp
 * @author Xuhua Huang (xuhua.huang.io@gmail.com)
 * @brief Units library
 * @version 0.1
 * @date 2022-03-19
 * 
 * Strategy of representing a so-called scientific units:
 * Split a unit into 2 parts: Dimension and magnitude
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/* Create variadic-argument templates for Dimensions */
template <typename... BaseDimPowers>
struct Dimension;

template <typename Base, int Num, int Denominator = 1>
struct Pow;

/* Ordered base dimensions example: length, mass time and angle */
using result_dim = product_t<
    Dimension<
        Pow<Length, 1>,
        Pow<Time, -1>,
        Pow<Angle, 1>
    >,
    Dimension<
        Pow<Time, 2>,
        Pow<Angle, -1>
    >
>;

/* Create variadic-argument templates for Units*/
template <typename Dim, typename Mag>
struct Unit;

template <typename... Units>
using product_t = Unit<
    dim::product_t<dim_t<Units>...>,
    mag::product_t<mag_t<Units>...>
>;

/* Example Units and Compund Units */
template <typename U>
using centi = scale_unit<U, mag::ratio_t<1, 100>>;

using Inches = scale_unit<centi<Meters>, mag::ratio_t<254, 100>>;

using MilesPerHour = quotient_t<Miles, Hours>;
