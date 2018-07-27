#include "Matrix.h"
#include <iostream>
#include <math.h>
#include <stdexcept>

Matrix Matrix::operator+(const Matrix& m) const {
	if(rows != m.rows || cols != m.cols) {
		std::cout << "Can't add matrices of size " << rows << " x " << cols << " and " << m.rows << " x " << m.cols << std::endl;
		return Matrix(rows, cols, values);
	}
	double* temp = new double[rows*cols];
	int n = 0;
	for(int x = 0; x < rows; x++) {
		for(int y = 0; y < cols; y++) {
			temp[n] = values[x][y] + m.values[x][y];
			n++;
		}
	}
	return Matrix(rows, cols, temp);
}

Matrix Matrix::operator-(const Matrix& m) const {
	if(rows != m.rows || cols != m.cols) {
		std::cout << "Can't add matrices of size " << rows << " x " << cols << " and " << m.rows << " x " << m.cols << std::endl;
		return Matrix(rows, cols, values);
	}
	double* temp = new double[rows*cols];
	int n = 0;
	for(int x = 0; x < rows; x++) {
		for(int y = 0; y < cols; y++) {
			temp[n] = values[x][y] - m.values[x][y];
			n++;
		}
	}
	return Matrix(rows, cols, temp);	
}

Matrix Matrix::operator*(const Matrix& m) const {
	if(cols != m.rows) {
		std::cout << "Can't multiply matrices of size " << rows << " x " << cols << " and " << m.rows << " x " << m.cols << std::endl;
		return Matrix(rows, cols, values);
	}
	double** temp = new double*[rows];
	for(int x = 0; x < rows; x++) {
		temp[x] = new double[m.cols];
		for(int y = 0; y < m.cols; y++) {
			temp[x][y] = 0;
			for(int z = 0; z < cols; z++) {
				temp[x][y] += values[x][z]*m.values[z][y];
			}
		}
	}	
	return Matrix(rows, m.cols, temp);
}

Matrix Matrix::operator=(const Matrix& m) const {
	return Matrix(m.rows, m.cols, m.values);
}

Matrix Matrix::operator+(const int& m) const {
	double* temp = new double[rows*cols];
	int n = 0;
	for(int x = 0; x < rows; x++) {
		for(int y = 0; y < cols; y++) {
			temp[n] = values[x][y] + m;
			n++;
		}
	}
	return Matrix(rows, cols, temp);
}

Matrix Matrix::operator-(const int& m) const {
	double* temp = new double[rows*cols];
	int n = 0;
	for(int x = 0; x < rows; x++) {
		for(int y = 0; y < cols; y++) {
			temp[n] = values[x][y] - m;
			n++;
		}
	}
	return Matrix(rows, cols, temp);
}

Matrix Matrix::operator*(const int& m) const {
	double* temp = new double[rows*cols];
	int n = 0;
	for(int x = 0; x < rows; x++) {
		for(int y = 0; y < cols; y++) {
			temp[n] = values[x][y] * m;
			n++;
		}
	}
	return Matrix(rows, cols, temp);
}

Matrix Matrix::operator/(const int& m) const {
	double* temp = new double[rows*cols];
	int n = 0;
	for(int x = 0; x < rows; x++) {
		for(int y = 0; y < cols; y++) {
			temp[n] = values[x][y] / m;
			n++;
		}
	}
	return Matrix(rows, cols, temp);
}

Matrix Matrix::operator^(const int& m) const {
	//implement later
	return Matrix(rows, cols, values);
}

Matrix Matrix::operator+(const double& m) const {
	double* temp = new double[rows*cols];
	int n = 0;
	for(int x = 0; x < rows; x++) {
		for(int y = 0; y < cols; y++) {
			temp[n] = values[x][y] + m;
			n++;
		}
	}
	return Matrix(rows, cols, temp);
}

Matrix Matrix::operator-(const double& m) const {
	double* temp = new double[rows*cols];
	int n = 0;
	for(int x = 0; x < rows; x++) {
		for(int y = 0; y < cols; y++) {
			temp[n] = values[x][y] - m;
			n++;
		}
	}
	return Matrix(rows, cols, temp);
}

Matrix Matrix::operator*(const double& m) const {
	double* temp = new double[rows*cols];
	int n = 0;
	for(int x = 0; x < rows; x++) {
		for(int y = 0; y < cols; y++) {
			temp[n] = values[x][y] * m;
			n++;
		}
	}
	return Matrix(rows, cols, temp);
}

Matrix Matrix::operator/(const double& m) const {
	double* temp = new double[rows*cols];
	int n = 0;
	for(int x = 0; x < rows; x++) {
		for(int y = 0; y < cols; y++) {
			temp[n] = values[x][y] / m;
			n++;
		}
	}
	return Matrix(rows, cols, temp);
}

Matrix Matrix::operator+(const float& m) const {
	double* temp = new double[rows*cols];
	int n = 0;
	for(int x = 0; x < rows; x++) {
		for(int y = 0; y < cols; y++) {
			temp[n] = values[x][y] + m;
			n++;
		}
	}
	return Matrix(rows, cols, temp);
}

Matrix Matrix::operator-(const float& m) const {
	double* temp = new double[rows*cols];
	int n = 0;
	for(int x = 0; x < rows; x++) {
		for(int y = 0; y < cols; y++) {
			temp[n] = values[x][y] - m;
			n++;
		}
	}
	return Matrix(rows, cols, temp);
}

Matrix Matrix::operator*(const float& m) const {
	double* temp = new double[rows*cols];
	int n = 0;
	for(int x = 0; x < rows; x++) {
		for(int y = 0; y < cols; y++) {
			temp[n] = values[x][y] * m;
			n++;
		}
	}
	return Matrix(rows, cols, temp);
}

Matrix Matrix::operator/(const float& m) const {
	double* temp = new double[rows*cols];
	int n = 0;
	for(int x = 0; x < rows; x++) {
		for(int y = 0; y < cols; y++) {
			temp[n] = values[x][y] / m;
			n++;
		}
	}
	return Matrix(rows, cols, temp);
}

Matrix Matrix::operator~() const {
	return Matrix(rows, cols, values).transpose();
}

Matrix Matrix::operator-() const {
	return Matrix(rows, cols, values) * -1;
}