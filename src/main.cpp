#include <iostream>
#include <random>
#include <limits>

#include <Eigen/Dense>

#include <cxxopts.hpp>

using namespace std;
using namespace Eigen;

enum Test {
	ONE = 1,
	NONE = -1
};

int main(int argc, char* argv[]) {
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

	// Eigen test
	cout << endl << endl;
	MatrixXd m = MatrixXd::Random(3,3);
	m = (m + MatrixXd::Constant(3,3,1.2)) * 50;
	cout << "m =" << endl << m << endl;
	VectorXd v(3);
	v << 1, 2, 3;
	cout << "m * v =" << endl << m * v << endl;
	cout << "m .* v =" << endl << m.array().colwise() * v.array() << endl;

	return 0;
}
