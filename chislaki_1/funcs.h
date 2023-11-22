#include <iostream>
#include <cmath>
#include <vector>

std::vector<double> solve(std::vector<std::vector<double>> matrix, std::vector<double> &vector);
void output_result(const std::vector<double> &result);
void input_matrix_and_vector(std::vector<std::vector<double>> &matrix, std::vector<double> &vector, const int &rows, const int &columns);
void output_matrix(const std::vector<std::vector<double>> &matrix, const std::vector<double> &vector);
std::vector<double> calculate_residual_vector(const std::vector<std::vector<double>> &matrix, const std::vector<double> &vector, const std::vector<double> &result);
double find_norm(const std::vector<double> &resudial_vector);
double find_error(const std::vector<std::vector<double>> &matrix_clone, const std::vector<double>& result);
