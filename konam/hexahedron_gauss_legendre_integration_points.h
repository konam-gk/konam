// The coordinates and related weights for isoparametric Hexahedron Domains
// using Gauss-Legendre quadrature

#ifndef HEXAHEDRON_GAUSS_LEGENDRE_INTEGRATION_POINTS_H
#define HEXAHEDRON_GAUSS_LEGENDRE_INTEGRATION_POINTS_H

#include <cmath>
#include <stdexcept>

#include "konam_array.h"


auto hexahedron_gauss_legendre_integration_points(const unsigned int num_int_pts)
{
	// num_int_pts - number of integration points
	const int dim{ 3 };
	konam_mat coordinates(num_int_pts, dim);
	konam_vec weights(num_int_pts);

	switch (num_int_pts) {
	case 1:
		// point 1
		coordinates(0, 0) = 0.0;						weights(0) = 8.0;
		coordinates(0, 1) = 0.0;
		coordinates(0, 2) = 0.0;
		break;
	case 8:
		// point 1
		coordinates(0, 0) = -std::sqrt(1.0 / 3.0);		weights(0) = 1.0;
		coordinates(0, 1) = -std::sqrt(1.0 / 3.0);
		coordinates(0, 2) = -std::sqrt(1.0 / 3.0);
		// point 2 
		coordinates(1, 0) = +std::sqrt(1.0 / 3.0);		weights(1) = weights(0);
		coordinates(1, 1) = -std::sqrt(1.0 / 3.0);
		coordinates(1, 2) = -std::sqrt(1.0 / 3.0);
		// point 3										
		coordinates(2, 0) = +std::sqrt(1.0 / 3.0);		weights(2) = weights(0);
		coordinates(2, 1) = +std::sqrt(1.0 / 3.0);
		coordinates(2, 2) = -std::sqrt(1.0 / 3.0);
		// point 4
		coordinates(3, 0) = -std::sqrt(1.0 / 3.0);		weights(3) = weights(0);
		coordinates(3, 1) = +std::sqrt(1.0 / 3.0);
		coordinates(3, 2) = -std::sqrt(1.0 / 3.0);
		// point 5
		coordinates(4, 0) = -std::sqrt(1.0 / 3.0);		weights(4) = weights(0);
		coordinates(4, 1) = -std::sqrt(1.0 / 3.0);
		coordinates(4, 2) = +std::sqrt(1.0 / 3.0);
		// point 6
		coordinates(5, 0) = +std::sqrt(1.0 / 3.0);		weights(5) = weights(0);
		coordinates(5, 1) = -std::sqrt(1.0 / 3.0);
		coordinates(5, 2) = +std::sqrt(1.0 / 3.0);
		// point 7
		coordinates(6, 0) = +std::sqrt(1.0 / 3.0);		weights(6) = weights(0);
		coordinates(6, 1) = +std::sqrt(1.0 / 3.0);
		coordinates(6, 2) = +std::sqrt(1.0 / 3.0);
		// point 8
		coordinates(7, 0) = -std::sqrt(1.0 / 3.0);		weights(7) = weights(0);
		coordinates(7, 1) = +std::sqrt(1.0 / 3.0);
		coordinates(7, 2) = +std::sqrt(1.0 / 3.0);
		break;
	case 27:
		// point 1
		coordinates(0, 0) = -std::sqrt(0.6);			weights(0) = 125.0 / 729.0;
		coordinates(0, 1) = -std::sqrt(0.6);
		coordinates(0, 2) = -std::sqrt(0.6);
		// point 2
		coordinates(1, 0) = 0.0;						weights(1) = 200.0 / 729.0;
		coordinates(1, 1) = -std::sqrt(0.6);
		coordinates(1, 2) = -std::sqrt(0.6);
		// point 3
		coordinates(2, 0) = +std::sqrt(0.6);			weights(2) = 125.0 / 729.0;
		coordinates(2, 1) = -std::sqrt(0.6);
		coordinates(2, 2) = -std::sqrt(0.6);
		// point 4
		coordinates(3, 0) = -std::sqrt(0.6);			weights(3) = 200.0 / 729.0;
		coordinates(3, 1) = 0.0;
		coordinates(3, 2) = -std::sqrt(0.6);
		// point 5
		coordinates(4, 0) = 0.0;						weights(4) = 320.0 / 729.0;
		coordinates(4, 1) = 0.0;
		coordinates(4, 2) = -std::sqrt(0.6);
		// point 6
		coordinates(5, 0) = +std::sqrt(0.6);			weights(5) = 200.0 / 729.0;
		coordinates(5, 1) = 0.0;
		coordinates(5, 2) = -std::sqrt(0.6);
		// point 7
		coordinates(6, 0) = -std::sqrt(0.6);			weights(6) = 125.0 / 729.0;
		coordinates(6, 1) = +std::sqrt(0.6);
		coordinates(6, 2) = -std::sqrt(0.6);
		// point 8
		coordinates(7, 0) = 0.0;						weights(7) = 200.0 / 729.0;
		coordinates(7, 1) = +std::sqrt(0.6);
		coordinates(7, 2) = -std::sqrt(0.6);
		// point 9
		coordinates(8, 0) = +std::sqrt(0.6);			weights(8) = 125.0 / 729.0;
		coordinates(8, 1) = +std::sqrt(0.6);
		coordinates(8, 2) = -std::sqrt(0.6);
		// point 10
		coordinates(9, 0) = -std::sqrt(0.6);			weights(9) = 200.0 / 729.0;
		coordinates(9, 1) = -std::sqrt(0.6);
		coordinates(9, 2) = 0.0;
		// point 11
		coordinates(10, 0) = 0.0;						weights(10) = 320.0 / 729.0;
		coordinates(10, 1) = -std::sqrt(0.6);
		coordinates(10, 2) = 0.0;
		// point 12
		coordinates(11, 0) = +std::sqrt(0.6);			weights(11) = 200.0 / 729.0;
		coordinates(11, 1) = -std::sqrt(0.6);
		coordinates(11, 2) = 0.0;
		// point 13
		coordinates(12, 0) = -std::sqrt(0.6);			weights(12) = 320.0 / 729.0;
		coordinates(12, 1) = 0.0;
		coordinates(12, 2) = 0.0;
		// point 14
		coordinates(13, 0) = 0.0;						weights(13) = 512.0 / 729.0;
		coordinates(13, 1) = 0.0;
		coordinates(13, 2) = 0.0;
		// point 15
		coordinates(14, 0) = +std::sqrt(0.6);			weights(14) = 320.0 / 729.0;
		coordinates(14, 1) = 0.0;
		coordinates(14, 2) = 0.0;
		// point 16
		coordinates(15, 0) = -std::sqrt(0.6);			weights(15) = 200.0 / 729.0;
		coordinates(15, 1) = +std::sqrt(0.6);
		coordinates(15, 2) = 0.0;
		// point 17
		coordinates(16, 0) = 0.0;						weights(16) = 320.0 / 729.0;
		coordinates(16, 1) = +std::sqrt(0.6);
		coordinates(16, 2) = 0.0;
		// point 18
		coordinates(17, 0) = +std::sqrt(0.6);			weights(17) = 200.0 / 729.0;
		coordinates(17, 1) = +std::sqrt(0.6);
		coordinates(17, 2) = 0.0;
		// point 19
		coordinates(18, 0) = -std::sqrt(0.6);			weights(18) = 125.0 / 729.0;
		coordinates(18, 1) = -std::sqrt(0.6);
		coordinates(18, 2) = +std::sqrt(0.6);
		// point 20
		coordinates(19, 0) = 0.0;						weights(19) = 200.0 / 729.0;
		coordinates(19, 1) = -std::sqrt(0.6);
		coordinates(19, 2) = +std::sqrt(0.6);
		// point 21
		coordinates(20, 0) = +std::sqrt(0.6);			weights(20) = 125.0 / 729.0;
		coordinates(20, 1) = -std::sqrt(0.6);
		coordinates(20, 2) = +std::sqrt(0.6);
		// point 22
		coordinates(21, 0) = -std::sqrt(0.6);			weights(21) = 200.0 / 729.0;
		coordinates(21, 1) = 0.0;
		coordinates(21, 2) = +std::sqrt(0.6);
		// point 23
		coordinates(22, 0) = 0.0;						weights(22) = 320.0 / 729.0;
		coordinates(22, 1) = 0.0;
		coordinates(22, 2) = +std::sqrt(0.6);
		// point 24
		coordinates(23, 0) = +std::sqrt(0.6);			weights(23) = 200.0 / 729.0;
		coordinates(23, 1) = 0.0;
		coordinates(23, 2) = +std::sqrt(0.6);
		// point 25
		coordinates(24, 0) = -std::sqrt(0.6);			weights(24) = 125.0 / 729.0;
		coordinates(24, 1) = +std::sqrt(0.6);
		coordinates(24, 2) = +std::sqrt(0.6);
		// point 26
		coordinates(25, 0) = 0.0;						weights(25) = 200.0 / 729.0;
		coordinates(25, 1) = +std::sqrt(0.6);
		coordinates(25, 2) = +std::sqrt(0.6);
		// point 27
		coordinates(26, 0) = +std::sqrt(0.6);			weights(26) = 125.0 / 729.0;
		coordinates(26, 1) = +std::sqrt(0.6);
		coordinates(26, 2) = +std::sqrt(0.6);
		break;
	case 64:
	{
		const double weig_1 = 0.04209147749053145454;
		const double weig_2 = 0.07891151579507055098;
		const double weig_3 = 0.14794033605678130087;
		const double weig_4 = 0.27735296695391298990;

		const double coor_1 = 0.86113631159405257522;
		const double coor_2 = 0.33998104358485626480;

		// point 1
		coordinates(0, 0) = -coor_1;					weights(0) = weig_1;
		coordinates(0, 1) = -coor_1;
		coordinates(0, 2) = -coor_1;
		// point 2
		coordinates(1, 0) = -coor_2;					weights(1) = weig_2;
		coordinates(1, 1) = -coor_1;
		coordinates(1, 2) = -coor_1;
		// point 3
		coordinates(2, 0) = +coor_2;					weights(2) = weig_2;
		coordinates(2, 1) = -coor_1;
		coordinates(2, 2) = -coor_1;
		// point 4
		coordinates(3, 0) = +coor_1;					weights(3) = weig_1;
		coordinates(3, 1) = -coor_1;
		coordinates(3, 2) = -coor_1;
		// point 5
		coordinates(4, 0) = -coor_1;					weights(4) = weig_2;
		coordinates(4, 1) = -coor_2;
		coordinates(4, 2) = -coor_1;
		// point 6
		coordinates(5, 0) = -coor_2;					weights(5) = weig_3;
		coordinates(5, 1) = -coor_2;
		coordinates(5, 2) = -coor_1;
		// point 7
		coordinates(6, 0) = +coor_2;					weights(6) = weig_3;
		coordinates(6, 1) = -coor_2;
		coordinates(6, 2) = -coor_1;
		// point 8
		coordinates(7, 0) = +coor_1;					weights(7) = weig_2;
		coordinates(7, 1) = -coor_2;
		coordinates(7, 2) = -coor_1;
		// point 9
		coordinates(8, 0) = -coor_1;					weights(8) = weig_2;
		coordinates(8, 1) = +coor_2;
		coordinates(8, 2) = -coor_1;
		// point 10
		coordinates(9, 0) = -coor_2;					weights(9) = weig_3;
		coordinates(9, 1) = +coor_2;
		coordinates(9, 2) = -coor_1;
		// point 11
		coordinates(10, 0) = +coor_2;					weights(10) = weig_3;
		coordinates(10, 1) = +coor_2;
		coordinates(10, 2) = -coor_1;
		// point 12
		coordinates(11, 0) = +coor_1;					weights(11) = weig_2;
		coordinates(11, 1) = +coor_2;
		coordinates(11, 2) = -coor_1;
		// point 13
		coordinates(12, 0) = -coor_1;					weights(12) = weig_1;
		coordinates(12, 1) = +coor_1;
		coordinates(12, 2) = -coor_1;
		// point 14
		coordinates(13, 0) = -coor_2;					weights(13) = weig_2;
		coordinates(13, 1) = +coor_1;
		coordinates(13, 2) = -coor_1;
		// point 15
		coordinates(14, 0) = +coor_2;					weights(14) = weig_2;
		coordinates(14, 1) = +coor_1;
		coordinates(14, 2) = -coor_1;
		// point 16
		coordinates(15, 0) = +coor_1;					weights(15) = weig_1;
		coordinates(15, 1) = +coor_1;
		coordinates(15, 2) = -coor_1;
		// point 17
		coordinates(16, 0) = -coor_1;					weights(16) = weig_2;
		coordinates(16, 1) = -coor_1;
		coordinates(16, 2) = -coor_2;
		// point 18
		coordinates(17, 0) = -coor_2;					weights(17) = weig_3;
		coordinates(17, 1) = -coor_1;
		coordinates(17, 2) = -coor_2;
		// point 19
		coordinates(18, 0) = +coor_2;					weights(18) = weig_3;
		coordinates(18, 1) = -coor_1;
		coordinates(18, 2) = -coor_2;
		// point 20
		coordinates(19, 0) = +coor_1;					weights(19) = weig_2;
		coordinates(19, 1) = -coor_1;
		coordinates(19, 2) = -coor_2;
		// point 21
		coordinates(20, 0) = -coor_1;					weights(20) = weig_3;
		coordinates(20, 1) = -coor_2;
		coordinates(20, 2) = -coor_2;
		// point 22
		coordinates(21, 0) = -coor_2;					weights(21) = weig_4;
		coordinates(21, 1) = -coor_2;
		coordinates(21, 2) = -coor_2;
		// point 23
		coordinates(22, 0) = +coor_2;					weights(22) = weig_4;
		coordinates(22, 1) = -coor_2;
		coordinates(22, 2) = -coor_2;
		// point 24
		coordinates(23, 0) = +coor_1;					weights(23) = weig_3;
		coordinates(23, 1) = -coor_2;
		coordinates(23, 2) = -coor_2;
		// point 25
		coordinates(24, 0) = -coor_1;					weights(24) = weig_3;
		coordinates(24, 1) = +coor_2;
		coordinates(24, 2) = -coor_2;
		// point 26
		coordinates(25, 0) = -coor_2;					weights(25) = weig_4;
		coordinates(25, 1) = +coor_2;
		coordinates(25, 2) = -coor_2;
		// point 27
		coordinates(26, 0) = +coor_2;					weights(26) = weig_4;
		coordinates(26, 1) = +coor_2;
		coordinates(26, 2) = -coor_2;
		// point 28
		coordinates(27, 0) = +coor_1;					weights(27) = weig_3;
		coordinates(27, 1) = +coor_2;
		coordinates(27, 2) = -coor_2;
		// point 29
		coordinates(28, 0) = -coor_1;					weights(28) = weig_2;
		coordinates(28, 1) = +coor_1;
		coordinates(28, 2) = -coor_2;
		// point 30
		coordinates(29, 0) = -coor_2;					weights(29) = weig_3;
		coordinates(29, 1) = +coor_1;
		coordinates(29, 2) = -coor_2;
		// point 31
		coordinates(30, 0) = +coor_2;					weights(30) = weig_3;
		coordinates(30, 1) = +coor_1;
		coordinates(30, 2) = -coor_2;
		// point 32
		coordinates(31, 0) = +coor_1;					weights(31) = weig_2;
		coordinates(31, 1) = +coor_1;
		coordinates(31, 2) = -coor_2;
		// point 33
		coordinates(32, 0) = -coor_1;					weights(32) = weig_2;
		coordinates(32, 1) = -coor_1;
		coordinates(32, 2) = +coor_2;
		// point 34
		coordinates(33, 0) = -coor_2;					weights(33) = weig_3;
		coordinates(33, 1) = -coor_1;
		coordinates(33, 2) = +coor_2;
		// point 35
		coordinates(34, 0) = +coor_2;					weights(34) = weig_3;
		coordinates(34, 1) = -coor_1;
		coordinates(34, 2) = +coor_2;
		// point 36
		coordinates(35, 0) = +coor_1;					weights(35) = weig_2;
		coordinates(35, 1) = -coor_1;
		coordinates(35, 2) = +coor_2;
		// point 37
		coordinates(36, 0) = -coor_1;					weights(36) = weig_3;
		coordinates(36, 1) = -coor_2;
		coordinates(36, 2) = +coor_2;
		// point 38
		coordinates(37, 0) = -coor_2;					weights(37) = weig_4;
		coordinates(37, 1) = -coor_2;
		coordinates(37, 2) = +coor_2;
		// point 39
		coordinates(38, 0) = +coor_2;					weights(38) = weig_4;
		coordinates(38, 1) = -coor_2;
		coordinates(38, 2) = +coor_2;
		// point 40
		coordinates(39, 0) = +coor_1;					weights(39) = weig_3;
		coordinates(39, 1) = -coor_2;
		coordinates(39, 2) = +coor_2;
		// point 41
		coordinates(40, 0) = -coor_1;					weights(40) = weig_3;
		coordinates(40, 1) = +coor_2;
		coordinates(40, 2) = +coor_2;
		// point 42
		coordinates(41, 0) = -coor_2;					weights(41) = weig_4;
		coordinates(41, 1) = +coor_2;
		coordinates(41, 2) = +coor_2;
		// point 43
		coordinates(42, 0) = +coor_2;					weights(42) = weig_4;
		coordinates(42, 1) = +coor_2;
		coordinates(42, 2) = +coor_2;
		// point 44
		coordinates(43, 0) = +coor_1;					weights(43) = weig_3;
		coordinates(43, 1) = +coor_2;
		coordinates(43, 2) = +coor_2;
		// point 45
		coordinates(44, 0) = -coor_1;					weights(44) = weig_2;
		coordinates(44, 1) = +coor_1;
		coordinates(44, 2) = +coor_2;
		// point 46
		coordinates(45, 0) = -coor_2;					weights(45) = weig_3;
		coordinates(45, 1) = +coor_1;
		coordinates(45, 2) = +coor_2;
		// point 47
		coordinates(46, 0) = +coor_2;					weights(46) = weig_3;
		coordinates(46, 1) = +coor_1;
		coordinates(46, 2) = +coor_2;
		// point 48
		coordinates(47, 0) = +coor_1;					weights(47) = weig_2;
		coordinates(47, 1) = +coor_1;
		coordinates(47, 2) = +coor_2;
		// point 49
		coordinates(48, 0) = -coor_1;					weights(48) = weig_1;
		coordinates(48, 1) = -coor_1;
		coordinates(48, 2) = +coor_1;
		// point 50
		coordinates(49, 0) = -coor_2;					weights(49) = weig_2;
		coordinates(49, 1) = -coor_1;
		coordinates(49, 2) = +coor_1;
		// point 51
		coordinates(50, 0) = +coor_2;					weights(50) = weig_2;
		coordinates(50, 1) = -coor_1;
		coordinates(50, 2) = +coor_1;
		// point 52
		coordinates(51, 0) = +coor_1;					weights(51) = weig_1;
		coordinates(51, 1) = -coor_1;
		coordinates(51, 2) = +coor_1;
		// point 53
		coordinates(52, 0) = -coor_1;					weights(52) = weig_2;
		coordinates(52, 1) = -coor_2;
		coordinates(52, 2) = +coor_1;
		// point 54
		coordinates(53, 0) = -coor_2;					weights(53) = weig_3;
		coordinates(53, 1) = -coor_2;
		coordinates(53, 2) = +coor_1;
		// point 55
		coordinates(54, 0) = +coor_2;					weights(54) = weig_3;
		coordinates(54, 1) = -coor_2;
		coordinates(54, 2) = +coor_1;
		// point 56
		coordinates(55, 0) = +coor_1;					weights(55) = weig_2;
		coordinates(55, 1) = -coor_2;
		coordinates(55, 2) = +coor_1;
		// point 57
		coordinates(56, 0) = -coor_1;					weights(56) = weig_2;
		coordinates(56, 1) = +coor_2;
		coordinates(56, 2) = +coor_1;
		// point 58
		coordinates(57, 0) = -coor_2;					weights(57) = weig_3;
		coordinates(57, 1) = +coor_2;
		coordinates(57, 2) = +coor_1;
		// point 59
		coordinates(58, 0) = +coor_2;					weights(58) = weig_3;
		coordinates(58, 1) = +coor_2;
		coordinates(58, 2) = +coor_1;
		// point 60
		coordinates(59, 0) = +coor_1;					weights(59) = weig_2;
		coordinates(59, 1) = +coor_2;
		coordinates(59, 2) = +coor_1;
		// point 61
		coordinates(60, 0) = -coor_1;					weights(60) = weig_1;
		coordinates(60, 1) = +coor_1;
		coordinates(60, 2) = +coor_1;
		// point 62
		coordinates(61, 0) = -coor_2;					weights(61) = weig_2;
		coordinates(61, 1) = +coor_1;
		coordinates(61, 2) = +coor_1;
		// point 63
		coordinates(62, 0) = +coor_2;					weights(62) = weig_2;
		coordinates(62, 1) = +coor_1;
		coordinates(62, 2) = +coor_1;
		// point 64
		coordinates(63, 0) = +coor_1;					weights(63) = weig_1;
		coordinates(63, 1) = +coor_1;
		coordinates(63, 2) = +coor_1;
		break;
	}
	case 125:
	{
		const double weig_1 = 0.013299736420632648092;
		const double weig_2 = 0.026867508765371842524;
		const double weig_3 = 0.031934207352848290676;
		const double weig_4 = 0.05427649123462815748;
		const double weig_5 = 0.06451200000000000000;
		const double weig_6 = 0.07667773006934522489;
		const double weig_7 = 0.10964684245453881967;
		const double weig_8 = 0.13032414106964827997;
		const double weig_9 = 0.15490078296220484370;
		const double weig_10 = 0.18411210973936899863;

		const double coor_1 = 0.90617984593866399280;
		const double coor_2 = 0.53846931010568309104;

		// point 1
		coordinates(0, 0) = -coor_1;					weights(0) = weig_1;
		coordinates(0, 1) = -coor_1;
		coordinates(0, 2) = -coor_1;
		// point 2
		coordinates(1, 0) = -coor_2;					weights(1) = weig_2;
		coordinates(1, 1) = -coor_1;
		coordinates(1, 2) = -coor_1;
		// point 3
		coordinates(2, 0) = 0.0;						weights(2) = weig_3;
		coordinates(2, 1) = -coor_1;
		coordinates(2, 2) = -coor_1;
		// point 4
		coordinates(3, 0) = +coor_2;					weights(3) = weig_2;
		coordinates(3, 1) = -coor_1;
		coordinates(3, 2) = -coor_1;
		// point 5
		coordinates(4, 0) = +coor_1;					weights(4) = weig_1;
		coordinates(4, 1) = -coor_1;
		coordinates(4, 2) = -coor_1;
		// point 6
		coordinates(5, 0) = -coor_1;					weights(5) = weig_2;
		coordinates(5, 1) = -coor_2;
		coordinates(5, 2) = -coor_1;
		// point 7
		coordinates(6, 0) = -coor_2;					weights(6) = weig_4;
		coordinates(6, 1) = -coor_2;
		coordinates(6, 2) = -coor_1;
		// point 8
		coordinates(7, 0) = 0.0;						weights(7) = weig_5;
		coordinates(7, 1) = -coor_2;
		coordinates(7, 2) = -coor_1;
		// point 9
		coordinates(8, 0) = +coor_2;					weights(8) = weig_4;
		coordinates(8, 1) = -coor_2;
		coordinates(8, 2) = -coor_1;
		// point 10
		coordinates(9, 0) = +coor_1;					weights(9) = weig_2;
		coordinates(9, 1) = -coor_2;
		coordinates(9, 2) = -coor_1;
		// point 11
		coordinates(10, 0) = -coor_1;					weights(10) = weig_3;
		coordinates(10, 1) = 0.0;
		coordinates(10, 2) = -coor_1;
		// point 12
		coordinates(11, 0) = -coor_2;					weights(11) = weig_5;
		coordinates(11, 1) = 0.0;
		coordinates(11, 2) = -coor_1;
		// point 13
		coordinates(12, 0) = 0.0;						weights(12) = weig_6;
		coordinates(12, 1) = 0.0;
		coordinates(12, 2) = -coor_1;
		// point 14
		coordinates(13, 0) = +coor_2;					weights(13) = weig_5;
		coordinates(13, 1) = 0.0;
		coordinates(13, 2) = -coor_1;
		// point 15
		coordinates(14, 0) = +coor_1;					weights(14) = weig_3;
		coordinates(14, 1) = 0.0;
		coordinates(14, 2) = -coor_1;
		// point 16
		coordinates(15, 0) = -coor_1;					weights(15) = weig_2;
		coordinates(15, 1) = +coor_2;
		coordinates(15, 2) = -coor_1;
		// point 17
		coordinates(16, 0) = -coor_2;					weights(16) = weig_4;
		coordinates(16, 1) = +coor_2;
		coordinates(16, 2) = -coor_1;
		// point 18
		coordinates(17, 0) = 0.0;						weights(17) = weig_5;
		coordinates(17, 1) = +coor_2;
		coordinates(17, 2) = -coor_1;
		// point 19
		coordinates(18, 0) = +coor_2;					weights(18) = weig_4;
		coordinates(18, 1) = +coor_2;
		coordinates(18, 2) = -coor_1;
		// point 20
		coordinates(19, 0) = +coor_1;					weights(19) = weig_2;
		coordinates(19, 1) = +coor_2;
		coordinates(19, 2) = -coor_1;
		// point 21
		coordinates(20, 0) = -coor_1;					weights(20) = weig_1;
		coordinates(20, 1) = +coor_1;
		coordinates(20, 2) = -coor_1;
		// point 22
		coordinates(21, 0) = -coor_2;					weights(21) = weig_2;
		coordinates(21, 1) = +coor_1;
		coordinates(21, 2) = -coor_1;
		// point 23
		coordinates(22, 0) = 0.0;						weights(22) = weig_3;
		coordinates(22, 1) = +coor_1;
		coordinates(22, 2) = -coor_1;
		// point 24
		coordinates(23, 0) = +coor_2;					weights(23) = weig_2;
		coordinates(23, 1) = +coor_1;
		coordinates(23, 2) = -coor_1;
		// point 25
		coordinates(24, 0) = +coor_1;					weights(24) = weig_1;
		coordinates(24, 1) = +coor_1;
		coordinates(24, 2) = -coor_1;
		// point 26
		coordinates(25, 0) = -coor_1;					weights(25) = weig_2;
		coordinates(25, 1) = -coor_1;
		coordinates(25, 2) = -coor_2;
		// point 27
		coordinates(26, 0) = -coor_2;					weights(26) = weig_4;
		coordinates(26, 1) = -coor_1;
		coordinates(26, 2) = -coor_2;
		// point 28
		coordinates(27, 0) = 0.0;						weights(27) = weig_5;
		coordinates(27, 1) = -coor_1;
		coordinates(27, 2) = -coor_2;
		// point 29
		coordinates(28, 0) = +coor_2;					weights(28) = weig_4;
		coordinates(28, 1) = -coor_1;
		coordinates(28, 2) = -coor_2;
		// point 30
		coordinates(29, 0) = +coor_1;					weights(29) = weig_2;
		coordinates(29, 1) = -coor_1;
		coordinates(29, 2) = -coor_2;
		// point 31
		coordinates(30, 0) = -coor_1;					weights(30) = weig_4;
		coordinates(30, 1) = -coor_2;
		coordinates(30, 2) = -coor_2;
		// point 32
		coordinates(31, 0) = -coor_2;					weights(31) = weig_7;
		coordinates(31, 1) = -coor_2;
		coordinates(31, 2) = -coor_2;
		// point 33
		coordinates(32, 0) = 0.0;						weights(32) = weig_8;
		coordinates(32, 1) = -coor_2;
		coordinates(32, 2) = -coor_2;
		// point 34
		coordinates(33, 0) = +coor_2;					weights(33) = weig_7;
		coordinates(33, 1) = -coor_2;
		coordinates(33, 2) = -coor_2;
		// point 35
		coordinates(34, 0) = +coor_1;					weights(34) = weig_4;
		coordinates(34, 1) = -coor_2;
		coordinates(34, 2) = -coor_2;
		// point 36
		coordinates(35, 0) = -coor_1;					weights(35) = weig_5;
		coordinates(35, 1) = 0.0;
		coordinates(35, 2) = -coor_2;
		// point 37
		coordinates(36, 0) = -coor_2;					weights(36) = weig_8;
		coordinates(36, 1) = 0.0;
		coordinates(36, 2) = -coor_2;
		// point 38
		coordinates(37, 0) = 0.0;						weights(37) = weig_9;
		coordinates(37, 1) = 0.0;
		coordinates(37, 2) = -coor_2;
		// point 39
		coordinates(38, 0) = +coor_2;					weights(38) = weig_8;
		coordinates(38, 1) = 0.0;
		coordinates(38, 2) = -coor_2;
		// point 40
		coordinates(39, 0) = +coor_1;					weights(39) = weig_5;
		coordinates(39, 1) = 0.0;
		coordinates(39, 2) = -coor_2;
		// point 41
		coordinates(40, 0) = -coor_1;					weights(40) = weig_4;
		coordinates(40, 1) = +coor_2;
		coordinates(40, 2) = -coor_2;
		// point 42
		coordinates(41, 0) = -coor_2;					weights(41) = weig_7;
		coordinates(41, 1) = +coor_2;
		coordinates(41, 2) = -coor_2;
		// point 43
		coordinates(42, 0) = 0.0;						weights(42) = weig_8;
		coordinates(42, 1) = +coor_2;
		coordinates(42, 2) = -coor_2;
		// point 44
		coordinates(43, 0) = +coor_2;					weights(43) = weig_7;
		coordinates(43, 1) = +coor_2;
		coordinates(43, 2) = -coor_2;
		// point 45
		coordinates(44, 0) = +coor_1;					weights(44) = weig_4;
		coordinates(44, 1) = +coor_2;
		coordinates(44, 2) = -coor_2;
		// point 46
		coordinates(45, 0) = -coor_1;					weights(45) = weig_2;
		coordinates(45, 1) = +coor_1;
		coordinates(45, 2) = -coor_2;
		// point 47
		coordinates(46, 0) = -coor_2;					weights(46) = weig_4;
		coordinates(46, 1) = +coor_1;
		coordinates(46, 2) = -coor_2;
		// point 48
		coordinates(47, 0) = 0.0;						weights(47) = weig_5;
		coordinates(47, 1) = +coor_1;
		coordinates(47, 2) = -coor_2;
		// point 49
		coordinates(48, 0) = +coor_2;					weights(48) = weig_4;
		coordinates(48, 1) = +coor_1;
		coordinates(48, 2) = -coor_2;
		// point 50
		coordinates(49, 0) = +coor_1;					weights(49) = weig_2;
		coordinates(49, 1) = +coor_1;
		coordinates(49, 2) = -coor_2;
		// point 51
		coordinates(50, 0) = -coor_1;					weights(50) = weig_3;
		coordinates(50, 1) = -coor_1;
		coordinates(50, 2) = 0.0;
		// point 52
		coordinates(51, 0) = -coor_2;					weights(51) = weig_5;
		coordinates(51, 1) = -coor_1;
		coordinates(51, 2) = 0.0;
		// point 53
		coordinates(52, 0) = 0.0;						weights(52) = weig_6;
		coordinates(52, 1) = -coor_1;
		coordinates(52, 2) = 0.0;
		// point 54
		coordinates(53, 0) = +coor_2;					weights(53) = weig_5;
		coordinates(53, 1) = -coor_1;
		coordinates(53, 2) = 0.0;
		// point 55
		coordinates(54, 0) = +coor_1;					weights(54) = weig_3;
		coordinates(54, 1) = -coor_1;
		coordinates(54, 2) = 0.0;
		// point 56
		coordinates(55, 0) = -coor_1;					weights(55) = weig_5;
		coordinates(55, 1) = -coor_2;
		coordinates(55, 2) = 0.0;
		// point 57
		coordinates(56, 0) = -coor_2;					weights(56) = weig_8;
		coordinates(56, 1) = -coor_2;
		coordinates(56, 2) = 0.0;
		// point 58
		coordinates(57, 0) = 0.0;						weights(57) = weig_9;
		coordinates(57, 1) = -coor_2;
		coordinates(57, 2) = 0.0;
		// point 59
		coordinates(58, 0) = +coor_2;					weights(58) = weig_8;
		coordinates(58, 1) = -coor_2;
		coordinates(58, 2) = 0.0;
		// point 60
		coordinates(59, 0) = +coor_1;					weights(59) = weig_5;
		coordinates(59, 1) = -coor_2;
		coordinates(59, 2) = 0.0;
		// point 61
		coordinates(60, 0) = -coor_1;					weights(60) = weig_6;
		coordinates(60, 1) = 0.0;
		coordinates(60, 2) = 0.0;
		// point 62
		coordinates(61, 0) = -coor_2;					weights(61) = weig_9;
		coordinates(61, 1) = 0.0;
		coordinates(61, 2) = 0.0;
		// point 63
		coordinates(62, 0) = 0.0;						weights(62) = weig_10;
		coordinates(62, 1) = 0.0;
		coordinates(62, 2) = 0.0;
		// point 64
		coordinates(63, 0) = +coor_2;					weights(63) = weig_9;
		coordinates(63, 1) = 0.0;
		coordinates(63, 2) = 0.0;
		// point 65
		coordinates(64, 0) = +coor_1;					weights(64) = weig_6;
		coordinates(64, 1) = 0.0;
		coordinates(64, 2) = 0.0;
		// point 66
		coordinates(65, 0) = -coor_1;					weights(65) = weig_5;
		coordinates(65, 1) = +coor_2;
		coordinates(65, 2) = 0.0;
		// point 67
		coordinates(66, 0) = -coor_2;					weights(66) = weig_8;
		coordinates(66, 1) = +coor_2;
		coordinates(66, 2) = 0.0;
		// point 68
		coordinates(67, 0) = 0.0;						weights(67) = weig_9;
		coordinates(67, 1) = +coor_2;
		coordinates(67, 2) = 0.0;
		// point 69
		coordinates(68, 0) = +coor_2;					weights(68) = weig_8;
		coordinates(68, 1) = +coor_2;
		coordinates(68, 2) = 0.0;
		// point 70
		coordinates(69, 0) = +coor_1;					weights(69) = weig_5;
		coordinates(69, 1) = +coor_2;
		coordinates(69, 2) = 0.0;
		// point 71
		coordinates(70, 0) = -coor_1;					weights(70) = weig_3;
		coordinates(70, 1) = +coor_1;
		coordinates(70, 2) = 0.0;
		// point 72
		coordinates(71, 0) = -coor_2;					weights(71) = weig_5;
		coordinates(71, 1) = +coor_1;
		coordinates(71, 2) = 0.0;
		// point 73
		coordinates(72, 0) = 0.0;						weights(72) = weig_6;
		coordinates(72, 1) = +coor_1;
		coordinates(72, 2) = 0.0;
		// point 74
		coordinates(73, 0) = +coor_2;					weights(73) = weig_5;
		coordinates(73, 1) = +coor_1;
		coordinates(73, 2) = 0.0;
		// point 75
		coordinates(74, 0) = +coor_1;					weights(74) = weig_3;
		coordinates(74, 1) = +coor_1;
		coordinates(74, 2) = 0.0;
		// point 76
		coordinates(75, 0) = -coor_1;					weights(75) = weig_2;
		coordinates(75, 1) = -coor_1;
		coordinates(75, 2) = +coor_2;
		// point 77
		coordinates(76, 0) = -coor_2;					weights(76) = weig_4;
		coordinates(76, 1) = -coor_1;
		coordinates(76, 2) = +coor_2;
		// point 78
		coordinates(77, 0) = 0.0;						weights(77) = weig_5;
		coordinates(77, 1) = -coor_1;
		coordinates(77, 2) = +coor_2;
		// point 79
		coordinates(78, 0) = +coor_2;					weights(78) = weig_4;
		coordinates(78, 1) = -coor_1;
		coordinates(78, 2) = +coor_2;
		// point 80
		coordinates(79, 0) = +coor_1;					weights(79) = weig_2;
		coordinates(79, 1) = -coor_1;
		coordinates(79, 2) = +coor_2;
		// point 81
		coordinates(80, 0) = -coor_1;					weights(80) = weig_4;
		coordinates(80, 1) = -coor_2;
		coordinates(80, 2) = +coor_2;
		// point 82
		coordinates(81, 0) = -coor_2;					weights(81) = weig_7;
		coordinates(81, 1) = -coor_2;
		coordinates(81, 2) = +coor_2;
		// point 83
		coordinates(82, 0) = 0.0;						weights(82) = weig_8;
		coordinates(82, 1) = -coor_2;
		coordinates(82, 2) = +coor_2;
		// point 84
		coordinates(83, 0) = +coor_2;					weights(83) = weig_7;
		coordinates(83, 1) = -coor_2;
		coordinates(83, 2) = +coor_2;
		// point 85
		coordinates(84, 0) = +coor_1;					weights(84) = weig_4;
		coordinates(84, 1) = -coor_2;
		coordinates(84, 2) = +coor_2;
		// point 86
		coordinates(85, 0) = -coor_1;					weights(85) = weig_5;
		coordinates(85, 1) = 0.0;
		coordinates(85, 2) = +coor_2;
		// point 87
		coordinates(86, 0) = -coor_2;					weights(86) = weig_8;
		coordinates(86, 1) = 0.0;
		coordinates(86, 2) = +coor_2;
		// point 88
		coordinates(87, 0) = 0.0;						weights(87) = weig_9;
		coordinates(87, 1) = 0.0;
		coordinates(87, 2) = +coor_2;
		// point 89
		coordinates(88, 0) = +coor_2;					weights(88) = weig_8;
		coordinates(88, 1) = 0.0;
		coordinates(88, 2) = +coor_2;
		// point 90
		coordinates(89, 0) = +coor_1;					weights(89) = weig_5;
		coordinates(89, 1) = 0.0;
		coordinates(89, 2) = +coor_2;
		// point 91
		coordinates(90, 0) = -coor_1;					weights(90) = weig_4;
		coordinates(90, 1) = +coor_2;
		coordinates(90, 2) = +coor_2;
		// point 92
		coordinates(91, 0) = -coor_2;					weights(91) = weig_7;
		coordinates(91, 1) = +coor_2;
		coordinates(91, 2) = +coor_2;
		// point 93
		coordinates(92, 0) = 0.0;						weights(92) = weig_8;
		coordinates(92, 1) = +coor_2;
		coordinates(92, 2) = +coor_2;
		// point 94
		coordinates(93, 0) = +coor_2;					weights(93) = weig_7;
		coordinates(93, 1) = +coor_2;
		coordinates(93, 2) = +coor_2;
		// point 95
		coordinates(94, 0) = +coor_1;					weights(94) = weig_4;
		coordinates(94, 1) = +coor_2;
		coordinates(94, 2) = +coor_2;
		// point 96
		coordinates(95, 0) = -coor_1;					weights(95) = weig_2;
		coordinates(95, 1) = +coor_1;
		coordinates(95, 2) = +coor_2;
		// point 97
		coordinates(96, 0) = -coor_2;					weights(96) = weig_4;
		coordinates(96, 1) = +coor_1;
		coordinates(96, 2) = +coor_2;
		// point 98
		coordinates(97, 0) = 0.0;						weights(97) = weig_5;
		coordinates(97, 1) = +coor_1;
		coordinates(97, 2) = +coor_2;
		// point 99
		coordinates(98, 0) = +coor_2;					weights(98) = weig_4;
		coordinates(98, 1) = +coor_1;
		coordinates(98, 2) = +coor_2;
		// point 100
		coordinates(99, 0) = +coor_1;					weights(99) = weig_2;
		coordinates(99, 1) = +coor_1;
		coordinates(99, 2) = +coor_2;
		// point 101
		coordinates(100, 0) = -coor_1;					weights(100) = weig_1;
		coordinates(100, 1) = -coor_1;
		coordinates(100, 2) = +coor_1;
		// point 102
		coordinates(101, 0) = -coor_2;					weights(101) = weig_2;
		coordinates(101, 1) = -coor_1;
		coordinates(101, 2) = +coor_1;
		// point 103
		coordinates(102, 0) = 0.0;						weights(102) = weig_3;
		coordinates(102, 1) = -coor_1;
		coordinates(102, 2) = +coor_1;
		// point 104
		coordinates(103, 0) = +coor_2;					weights(103) = weig_2;
		coordinates(103, 1) = -coor_1;
		coordinates(103, 2) = +coor_1;
		// point 105
		coordinates(104, 0) = +coor_1;					weights(104) = weig_1;
		coordinates(104, 1) = -coor_1;
		coordinates(104, 2) = +coor_1;
		// point 106
		coordinates(105, 0) = -coor_1;					weights(105) = weig_2;
		coordinates(105, 1) = -coor_2;
		coordinates(105, 2) = +coor_1;
		// point 107
		coordinates(106, 0) = -coor_2;					weights(106) = weig_4;
		coordinates(106, 1) = -coor_2;
		coordinates(106, 2) = +coor_1;
		// point 108
		coordinates(107, 0) = 0.0;						weights(107) = weig_5;
		coordinates(107, 1) = -coor_2;
		coordinates(107, 2) = +coor_1;
		// point 109
		coordinates(108, 0) = +coor_2;					weights(108) = weig_4;
		coordinates(108, 1) = -coor_2;
		coordinates(108, 2) = +coor_1;
		// point 110
		coordinates(109, 0) = +coor_1;					weights(109) = weig_2;
		coordinates(109, 1) = -coor_2;
		coordinates(109, 2) = +coor_1;
		// point 111
		coordinates(110, 0) = -coor_1;					weights(110) = weig_3;
		coordinates(110, 1) = 0.0;
		coordinates(110, 2) = +coor_1;
		// point 112
		coordinates(111, 0) = -coor_2;					weights(111) = weig_5;
		coordinates(111, 1) = 0.0;
		coordinates(111, 2) = +coor_1;
		// point 113
		coordinates(112, 0) = 0.0;						weights(112) = weig_6;
		coordinates(112, 1) = 0.0;
		coordinates(112, 2) = +coor_1;
		// point 114
		coordinates(113, 0) = +coor_2;					weights(113) = weig_5;
		coordinates(113, 1) = 0.0;
		coordinates(113, 2) = +coor_1;
		// point 115
		coordinates(114, 0) = +coor_1;					weights(114) = weig_3;
		coordinates(114, 1) = 0.0;
		coordinates(114, 2) = +coor_1;
		// point 116
		coordinates(115, 0) = -coor_1;					weights(115) = weig_2;
		coordinates(115, 1) = +coor_2;
		coordinates(115, 2) = +coor_1;
		// point 117
		coordinates(116, 0) = -coor_2;					weights(116) = weig_4;
		coordinates(116, 1) = +coor_2;
		coordinates(116, 2) = +coor_1;
		// point 118
		coordinates(117, 0) = 0.0;						weights(117) = weig_5;
		coordinates(117, 1) = +coor_2;
		coordinates(117, 2) = +coor_1;
		// point 119
		coordinates(118, 0) = +coor_2;					weights(118) = weig_4;
		coordinates(118, 1) = +coor_2;
		coordinates(118, 2) = +coor_1;
		// point 120
		coordinates(119, 0) = +coor_1;					weights(119) = weig_2;
		coordinates(119, 1) = +coor_2;
		coordinates(119, 2) = +coor_1;
		// point 121
		coordinates(120, 0) = -coor_1;					weights(120) = weig_1;
		coordinates(120, 1) = +coor_1;
		coordinates(120, 2) = +coor_1;
		// point 122
		coordinates(121, 0) = -coor_2;					weights(121) = weig_2;
		coordinates(121, 1) = +coor_1;
		coordinates(121, 2) = +coor_1;
		// point 123
		coordinates(122, 0) = 0.0;						weights(122) = weig_3;
		coordinates(122, 1) = +coor_1;
		coordinates(122, 2) = +coor_1;
		// point 124
		coordinates(123, 0) = +coor_2;					weights(123) = weig_2;
		coordinates(123, 1) = +coor_1;
		coordinates(123, 2) = +coor_1;
		// point 125
		coordinates(124, 0) = +coor_1;					weights(124) = weig_1;
		coordinates(124, 1) = +coor_1;
		coordinates(124, 2) = +coor_1;
		break;
	}
	default:
		throw std::out_of_range("Invalid number of integration points. Error in file " __FILE__);
	}
	return std::make_pair(coordinates, weights);
}

#endif // !HEXAHEDRON_GAUSS_LEGENDRE_INTEGRATION_POINTS_H
