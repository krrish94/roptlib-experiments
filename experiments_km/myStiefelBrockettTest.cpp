/*
Test file for my version of optimizing the Brockett cost function over the Stiefel manifold.
*/

// Problem related classes
#include "Problems/Problem.h"
#include "experiments_km/myStiefelBrockett.h"

// Manifold related classes
#include "Manifolds/Manifold.h"
#include "Manifolds/Stiefel/StieVector.h"
#include "Manifolds/Stiefel/StieVariable.h"
#include "Manifolds/Stiefel/Stiefel.h"

// Solver we intend to use (RTRNewton)
#include "Solvers/RTRNewton.h"

// File containing global definitions
#include "Others/def.h"

// Random number generator
#include "Others/randgen.h"

// Standard C++ headers
#include <iostream>
#include <ctime>

// Using the Eigen library to represent matrices


using namespace ROPTLIB;


// Main function
int main() {

	// Seed the random number generator, for repeatability
	genrandseed(0);

	// Size of the Stiefel manifold
	int n = 12, p = 8;

	// Generate matrices for the problem
	double *B = new double[n*n + p];
	double *D = B + n * n;

	// Initial guess
	StieVariable X(n, p);
	X.RandInManifold();

	// Define the Stiefel Manifold
	Stiefel Domain(n, p);

	// Define the problem (optimizing the Brockett cost function)
	MyStiefelBrockett Problem(B, D, n, p);

	// Set the domain of the problem to the Stiefel manifold
	Problem.SetDomain(&Domain);

	// Output the parameters of the manifold of the domain
	Domain.CheckParams();


	return 0;

}
