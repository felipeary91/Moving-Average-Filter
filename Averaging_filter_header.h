#include "mex.h"
#include <stdio.h>
#include <complex.h>
#include <tgmath.h>
#include <omp.h>


void MATLAB_main(double*, double*, size_t, double);


void mexFunction(int nlhs, mxArray* plhs[], int nrhs, const mxArray* prhs[]) {
	double multiplier[1];
	mxDouble* y, * z;	//y is the input and z is the output
	size_t mrows, ncols, numb_elements;

	//Verifying that we have two inputs and one output
	if (nrhs != 2) {
		mexErrMsgIdAndTxt("MATLAB:xtimesy:invalidNumInputs", "Invalid number of inputs.");
	}
	if (nlhs != 1) {
		mexErrMsgIdAndTxt("MATLAB:xtimesy:invalidNumOutputs", "Invalid number of outputs. One is required.");
	}

	//Getting the value from sizeBuffer
	multiplier[0] = mxGetScalar(prhs[1]);

	//Getting the pointer to the input array
	y = mxGetDoubles(prhs[0]);
	//Getting the dimension of the input array
	mrows = mxGetM(prhs[0]);
	ncols = mxGetN(prhs[0]);

	if (mrows == 1) {
		numb_elements = ncols;
	}
	else {
		numb_elements = mrows;
	}

	//Setting the pointer to the output array
	plhs[0] = mxCreateDoubleMatrix(mrows, ncols, mxREAL);
	//Getting the pointer to a copy of the output array
	z = mxGetDoubles(plhs[0]);

	MATLAB_main(z, y, numb_elements, multiplier[0]);
}