#include "Matrix.hpp"
#include "ctype.h"
using namespace std;
using namespace zich;

// ------------------ contrusctors ------------------
Matrix::Matrix() {

}

Matrix::Matrix(int rows, int cols) {
    if (rows < 0 or cols < 0) {
        throw invalid_argument("Rows or cols cannot be negative");
    }
    values.resize((unsigned int) rows);
    for (unsigned int i = 0; i < rows; i++) {
        values[i].resize((unsigned int) cols);
    }
}

Matrix::Matrix(vector<double> vec, int rows, int cols) {
    if (vec.size() != rows * cols) {
        throw invalid_argument("Rows or cols are not matching vector size");
    }
    if (rows < 0 or cols < 0) {
        throw invalid_argument("Rows or cols cannot be negative");
    }
    this->values.resize((unsigned int) rows);
    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < cols; j++) {
            values[i].push_back(vec[i*(unsigned int) cols + j]);
        }
    }
}
// ---------------end contrusctors ------------------

// ------------------ + operators ------------------
Matrix Matrix::operator + () {
    Matrix M;
    M.values.resize(this->values.size());
    for (unsigned int i = 0; i < values.size(); i++) {
        for (unsigned int j = 0; j < values[i].size(); j++) {
            M.values[i].push_back(this->values[i][j]);
        }
    }
    return M;
}

Matrix& Matrix::operator ++ () { // prefix definition
    for (unsigned int i = 0; i < values.size(); i++) {
        for (unsigned int j = 0; j < values[i].size(); j++) {
            values[i][j]++;
        }
    }
    return *this;
}

Matrix Matrix::operator ++ (int dummy) { // postfix definition
    Matrix temp = *this;
    ++*this;
    return temp;
}

Matrix Matrix::operator + (Matrix const &M) {
    if (this->values.size() != M.values.size() or this->values.at(0).size() != M.values.at(0).size()) {
        throw logic_error("Cannot add matrices of different sizes");
    }
    Matrix result;
    result.values.resize(this->values.size());
    for (unsigned int i = 0; i < this->values.size(); i++) {
        for (unsigned int j = 0; j < this->values[i].size(); j++) {
            result.values[i].push_back(this->values[i][j] + M.values[i][j]);
        }
    }
    return result;
}

Matrix Matrix::operator += (const Matrix &M) {
    if (this->values.size() != M.values.size() or this->values.at(0).size() != M.values.at(0).size()) {
        throw logic_error("Cannot add matrices of different size");
    }
    for (unsigned int i = 0; i < this->values.size(); i++) {
        for (unsigned int j = 0; j < this->values[i].size(); j++) {
            this->values[i][j] += M.values[i][j];
        }
    }
    return *this;
}
// ---------------end + operators ------------------

// ------------------ - operators ------------------
Matrix Matrix::operator - () {
    Matrix M;
    M.values.resize(this->values.size());
    M.values.resize(this->values.size());
    for (unsigned int i = 0; i < values.size(); i++) {
        for (unsigned int j = 0; j < values[i].size(); j++) {
            M.values[i].push_back(-1 * this->values[i][j]);
        }
    }
    return M;
}

Matrix& Matrix::operator -- () { // prefix definition
    for (unsigned int i = 0; i < values.size(); i++) {
        for (unsigned int j = 0; j < values[i].size(); j++) {
            values[i][j]--;
        }
    }
    return *this;
}

Matrix Matrix::operator -- (int dummy) { // postfix definition
    Matrix temp = *this;
    --*this;
    return temp;
}

Matrix Matrix::operator - (Matrix const &M) {
    if (this->values.size() != M.values.size() or this->values.at(0).size() != M.values.at(0).size()) {
        throw logic_error("Cannot subtract matrices of different sizes");
    }
    Matrix result;
    result.values.resize(this->values.size());
    for (unsigned int i = 0; i < this->values.size(); i++) {
        for (unsigned int j = 0; j < this->values[i].size(); j++) {
            result.values[i].push_back(this->values[i][j] - M.values[i][j]);
        }
    }
    return result;
}

Matrix Matrix::operator -= (const Matrix &M) {
    if (this->values.size() != M.values.size() or this->values.at(0).size() != M.values.at(0).size()) {
        throw logic_error("Cannot subtract matrices of different size");
    }
    for (unsigned int i = 0; i < this->values.size(); i++) {
        for (unsigned int j = 0; j < this->values[i].size(); j++) {
            this->values[i][j] -= M.values[i][j];
        }
    }
    return *this;
}
// ---------------end - operators ------------------

// ------------------ * operators ------------------
Matrix Matrix::operator *= (double toMultiple) {
    for (unsigned int i = 0; i < values.size(); i++) {
        for (unsigned int j = 0; j < values[i].size(); j++) {
            values[i][j] *= toMultiple;
        }
    }
    return *this;
}

