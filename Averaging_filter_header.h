#include "mex.h"
#include <stdio.h>
#include <complex.h>
#include <tgmath.h>
#include <omp.h>


void MATLAB_main(mxComplexDouble*, double*, double*, size_t, double, double);

#include "mex.h"

void mexFunction(int nlhs, mxArray* plhs[], int nrhs, const mxArray* prhs[]) {
	
	double multiplier[2];	//multiplier is the array of scalar inputs
	mxDouble* y, * z;	//y is the input and z is the output
	mxComplexDouble* w;	//w is the complex vector output 
	size_t mrows, ncols, numb_elements;

	//Verifying that we have three inputs and two outputs
	if (nrhs != 3) {
		mexErrMsgIdAndTxt("MATLAB:xtimesy:invalidNumInputs", "Invalid number of inputs.");
	}
	if (nlhs != 2) {
		mexErrMsgIdAndTxt("MATLAB:xtimesy:invalidNumOutputs", "Invalid number of outputs. Two are required.");
	}

	//Getting the value from sizeBuffer
	//and number of points for the frequency
	//response
	multiplier[0] = mxGetScalar(prhs[1]);
	multiplier[1] = mxGetScalar(prhs[2]);

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

	//Setting the pointer to the complex output array
	plhs[1] = mxCreateDoubleMatrix(1, multiplier[1] + 1, mxCOMPLEX);
	//Getting the pointer to the complex output array
	w = mxGetComplexDoubles(plhs[1]);

	MATLAB_main(w, z, y, numb_elements, multiplier[0], multiplier[1]);
}