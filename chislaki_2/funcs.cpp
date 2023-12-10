#include "funcs.h"

double** Create(const int& n, const int& m) {
	double** arr = new double* [n];

	for (int i = 0; i < n; i++) {
		arr[i] = new double[m];
	}
	return arr;
}

double Func1(const double& x1, const double& x2) {
	return sin(x1) - x2 - 1.32;
}

double Func2(const double& x1, const double& x2) {
	return cos(x2) - x1 + 0.85;
}


void Jacob(double** J, const double& x1, const double& x2) {
	J[0][0] = cos(x1);			J[0][1] = -1;
	J[1][0] = -sin(x2) - 1;		J[1][1] = -sin(x2);
}

void Nevyaz(double* arr, const double& x1, const double& x2) {
	arr[0] = -Func1(x1, x2);
	arr[1] = -Func2(x1, x2);
}

void SwapLines(const int& line1, const int& line2, double** arr) {
	for (int j = 0; j < 4; j++) {
		swap(arr[line1][j], arr[line2][j]);
	}
}

void NevPlJ(double** a, double** J, const double* Nev,const  int& n) {
	for (int i = 0; i < n; i++) {
		a[i][n] = Nev[i];
		for (int j = 0; j < n; j++) {
			a[i][j] = J[i][j];
		}
	}
}

double* Gauss(double** arr, const int& n, const int& m) {
	double maxi = arr[n - 1][m - 1];

	for (int i = 0; i < n; i++){
		for (int l = i; l < n; l++) {
			if (arr[i][i] < arr[l][i]) {
				SwapLines(i, l, arr);
			}
		}
		if (arr[i][i] == 0) {
			throw "DivByZero";
			exit(0);
		}

		maxi = arr[i][i];

		for (int j = i; j < m; j++) {
			arr[i][j] /= maxi;
		}

		for (int k = i + 1; k < n; k++) {
			double dp = arr[k][i];
			for (int j = i; j < m; j++) {
				arr[k][j] -= arr[i][j] * dp;
			}
		}
	}

	double* ans = new double[n];
	ans[n - 1] = arr[n - 1][m - 1];

	for (int i = n - 2; i >= 0; i--) {
		double sum = 0;
		for (int k = i + 1; k < n; k++) {
			sum += arr[i][k] * ans[k];
		}
		ans[i] = arr[i][n] - sum;
	}

	return ans;
}

double* Newton(const int& n, double& x1, double& x2) {
	int NIT = 100;
	double e = 1e-10;
	double** J;
	double** matrix;
	double* nevyaz = new double[n];
	double* del = new double[n];
	double* ans = new double[n + 1];
	ans[0] = x1;
	ans[1] = x2;

	double* ansG = new double[n];

	double del1 = x1, del2 = x2;
	int k = 0;
	J = Create(n, n);
	matrix = Create(n, n + 1);

	cout << "x1" << setw(10) << "x2" << setw(20) << "delta1" << setw(20) << "delta2" << setw(20) << "k" << endl;

	while (del1 > e || del2 > e) {
		if (k > NIT) {
			cout << "IER = 2";
			return nullptr;
		}

		Nevyaz(nevyaz, x1, x2);
		Jacob(J, x1, x2);

		NevPlJ(matrix, J, nevyaz, n);

		try {
			ansG = Gauss(matrix, n, n + 1);
		}
		catch (const char* mess) {
			cout << mess << " ";
			exit(0);
		}

		double maxdel1 = 0.0;
		double maxdel2 = 0.0;

		for (int i = 0; i < n; i++) {
			ans[i] += ansG[i];
		}

		maxdel1 = max(maxdel1, fabs(Func1(ans[0], ans[1])));
		maxdel1 = max(maxdel1, fabs(Func1(ans[0], ans[1])));

		for (int i = 0; i < n; i++) {
			if (fabs(ansG[i]) < 1) {
				maxdel2 = max(maxdel2, fabs(ans[i] - (ans[i] - ansG[i])));
			}
			if (fabs(ansG[i]) >= 1) {
				maxdel2 = max(maxdel2, fabs((ans[i] - (ans[i] - ansG[i])) / ans[i]));
			}
		}

		del1 = maxdel1;
		del2 = maxdel2;

		x1 = ans[0];
		x2 = ans[1];
		cout << setprecision(3) << x1 << setw(10) << x2 << setw(20) << del1 << setw(20) << del2 << setw(20) << k << endl << endl;
		k++;
	}
	return ans;
}
