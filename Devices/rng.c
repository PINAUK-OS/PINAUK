// Random number generator

int seed = 880055535;	// Default seed value

void setseed(int new_seed) 
{
    seed = new_seed;
}
int genrndno() 
{
	return (seed = (seed * 1103515245 + 28162) & 0x7fffffff) % 1000000;	// I guess it's random enough...
}