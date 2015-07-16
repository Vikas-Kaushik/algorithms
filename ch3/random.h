/*
 * File: random.h
 * --------------
 * This interface is for random number generation.
 */

#ifndef _random_h
#define _random_h

/*
 * Function: RandomIneger
 * Usage: n = RandomInteger(low, high);
 * ------------------------------------
 * This funciton does this and that...
 * range : [low, high]
 */

int RandomInteger(int low, int high);

/*
 * range :[low, high)
 */

double RandomReal(double low, double high);

bool RandomChance(double p);

void Randomize();

#endif 
