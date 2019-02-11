#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <limits>

#include <xtensor/xarray.hpp>

#include "../util/task.h"

class Individual {
protected:
	xt::xarray<double> x;
	double f = std::numeric_limits<double>::infinity();

public:
	Individual();
	Individual(xt::xarray<double>, Task);
	bool operator<(Individual i);
};

#endif // INDIVIDUAL_H
