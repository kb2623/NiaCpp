#ifndef DIFFERENTIALEVOLUTION_H
#define DIFFERENTIALEVOLUTION_H


class DifferentialEvolution {
protected:
	unsigned int NP;
	double F, CR;

public:
	DifferentialEvolution();
	DifferentialEvolution(unsigned int, double, double);
};

#endif // DIFFERENTIALEVOLUTION_H
