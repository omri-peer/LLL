#include "Matrix.h"
#include <gtest/gtest.h>

TEST(matrix, equality)
{
    Matrix<double> m1(3, 3);
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(0, 2) = 3;
    m1(1, 0) = 10;
    m1(1, 1) = 0;
    m1(1, 2) = -3;
    m1(2, 0) = 27;
    m1(2, 1) = 1;
    m1(2, 2) = 0;

    Matrix<double> m2(3, 3);
    m2(0, 0) = 1;
    m2(0, 1) = 2;
    m2(0, 2) = 3;
    m2(1, 0) = 10;
    m2(1, 1) = 0;
    m2(1, 2) = -3;
    m2(2, 0) = 27;
    m2(2, 1) = 1;
    m2(2, 2) = 0;

    Matrix<double> m3(3, 3);
    m3(0, 0) = 1;
    m3(0, 1) = 2;
    m3(0, 2) = 3;
    m3(1, 0) = 10;
    m3(1, 1) = 0;
    m3(1, 2) = 3;
    m3(2, 0) = 27;
    m3(2, 1) = 1;
    m3(2, 2) = 0;

    EXPECT_EQ(m1, m2);
    EXPECT_NE(m2, m3);
}

TEST(matrix, addition)
{
    Matrix<double> m1(3, 3);
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(0, 2) = 3;
    m1(1, 0) = 10;
    m1(1, 1) = 0;
    m1(1, 2) = -3;
    m1(2, 0) = 27;
    m1(2, 1) = 1;
    m1(2, 2) = 0;

    Matrix<double> m2(3, 3);
    m2(0, 0) = 1;
    m2(0, 1) = 1;
    m2(0, 2) = 1;
    m2(1, 0) = 10;
    m2(1, 1) = 1;
    m2(1, 2) = 13;
    m2(2, 0) = 17;
    m2(2, 1) = 1;
    m2(2, 2) = 1;

    Matrix<double> m3(3, 3);
    m3(0, 0) = 2;
    m3(0, 1) = 3;
    m3(0, 2) = 4;
    m3(1, 0) = 20;
    m3(1, 1) = 1;
    m3(1, 2) = 10;
    m3(2, 0) = 44;
    m3(2, 1) = 2;
    m3(2, 2) = 1;

    Matrix<double> n1(2, 3);
    n1(0, 0) = 1;
    n1(0, 1) = 2;
    n1(0, 2) = 3;
    n1(1, 0) = 10;
    n1(1, 1) = 0;
    n1(1, 2) = -3;

    Matrix<double> n2(2, 3);
    n2(0, 0) = 1;
    n2(0, 1) = 1;
    n2(0, 2) = 1;
    n2(1, 0) = 10;
    n2(1, 1) = 1;
    n2(1, 2) = 13;

    Matrix<double> n3(2, 3);
    n3(0, 0) = 2;
    n3(0, 1) = 3;
    n3(0, 2) = 4;
    n3(1, 0) = 20;
    n3(1, 1) = 1;
    n3(1, 2) = 10;

    EXPECT_EQ(m1 + m2, m3);
    EXPECT_EQ(n1 + n2, n3);
}

TEST(matrix, addition_in_place)
{
    Matrix<double> m1(3, 3);
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(0, 2) = 3;
    m1(1, 0) = 10;
    m1(1, 1) = 0;
    m1(1, 2) = -3;
    m1(2, 0) = 27;
    m1(2, 1) = 1;
    m1(2, 2) = 0;

    Matrix<double> m2(3, 3);
    m2(0, 0) = 1;
    m2(0, 1) = 1;
    m2(0, 2) = 1;
    m2(1, 0) = 10;
    m2(1, 1) = 1;
    m2(1, 2) = 13;
    m2(2, 0) = 17;
    m2(2, 1) = 1;
    m2(2, 2) = 1;

    Matrix<double> m3(3, 3);
    m3(0, 0) = 2;
    m3(0, 1) = 3;
    m3(0, 2) = 4;
    m3(1, 0) = 20;
    m3(1, 1) = 1;
    m3(1, 2) = 10;
    m3(2, 0) = 44;
    m3(2, 1) = 2;
    m3(2, 2) = 1;

    Matrix<double> n1(2, 3);
    n1(0, 0) = 1;
    n1(0, 1) = 2;
    n1(0, 2) = 3;
    n1(1, 0) = 10;
    n1(1, 1) = 0;
    n1(1, 2) = -3;

    Matrix<double> n2(2, 3);
    n2(0, 0) = 1;
    n2(0, 1) = 1;
    n2(0, 2) = 1;
    n2(1, 0) = 10;
    n2(1, 1) = 1;
    n2(1, 2) = 13;

    Matrix<double> n3(2, 3);
    n3(0, 0) = 2;
    n3(0, 1) = 3;
    n3(0, 2) = 4;
    n3(1, 0) = 20;
    n3(1, 1) = 1;
    n3(1, 2) = 10;

    m1 += m2;
    n1 += n2;
    EXPECT_EQ(m1, m3);
    EXPECT_EQ(n1, n3);
}

