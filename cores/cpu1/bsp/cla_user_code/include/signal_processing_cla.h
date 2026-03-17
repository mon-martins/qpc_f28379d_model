/*
 * signal_processing_cla.h
 *
 *  Created on: 7 de jun de 2024
 *      Author: ramon.martins
 */


#ifndef APPLICATION_INCLUDE_CLA_SIGNAL_PROCESSING_CLA_H_
#define APPLICATION_INCLUDE_CLA_SIGNAL_PROCESSING_CLA_H_

#include "CLAmath.h"

#include "board.h"

#define N_STAGES 8

typedef struct {
    float b[N_STAGES + 1]; // Numerator coefficients
    float a[N_STAGES + 1]; // Denominator coefficients
    float x[N_STAGES + 1];
    float y[N_STAGES + 1];
}IIRFilter;

void initializeIIRFilter(IIRFilter *filter, float *b, float *a);
float applyIIRFilter(IIRFilter *filter, float input);

// Control

typedef struct{

    float kp;
    float ki;
    float kd;
    float tau;

    float p_component;
    float i_component;
    float d_component;

    float klim;

    float max_lim;
    float min_lim;

    float back_calculation;
    float error;
    float setpoint;
    float measure;

    float ktt;

    float error_prev;

} PID_Control_t;

float PID_Control_Exe( PID_Control_t *PID_Data , float32_t period_seconds );

#endif /* APPLICATION_INCLUDE_CLA_SIGNAL_PROCESSING_CLA_H_ */
