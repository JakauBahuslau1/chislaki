#include "task.h"

int main()
{
    double a = 3.000, b = 4.254; 
    double a_kub = 0.0, b_kub = 4.0, c = 1.0, d = 2.0;
    int n = 10; 
    double trapezoidal_result = trapezoidal(a, b, n);
    double simpson_result = simpson(a, b, n);
    double double_simpson_method_result = calculate_double_simpson(a_kub, b_kub, c, d, n);
    cout << "Результат по формуле трапеций: " << trapezoidal_result << endl;
    cout << "Результат по формуле Симпсона: " << simpson_result << endl;
    cout << "Результат по кубатурной формуле формуле Симпсона: " << double_simpson_method_result << endl;
    return 0;
}

