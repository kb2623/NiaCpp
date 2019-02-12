#include <iostream>
#include <random>
#include <limits>
#include <vector>

// TODO To be deleted
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xrandom.hpp>
// TODO To be deleted
#include <Eigen/Dense>
#include "arrays/array.h"

#include <cxxopts.hpp>

using namespace std;

enum Test {
	ONE = 1,
	NONE = -1
};

void xtensor_example() {
	// Example of init
	cout << endl << endl;
	xt::xarray<int> arr {1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << arr.shape()[0] << endl;
	auto r = argwhere(arr < 5);
	cout << r.data() << endl;
	arr.reshape({3, 3});
	cout << arr.shape().size() << endl;
	cout << arr << endl;

	// Example of operations
	cout << endl << endl;
	cout << arr + arr << endl;
	cout << arr * arr << endl;
	cout << arr / arr << endl;

	// Example for using randome engine
	cout << endl << endl;
	auto rnd1 = xt::random::get_default_random_engine();
	auto rnd2 = xt::random::get_default_random_engine();
	rnd1.seed(123);
	rnd2.seed(123);
	cout << xt::random::rand<double>({3, 3}, -10, 10, rnd1) << endl;
	cout << xt::random::rand<double>({3, 3}, -10, 10, rnd2) << endl;
	cout << xt::random::rand<double>({4, 4, 4, 4}) << endl;

	// random generator
	cout << endl << endl;
	auto rand1 = minstd_rand0(123);
	auto rand2 = minstd_rand0(123);
	cout << endl;
	cout << xt::random::rand<double>({2, 2}, -10, 10, rand1) << endl;
	cout << xt::random::rand<double>({2, 2}, -10, 10, rand2) << endl;

	// Brodcasting
	cout << endl << endl;
	auto rnd = minstd_rand0(123);
	auto A = xt::random::rand<double>({3, 3}, -10, 10, rnd);
	cout << "A = " << endl << A << endl;
	xt::xarray<double> b = xt::random::rand<double>({3}, -10, 10, rnd);
	cout << "b = " << endl << b << endl;
	cout << "A + b  = " << endl << A + b << endl;
	b.reshape({3, 1});
	cout << "b' = " << endl << b << endl;
	cout << "A + b' = " << endl << A + b << endl;
}

void eigen_example() {
	// Eigen test
	cout << endl << endl;
	Eigen::MatrixXd m = Eigen::MatrixXd::Random(3,3);
	m = (m + Eigen::MatrixXd::Constant(3,3,1.2)) * 50;
	cout << "m =" << endl << m << endl << endl;
	auto v = Eigen::VectorXd(3);
	v << 1, 2, 3;
	cout << "v =" << endl << v << endl << endl;
	cout << "m * v =" << endl << m * v << endl << endl;
	cout << "m .* v =" << endl << m.array().colwise() * v.array() << endl;
}

void cpp_test() {
	// infinity
	cout << endl << endl;
	auto infd = numeric_limits<double>::infinity();
	cout << infd << endl;
	auto infi = numeric_limits<int>::infinity();
	cout << infi << endl;
	cout << (infd < infi) << endl;
	cout << (infd == infi) << endl;
	cout << (infi == infi) << endl;
	cout << (infd == infd) << endl;
	cout << -1 * infd << endl;
	cout << -1 * infi << endl;

	// Enum test
	cout << endl << endl;
	cout << ONE << endl;
	cout << NONE << endl;

	// Random generator
	auto rand1 = minstd_rand0(123);
	auto rand2 = minstd_rand0(123);
	auto dist = uniform_int_distribution(0, 10);
	for (int i = 0; i < 10; ++i) cout << dist(rand1) << " " << dist(rand2) << " | ";
}

void test_array() {
	auto shape = vector<unsigned int>({3, 3, 3});
	auto a = Array(shape);
	auto b = Array({3, 3, 3});
}

int main(int argc, char* argv[]) {
//	eigen_example();
//	cpp_test();
//	xtensor_example();
	test_array();
	return 0;
}
