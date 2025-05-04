//yaeldorani@gmail.com

#include <iostream>

#ifndef SQUAREMAT_HPP
#define SQUAREMAT_HPP


namespace my_matrix{

class SquareMat{
    static int ID;
    
    private:
        double** mat;

public:

    int id; // id to identify each mat
    int size; // save the current mateix size, make sure the size is positive

    SquareMat(int size); 
    SquareMat(const SquareMat& other);
    ~SquareMat();

    double* operator[](int index) const;
    double* operator[](int index);

    SquareMat& operator=(const SquareMat& other);
    bool operator==(const SquareMat& other) const;
    bool operator!=(const SquareMat& other) const;
    bool operator<=(const SquareMat& other) const;
    bool operator>=(const SquareMat& other) const;
    bool operator>(const SquareMat& other) const;
    bool operator<(const SquareMat& other) const;


    SquareMat operator+(const SquareMat& other) const;
    SquareMat operator-(const SquareMat& other) const;

    SquareMat operator~() const;

    SquareMat& operator-();
    SquareMat& operator++();
    SquareMat operator++(int);
    SquareMat& operator--();
    SquareMat operator--(int);
    SquareMat operator*(const SquareMat& other) const;
    SquareMat operator^(int pow) const;
    SquareMat operator*(double scalar) const;
    friend SquareMat operator*(double scalar, const SquareMat& mat);

    SquareMat operator/(double scalar) const;
    SquareMat operator% (const SquareMat& other) const;
    SquareMat operator% (int mod) const;

    
    friend std::ostream& operator<<(std::ostream& out, const SquareMat& mat);

    double find_sum() const;
    
    SquareMat minor (int row, int col) const;
    double operator!() const;

    SquareMat& operator+= (const SquareMat& other); 
    SquareMat& operator-= (const SquareMat& other); 
    SquareMat& operator/=(double scalar);
    SquareMat&  operator*=(double scalar);
    SquareMat& operator*=(const SquareMat &other);
    SquareMat& operator%= (const SquareMat& other);
    SquareMat& operator%= (int mod);

};

}
#endif