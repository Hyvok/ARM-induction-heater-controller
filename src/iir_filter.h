#ifndef IIR_FILTER_H
#define IIR_FILTER_H

/*--------------------------------------------------------------------*/
// Infinite impulse response filter 
/*--------------------------------------------------------------------*/

struct IirFilter
{
    float b0f;
    float b1f;
    float a1f;
    float lastInput;
    float lastOutput;
};

/*--------------------------------------------------------------------*/
// Initialize IIR filter 
//
struct IirFilter* initIirFilter(float b0f, float b1f, float a1f);

/*--------------------------------------------------------------------*/
// Compute IIR filter 
//
float computeIirFilter(float value);

#endif // Include guard
