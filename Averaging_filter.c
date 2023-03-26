#include "Averaging_filter_header.h"
#include <stdio.h>
#include <string.h>


void MATLAB_main(double *y, double *x, size_t sizeSignal, double sizeBuffer) {
	
	for (int i = 0; i < sizeSignal; i++) {
		//Initializing the buffer with the values from
		//input signal
		double sum = 0.;
		for (int k = 0; k < sizeBuffer; k++) {
			if ((i + k) < sizeSignal) {
				sum += x[i + k];
			}
			else {
				sum += x[(i+k) - sizeSignal];
			}
		}
		y[i] = sum / sizeBuffer;
	}
}