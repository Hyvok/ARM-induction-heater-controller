#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

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

struct PidController* initPid(  float prop, float deriv, float integ, 
                                float posCap, float negCap);

float computePid(float val);

#endif // Include guard
