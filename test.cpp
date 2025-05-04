//yaeldorani@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.hpp"

using namespace my_matrix;

//constractor, [][], copy constractor, =
TEST_CASE("Constructor and basic element access") {
    SquareMat m(2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;
    CHECK(m[0][0] == 1);
    CHECK(m[1][0] == 3);

    SquareMat n(m); //copy constractor

    SquareMat a (3); 
    a = m; //copy assignment 
    CHECK(n[0][1] == 2);
    CHECK(a[1][1] == 4);

}

//Simple arithmetic operators between two matrices(+, +=, -, -=, *, *=, %, %=):
TEST_CASE("Simple arithmetic operators between two matrices") {
    SquareMat m(2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;

    SquareMat n(2);
    n[0][0] = 4;
    n[0][1] = 3;
    n[1][0] = 2;
    n[1][1] = 1;

    SquareMat a = m + n;

    CHECK(a[0][0] == 5);
    CHECK(a[1][0] == 5);
    CHECK(a[0][1] == 5);
    CHECK(a[1][1] == 5);

    SquareMat b (3);
    b = a - m;
    CHECK(b[0][0] == 4);
    CHECK(b[0][1] == 3);
    CHECK(b[1][0] == 2);
    CHECK(b[1][1] == 1);

    m += n;
    CHECK(m[0][0] == 5);    
    CHECK(m[0][1] == 5);
    CHECK(m[1][0] == 5);
    CHECK(m[1][1] == 5);
   
    n -= m;
    CHECK(n[0][0] == -1);
    CHECK(n[0][1] == -2);
    CHECK(n[1][0] == -3);
    CHECK(n[1][1] == -4);

    SquareMat c(3);
    SquareMat d(3);

    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            c[i][j] = 2;
            d[i][j] = 3;
        }
    }

    SquareMat e = c*d;
    CHECK(e[1][1] == 18);

    SquareMat f(2);
    f[0][0] = 1;
    f[0][1] = 2;
    f[1][0] = 3;
    f[1][1] = 4;

    SquareMat g(2);
    g[0][0] = 5;
    g[0][1] = 6;
    g[1][0] = 7;
    g[1][1] = 8;

    SquareMat h = f*g;
    CHECK(h[1][0] == 43);

    SquareMat i(2);
    i[0][0] = 2;
    i[0][1] = 0;
    i[1][0] = 0;
    i[1][1] = 2;

    f*=i;
    CHECK(f[1][0] == 6);
    
    SquareMat j = b % g; 
    CHECK(j[1][0] == 14);

    j%=i;
    CHECK(j[0][0] == 40);
    CHECK(j[1][0] == 0);

}

//==, !=, <, >, <=, >=
TEST_CASE("Comarisons") {
    SquareMat m(2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;

    SquareMat n(2);
    n[0][0] = 4;
    n[0][1] = 3;
    n[1][0] = 2;
    n[1][1] = 1;

    CHECK(m == n);
    CHECK_FALSE(n != m);
    CHECK(m >= n);
    CHECK(m <= n);

    SquareMat c(3);
    SquareMat d(3);

    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            c[i][j] = 2;
            d[i][j] = 3;
        }
    }

    CHECK(c != d);
    CHECK_FALSE(c == d);
    CHECK(c < d);
    CHECK(c <= d);
    CHECK_FALSE(c >= d);
    CHECK_FALSE(c > d);
}

//++,--,-, *, *=, %, %=, /, /=
TEST_CASE("Simple arithmetic operator on a single matrix") {
    SquareMat m(2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;

    SquareMat n(2);
    n[0][0] = 4;
    n[0][1] = 3;
    n[1][0] = 2;
    n[1][1] = 1;


    SquareMat b = ++m;

    CHECK(b[0][0] == 2);
    CHECK(b[0][1] == 3);
    CHECK(b[1][0] == 4);
    CHECK(b[1][1] == 5);

    SquareMat a = m++;

    CHECK(a[0][0] == 2);
    CHECK(a[0][1] == 3);
    CHECK(a[1][0] == 4);
    CHECK(a[1][1] == 5);

    CHECK(m[0][0] == 3);
    CHECK(m[0][1] == 4);
    CHECK(m[1][0] == 5);
    CHECK(m[1][1] == 6);

    a--;
    CHECK(a[0][0] == 1);
    CHECK(a[0][1] == 2);
    CHECK(a[1][0] == 3);
    CHECK(a[1][1] == 4);

    SquareMat e = --a;
    CHECK(e[0][0] == 0);
    CHECK(e[0][1] == 1);
    CHECK(e[1][0] == 2);
    CHECK(e[1][1] == 3);

    -a;
    CHECK(a[0][0] == 0);
    CHECK(a[0][1] == -1);
    CHECK(a[1][0] == -2);
    CHECK(a[1][1] == -3);


    SquareMat c(3);
    SquareMat d(3);

    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            c[i][j] = 2;
            d[i][j] = 3;
        }
    }

    SquareMat f = c*2;

    CHECK(f[0][0] == 4);
    CHECK(f[0][1] == 4);
    CHECK(f[1][0] == 4);
    CHECK(f[1][1] == 4);

    SquareMat g(2);
    g[0][0] = 5;
    g[0][1] = 6;
    g[1][0] = 7;
    g[1][1] = 8;

    
    SquareMat h = 4*g;
    CHECK(h[0][0] == 20);
    CHECK(h[0][1] == 24);
    CHECK(h[1][0] == 28);
    CHECK(h[1][1] == 32);

    SquareMat i(2);
    i[0][0] = 2;
    i[0][1] = 0;
    i[1][0] = 0;
    i[1][1] = 2;


    i*=3;
    CHECK(i[0][0] == 6);
    CHECK(i[0][1] == 0);
    CHECK(i[1][0] == 0);
    CHECK(i[1][1] == 6);

    SquareMat k = i % 7;
    CHECK(k[0][0] == 6);
    CHECK(k[0][1] == 0);
    CHECK(k[1][0] == 0);
    CHECK(k[1][1] == 6);

    i%=5;
    CHECK(i[0][0] == 1);
    CHECK(i[0][1] == 0);
    CHECK(i[1][0] == 0);
    CHECK(i[1][1] == 1);

    SquareMat j = h / 4; 
    CHECK(j[0][0] == 5);
    CHECK(j[0][1] == 6);
    CHECK(j[1][0] == 7);
    CHECK(j[1][1] == 8);

    h /= 2;
    h[0][0] = 10;
    h[0][1] = 12;
    h[1][0] = 14;
    h[1][1] = 16;
    CHECK(h[0][0] == 10);
    CHECK(h[0][1] == 12);
    CHECK(h[1][0] == 14);
    CHECK(h[1][1] == 16);

    SquareMat l = j^2;
    CHECK(l[0][0] == 67);
    CHECK(l[0][1] == 78);
    CHECK(l[1][0] == 91);
    CHECK(l[1][1] == 106);

}

//Matrix-specific operations, !, ~
TEST_CASE("Matrix-specific operations ") {
    SquareMat m(2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;

    SquareMat a = ~m;
    CHECK(a[0][0] == 1);
    CHECK(a[0][1] == 3);
    CHECK(a[1][0] == 2);
    CHECK(a[1][1] == 4);

    double b = !m;

    CHECK(b == -2);

}

