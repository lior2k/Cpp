// #include "doctest.h"
// #include <string>
// #include "Matrix.hpp"
// using namespace zich;
// using namespace std;

// TEST_CASE("Good Input") {    
//     bool compare = 0;
//     vector<double> values1 = {1, 3, 5, 2, 4, 6}; // 2x3
//     vector<double> values2 = {2, 3, 2, -2, 4, -5, -1, -2, -3, 2, 1, 3}; // 3x4
//     Matrix A{values1, 2, 3};
//     Matrix B{values2, 3, 4};
     
//     Matrix C = A * B;
//     vector<double> values3 = {-1, -2, 4, 7, 2, -2, 6, 6};
//     Matrix D{values3, 2, 4};
//     compare = (C == D);
//     CHECK(compare == true); //check A*B

//     A*=B;
//     compare = (A == C);
//     CHECK(compare == true); // check A*=B

//     vector<double> values4 = {3, 4, 3, -1, 5, -4, 0, -1, -2, 3, 2, 4}; // 3x4
//     Matrix F{values4, 3, 4};
//     B++;
//     compare = (B == F);
//     CHECK(compare == true); // check B++
    
//     vector<double> values5 = {-2, -3, 3, 6, 1, -3, 5, 5};
//     Matrix G{values5, 2, 4};
//     A--;
//     compare = (A == G);
//     CHECK(compare == true); // check A--

//     Matrix A2 = +A;
//     compare = (A == A2);
//     CHECK(compare == true); // check + unary

//     vector<double> values6 = {2, 3, -3, -6, -1, 3, -5, -5}; // minus A
//     Matrix Am{values6, 2, 4};
//     Matrix Am2 = -A; 
//     compare = (Am == Am2);
//     CHECK(compare == true); // check - unary

//     Matrix I{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 3, 4};
//     Matrix Bp2{{4, 5, 4, 0, 6, -3, 1, 0, -1, 4, 3, 5}, 3, 4};
//     Matrix Bp1 = B + I;
//     compare = (Bp1 == Bp2);
//     CHECK(compare == true);

//     Matrix Bm1{{2, 3, 2, -2, 4, -5, -1, -2, -3, 2, 1, 3}, 3, 4};
//     Matrix Bm2 = B - I;
//     compare = (Bm1 == Bm2);
//     CHECK(compare == true);

//     Bm1+=I;
//     compare = (Bm1 == B);
//     CHECK(compare == true);

//     Bm1-=I;
//     compare = (Bm1 == Bm2);
//     CHECK(compare == true);
// }

// TEST_CASE("Bad Input") {    
//     Matrix A{2, 2};
//     Matrix B{2, 3};
//     Matrix C{3, 3};
//     CHECK_THROWS(A+B);
//     CHECK_THROWS(B+A);
//     CHECK_THROWS(A+=B);
//     CHECK_THROWS(B+=A);
//     CHECK_THROWS(A-B);
//     CHECK_THROWS(B-A);
//     CHECK_THROWS(A-=B);
//     CHECK_THROWS(B-=A);
//     CHECK_THROWS(A*C);
//     CHECK_THROWS(C*A);
//     CHECK_THROWS(A*=C);
//     CHECK_THROWS(C*=A);
//     // CHECK_THROWS((A == B));
//     // CHECK_THROWS((A != B));
// }

#include "doctest.h"
#include "Matrix.hpp"
#include "string"
#include "algorithm"
using namespace std;
using namespace zich;

TEST_CASE("Good")
{
    bool ans = 0;
    vector<double> testcase = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<double> testcase2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<double> test1 = {1, 2, 3, 4};
    vector<double> test2 = {5, 6, 7, 8};
    vector<double> test1test2 = {19, 22, 43, 50};
    Matrix A{testcase, 3, 3};
    Matrix B{testcase2, 3, 3};
    Matrix t1{test1, 2, 2};
    Matrix t2{test2, 2, 2};
    Matrix C{test1test2, 2, 2};
    ans = (A >= B);
    cout << ans;
    CHECK(ans == true);
    ans = A <= B;
    CHECK(ans == true);
    A *= 2;
    ans = A > B;
    CHECK(ans == true);
    ans = t1 * t2 == C;
    CHECK(ans == true);
    ++t1;
    ans = t1 * t1 != C;
    CHECK(ans == true);
    Matrix f = {{0, 0, 0, 0, 0, 0, 0, 0, 0}, 3, 3};
    Matrix f_ans = {{1, 1, 1, 1, 1, 1, 1, 1, 1}, 3, 3};
    Matrix G = -B - B;
    ans = A - G == f;
    CHECK(ans == false);
    f++;
    ans = f == f_ans;
    CHECK(ans == true);
    Matrix mat4{{1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3};
    Matrix mat5{{1, 2, 3, 4, 5, 6}, 2, 3};
    ans = mat5 * mat4 == mat5 * mat4;
    CHECK(ans == true);

    std::vector<double> identity = {1, 2, 0, 5, 1, 0, -1, 0, 1};
    std::vector<double> arr = {3, 0, 0, 0, 3, -3, 2, 0, 3};
    Matrix a1{identity, 3, 3};
    Matrix b1{arr, 3, 3};
    Matrix c1{{3, 6, -6, 15, 3, -3, -1, 0, 3}, 3, 3};
    Matrix d1{{4,2,0,5,4,-3,1,0,4}, 3, 3};
    Matrix e1{{-2, 2, 0, 5, -2, 3, -3, 0, -2}, 3, 3};
    ans = a1 * b1 == c1;
    CHECK(ans == true);
    ans = a1 + b1 == d1;
    CHECK(ans == true);
    ans = a1 - b1 == e1;
    CHECK(ans == true);
    mat5++;
    Matrix mat5a{{2, 3, 4, 5, 6, 7}, 2, 3};
    ans = mat5 == mat5a;
    CHECK(ans == true);
}
TEST_CASE("goodinput"){

}

TEST_CASE("Bad")
{
    bool res = 0;
    Matrix mat{{1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3};
    Matrix mat2{{1, 2, 3, 4, 5, 6}, 2, 3};
    CHECK_THROWS(mat + mat2);
    CHECK_THROWS(mat - mat2);
    CHECK_THROWS(mat += mat2);
    CHECK_THROWS(mat * mat2);
    CHECK_THROWS(mat2 - mat);
    CHECK_THROWS(mat2 + mat);
    std::vector<double> mat6vector;
    for (unsigned int i = 0; i < 99; i++)
    {
        mat6vector.push_back(i);
    }
    Matrix mat6{mat6vector, 33, 3};
    CHECK_THROWS(mat6 * mat2);
    CHECK_THROWS(mat6 + mat2);
    CHECK_THROWS(mat6 - mat2);
}