TEST(matrix, negation)
{
    Matrix<double> m1(3, 3);
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(0, 2) = 3;
    m1(1, 0) = 10;
    m1(1, 1) = 0;
    m1(1, 2) = -3;
    m1(2, 0) = 27;
    m1(2, 1) = 1;
    m1(2, 2) = 0;

    Matrix<double> m2(3, 3);
    m2(0, 0) = -1;
    m2(0, 1) = -2;
    m2(0, 2) = -3;
    m2(1, 0) = -10;
    m2(1, 1) = -0;
    m2(1, 2) = 3;
    m2(2, 0) = -27;
    m2(2, 1) = -1;
    m2(2, 2) = -0;

    Matrix<double> n1(2, 3);
    n1(0, 0) = 1;
    n1(0, 1) = 2;
    n1(0, 2) = 3;
    n1(1, 0) = 10;
    n1(1, 1) = 0;
    n1(1, 2) = -3;

    Matrix<double> n2(2, 3);
    n2(0, 0) = -1;
    n2(0, 1) = -2;
    n2(0, 2) = -3;
    n2(1, 0) = -10;
    n2(1, 1) = 0;
    n2(1, 2) = 3;

    EXPECT_EQ(-m1, m2);
    EXPECT_EQ(-n1, n2);
}

TEST(matrix, substraction)
{
    Matrix<double> m1(3, 3);
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(0, 2) = 3;
    m1(1, 0) = 10;
    m1(1, 1) = 0;
    m1(1, 2) = -3;
    m1(2, 0) = 27;
    m1(2, 1) = 1;
    m1(2, 2) = 0;

    Matrix<double> m2(3, 3);
    m2(0, 0) = 1;
    m2(0, 1) = 1;
    m2(0, 2) = 1;
    m2(1, 0) = 10;
    m2(1, 1) = 1;
    m2(1, 2) = 13;
    m2(2, 0) = 17;
    m2(2, 1) = 1;
    m2(2, 2) = 1;

    Matrix<double> m3(3, 3);
    m3(0, 0) = 2;
    m3(0, 1) = 3;
    m3(0, 2) = 4;
    m3(1, 0) = 20;
    m3(1, 1) = 1;
    m3(1, 2) = 10;
    m3(2, 0) = 44;
    m3(2, 1) = 2;
    m3(2, 2) = 1;

    Matrix<double> n1(2, 3);
    n1(0, 0) = 1;
    n1(0, 1) = 2;
    n1(0, 2) = 3;
    n1(1, 0) = 10;
    n1(1, 1) = 0;
    n1(1, 2) = -3;

    Matrix<double> n2(2, 3);
    n2(0, 0) = 1;
    n2(0, 1) = 1;
    n2(0, 2) = 1;
    n2(1, 0) = 10;
    n2(1, 1) = 1;
    n2(1, 2) = 13;

    Matrix<double> n3(2, 3);
    n3(0, 0) = 2;
    n3(0, 1) = 3;
    n3(0, 2) = 4;
    n3(1, 0) = 20;
    n3(1, 1) = 1;
    n3(1, 2) = 10;

    Matrix<double> m4(3, 3);

    EXPECT_EQ(m3 - m2, m1);
    EXPECT_EQ(n3 - n2, n1);
    EXPECT_EQ(m2 - m2, m4);
}

