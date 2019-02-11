#include <iostream>
#include <random>
#include <limits>

#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xrandom.hpp>

#include <cxxopts.hpp>

using namespace std;
using namespace xt;

enum Test {
	ONE = 1,
	NONE = -1
};

int main(int argc, char* argv[]) {
	// Example of init
	cout << endl << endl;
	xarray<int> arr {1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << arr.shape()[0] << endl;
	xarray<int> r = argwhere(arr < 5);
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
	auto rnd1 = random::get_default_random_engine();
	auto rnd2 = random::get_default_random_engine();
	rnd1.seed(123);
	rnd2.seed(123);
	cout << random::rand<double>({3, 3}, -10, 10, rnd1) << endl;
	cout << random::rand<double>({3, 3}, -10, 10, rnd2) << endl;
	cout << random::rand<double>({4, 4, 4, 4}) << endl;

	// random generator
	cout << endl << endl;
	auto rand1 = minstd_rand0(123);
	auto rand2 = minstd_rand0(123);
	auto dist = uniform_int_distribution(0, 10);
	for (int i = 0; i < 10; ++i) {
		cout << dist(rand1) << " " << dist(rand2) << " | ";
	}
	cout << endl;
	cout << random::rand<double>({2, 2}, -10, 10, rand1) << endl;
	cout << random::rand<double>({2, 2}, -10, 10, rand2) << endl;

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

	cout << endl << endl;
	cout << ONE << endl;
	cout << NONE << endl;

	return 0;
}
