/*
My realization of the minmization of the Brockett cost function over a Stiefel manifold
*/

#ifndef MY_STIEFEL_BROCKETT_H
#define MY_STIEFEL_BROCKETT_H

// Include headers specific to the Stiefel manifold
#include "Manifolds/Stiefel/Stiefel.h"
#include "Manifolds/Stiefel/StieVariable.h"
#include "Manifolds/Stiefel/StieVector.h"
// Header file containing the declaration of the 'Problem' class
#include "Problems/Problem.h"
// We'll be using the 'SharedSpace' class as well, to store temporary data
#include "Manifolds/SharedSpace.h"
// File containing global definitions
#include "Others/def.h"
// Header that includes wrapper functions on blas and lapack
#include "Others/MyMatrix.h"


namespace ROPTLIB{

	// Define a class that inherits the abstract class 'Problem'
	class MyStiefelBrockett : public Problem {

	public:
		// Constructor. Takes in the PSD (Positive Semi-Definite) matrix B and 
		// the symmetric matrix D, as well as integers p, n specifying the Stiefel 
		// manifold St(p, n) as input
		MyStiefelBrockett(double *B, double *D, integer n, integer p);
		// Destructor
		virtual ~MyStiefelBrockett();
		// Function to evaluate the cost function at iterate x
		virtual double f(Variable *X) const;
		// Function to compute the Euclidean gradient of f
		virtual void EucGrad(Variable *X, Vector *grad) const;
		// Function to compute the action of the Euclidean Hessian
		virtual void EucHessianEta(Variable *X, Vector *eta, Vector *actHessian) const;

		// Variables to hold problem parameters and variables

		// n-by-n PSD matrix
		double *B;
		// p-by-p diagonal matrix
		double *D;
		// Parameters n,p of the Stiefel manifold St(p,n)
		integer n;
		integer p;

	};

};

# endif
