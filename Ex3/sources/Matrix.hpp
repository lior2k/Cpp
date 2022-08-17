#include <vector>
#include <iostream>

namespace zich {

    class Matrix {

        private:
            std::vector<std::vector<double>> values;
        public:
            // constructors
            Matrix();
            Matrix(int rows, int cols);
            Matrix(std::vector<double> vec, int rows, int cols);

            // scalar and matrix addition
            Matrix operator+ ();
            Matrix& operator++ (); //prefix increment
            Matrix operator++ (int dummy); //postfix increment
            Matrix operator+ (const Matrix& M);
            Matrix operator+= (const Matrix& M);

            // scalar and matrix reduction
            Matrix operator- ();
            Matrix& operator-- (); //prefix increment
            Matrix operator-- (int dummy); //postfix increment
            Matrix operator- (const Matrix& M);
            Matrix operator-= (const Matrix& M);

            // scalar and matrix multiplication
            Matrix operator*= (double toMultiple);
            Matrix operator* (const Matrix& M);
            Matrix operator*= (const Matrix& M);
            friend Matrix operator* (double toMultiple, const Matrix& M);
            friend Matrix operator* (const Matrix& M, double toMultiple);

            friend std::ostream& operator<< (std::ostream& os, const Matrix& M);
            friend std::istream& operator>> (std::istream& is, Matrix& M);

            // comparison operators
            friend bool operator == (const Matrix& M1, const Matrix& M2);

            bool operator == (const Matrix& M);
            bool operator != (const Matrix& M);
            bool operator <= (const Matrix& M);
            bool operator >= (const Matrix& M);
            bool operator < (const Matrix& M);
            bool operator > (const Matrix& M);
    };
}