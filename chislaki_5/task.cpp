#include "task.h"

int main()
{
    double a = 3.000, b = 4.254; 
    int n = 10; 
    double trapezoidal_result = trapezoidal(a, b, n);
    double simpson_result = simpson(a, b, n);
    cout << "Результат по формуле трапеций: " << trapezoidal_result << endl;
    cout << "Результат по формуле Симпсона: " << simpson_result << endl;
    return 0;
}