Matrix Matrix::operator * (const Matrix &M) {
    if (this->values.at(0).size() != M.values.size()) {
        throw logic_error("Columns of matrix A must be equal to rows of matrix B (eg 3x2 * 2x4)");
    }
    Matrix mult(this->values.size(), M.values[0].size());
    for (unsigned int i = 0; i < mult.values.size(); i++) {
        for (unsigned int j = 0; j < mult.values[i].size(); j++) {
            mult.values[i][j] = 0;
            for (unsigned int k = 0; k < M.values.size();k ++) {
                mult.values[i][j] += this->values[i][k] * M.values[k][j];
            } 
        }
    }
    return mult;
}

Matrix Matrix::operator *= (const Matrix &M) {
    if (this->values.at(0).size() != M.values.size()) {
        throw logic_error("Columns of matrix A must be equal to rows of matrix B (eg 3x2 * 2x4)");
    }
    Matrix mult(this->values.size(), M.values[0].size());
    for (unsigned int i = 0; i < mult.values.size(); i++) {
        for (unsigned int j = 0; j < mult.values[i].size(); j++) {
            mult.values[i][j] = 0;
            for (unsigned int k = 0; k < M.values.size();k ++) {
                mult.values[i][j] += this->values[i][k] * M.values[k][j];
            } 
        }
    }
    this->values = mult.values;
    return *this;
}
// ---------------end * operators ------------------

