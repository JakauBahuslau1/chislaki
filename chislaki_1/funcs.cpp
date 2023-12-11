#include "funcs.h"

std::vector<double> solve(std::vector<std::vector<double>> matrix, std::vector<double> &vector) { /* Здесь переменная matrix
                                                                                                   * передаётся не поссылке, так
                                                                                                   * как необходима именно
                                                                                                   * её копия */
    int rows = matrix.size();
    int columns = matrix[0].size();
    for (int i = 0; i < rows - 1; i++) {
        int maxRow = i;
        double maxElement = matrix[i][i];
        for (int k = i + 1; k < rows; k++) {
            if (std::abs(matrix[k][i]) > std::abs(maxElement)) {
                maxElement = matrix[k][i];
                maxRow = k;
            }
        }
        if (maxRow != i) {
            std::swap(matrix[i], matrix[maxRow]);
            std::swap(vector[i], vector[maxRow]);
        }
        for (int j = i + 1; j < rows; j++) {
            double quotient = matrix[j][i] / matrix[i][i];
            for (int k = i; k < columns; k++) {
                matrix[j][k] -= quotient * matrix[i][k];
            }
            vector[j] -= quotient * vector[i];
        }
    }

    std::vector<double> result(rows);
    for (int i = rows - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < rows; j++) {
            sum += matrix[i][j] * result[j];
        }
        result[i] = (vector[i] - sum) / matrix[i][i];
    }
    return result;
}

void output_result(const std::vector<double> &result) {
    for (int i = 0; i < result.size(); ++i) {
        std::cout << "\nx" << i << "=" << result[i];
    }
    std::cout << std::endl;
}

void input_matrix_and_vector(std::vector<std::vector<double>> &matrix, std::vector<double> &vector, const int &rows, const int &columns) {
    std::cout << "Enter matrix" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cin >> matrix[i][j];
        }
    }
    std::cout << "Enter vector" << std::endl;
    for (int i = 0; i < rows; i++) {
        std::cin >> vector[i];
    }
}

void output_matrix(const std::vector<std::vector<double>> &matrix, const std::vector<double> &vector) {
    int matrix_size = matrix[0].size() - 1;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (j < matrix_size) {
                std::cout << matrix[i][j] << "*x" << j << " + ";
            }
            else {
                std::cout << matrix[i][j] << "*x" << j << " = " << vector[i] << std::endl;
            }
        }
        std::cout << std::endl;
    }
}

std::vector<double> calculate_residual_vector(const std::vector<std::vector<double>> &matrix, const std::vector<double> &vector, const std::vector<double> &result) {
    int rows = matrix.size();
    int columns = matrix[0].size();
    std::vector<double> residualVector(rows);
    for (int i = 0; i < rows; i++) {
        double sum = 0;
        for (int j = 0; j < columns; j++) {
            sum += matrix[i][j] * result[j];
        }
        residualVector[i] = vector[i] - sum;
    }

    return residualVector;
}
double find_norm(const std::vector<double> &resudial_vector) {
    double max = std::abs(resudial_vector[0]);
    for (int i = 0; i < resudial_vector.size(); i++) {
        if (std::abs(resudial_vector[i]) > max)
            max = std::abs(resudial_vector[i]);
    }
    return max;
}

double find_error(const std::vector<std::vector<double>> &matrix_clone, const std::vector<double>& result) {
    std::vector<double> vectorAX(matrix_clone.size(), 0);

    for (int i = 0; i < matrix_clone.size(); i++) {
        for (int j = 0; j < matrix_clone[i].size(); j++) {
            vectorAX[i] += matrix_clone[i][j] * result[j];
        }
    }

    std::cout << "new B\n";
    for (int i = 0; i < vectorAX.size(); i++) {
        std::cout << vectorAX[i] << std::endl;
    }

    std::vector<double> second_result_vec = solve(matrix_clone, vectorAX);

    std::cout << "sec_res_vec\n";
    output_result(second_result_vec);

    double numerator = std::abs(result[0] - second_result_vec[0]);
    double denominator = std::abs(result[0]);

    for (int i = 0; i < result.size(); i++) {
        // if (numerator < std::abs(result[i] - second_result_vec[i]) && denominator < std::abs(result[i])) {
        //     numerator = std::abs(result[i] - second_result_vec[i]);
        //     denominator = std::abs(result[i]);
        // }
        if (numerator < std::abs(result[i] - second_result_vec[i])) {
            numerator = std::abs(result[i] - second_result_vec[i]);
        }
        if (denominator < std::abs(result[i])) {
            denominator = std::abs(result[i]);
        }
    }

    double delta = numerator / denominator;

    return delta;
}
