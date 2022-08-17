#include "mat.hpp"
#include <iostream>
#include <vector>
using namespace ariel;
using namespace std;
const int MAX_CHAR_VAL = 127;
const int MIN_CHAR_VAL = 32;

string getVectorAsString(vector<vector<char>> &cr, int rows, int cols) {
    string result;
    for (int n = 0; n < rows; n++) {
        for (int m = 0; m < cols; m++) {
            if (result.empty()) {
                result = cr[n][m];
            } else {
                result += cr[n][m];
            }            
        }
        result += '\n';
    }
    return result;
}

/*
- check for throws.
- build a matrix made of vectors.
- fill the matrix starting with outer layer (border) and so on.
- build then return the string.
*/
string ariel::mat(int cols, int rows, char x, char y) {
    if (cols % 2 == 0 or rows % 2 == 0) {
        throw std::invalid_argument("invalid arguement - even number");
    }
    if (cols < 0 or rows < 0) {
        throw std::invalid_argument("invalid arguement - 0 or negative number");
    }
    if ((int)x >= MAX_CHAR_VAL or (int)x <= MIN_CHAR_VAL or (int)y >= MAX_CHAR_VAL or (int)y <= MIN_CHAR_VAL) {
        throw std::invalid_argument("invalid arguement - bad char input");
    }

    // initiallize - declare and resize inner vectors
    // for (int i = 0; i < rows; i++) {
    //     vector<char> inner_vector;
    //     inner_vector.resize(cols);       code segment 41-46 replaced by row 48
    //     carpet.push_back(inner_vector);  
    // }

    vector<vector<char>> carpet (rows, vector<char>(cols));
    char toFill = y;
    int topRowIndex = 0; // upper row index
    int bottumRowIndex = rows - 1; // lower row index
    int leftColumnIndex = 0; // left column index
    int rightColumnIndex = cols - 1; //right column index

    // fill matrix
    while (topRowIndex <= bottumRowIndex && leftColumnIndex <= rightColumnIndex) {
        //swap char
        toFill = (toFill == y)? x : y;

        // fill rows
        for (int i = topRowIndex; i <= rightColumnIndex; i++) {
            carpet[topRowIndex][i] = toFill;
            carpet[bottumRowIndex][i] = toFill;
        }

        // fill columns
        for (int i = leftColumnIndex; i <= bottumRowIndex; i++) {
            carpet[i][leftColumnIndex] = toFill;
            carpet[i][rightColumnIndex] = toFill;
        }
        topRowIndex += 1;
        leftColumnIndex += 1;
        bottumRowIndex -= 1;
        rightColumnIndex -= 1;
    } 
    return getVectorAsString(carpet, rows, cols);
}