TEST(matrix, substraction_in_place)
{
    Matrix<double> m1(3, 3);
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(0, 2) = 3;
    m1(1, 0) = 10;
    m1(1, 1) = 0;
    m1(1, 2) = -3;
    m1(2, 0) = 27;
    m1(2, 1) = 1;
    m1(2, 2) = 0;

    Matrix<double> m2(3, 3);
    m2(0, 0) = 1;
    m2(0, 1) = 1;
    m2(0, 2) = 1;
    m2(1, 0) = 10;
    m2(1, 1) = 1;
    m2(1, 2) = 13;
    m2(2, 0) = 17;
    m2(2, 1) = 1;
    m2(2, 2) = 1;

    Matrix<double> m3(3, 3);
    m3(0, 0) = 2;
    m3(0, 1) = 3;
    m3(0, 2) = 4;
    m3(1, 0) = 20;
    m3(1, 1) = 1;
    m3(1, 2) = 10;
    m3(2, 0) = 44;
    m3(2, 1) = 2;
    m3(2, 2) = 1;

    Matrix<double> n1(2, 3);
    n1(0, 0) = 1;
    n1(0, 1) = 2;
    n1(0, 2) = 3;
    n1(1, 0) = 10;
    n1(1, 1) = 0;
    n1(1, 2) = -3;

    Matrix<double> n2(2, 3);
    n2(0, 0) = 1;
    n2(0, 1) = 1;
    n2(0, 2) = 1;
    n2(1, 0) = 10;
    n2(1, 1) = 1;
    n2(1, 2) = 13;

    Matrix<double> n3(2, 3);
    n3(0, 0) = 2;
    n3(0, 1) = 3;
    n3(0, 2) = 4;
    n3(1, 0) = 20;
    n3(1, 1) = 1;
    n3(1, 2) = 10;

    Matrix<double> m4(3, 3);

    m3 -= m2;
    m2 -= m2;
    n3 -= n2;
    EXPECT_EQ(m3, m1);
    EXPECT_EQ(n3, n1);
    EXPECT_EQ(m2, m4);
}

TEST(matrix, transpose)
{
    Matrix<double> m1(3, 3);
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(0, 2) = 3;
    m1(1, 0) = 10;
    m1(1, 1) = 0;
    m1(1, 2) = -3;
    m1(2, 0) = 27;
    m1(2, 1) = 1;
    m1(2, 2) = 0;

    Matrix<double> m2(3, 3);
    m2(0, 0) = 1;
    m2(0, 1) = 10;
    m2(0, 2) = -1;
    m2(1, 0) = 10;
    m2(1, 1) = -89;
    m2(1, 2) = 13;
    m2(2, 0) = -1;
    m2(2, 1) = 13;
    m2(2, 2) = 116;

    Matrix<double> m3(3, 3);
    m3(0, 0) = 1;
    m3(0, 1) = 10;
    m3(0, 2) = 27;
    m3(1, 0) = 2;
    m3(1, 1) = 0;
    m3(1, 2) = 1;
    m3(2, 0) = 3;
    m3(2, 1) = -3;
    m3(2, 2) = 0;

    Matrix<double> n1(2, 3);
    n1(0, 0) = 1;
    n1(0, 1) = 2;
    n1(0, 2) = 3;
    n1(1, 0) = 10;
    n1(1, 1) = 0;
    n1(1, 2) = 3;

    Matrix<double> n2(3, 2);
    n2(0, 0) = 1;
    n2(0, 1) = 10;
    n2(1, 0) = 2;
    n2(1, 1) = 0;
    n2(2, 0) = 3;
    n2(2, 1) = 3;

    EXPECT_EQ(m3.transpose(), m1);
    EXPECT_EQ(n2.transpose(), n1);
    EXPECT_EQ(n2.transpose().transpose(), n2);
    EXPECT_EQ(m2.transpose(), m2);
}

