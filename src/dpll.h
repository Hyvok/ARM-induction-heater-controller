#ifndef DPLL_H
#define DPLL_H

#include <stdint.h>

/*--------------------------------------------------------------------*/
// Digital phase-locked loop 
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
// Initialize DPLL
//
void initDpll();

/*--------------------------------------------------------------------*/
// Run DPLL algorithm
//
void computeDpll();

/*--------------------------------------------------------------------*/
// Start input capture timer
//
void startIcTimer();

/*--------------------------------------------------------------------*/
// Stop input capture timer
//
uint16_t stopIcTimer();

#endif // Include guard
