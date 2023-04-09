# Moving-Averaging-Filter
The moving-averaging-filter is easy-to-understand, and implement. While effective
on time domain, it is the worst filter in frequency domain. This averaging filter is
done with the integration of C and MATLAB in mind. The basic equation of the filter
is:

```math
\frac{1}{M} \sum_{k=1}^{M-1} x[i+j]
```


This function can be used in MATLAB in the following way:
- First create the .mex function with the command "mex -R2018a Averaging_filter.c"
- Simulate an input signal
- Use the .mex function with the command: Average_filter(input signal, 15). Where
  15 is the window size of the averaging filter.

**Note:** In order to successfully run this program it is necessary to have MATLAB Coder
installed, as well as the MinGW-w64 C/C++ compiler.
