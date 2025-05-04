//yaeldorani@gmail.com

#include <iostream>
#include "SquareMat.hpp"

using namespace std;
using namespace my_matrix;

int main() {

    SquareMat A(2);
    SquareMat B(2);

    
    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;

    B[0][0] = 5; B[0][1] = 6;
    B[1][0] = 7; B[1][1] = 8;

    cout << "Matrix A:\n" << A << endl;
    cout << "Matrix B:\n" << B << endl;

   
    cout << "A + B:\n" << (A + B) << endl;

  
    cout << "A - B:\n" << (A - B) << endl;

    
    cout << "-A:\n" << -A << endl;

    cout << "A ^ 2:\n" << (A ^ 2) << endl;

    cout << "A * B:\n" << (A * B) << endl;

  
    cout << "A * 2:\n" << (A * 2) << endl;
    cout << "2 * A:\n" << (2 * A) << endl;

    
    cout << "A / 2:\n" << (A / 2) << endl;

    
    cout << "A % B (Element-wise product):\n" << (A % B) << endl;

    
    cout << "A % 3 (mod 3 on each element):\n" << (A % 3) << endl;

 
    cout << "det(A): " << !A << endl;

   
    A += B;
    cout << "A += B:\n" << A << endl;

   
    A -= B;
    cout << "A -= B:\n" << A << endl;


    A /= 2;
    cout << "A /= 2:\n" << A << endl;

    
    cout << "++A:\n" << ++A << endl;
    cout << "A++:\n" << A++ << endl;
    cout << "--A:\n" << --A << endl;
    cout << "A--:\n" << A-- << endl;

    
    cout << "~A (transpose):\n" << ~A << endl;


    cout << "A == B: " << (A == B) << endl;
    cout << "A != B: " << (A != B) << endl;
    cout << "A <= B: " << (A <= B) << endl;
    cout << "A >= B: " << (A >= B) << endl;
    cout << "A < B: " << (A < B) << endl;
    cout << "A > B: " << (A > B) << endl;

    return 0;
}