TEST(matrix, transpose_in_place)
{
    Matrix<double> m1(3, 3);
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(0, 2) = 3;
    m1(1, 0) = 10;
    m1(1, 1) = 0;
    m1(1, 2) = -3;
    m1(2, 0) = 27;
    m1(2, 1) = 1;
    m1(2, 2) = 0;

    Matrix<double> m2(3, 3);
    m2(0, 0) = 1;
    m2(0, 1) = 10;
    m2(0, 2) = -1;
    m2(1, 0) = 10;
    m2(1, 1) = -89;
    m2(1, 2) = 13;
    m2(2, 0) = -1;
    m2(2, 1) = 13;
    m2(2, 2) = 116;

    Matrix<double> m3(3, 3);
    m3(0, 0) = 1;
    m3(0, 1) = 10;
    m3(0, 2) = 27;
    m3(1, 0) = 2;
    m3(1, 1) = 0;
    m3(1, 2) = 1;
    m3(2, 0) = 3;
    m3(2, 1) = -3;
    m3(2, 2) = 0;

    Matrix<double> m4(3, 3);
    m4(0, 0) = 1;
    m4(0, 1) = 10;
    m4(0, 2) = -1;
    m4(1, 0) = 10;
    m4(1, 1) = -89;
    m4(1, 2) = 13;
    m4(2, 0) = -1;
    m4(2, 1) = 13;
    m4(2, 2) = 116;

    m3.transpose_in_place();
    m2.transpose_in_place();

    EXPECT_EQ(m3, m1);
    EXPECT_EQ(m4, m2);
}

TEST(matrix, multiplication_by_scalar)
{
    Matrix<double> m1(3, 3);
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(0, 2) = 3;
    m1(1, 0) = 10;
    m1(1, 1) = 0;
    m1(1, 2) = -3;
    m1(2, 0) = 27;
    m1(2, 1) = 1;
    m1(2, 2) = 0;

    Matrix<double> m2(3, 3);
    m2(0, 0) = 3;
    m2(0, 1) = 6;
    m2(0, 2) = 9;
    m2(1, 0) = 30;
    m2(1, 1) = 0;
    m2(1, 2) = -9;
    m2(2, 0) = 81;
    m2(2, 1) = 3;
    m2(2, 2) = 0;

    Matrix<double> n1(2, 3);
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(0, 2) = 3;
    m1(1, 0) = 10;
    m1(1, 1) = 0;
    m1(1, 2) = -3;

    Matrix<double> n2(2, 3);
    m2(0, 0) = 3;
    m2(0, 1) = 6;
    m2(0, 2) = 9;
    m2(1, 0) = 30;
    m2(1, 1) = 0;
    m2(1, 2) = -9;

    EXPECT_EQ(m1 * 1, m1);
    EXPECT_EQ((m1 * 4) * 0.25, m1);
    EXPECT_EQ(3 * m1, m2);
    EXPECT_EQ(3 * n1, n2);
}

TEST(matrix, multiplication_by_scalar_in_place)
{
    Matrix<double> m1(3, 3);
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(0, 2) = 3;
    m1(1, 0) = 10;
    m1(1, 1) = 0;
    m1(1, 2) = -3;
    m1(2, 0) = 27;
    m1(2, 1) = 1;
    m1(2, 2) = 0;

    Matrix<double> m2(3, 3);
    m2(0, 0) = 3;
    m2(0, 1) = 6;
    m2(0, 2) = 9;
    m2(1, 0) = 30;
    m2(1, 1) = 0;
    m2(1, 2) = -9;
    m2(2, 0) = 81;
    m2(2, 1) = 3;
    m2(2, 2) = 0;

    Matrix<double> n1(2, 3);
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(0, 2) = 3;
    m1(1, 0) = 10;
    m1(1, 1) = 0;
    m1(1, 2) = -3;

    Matrix<double> n2(2, 3);
    m2(0, 0) = 3;
    m2(0, 1) = 6;
    m2(0, 2) = 9;
    m2(1, 0) = 30;
    m2(1, 1) = 0;
    m2(1, 2) = -9;

    m1 *= 3;
    n1 *= 3;

    EXPECT_EQ(m1, m2);
    EXPECT_EQ(n1, n2);
}

