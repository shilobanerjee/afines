/*
 *  globals.h
 *  
 *  Created by Simon Freedman on 9/12/2014
 *
 *  Created by Shiladitya Banerjee on 9/3/13.
 *  Copyright 2013 University of Chicago. All rights reserved.
 *
 */

//=====================================
//include guard
#ifndef __GLOBALS_H_INCLUDED__
#define __GLOBALS_H_INCLUDED__

//=====================================
// forward declared dependencies

//=====================================
//included dependences
#include <iostream>
//#include "iomanip"
#include <math.h>
#include "fstream"
#include "string"
#include "stdint.h"
#include <stdlib.h>
#include "vector"

/* distances in microns, time in seconds, forces in pN * 
 * --> Temp in pN-um                                   */
//const double pi, eps, dt, temperature;
const double pi = 3.14159265358979323;
const double eps = 0.001;
const double dt = 0.0001;
const double temperature = 0.004;
/*generic functions to be used below*/

double rng(double start, double end);
int pr(int num);
double rng_exp(double mean);
double rng_n(double mean, double var);
int event(double rate, double timestep);
double dis_points(double x1, double y1, double x2, double y2);
double velocity(double vel0, double force, double fstall);
double cross(double ax, double ay, double bx, double by);
double dot(double x1, double y1, double x2, double y2);
double mean(std::vector<double> vals);
double var(std::vector<double> vals);
double mode_var(std::vector<double> vals, double m);
bool close(double e, double a, double r);
std::vector<double> sum_vecs(std::vector<double> v1, std::vector<double> v2);

#endif
