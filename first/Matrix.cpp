//
// Created by User on 28.02.2023.
//
#include <iostream>
#include "Matrix.h"


Matrix::Matrix(std::initializer_list<double>& d){
    nd_array = new double[d.size()];
    std::copy(d.begin(),d.end(),nd_array);
    num_rows = 1;
    num_cols = d.size();
    std::cout<<"constructor of "<<num_rows<<"x"<<num_cols<<" matrix from initializer_list"<<std::endl;
}

Matrix::Matrix(size_t num_rows, size_t num_cols){
    this->nd_array = new double[num_cols * num_rows]{};
    this->num_cols=num_cols;
    this->num_rows=num_rows;
    std::cout<<"constructor of "<<num_rows<<"x"<<num_cols<<" matrix"<<std::endl;
}

Matrix::Matrix(std::initializer_list<std::initializer_list<double>>& d){
    size_t n=0,k=0;
    for(auto list : d){
        n++; // num of rows
        if(list.size() > k){
            k =  list.size();   // num of columns
        }
    }
    nd_array = new double[n*k] {};
    num_rows = n; num_cols = k;
    size_t curr_row = 0;
    for(auto list : d){
        size_t i=0; // curr element in row
        for(auto el : list){
            nd_array[curr_row * k + i] = el;
            i++;
        }
        // rest filled with zeros on init
        curr_row++;
    }
    std::cout<<"constructor of "<<num_rows<<"x"<<num_cols<<" matrix from initializer_list"<<std::endl;
}

Matrix::Matrix() {
    nd_array = new double[1] {};
    num_rows = num_cols = 1;
    std::cout<<"default construction [0]"<<std::endl;
}

Matrix::~Matrix() {
    std::cout<<"verbose destruction"<<std::endl;
    delete [] nd_array;
}

double Matrix::operator()(size_t row, size_t col) const {
    if(row > num_rows or col > num_cols){
        throw std::runtime_error("invalid number of rows or columns");
    }
    return nd_array[(row-1)*num_cols + (col - 1)];
}

double &Matrix::operator()(size_t row, size_t col) {
    if(row > num_rows or col > num_cols){
        throw std::runtime_error("invalid number of rows or columns");
    }
    return nd_array[(row-1)*num_cols + (col - 1)];
}



Matrix::Matrix(const Matrix &other) {
    this->num_cols = other.num_cols;
    this->num_rows = other.num_rows;
    size_t size = other.num_rows * other.num_cols;
    this->nd_array = new double[size];
    std::copy(other.nd_array,other.nd_array + size,this->nd_array);
    std::cout<<"copy constructor"<<std::endl;
}

Matrix &Matrix::operator=(const Matrix &other) {
    if(&other != this)
    {
        delete[] this->nd_array;
        this->num_cols = other.num_cols;
        this->num_rows = other.num_rows;
        this->nd_array = new double[other.num_cols * other.num_rows];
        std::copy(other.nd_array, other.nd_array + other.num_cols * other.num_rows, this->nd_array);

    }
    std::cout<<"copy assignment operator"<<std::endl;
    return *this;
}