TEST(matrix, matrix_multiplication)
{
    Matrix<double> m1(3, 3);
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(0, 2) = 3;
    m1(1, 0) = 4;
    m1(1, 1) = 5;
    m1(1, 2) = 6;
    m1(2, 0) = 7;
    m1(2, 1) = 8;
    m1(2, 2) = 9;

    Matrix<double> m2(3, 3);
    m2(0, 0) = 1;
    m2(0, 1) = 0;
    m2(0, 2) = 2;
    m2(1, 0) = 0;
    m2(1, 1) = 1;
    m2(1, 2) = 0;
    m2(2, 0) = -2;
    m2(2, 1) = 0;
    m2(2, 2) = 1;

    Matrix<double> m3(3, 3);
    m3(0, 0) = -5;
    m3(0, 1) = 2;
    m3(0, 2) = 5;
    m3(1, 0) = -8;
    m3(1, 1) = 5;
    m3(1, 2) = 14;
    m3(2, 0) = -11;
    m3(2, 1) = 8;
    m3(2, 2) = 23;

    Matrix<double> n1(2, 3);
    n1(0, 0) = 1;
    n1(0, 1) = 2;
    n1(0, 2) = 3;
    n1(1, 0) = 4;
    n1(1, 1) = 5;
    n1(1, 2) = 6;

    Matrix<double> n2(3, 2);
    n2(0, 0) = 1;
    n2(0, 1) = 0;
    n2(1, 0) = 0;
    n2(1, 1) = -1;
    n2(2, 0) = -1;
    n2(2, 1) = 0;

    Matrix<double> n3(2, 2);
    n3(0, 0) = -2;
    n3(0, 1) = -2;
    n3(1, 0) = -2;
    n3(1, 1) = -5;

    Matrix<double> I(1000, 1000);
    for (unsigned int i = 0; i < 1000; i++)
        I(i, i) = 1;

    EXPECT_EQ(m1 * m2, m3);
    EXPECT_EQ(n1 * n2, n3);
    EXPECT_EQ(I * I, I);
}

TEST(matrix, matrix_by_vector_multiplication)
{
    Matrix<double> m(3, 3);
    m(0, 0) = 1;
    m(0, 1) = 2;
    m(0, 2) = 3;
    m(1, 0) = 4;
    m(1, 1) = 5;
    m(1, 2) = 6;
    m(2, 0) = 7;
    m(2, 1) = 8;
    m(2, 2) = 9;

    Vector<double> v1(3);
    v1(0) = 2;
    v1(1) = -1;
    v1(2) = 1;
    Vector<double> v2(3);
    v2(0) = 3;
    v2(1) = 9;
    v2(2) = 15;

    Matrix<double> n(2, 3);
    n(0, 0) = 1;
    n(0, 1) = 2;
    n(0, 2) = 3;
    n(1, 0) = 4;
    n(1, 1) = 5;
    n(1, 2) = 6;

    Vector<double> u1(3);
    u1(0) = 1;
    u1(1) = 0;
    u1(2) = -1;

    Vector<double> u2(2);
    u2(0) = -2;
    u2(1) = -2;

    EXPECT_EQ(m * v1, v2);
    EXPECT_EQ(n * u1, u2);
}

TEST(matrix, matrix_multiplication_strassen)
{
    Matrix<double> m1(3, 3);
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(0, 2) = 3;
    m1(1, 0) = 4;
    m1(1, 1) = 5;
    m1(1, 2) = 6;
    m1(2, 0) = 7;
    m1(2, 1) = 8;
    m1(2, 2) = 9;

    Matrix<double> m2(3, 3);
    m2(0, 0) = 1;
    m2(0, 1) = 0;
    m2(0, 2) = 2;
    m2(1, 0) = 0;
    m2(1, 1) = 1;
    m2(1, 2) = 0;
    m2(2, 0) = -2;
    m2(2, 1) = 0;
    m2(2, 2) = 1;

    Matrix<double> m3(3, 3);
    m3(0, 0) = -5;
    m3(0, 1) = 2;
    m3(0, 2) = 5;
    m3(1, 0) = -8;
    m3(1, 1) = 5;
    m3(1, 2) = 14;
    m3(2, 0) = -11;
    m3(2, 1) = 8;
    m3(2, 2) = 23;

    Matrix<double> n1(2, 3);
    n1(0, 0) = 1;
    n1(0, 1) = 2;
    n1(0, 2) = 3;
    n1(1, 0) = 4;
    n1(1, 1) = 5;
    n1(1, 2) = 6;

    Matrix<double> n2(3, 2);
    n2(0, 0) = 1;
    n2(0, 1) = 0;
    n2(1, 0) = 0;
    n2(1, 1) = -1;
    n2(2, 0) = -1;
    n2(2, 1) = 0;

    Matrix<double> n3(2, 2);
    n3(0, 0) = -2;
    n3(0, 1) = -2;
    n3(1, 0) = -2;
    n3(1, 1) = -5;

    Matrix<double> I(1000, 1000);
    for (unsigned int i = 0; i < 1000; i++)
        I(i, i) = 1;

    EXPECT_EQ(m1.strassen(m2), m3);
    EXPECT_EQ(n1.strassen(n2), n3);
    EXPECT_EQ(I.strassen(I), I);
}

