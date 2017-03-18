/*
My realization of the optimization of the Brockett function over a Stiefel manifold.
*/


// Header file containing my declaration of the 'MyStiefelBrockett' class
#include "experiments_km/myStiefelBrockett.h"


// Use the ROPTLIB namespace
namespace ROPTLIB{

	// Constructor. Takes in the PSD (Positive Semi-Definite) matrix B and 
	// the symmetric matrix D, as well as integers p, n specifying the Stiefel 
	// manifold St(p, n) as input.
	MyStiefelBrockett::MyStiefelBrockett(double *B, double *D, integer n, integer p) {

	}

	// Destructor
	MyStiefelBrockett::~MyStiefelBrockett() {}

	// Function to evaluate the cost function at iterate X
	double MyStiefelBrockett::f(Variable *X) const {
		return 0.0;
	}

	// Function to compute the Euclidean gradient of f
	void MyStiefelBrockett::EucGrad(Variable *x, Vector *egf) const {

	}

	// Function to compute the action of the Euclidean Hessian
	void MyStiefelBrockett::EucHessianEta(Variable *X, Vector *eta, Vector *actHessian) const {

	}

};
