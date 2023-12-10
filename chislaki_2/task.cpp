#include "task.h"

int main() {
	int n = 2;
	double* answer = new double[n];
	double x1 = 0.5, x2 = 0.2;
	answer = Newton(n, x1, x2);
	if (answer == nullptr) {
		return 0;
	}
	cout << answer[0] << " " << answer[1];
	return 0;
}
