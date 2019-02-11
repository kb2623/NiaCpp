#include "differentialevolution.h"

DifferentialEvolution::DifferentialEvolution() : NP(25), F(0.2), CR(0.9) {}

DifferentialEvolution::DifferentialEvolution(unsigned int NP, double F, double CR) : NP(NP), F(F), CR(CR) {}
