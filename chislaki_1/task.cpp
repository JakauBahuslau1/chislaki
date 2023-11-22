#include "task.h"
#include "funcs.h"

int main() {
    int rows, columns;
    std::cout << "Enter rows: ";
    std::cin >> rows;
    std::cout << "Enter columns: ";
    std::cin >> columns;

    std::vector<std::vector<double>> matrix(rows, std::vector<double>(columns));
    std::vector<double> vector(rows);
    std::vector<double> residual_vector(rows);
    std::vector<double> result_vector(rows);

    input_matrix_and_vector(matrix, vector, rows, columns);
    std::vector<std::vector<double>> matrix_clone(matrix);

    output_matrix(matrix, vector);
    result_vector = solve(matrix, vector);
    output_result(result_vector);

    residual_vector = calculate_residual_vector(matrix, vector, result_vector);
    std::cout << "\nResidual vector:\n";
    output_result(residual_vector);

    double norm = find_norm(residual_vector);
    std::cout << "\nNorm = " << norm << std::endl;
    
    double delta = find_error(matrix_clone, result_vector);
    std::cout << std::setprecision(15);
    std::cout << "Error = " << delta << std::endl;

    return 0;
}
