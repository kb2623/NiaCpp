#include "task.h"

using namespace xt;

Task::Task() {}

Task::Task(EvalFunc func, int D, xarray<double> Lower, xarray<double> Upper, OptType ot) : func(func), D(D), Lower(Lower), Upper(Upper), ot(ot) {}

double Task::eval(xarray<double> I) {
	return (*func)(I) * ot;
}

StoppingTask::StoppingTask() {}

StoppingTask::StoppingTask(EvalFunc func, int D, xarray<double> Lower, xarray<double> Upper, long nFES, long nGEN, double rVAL, OptType ot) : Task(func, D, Lower, Upper, ot), nFES(nFES), nGEN(nGEN), rVAL(rVAL) {}

double StoppingTask::eval(xarray<double> I) {
	fes++;
	auto v = Task::eval(I);
	if (v < brVAL) brVAL = v;
	return v;
}

bool StoppingTask::stopCondE() {
	if (fes >= nFES) return true;
	return false;
}

bool StoppingTask::stopCondI() {
	if (gen >= nGEN) return true;
	return false;
}

bool StoppingTask::stopCondII() {
	if (stopCondI()) return true;
	gen++;
	return false;
}

bool StoppingTask::stopCondV() {
	if (rVAL <= brVAL) return true;
	return false;
}

bool StoppingTask::stopCond() {
	return stopCondE() || stopCondI() || stopCondV();
}
