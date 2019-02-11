#include <iostream>
#include <cxxopts.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xrandom.hpp>

using namespace std;
using namespace xt;

int main(int argc, char* argv[]) {
	// Example of init
	xarray<int> arr {1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << arr.shape()[0] << endl;
	arr.reshape({3, 3});
	cout << arr.shape().size() << endl;
	cout << arr << endl;
	// Example of operations
	cout << arr + arr << endl;
	cout << arr * arr << endl;
	cout << arr / arr << endl;
	// Example for using randome engine
	auto rnd1 = random::get_default_random_engine();
	auto rnd2 = random::get_default_random_engine();
	rnd1.seed(123);
	rnd2.seed(123);
	cout << random::rand<double>({3, 3}, -10, 10, rnd1) << endl;
	cout << random::rand<double>({3, 3}, -10, 10, rnd2) << endl;
	cout << random::rand<double>({4, 4, 4, 4}) << endl;
	return 0;
}
