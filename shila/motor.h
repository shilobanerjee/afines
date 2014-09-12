/*
 * motor.h
 *  
 *
 *  Created by Shiladitya Banerjee on 9/3/13.
 *  Copyright 2013 University of Chicago. All rights reserved.
 *
 */

//=====================================
//include guard
#ifndef __MOTOR_H_INCLUDED__
#define __MOTOR_H_INCLUDED__

//=====================================
// forward declared dependencies
class actin_ensemble;

//=====================================
//included dependences
#include "vector"
#include "map"
#include "string"

//motor class
class motor 
{
    public:

        motor(double mx, double my, double mang, double mlen, actin_ensemble* network, int state0, int state1, int aindex0, int aindex1, double fovx, double fovy, double v0, double stiffness, double ron, double roff, double rend, double actin_len, double vis, std::string col);

        ~motor();

        int* get_states();

        double* get_heads();

        std::string get_color();

        double tension();

        void attach(int hd);

        void brownian();

        void step_onehead(int hd);

        void step_twoheads();

        void actin_update();

        void update_shape();

    private:

        double hx[2],hy[2], xm[2], ym[2], mphi,mld,mobility,fm[2],vm[2],offrate[2], onrate, stretch,forcex[2],forcey[2],torque[2], force_par[2],force_perp[2],vs, pos_temp;

        int state[2], aindex[2];
        
        double dm,fmax,mk, kon, koff, kend;
        
        std::map<int, double> dist;
        
        std::string color;
        
        actin_ensemble *actin_network;
        
        double /*pos_actin[2],*/ pos_a_end[2], fov[2];

        inline void move_end_detach(int hd, double speed, double pos);

        inline void reflect(double x1, double x2, double y1, double y2);
};


//motor ensemble class
class motor_ensemble
{
    public:

        motor_ensemble(double mdensity, double fovx, double fovy, double mlen, actin_ensemble* network, double v0, double stiffness, double ron, double roff, double rend, double actin_len, double vis);

        ~motor_ensemble();

        void motor_walk();

        void reshape();

        void motor_write(std::ofstream& fout);

        void motor_tension(std::ofstream& fout);

        void add_motor(motor m);

    private:

        double fov[2], mrho, mld, mang, motorx, motory, mphi, mcor[3],alpha;
        int nm, s[2],a[2];
        actin_ensemble *a_network;
        std::vector<motor> n_motors;  
        std::string color;
};

#endif
