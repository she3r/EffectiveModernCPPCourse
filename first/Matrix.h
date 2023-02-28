//
// Created by User on 28.02.2023.
//
#include<initializer_list>
#include<algorithm>
#ifndef EFFECTIVEMODERNCPPCOURSE_MATRIX_H
#define EFFECTIVEMODERNCPPCOURSE_MATRIX_H

class Matrix{
private:
    double* nd_array;
    size_t num_rows;
    size_t num_cols;
public:
    Matrix(size_t num_rows, size_t num_cols);
    Matrix(std::initializer_list<double> d);
    Matrix(std::initializer_list<std::initializer_list<double>> d);
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);
    Matrix();
    ~Matrix();
    double operator()(size_t row, size_t col) const;
    double& operator()(size_t row, size_t col);
    Matrix operator-() const;
    friend std::ostream& operator<< (std::ostream& stream, const Matrix& matrix);
};
#endif //EFFECTIVEMODERNCPPCOURSE_MATRIX_H
