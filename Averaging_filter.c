#include "Averaging_filter_header.h"
#include <stdio.h>
#include <string.h>


void MATLAB_main(mxComplexDouble* w, double* y, double* x, size_t sizeSignal, double sizeWindow, double sizeFreqResp) {

	for (int i = 0; i < sizeSignal; i++) {
		//No buffer is being used. The values for
		//averaging are taken from the future input
		//values
		double sum = 0.;
		for (int k = 0; k < sizeWindow; k++) {
			if ((i + k) < sizeSignal) {
				sum += x[i + k];
			}
			else {
				sum += x[(i + k) - sizeSignal];
			}
		}
		y[i] = sum / sizeWindow;
	}

	//Calculating the frequency response
	double omega = 0;
	complex double num, dem, division_mag, division_angle, result;

	for (int i = 0; i <= sizeFreqResp; i++) {

		//Frequency response equation implementation
		num = (1 - cexp(-I * omega * sizeWindow));
		dem = (1 - cexp(-I * omega));
		
		//Dividing the magnitude of both num
		//and dem
		division_mag = (cabs(num) / cabs(dem)) / sizeWindow;

		//Checking if division_mag is a NaN in
		//which case we replace it by 0.
		if (division_mag != division_mag) {
			division_mag = 0;
		}

		division_angle = carg(num) - carg(dem);

		//Calculating the real and imaginary parts
		//of the frequency response, and saving them
		//in w
		w[i].real = division_mag * cos(division_angle);
		w[i].imag = (division_mag * sin(division_angle));

		//Increasing w by the step size
		omega += acos(-1) / sizeFreqResp;

	}
}