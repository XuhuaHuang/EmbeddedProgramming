/*****************************************************************//**
 * \file   BasicPlane.Figures.ixx
 * \brief  Export multiple module partitions using a single interface.
 * 
 * \author Xuhua Huang (xuhua.huang.io@gmail.com)
 * \date   September 2022
 *********************************************************************/

// the export module keywords mark this file as a primary module interface unit
export module BasicPlane.Figures;

// bring in the partition, then export it to the consumer of this module
export import :Point;
export import :Rectangle;
