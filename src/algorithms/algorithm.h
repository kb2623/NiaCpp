#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <map>
#include <string>
#include <tuple>

#include "individual.h"
#include "../util/task.h"

template<typename T>
class Algorithm {
public:
   Algorithm() {}
	virtual Individual<T> run(Task<T>) = 0;
};

#endif // ALGORITHM_H
