# Moving-Averaging-Filter
The moving-averaging-filter is easy-to-understand, and implement. While effective
on Time Domain, it is the worst filter in Frequency Domain. The basic equation of
the moving-average-filter is:

```math
y(n) = \frac{1}{M} \sum_{j=0}^{M-1} x[n+j]
```

On the other hand, the Frequency Response is given by:

```math
H(w) = \frac{1}{M} \sum_{k=0}^{M-1} e^{-jwk} = \frac{1 - e^{-jwM}}{1 - e^{-jw}}
```
where M is the window size of the filter. <br /> 

<br />
<br />

This implementation allows to explore how Time and Frequency Responses of the moving-
averaging-filter vary according to its window size. Code is implemented with integration
of C and MATLAB in mind, thus a MEX function can be created in MATLAB as follows:

- Using the command `mex -R2018a Averaging_filter.c`.

Then, an input signal can be simulated and the passed to the MEX function created.

- Use the .mex function with the command: 
  `[filtered_data, frequency_response] = Average_filter(input signal, 15, 500)`
  , where 15 is the window size of the averaging-filter and 500 is the size of the
  Frequency Response.

- When plotting, remember to use the absolute value (command abs() in MATLAB) when
  passing the frequency_response to plot().

**Note:** In order to successfully run this program it is necessary to have MATLAB Coder
installed, as well as the MinGW-w64 C/C++ compiler.
