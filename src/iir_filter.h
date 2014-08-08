#ifndef IIR_FILTER_H
#define IIR_FILTER_H

struct IirFilter
{
    float b0f;
    float b1f;
    float a1f;
    float lastInput;
    float lastOutput;
};

struct IirFilter* initIirFilter(float b0f, float b1f, float a1f);

float computeIirFilter(float value);

#endif // Include guard
