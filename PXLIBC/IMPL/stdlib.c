#include "stdlib.h"
#include "../../Devices/rng.c"
void srand(unsigned int seed) 
{
	setseed(seed);
}
int rand() 
{
	return genrndno();
}