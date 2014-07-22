#include <stdbool.h>
#include "pid_controller.h"

struct PidController pid = {0, 0, 0, 0, 0, 0, false};

struct PidController* initPid(  float prop, float deriv, float integ, 
                                float posCap, float negCap)
{
    pid.prop = prop;
    pid.deriv = deriv;
    pid.integ = integ;
    pid.posCap = posCap;
    pid.negCap = negCap;
    pid.saturated = false;

    return &pid;
}
float computePid(float val)
{
    float error = (val * pid.prop) + ((val - pid.lastError) * pid.deriv);
   
    // If the controller output has not saturated, then continue increasing the
    // integral term, otherwise not (to prevent integral windup)
    if(pid.saturated == false && pid.integ != 0)
    {
       error += pid.lastError * pid.integ;
    }

    // Cap error value if output saturates
    if(error > pid.posCap)
    {
        error = pid.posCap;
        pid.saturated = true;
    }
    else if(error < pid.negCap)
    {
        error = pid.negCap;
        pid.saturated = true;
    }
    else
    {
        pid.saturated = false;
    }

    pid.lastError = error;

    return error;
}
