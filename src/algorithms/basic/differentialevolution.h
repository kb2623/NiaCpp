#ifndef DIFFERENTIALEVOLUTION_H
#define DIFFERENTIALEVOLUTION_H

#include "../algorithm.h"

class DifferentialEvolution : Algorithm {
protected:
	unsigned int NP;
	double F;
	double CR;

public:
	DifferentialEvolution();
	DifferentialEvolution(unsigned int, double, double);
};

#endif // DIFFERENTIALEVOLUTION_H
