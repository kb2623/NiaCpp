#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <limits>

#include "../arrays/array.h"

template<class T>
class Individual {
protected:
//	xt::xarray<double> x;
	double f = std::numeric_limits<double>::infinity();

public:
	Individual();
	Individual(Array<T>);
	bool operator<(Individual<T> i) {
		return f < i.f;
	}
};

#endif // INDIVIDUAL_H
