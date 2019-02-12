#ifndef TASK_H
#define TASK_H

#include <limits>

#include "../arrays/array.h"
#include "../algorithms/individual.h"

enum OptType {
	MINIMIZATION = 1,
	MAXIMIZATION = -1
};

template<typename T>
class Task {
protected:
	unsigned int D = 0;
	unsigned long fes = 0, gen = 0;
	Array<T> Lower;
	Array<T> Upper;
	OptType ot = MINIMIZATION;
	double (*evalFunc)(Individual<T>) = nullptr;

public:
	Task();
	/**
	 * @brief Task
	 */
	Task(double (*evalFunc)(Individual<T>), int, Array<T>, Array<T>, OptType);
	/**
	 * @brief eval
	 * @return
	 */
	double eval(Array<T> i) {
		return evalFunc(i) * ot;
	}
	/**
	 * @brief repair
	 * @return
	 */
        /*
	xt::xarray<double> repair();
        */
};

template<typename T>
class StoppingTask : Task<T> {
protected:
	long nFES = -1, nGEN = -1;
	double rVAL = std::numeric_limits<double>::infinity() * this->ot, brVAL = std::numeric_limits<double>::infinity() * this->ot;

public:
	StoppingTask();
	/**
	 * @brief StoppingTask
	 */
	StoppingTask(double (*evalFunc)(Individual<T>), int, Array<T>, Array<T>, long, long, double, OptType);
	/**
	 * @brief eval
	 * @return
	 */
	double eval(Array<T>);
	/**
	 * @brief stopCond
	 * @return
	 */
	bool stopCond();
	/**
	 * @brief stopCondE
	 * @return
	 */
	bool stopCondE();
	/**
	 * @brief stopCondI
	 *
	 * @return Is generations/iterations contition met
	 */
	bool stopCondI();
	/**
	 * @brief stopCondII Checks the stopping condition for number of generations/iterations of algorithm and increments generation/iteration counter
	 *
	 * @return Is generations/iterations contition met
	 */
	bool stopCondII();
	/**
	 * @brief stopCondV
	 * @return
	 */
	bool stopCondV();
};

#endif // TASK_H