// ------------- comparison operators ---------------
    bool Matrix::operator == (const Matrix& M) {
        if (this->values.size() != M.values.size() or this->values.at(0).size() != M.values.at(0).size()) {
            throw logic_error("Size does not match");
        }
        for (unsigned int i = 0; i < this->values.size(); i++) {
            for (unsigned int j = 0; j < this->values[i].size(); j++) {
                if (this->values[i][j] != M.values[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool Matrix::operator != (const Matrix& M) {
        return !(*this == M);
    }

    bool Matrix::operator <= (const Matrix& M) {
        if (this->values.size() != M.values.size() or this->values.at(0).size() != M.values.at(0).size()) {
            throw logic_error("Size does not match");
        }
        int sum1 = 0;
        int sum2 = 0;
        for (unsigned int i = 0; i < this->values.size(); i++) {
            for (unsigned int j = 0; j < this->values[i].size(); j++) {
                sum1 += this->values[i][j];
            }
        }
        for (unsigned int i = 0; i < M.values.size(); i++) {
            for (unsigned int j = 0; j < M.values[i].size(); j++) {
                sum2 += M.values[i][j];
            }
        }
        return sum1 <= sum2;
    }

    bool Matrix::operator >= (const Matrix& M) {
        if (this->values.size() != M.values.size() or this->values.at(0).size() != M.values.at(0).size()) {
            throw logic_error("Size does not match");
        }
        int sum1 = 0;
        int sum2 = 0;
        for (unsigned int i = 0; i < this->values.size(); i++) {
            for (unsigned int j = 0; j < this->values[i].size(); j++) {
                sum1 += this->values[i][j];
            }
        }
        for (unsigned int i = 0; i < M.values.size(); i++) {
            for (unsigned int j = 0; j < M.values[i].size(); j++) {
                sum2 += M.values[i][j];
            }
        }
        return sum1 >= sum2;
    }

    bool Matrix::operator < (const Matrix& M) {
        if (this->values.size() != M.values.size() or this->values.at(0).size() != M.values.at(0).size()) {
            throw logic_error("Size does not match");
        }
        int sum1 = 0;
        int sum2 = 0;
        for (unsigned int i = 0; i < this->values.size(); i++) {
            for (unsigned int j = 0; j < this->values[i].size(); j++) {
                sum1 += this->values[i][j];
            }
        }
        for (unsigned int i = 0; i < M.values.size(); i++) {
            for (unsigned int j = 0; j < M.values[i].size(); j++) {
                sum2 += M.values[i][j];
            }
        }
        return sum1 < sum2;
    }
            
    bool Matrix::operator > (const Matrix& M) {
        if (this->values.size() != M.values.size() or this->values.at(0).size() != M.values.at(0).size()) {
            throw logic_error("Size does not match");
        }
        int sum1 = 0;
        int sum2 = 0;
        for (unsigned int i = 0; i < this->values.size(); i++) {
            for (unsigned int j = 0; j < this->values[i].size(); j++) {
                sum1 += this->values[i][j];
            }
        }
        for (unsigned int i = 0; i < M.values.size(); i++) {
            for (unsigned int j = 0; j < M.values[i].size(); j++) {
                sum2 += M.values[i][j];
            }
        }
        return sum1 > sum2;
    }

// ----------end comparison operators ---------------

namespace zich {
    // scalar multiplication
    Matrix operator * (double toMultiple, const Matrix& M) {
    Matrix result = Matrix(M.values.size(), M.values[0].size());
    for (unsigned int i = 0; i < M.values.size(); i++) {
        for (unsigned int j = 0; j < M.values[i].size(); j++) {
            result.values[i][j] = toMultiple * M.values[i][j];
        }
    }
    return result;
}

    Matrix operator* (const Matrix& M, double toMultiple) {
        return toMultiple*M;
    }

    // cout operator
    ostream& operator << (ostream& os, const Matrix& M) {
    string toPrint;
    for (unsigned int i = 0; i < M.values.size(); i++) {
        toPrint += '[';
        for (unsigned int j = 0; j < M.values[i].size(); j++) {
            if ((int) M.values[i][j] == M.values[i][j]) {
                toPrint += to_string((int) M.values[i][j]);
            } else {
                toPrint += to_string(M.values[i][j]);
            }
            if (j != M.values[i].size() - 1) {
                toPrint += ' ';
            }
        }
        if (i != M.values.size() - 1) {
            toPrint += "]\n";
        } else {
            toPrint += ']';
        }
        
    }
    os << toPrint;
    return os;
}

    void check_string_read(string read_data) {
        // starts with '[' and ends with ']'.
        if (read_data[0] != '[' or read_data[read_data.size() - 1] != ']') {
            throw("Invalid syntax");
        }

        unsigned int i = 0;
        int coma_counter = 0;
        int parentheses_counter1 = 0;
        int parentheses_counter2 = 0;

        // check overall syntax, has to be digit after '[' and before ']'
        // also check lines are seperated by coma and a single space.
        for (;i < read_data.size(); i++) {
            if (read_data[i] == '[') {
                parentheses_counter1++;
                if (i + 1 < read_data.size()) {
                    if (isdigit(read_data[i+1]) == 0 and read_data[i+1] != '-') {
                       throw("Invalid syntax"); 
                    }
                    
                }
            }
            if (read_data[i] == ']') {
                parentheses_counter2++;
                if (isdigit(read_data[i-1]) == 0) {
                    throw("Invalid syntax");
                }
            }
            if (read_data[i] == ',') {
                coma_counter++;
                if (i + 1 < read_data.size() and read_data[i+1] != ' ') {
                    throw("Invalid syntax");
                }
                if (i + 2 < read_data.size() and read_data[i+2] != '[') {
                    throw("Invalid syntax");
                }
            }
        }

        // check amount of '[' equals amount of ']'.
        if (parentheses_counter1 != parentheses_counter2) {
            throw("Invalid syntax");
        }

        // check amount of ',' equals amount of parentheses - 1.
        if (parentheses_counter1 - 1 != coma_counter) {
            throw("Invalid syntax");
        }
    }

    // cin operator
    istream& operator >> (istream& is, Matrix& M) {
        string read_data;
        std::getline(is, read_data);
        check_string_read(read_data);
        unsigned int row_counter = 0;
        for (unsigned int i = 0; i < read_data.size(); i++) {
            if (read_data[i] == ',') {
                row_counter++;
            }
        }
        row_counter = row_counter + 1;
        unsigned int i = 0;
        unsigned int col_counter = 0;
        while (read_data[i] != ']') {
            if (read_data[i] == ' ') {
                col_counter++;
            }
            i++;
        }
        col_counter = col_counter + 1; // for the first '['
        vector<double> vals;
        string val;
        for (unsigned int i = 0; i < read_data.size(); i++) {
            if (read_data[i] == '.' or read_data[i] == '-') {
                val += read_data[i];
                continue;
            }
            if (isdigit(read_data[i]) != 0) {
                val += read_data[i];
            } else if (!val.empty()) {
                double toAdd = std::stod(val);
                vals.push_back(toAdd);
                val = "";
            }
        }
        M.values.resize(row_counter);
        for (unsigned int i = 0; i < row_counter; i++) {
            vector<double> tmp;
            for (unsigned int j = 0; j < col_counter; j++) {
                tmp.push_back(vals[i*col_counter + j]);
            }
            M.values[i] = tmp;
        }
        return is;
    }

    bool operator == (const Matrix& M1, const Matrix& M2) {
        if (M1.values.size() != M2.values.size() or M1.values[0].size() != M2.values[0].size()) {
            return false;
        }
        for (unsigned int i = 0; i < M1.values.size(); i++) {
            for (unsigned int j = 0; j < M1.values[0].size(); j++) {
                if (M1.values[i][j] != M2.values[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
}




