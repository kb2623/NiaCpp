#ifndef DIFFERENTIALEVOLUTION_H
#define DIFFERENTIALEVOLUTION_H

#include "../algorithm.h"
#include "../individual.h"
#include "../../util/task.h"

template<typename T>
class DifferentialEvolution : Algorithm<T> {
protected:
	unsigned int NP;
	double F;
	double CR;

public:
	DifferentialEvolution() : NP(25), F(0.9), CR(0.9) {}

	DifferentialEvolution(unsigned int iNP, double F, double CR) : NP(iNP), F(F), CR(CR) {	}

	Individual<T> run(Task<T> task) {
		// TODO
		return Individual<T>();
	}

	~DifferentialEvolution() {}

};

#endif // DIFFERENTIALEVOLUTION_H