TEST(matrix, swap_rows)
{
    Matrix<double> m1(3, 3);
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(0, 2) = 3;
    m1(1, 0) = 4;
    m1(1, 1) = 5;
    m1(1, 2) = 6;
    m1(2, 0) = 7;
    m1(2, 1) = 8;
    m1(2, 2) = 9;

    Matrix<double> m2(3, 3);
    m2(0, 0) = 4;
    m2(0, 1) = 5;
    m2(0, 2) = 6;
    m2(1, 0) = 1;
    m2(1, 1) = 2;
    m2(1, 2) = 3;
    m2(2, 0) = 7;
    m2(2, 1) = 8;
    m2(2, 2) = 9;

    m1.swap_rows(0, 1);
    EXPECT_EQ(m1, m2);

    m2.swap_rows(2, 2);
    EXPECT_EQ(m1, m2);
}

TEST(matrix, multiply_row_by_scalar)
{
    Matrix<double> m1(3, 3);
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(0, 2) = 3;
    m1(1, 0) = 4;
    m1(1, 1) = 5;
    m1(1, 2) = 6;
    m1(2, 0) = 7;
    m1(2, 1) = 8;
    m1(2, 2) = 9;

    Matrix<double> m2(3, 3);
    m2(0, 0) = 2;
    m2(0, 1) = 4;
    m2(0, 2) = 6;
    m2(1, 0) = 4;
    m2(1, 1) = 5;
    m2(1, 2) = 6;
    m2(2, 0) = 7;
    m2(2, 1) = 8;
    m2(2, 2) = 9;

    Matrix<double> m3(3, 3);
    m3(0, 0) = 2;
    m3(0, 1) = 4;
    m3(0, 2) = 6;
    m3(1, 0) = 4;
    m3(1, 1) = 5;
    m3(1, 2) = 6;
    m3(2, 0) = 0;
    m3(2, 1) = 0;
    m3(2, 2) = 0;

    m1.multiply_row_by_scalar(0, 2);
    EXPECT_EQ(m1, m2);

    m1.multiply_row_by_scalar(2, 0);
    EXPECT_EQ(m1, m3);
}

TEST(matrix, add_multiplied_row)
{
    Matrix<double> m1(3, 3);
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(0, 2) = 3;
    m1(1, 0) = 4;
    m1(1, 1) = 5;
    m1(1, 2) = 6;
    m1(2, 0) = 7;
    m1(2, 1) = 8;
    m1(2, 2) = 9;

    Matrix<double> m2(3, 3);
    m2(0, 0) = 2;
    m2(0, 1) = 4;
    m2(0, 2) = 6;
    m2(1, 0) = 4;
    m2(1, 1) = 5;
    m2(1, 2) = 6;
    m2(2, 0) = 7;
    m2(2, 1) = 8;
    m2(2, 2) = 9;

    Matrix<double> m3(3, 3);
    m3(0, 0) = 2;
    m3(0, 1) = 4;
    m3(0, 2) = 6;
    m3(1, 0) = 4;
    m3(1, 1) = 5;
    m3(1, 2) = 6;
    m3(2, 0) = 0;
    m3(2, 1) = 0;
    m3(2, 2) = 0;

    Matrix<double> m4(3, 3);
    m4(0, 0) = 1;
    m4(0, 1) = 2;
    m4(0, 2) = 3;
    m4(1, 0) = 2;
    m4(1, 1) = 1;

    m1.add_multiplied_row(0, 0, 1);
    EXPECT_EQ(m1, m2);

    m1.add_multiplied_row(2, 2, -1);
    EXPECT_EQ(m1, m3);

    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(0, 2) = 3;
    m1(1, 0) = 4;
    m1(1, 1) = 5;
    m1(1, 2) = 6;
    m1(2, 0) = 7;
    m1(2, 1) = 8;
    m1(2, 2) = 9;

    m1.add_multiplied_row(1, 0, -1);
    m1.add_multiplied_row(2, 0, -1);
    m1.add_multiplied_row(2, 1, -2);
    m1.add_multiplied_row(1, 0, -1);
    EXPECT_EQ(m1, m4);
}

