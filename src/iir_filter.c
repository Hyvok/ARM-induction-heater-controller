#include "hw.h"
#include "iir_filter.h"

struct IirFilter iir = {0, 0, 0, 0, 0};

struct IirFilter* initIirFilter(float b0f, float b1f, float a1f)
{
    iir.b0f = b0f;
    iir.b1f = b1f;
    iir.a1f = a1f;

    return &iir;
}
float computeIirFilter(float value)
{
    float res = 0;

    res = iir.b0f * value + iir.b1f * iir.lastInput - iir.a1f * iir.lastOutput;

    iir.lastOutput = res;
    iir.lastInput = value;

    return res;
}
