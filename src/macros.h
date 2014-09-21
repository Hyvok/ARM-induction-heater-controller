#ifndef MACROS_H
#define MACROS_H

/*--------------------------------------------------------------------*/
// Helper macros
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
// Set register bits specified by mask to value
//
#define SET_MASK(reg, mask, val)    (reg = ((reg & ~mask)) | val)

#endif // Include guard