TEST(matrix, det)
{
    Matrix<double> m1(3, 3);
    m1(0, 0) = 2;
    m1(0, 1) = 2;
    m1(0, 2) = 3;
    m1(1, 0) = 4;
    m1(1, 1) = 5;
    m1(1, 2) = 6;
    m1(2, 0) = 7;
    m1(2, 1) = 8;
    m1(2, 2) = 9;

    EXPECT_EQ((unsigned int)m1.get_det(), -3);

    Matrix<double> m2(3, 3);
    m2(0, 0) = 1;
    m2(0, 1) = 2;
    m2(0, 2) = 3;
    m2(1, 0) = 4;
    m2(1, 1) = 5;
    m2(1, 2) = 6;
    m2(2, 0) = 7;
    m2(2, 1) = 8;
    m2(2, 2) = 9;

    EXPECT_EQ((unsigned int)m2.get_det(), 0);
}

TEST(matrix, find_inverse)
{
    Matrix<double> m1(3, 3);
    m1(0, 0) = 2;
    m1(0, 1) = 0;
    m1(0, 2) = 0;
    m1(1, 0) = 1;
    m1(1, 1) = 1;
    m1(1, 2) = 0;
    m1(2, 0) = 1;
    m1(2, 1) = 0;
    m1(2, 2) = 1;

    Matrix<double> m2(3, 3);
    m2(0, 0) = 1 / (double)2;
    m2(0, 1) = 0;
    m2(0, 2) = 0;
    m2(1, 0) = -1 / (double)2;
    m2(1, 1) = 1;
    m2(1, 2) = 0;
    m2(2, 0) = -1 / (double)2;
    m2(2, 1) = 0;
    m2(2, 2) = 1;

    EXPECT_EQ(m1.find_inverse(), m2);

    Matrix<double> m3(3, 3);
    m3(0, 0) = 2;
    m3(0, 1) = 3;
    m3(0, 2) = 0;
    m3(1, 0) = 1;
    m3(1, 1) = 2;
    m3(1, 2) = 0;
    m3(2, 0) = 6;
    m3(2, 1) = 0;
    m3(2, 2) = 1;

    Matrix<double> m4(3, 3);
    m4(0, 0) = 2;
    m4(0, 1) = -3;
    m4(0, 2) = 0;
    m4(1, 0) = -1;
    m4(1, 1) = 2;
    m4(1, 2) = 0;
    m4(2, 0) = -12;
    m4(2, 1) = 18;
    m4(2, 2) = 1;

    EXPECT_EQ(m3.find_inverse(), m4);
}

TEST(matrix, rank)
{
    Matrix<double> m1(3, 3);
    m1(0, 0) = 2;
    m1(0, 1) = 2;
    m1(0, 2) = 3;
    m1(1, 0) = 4;
    m1(1, 1) = 5;
    m1(1, 2) = 6;
    m1(2, 0) = 7;
    m1(2, 1) = 8;
    m1(2, 2) = 9;

    EXPECT_EQ(m1.get_rank(), 3);

    Matrix<double> m2(3, 3);
    m2(0, 0) = 1;
    m2(0, 1) = 2;
    m2(0, 2) = 3;
    m2(1, 0) = 4;
    m2(1, 1) = 5;
    m2(1, 2) = 6;
    m2(2, 0) = 7;
    m2(2, 1) = 8;
    m2(2, 2) = 9;

    EXPECT_EQ(m2.get_rank(), 2);

    Matrix<double> m3(2, 3);
    m3(0, 0) = 0;
    m3(0, 1) = 0;
    m3(0, 2) = 3;
    m3(1, 0) = 0;
    m3(1, 1) = 0;
    m3(1, 2) = -3;

    EXPECT_EQ(m3.get_rank(), 1);

    Matrix<double> m4(3, 2);
    m2(0, 0) = 0;
    m2(0, 1) = 0;
    m2(1, 0) = 0;
    m2(1, 1) = 0;
    m2(2, 0) = 0;
    m2(2, 1) = 0;

    EXPECT_EQ(m4.get_rank(), 0);
}
