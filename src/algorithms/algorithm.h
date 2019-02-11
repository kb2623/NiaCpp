#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <map>
#include <string>
#include <tuple>

#include <xtensor/xarray.hpp>

#include "../util/task.h"

class Algorithm {
public:
   Algorithm() {}
   virtual ~Algorithm() {}
   virtual std::tuple<xt::xarray<double>, double> run(Task) = 0;
};

#endif // ALGORITHM_H
