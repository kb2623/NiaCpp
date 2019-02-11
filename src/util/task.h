#ifndef TASK_H
#define TASK_H

#include <limits>

#include <xtensor/xarray.hpp>

using EvalFunc = double (*)(xt::xarray<double>);

enum OptType {
	MINIMIZATION = 1,
	MAXIMIZATION = -1
};

class Task {
protected:
	unsigned int D = 0;
	unsigned long fes = 0, gen = 0;
	xt::xarray<double> Lower;
	xt::xarray<double> Upper;
	OptType ot = MINIMIZATION;
	EvalFunc func = nullptr;

public:
	Task();
	/**
	 * @brief Task
	 */
	Task(EvalFunc, int, xt::xarray<double>, xt::xarray<double>, OptType);
	/**
	 * @brief eval
	 * @return
	 */
	double eval(xt::xarray<double>);
	/**
	 * @brief repair
	 * @return
	 */
	xt::xarray<double> repair(xt::xarray<double>);
};

class StoppingTask : Task {
protected:
	long nFES = -1, nGEN = -1;
	double rVAL = std::numeric_limits<double>::infinity() * ot, brVAL = std::numeric_limits<double>::infinity() * ot;

public:
	StoppingTask();
	/**
	 * @brief StoppingTask
	 */
	StoppingTask(EvalFunc, int, xt::xarray<double>, xt::xarray<double>, long, long, double, OptType);
	/**
	 * @brief eval
	 * @return
	 */
	double eval(xt::xarray<double>);
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
