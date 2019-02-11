#include "individual.h"

using namespace xt;

Individual::Individual() {

}

Individual::Individual(xarray<double> ix, Task t) : x(t.repair(ix)) {
	f = t.eval(x);
}

bool Individual::operator<(Individual i) {
	if (f < i.f) return true;
	return false;
}
