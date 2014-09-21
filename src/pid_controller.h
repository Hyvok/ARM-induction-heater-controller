#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

/*--------------------------------------------------------------------*/
// Proportional/integral/derivative controller 
/*--------------------------------------------------------------------*/

struct PidController
{
    float prop;
    float deriv;
    float integ;
    float posCap;
    float negCap;
    float lastError;
    bool saturated;
};

/*--------------------------------------------------------------------*/
// Initialize PID filter 
//
struct PidController* initPid(  float prop, float deriv, float integ, 
                                float posCap, float negCap);

/*--------------------------------------------------------------------*/
// Compute PID filter 
//
float computePid(float currVal);

#endif // Include guard
