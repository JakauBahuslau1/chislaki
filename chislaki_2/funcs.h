#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double** Create(const int& n, const int& m);
double Func1(const double& x1, const double& x2);
double Func2(const double& x1, const double& x2);
double df1dx1(const double& x1, const double& x2);
double df1dx2(const double& x1, const double& x2);
double df2dx1(const double& x1, const double& x2);
double df2dx2(const double& x1, const double& x2);
void Jacob(double** J, const double& x1, const double& x2);
void JacobM(double x1, double x2, double **J, double M);
void Nevyaz(double* arr, const double& x1, const double& x2);
void SwapLines(const int& line1, const int& line2, double** arr);
void NevPlJ(double** a, double** J, const double* Nev,const  int& n);
double* Gauss(double** arr, const int& n, const int& m);
double* Newton(const int& n, double& x1, double& x2);
