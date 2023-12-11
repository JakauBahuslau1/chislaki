#include "funcs.h"

double f(const double& x) {
    return (1+x*x)/(1+x*x*x);
}

double trapezoidal(const double& a, const double& b, const int& n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += f(x);
    }
    return h * sum;
}

double simpson(const double& a, const double& b, const int& n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i += 2) {
        double x = a + i * h;
        sum += 4 * f(x);
    }
    for (int i = 2; i < n; i += 2) {
        double x = a + i * h;
        sum += 2 * f(x);
    }
    return h * sum / 3;
}

double double_simpson_method(const double& a, const double& b, const double& c, const double& d, const int& n) {
	double hx = (b - a) / (2 * n);
	double hy = (d - c) / (2 * n);

	double result = 0.0;

	for (int i = 0; i <= n - 1; ++i) {
		for (int j = 0; j <= n - 1; ++j) {
			result += f(a + (double(i) * 2) * hx, c + (double(j) * 2) * hy);
			result += 4 * f(a + (double(i) * 2 + 1) * hx, c + (double(j) * 2) * hy);
			result += f(a + (double(i) * 2 + 2) * hx, c + (double(j) * 2) * hy);
			result += 4 * f(a + (double(i) * 2) * hx, c + (double(j) * 2 + 1) * hy);
			result += 16 * f(a + (double(i) * 2 + 1) * hx, c + (double(j) * 2 + 1) * hy);
			result += 4 * f(a + (double(i) * 2 + 2) * hx, c + (double(j) * 2 + 1) * hy);
			result += f(a + (double(i) * 2) * hx, c + (double(j) * 2 + 2) * hy);
			result += 4 * f(a + (double(i) * 2 + 1) * hx, c + (double(j) * 2 + 2) * hy);
			result += f(a + (double(i) * 2 + 2) * hx, c + (double(j) * 2 + 2) * hy);
		}
	}
	return hx * hy * result / 9;
}

double calculate_double_simpson(const double& a, const double& b, const double& c, const double& d, const double& epsilon) {
	long n = 10;
	double inter1 = 0;
	double inter2 = double_simpson_method(a, b, c, d, n);

	while (abs(inter1 - inter2) > 15 * epsilon) {
		n *= 2;
		inter1 = inter2;
		inter2 = double_simpson_method(a, b, c, d, n);
	}

	return inter2;
}

