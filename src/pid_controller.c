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
float computePid(float currVal)
{
    currVal *= (-1.0);
    float proportional = currVal * pid.prop;
    float out = proportional + ((currVal - pid.lastError) * pid.deriv);
   
    // If the controller output has not saturated, then continue increasing the
    // integral term, otherwise not (to prevent integral windup)
    if(pid.saturated == false && pid.integ != 0)
    {
       out += proportional * pid.integ;
    }

    // Cap out currValue if output saturates
    if(out > pid.posCap)
    {
        out = pid.posCap;
        pid.saturated = true;
    }
    else if(out < pid.negCap)
    {
        out = pid.negCap;
        pid.saturated = true;
    }
    else
    {
        pid.saturated = false;
    }

    pid.lastError = currVal;

    return out;
}
