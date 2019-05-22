#pragma once

#include "Vector.h"
#include <iostream>
#include <vector>

template <class T>
class Matrix
{
    using vector_t = std::vector<T>;

private:
    int rows;                        // num of rows
    int cols;                        // num of columns
    std::vector<vector_t> major_row; // the matrix's entries, stored as a vector of rows of the matrix, in row major fashion.

public:
    // default constructor. Constructs a 1X1 with 0
    explicit Matrix() : rows(1), cols(1), major_row(std::vector<vector_t>(1, vector_t(1, 0)))
    {
    }

    // constructs an rXc matrix, filled with 0's
    explicit Matrix(int r, int c) : rows(r), cols(c), major_row(std::vector<vector_t>(rows, vector_t(cols, 0)))
    {
        }

    // constructor by const reference to std::vector of vector_t (the entries)
    explicit Matrix(const std::vector<vector_t>& entries) : rows(entries.size()), cols(entries[0].size()), major_row(entries)
    {
    }

    // constructor by rvalue reference to std::vector of vector_t (the entries)
    explicit Matrix(std::vector<vector_t>&& entries) : rows(entries.size()), cols(entries[0].size()), major_row(std::move(entries))
    {
    }

    // copy constructor. Constructs a copy of a given matrix
    Matrix(const Matrix& m) : rows(m.rows), cols(m.cols), major_row(m.major_row)
    {
        }

    // move constructor by rvalue reference of a different matrix
    Matrix(Matrix&& m) noexcept : rows(m.rows), cols(m.cols), major_row(std::move(m.major_row))
    {
    }

    // copy assignment by const reference
    Matrix& operator=(const Matrix& m)
    {
        rows = m.rows;
        cols = m.cols;
        major_row = m.major_row;
    }

    // move assignment by rvalue reference
    Matrix& operator=(Matrix&& m) noexcept
    {
        major_row = std::move(m.major_row);
    }

    // returns the number of rows
    int get_rows() const
        {
            return rows;
        }

        // returns the number of columns
        int get_cols() const
		{
			return cols;
		}

        // matrix(i, j) is the matrix's entry at the i'th row and j'th column, zero based (for get and set)
        T operator()(int i, int j) const
        {
            return major_row[i][j];
        }

        T& operator()(int i, int j)
        {
			return major_row[i][j];
		}

        // matrix at(i,j) returns the matrix's entry at the i'th row and j'th column, if there is such entry, zero based, or NULL if it does not exist.
        T at(int i, int j) const
		{
			if (i < rows && j < cols && i >= 0 && j >= 0)
			{
				return major_row[i][j];
			}
			else
			{
				return NULL;
			}
		}

        // changes the matrix to its transpoesd form
        void transpose_in_place(Matrix m)
        {
            T temp;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < i; j++) {
                    temp = major_row[i][j];
                    major_row[i][j] = major_row[j][i];
                    major_row[j][i] = temp;
                }
            }
        }

        // returns the transposed matrix.
        Matrix transpose() const
        {
            Matrix transed(cols, rows);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    transed(j, i) = major_row[i][j];
                }
            }
            return transed;
        }

        // in-place matrices addition
        void operator+=(const Matrix& m)
        {
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    major_row[i][j] += m(i, j);
                }
            }
        }

        // matrices addition
        Matrix operator+(const Matrix& m) const
        {
            Matrix sum(rows, cols);
            for (int i = 0; i < rows; ++i) {
				for(int j = 0; j < cols; ++j)
				{
					sum(i, j) = major_row[i][j] + m(i, j);
				}
			}
			return sum;	
		}

        // in-place matrices multiplication
        void operator*=(const Matrix& m)
        {
            T tmp_val;
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < m.get_cols(); ++j) {
                    tmp_val = 0;
                    for (int k = 0; k < cols; ++k) {
                        tmp_val += major_row[i][k] * m(k, j);
                    }
                    major_row[i][j] = tmp_val;
                }
            }
        }

        // matrices multiplication
        Matrix operator*(const Matrix& m) const
        {
            Matrix prod(rows, cols);
            T tmp_val;
			for (int i = 0; i < rows; ++i)
			{
				for(int j = 0; j < m.get_cols(); ++j)
				{
					tmp_val = 0;
					for (int k = 0; k < cols; ++k)
					{
						tmp_val += major_row[i][k] * m(k, j);
					}
					prod(i, j)=tmp_val;
				}
			}
			return prod;		
		}

        // in-place matrices difference
        void operator-=(const Matrix& m)
        {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; ++j) {
                    major_row[i][j] -= m(i, j);
                }
            }
        }

        // matrices difference
        Matrix operator-(const Matrix& m) const
        {
            Matrix diff(rows, cols);
            for (int i=0; i<rows; i++)
			{
				for(int j = 0; j < cols; ++j)
				{
                    diff(i, j) -= m(i, j);
                }
			}
			return diff;
		}

        // matrix negation
        Matrix operator-() const
        {
            Matrix neg(rows, cols);
            for (int i = 0; i < rows; ++i)
			{
				for(int j = 0; j < cols; ++j)
				{
					neg(i, j) = -major_row[i][j];
				}
			}
			return neg;
		}

        // matrix by vector multiplication
        friend Vector<T> operator*(const Matrix& m, const Vector<T>& v)
        {
			Vector<T> res(m.get_rows());
			T tmp_val;
			for (int i = 0; i < m.get_rows(); ++i)
			{
				tmp_val = 0;
				for(int j = 0; j < m.get_cols(); ++j)
				{
					tmp_val += m(i, j) * v(j);
				}
				res(i) = tmp_val;
			}
			return res;	
		}

        // in-place matrix by scalar multiplication
        void operator*=(const T& s)
        {
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    major_row[i][j] *= s;
                }
            }
        }

        // matrix by scalar multiplication (both directions)
        friend Matrix operator*(const Matrix& m, const T& s)
        {
            Matrix prod(m.get_rows(), m.get_cols());
            for (int i = 0; i < m.get_rows(); ++i)
			{
				for(int j = 0; j < m.get_cols(); ++j)
				{
					prod(i, j) = m(i, j) * s;
				}
			}
			return prod;
		}

        friend Matrix operator*(const T& s, const Matrix& m)
        {
			return m * s;
		}

};

// sending to output stream using <<
template <class T>
std::ostream& operator<<(std::ostream& strm, const Matrix<T>& m)
{
	strm << "[";
	for (int i = 0; i < m.get_rows(); ++i)
	{
		strm << "(";
		for (int j = 0; j < m.get_cols() - 1; ++j)
		{
			strm << m(i,j) << ", ";
		}
		strm << m(i, m.get_cols() - 1) << ")\n";
	}
	strm << "]" << std::endl;
	return strm;
}