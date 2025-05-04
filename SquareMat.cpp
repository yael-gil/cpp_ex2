//yaeldorani@gmail.com

#include "SquareMat.hpp"
#include <stdexcept>
#include <iostream>
#include <cmath>

namespace my_matrix{

    // regular constructor
    SquareMat::SquareMat(int n) : 
    id(ID++),  // define the id of the new matrix
    size(n)
    { 
        // if n < 0, throw exeption
        if (n <= 0) {
            throw std::invalid_argument("Matrix size must be positive.");
        }
            mat = new double*[n]; // create the matrix 
            
            for (int i = 0; i < n; i++){
                mat[i] = new double[n];
            }

    }

    //copy constructor
    SquareMat::SquareMat(const SquareMat& other){
        size  = other.size;
        id = ID++;

        mat = new double*[size]; // create the matrix 

        for (int i = 0; i < size; i++){
            mat[i] = new double[size];
            for (int j = 0 ; j < size; j++){
                mat[i][j] = other.mat[i][j];
            }
        }
    }

    //destructor
    SquareMat::~SquareMat(){
        for (int j = 0; j < this->size; j++){
            delete[] mat[j];
        } 
        delete[] mat;
    }


    //copy assignment operator
    SquareMat& SquareMat::operator=(const SquareMat& other){
        if (this == &other) return *this; // prevents unnecessary palcement

        //if the matrices are of diffremt sizes, 
        //delete the data of the "this" matrix and create new a mat of the "other" size  
        
        if (this-> size != other.size){
            for (int i = 0; i < size; i++){
                delete[] this->mat[i];
            }
            delete[] this-> mat;
            
            size = other.size;
            mat = new double*[size];
            for (int i = 0; i < size; ++i) {
                mat[i] = new double[size];
            }
        }

        //copy the data 
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                (*this)[i][j] = (other)[i][j];
            }
        }
        return *this;
    }
    
    
//operator [] use to get and set cell in the matrix:

    // get a specific value in a matrix
    double* SquareMat::operator[](int index) const{
        std::cout << "c";

        //check if the index is in the matrix
        if (index >= size || index < 0){
            throw std::out_of_range("Matrix index out of bounds: "+std::to_string(index));
        }

        return this->mat[index];
    }

    //set a specific value in a matrix
    double* SquareMat::operator[](int index){

        //check if the index is in the matrix
        if (index >= size || index < 0){
            throw std::out_of_range("Matrix index out of bounds: "+std::to_string(index));
        }
        return this->mat[index];
    }

//Simple arithmetic operators between two matrices(+, +=, -, -=, *, *=, %, %=):

    //(+)
    SquareMat SquareMat::operator+ (const SquareMat& other) const{
        
        //if the matrices are of diffremt sizes, return error
        if (this->size != other.size){
            throw std::invalid_argument("Matrix sizes do not match.");
        }

        SquareMat res(this->size);

        // inserts into each element of the matrix the sum of the elements in the current and other  matrices
        for (int i = 0; i < this->size; i++){
            for (int j = 0; j < this->size; j++){
                res.mat[i][j] = this->mat[i][j] + other.mat[i][j];            
            }
        }
        return res;
    }

        //(+=)
        SquareMat& SquareMat::operator+= (const SquareMat& other) {
            
            //if the matrices are of diffremt sizes, return error
            if (this->size != other.size){
                throw std::invalid_argument("Matrix sizes do not match.");
            }
    
            // inserts into each element of "this" matrix 
            // the sum of the elements in "this" and "other" matrices
            for (int i = 0; i < this->size; i++){
                for (int j = 0; j < this->size; j++){
                    this->mat[i][j] = this->mat[i][j] + other.mat[i][j];            
                }
            }
            return *this;
        }

    //(-)
    SquareMat SquareMat::operator- (const SquareMat& other) const{
        
        //if the matrices are of diffremt sizes, return error
        if (this->size != other.size){
            throw std::invalid_argument("Matrix sizes do not match.");
        }
        SquareMat res(this->size);

        // inserts into each element of the matrix the subtraction
        // of the elements in the current and other  matrices
        for (int i = 0; i < this->size; i++){
            for (int j = 0; j < this->size; j++){
                res.mat[i][j] = this->mat[i][j] - other.mat[i][j];            
            }
        }
        return res;
    }

    //(-=)
    SquareMat& SquareMat::operator-= (const SquareMat& other) {
    
        //if the matrices are of diffremt sizes, return error
        if (this->size != other.size){
            throw std::invalid_argument("Matrix sizes do not match.");
        }

        // inserts into each element of "this" matrix the subtraction 
        //of the elements in "this" and "other"  matrices
        for (int i = 0; i < this->size; i++){
            for (int j = 0; j < this->size; j++){
                this->mat[i][j] = this->mat[i][j] - other.mat[i][j];            
            }
        }
        return *this;
    }



    //(*)
    SquareMat SquareMat::operator*(const SquareMat &other) const{
    
        //if the matrices are of diffremt sizes, return error
        if (this->size != other.size) {
            throw std::invalid_argument("Matrix sizes do not match.");
        }
    
        SquareMat result(size);
        int count = 0; //save the current row 
        double ij_sum = 0; // The sum of the product of the current row by the current colum


        while (count < size) { //Iterates over all the matrix rows
            for (int i = 0; i < size; i++) { 
                for (int j = 0; j < size; j++) {
                ij_sum += this->mat[count][j] * other.mat[j][i]; //Calculates the sum
                }
                result.mat[count][i] = ij_sum; // Update the sum at appropriate position in the matrix
                ij_sum = 0;
            }
            count++;
        }
        return result;
    }

    //(*=)
    SquareMat& SquareMat::operator*=(const SquareMat &other) {
       
            //if the matrices are of diffremt sizes, return error
            if (this->size != other.size) {
                throw std::invalid_argument("Matrix sizes do not match.");
            }
        
            SquareMat result(size);
            int count = 0;  //save the current row 
            double ij_sum = 0; // The sum of the product of the current row by the current colum

    
            while (count < size) { //Iterates over all the matrix rows
                for (int i = 0; i < size; i++) {
                    for (int j = 0; j < size; j++) {
                    ij_sum += this->mat[count][j] * other.mat[j][i]; //Calculates the sum
                    }
                    result.mat[count][i] = ij_sum; // Update the sum at appropriate position in the matrix
                    ij_sum = 0;
                }
                count++;
            }
            *this = result;
            return *this;
    }

    // Elemnt-wise multiplication, multiplies each element
    // in "this" matrix by the corresponding elemnt in "other" matrix
    //create a new matrix
    SquareMat SquareMat:: operator% (const SquareMat& other) const{
       
        //if the matrices are of diffremt sizes, return error
        if (this->size != other.size){
            throw std::invalid_argument("Matrix sizes do not match.");
        }

        SquareMat res (this->size);

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
               res.mat[i][j] = this->mat[i][j] * other[i][j];
            }
        }  
        return res;
    }

    // Elemnt-wise multiplication, multiplies each element
    // in "this" matrix by the corresponding elemnt in "other" matrix
    //return "this"
    SquareMat& SquareMat:: operator%= (const SquareMat& other){
        
        //if the matrices are of diffremt sizes, return error
        if (this->size != other.size){
            throw std::invalid_argument("Matrix sizes do not match.");
        }

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
               this->mat[i][j] = this->mat[i][j] * other[i][j];
            }
        }  
        return *this;
    }

//Simple arithmetic operator on a single matrix

    //++mat, Adds 1 to each element of the matrix and return the modified matrix
    SquareMat& SquareMat:: operator++(){
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){

                this->mat[i][j] = ++mat[i][j];
  
            }
        } 
        return *this;
    }

    //--mat, subtracts 1 to each element of the matrix and return the modified matrix
    SquareMat& SquareMat:: operator--(){
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){

                this->mat[i][j] = --mat[i][j];
    
            }
        } 
        return *this;
    }

    //mat++, Adds 1 to each element of the matrix and return the matrix before the change
    SquareMat SquareMat:: operator++(int){
        SquareMat copy (*this);

        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){

                this->mat[i][j]++;
  
            }
        } 
        return copy; 
    }
    
    //mat--, subtracts 1 to each element of the matrix and return the matrix before the change
    SquareMat SquareMat:: operator--(int){
        SquareMat copy (*this);

        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){

                this->mat[i][j]--;
  
            }
        } 
        return copy; 
    }


    //(-) multiplies each term in the matrix by (-1)
    SquareMat& SquareMat::operator- (){
    
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){

                this->mat[i][j] = -mat[i][j];
  
            }
        } 
        return *this;
    }

    // Power, multipies the matrix by itself "pow" times
    SquareMat SquareMat::operator^(int pow) const {
        if (pow < 0){
            throw std::invalid_argument("Negative powers are not supported.");
        }
        
        SquareMat original(*this);

        // if "pow" is equal to 0, return the identity matrix
        if (pow == 0){
            for (int i = 0; i < this->size; i++){
                for (int j = 0; j < this->size; j++){
                    if (i == j) original.mat[i][j] = 1.0;
                    else original.mat[i][j] = 0.0;
                }
            } return original; 
        }
        //if "pow" = 1, return the matrix itself
        if(pow == 1){

            return  original;
        }

        else{

            SquareMat result (*this);

            for(int m = 1; m < pow; m++){
                SquareMat temp (*this);
                
                for (int i = 0; i < size; ++i) {
                    for (int j = 0; j < size; ++j) {
                        temp.mat[i][j] = 0;
                        for (int k = 0; k < size; ++k) {
                            temp.mat[i][j] += result.mat[i][k] * original.mat[k][j];
                        }
                    }
                }
                result = temp;
            }
            return result;
        }

    }

    //(*)
    SquareMat SquareMat:: operator*(double scalar) const{
        
        SquareMat res (this->size);

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
               res.mat[i][j] = this->mat[i][j] * scalar;
            }
        }  
        return res;
    }


    //(*=)
    SquareMat& SquareMat:: operator*=(double scalar) {
        
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
               this->mat[i][j] = this->mat[i][j] * scalar;
            }
        }  
        return *this;
    }

    SquareMat operator*(double scalar, const SquareMat& mat){
       
        return mat*scalar; //use privious function
    
    }


    //(/)
    SquareMat SquareMat:: operator/(double scalar) const{
        
        SquareMat res (this->size);

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
               res.mat[i][j] = this->mat[i][j] / scalar;
            }
        }  
        return res;
    }

    //(/=)
    SquareMat& SquareMat:: operator/=(double scalar){
    
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                this->mat[i][j] = this->mat[i][j] / scalar;
            }
        }  
        return *this;
    }

    //Performs modulo operation on each element in the matrix
    SquareMat SquareMat:: operator% (int mod) const{
        if (mod == 0){
            throw std::invalid_argument("C'ant do % by zero.");
        }

        SquareMat res(this->size);

        for(int i = 0; i < this->size; i++){
            for (int j = 0; j < this->size; j++){
                res.mat[i][j] = fmod(this->mat[i][j], mod);
            }
        }
        return res;
    }

    SquareMat& SquareMat:: operator%= (int mod){
        if (mod == 0){
            throw std::invalid_argument("C'ant do % by zero.");
        } 

        for(int i = 0; i < this->size; i++){
            for (int j = 0; j < this->size; j++){
                this->mat[i][j] = fmod(this->mat[i][j], mod);
            }
        }
        return *this;
    }


//Matrix-specific operations 

    //Transpose 
    SquareMat SquareMat:: operator~() const{
        SquareMat res (this->size);

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
               res.mat[j][i] = this->mat[i][j];
            }
        }  
        return res;
    }

    //Determinant
    double SquareMat:: operator!() const{
        
        if (this->size == 1){
            return this->mat[0][0];
        } 
        double det = 0.0;

        if (this->size == 2){
            det = mat[0][0] * mat[1][1] - mat[0][1]*mat[1][0];
            return det;
        }
 
        if (this->size > 2){
            for (int j = 0; j < this->size; j++) {
                SquareMat minor_mat = this->minor(0, j);
                double neg = -1;
                if (j % 2 == 0) neg = 1;
                double temp = neg * mat[0][j] * !minor_mat;
                det += temp;
            } 
            return det;
        }
        
            throw std::invalid_argument("invalide matrix sizes.");
    }

    //Minor, helper function for determinant calculation
    SquareMat SquareMat:: minor (int row, int col) const{
        SquareMat res (this->size - 1);
        
        int r = 0;
        
        for (int i = 0; i < this->size; i++){
        
            if (i == row) continue;
            int c = 0;

            for (int j = 0; j < this->size; j++){

                if (j == col) continue;

                res[r][c] = this-> mat[i][j];

                c++;
            } 
            r++;
        }
        return res;
    }


//Comparison operators

    //(==)
    bool SquareMat:: operator==(const SquareMat& other) const{
        double sum_mat_1 = this->find_sum();
        double sum_mat_2 = other.find_sum();

        if(sum_mat_1 == sum_mat_2){
            return true;
        }

        return false;
    }

    //(!=)
    bool SquareMat:: operator!=(const SquareMat& other) const{
        double sum_mat_1 = this->find_sum();
        double sum_mat_2 = other.find_sum();

        if(sum_mat_1 == sum_mat_2){
            return false;
        }

        return true;
    }

    //(<=)
    bool SquareMat:: operator<=(const SquareMat& other) const{
        double sum_mat_1 = this->find_sum();
        double sum_mat_2 = other.find_sum();

        if(sum_mat_1 <= sum_mat_2){
            return true;
        }

        return false;
    }

    //(>=)
    bool SquareMat:: operator>=(const SquareMat& other) const{
        double sum_mat_1 = this->find_sum();
        double sum_mat_2 = other.find_sum();

        if(sum_mat_1 >= sum_mat_2){
            return true;
        }

        return false;
    }

    //(>)
    bool SquareMat:: operator>(const SquareMat& other) const{
        double sum_mat_1 = this->find_sum();
        double sum_mat_2 = other.find_sum();

        if(sum_mat_1 > sum_mat_2){
            return true;
        }

        return false;
    }
    //(<)
    bool SquareMat:: operator<(const SquareMat& other) const{
        double sum_mat_1 = this->find_sum();
        double sum_mat_2 = other.find_sum();

        if(sum_mat_1 < sum_mat_2){
            return true;
        }

        return false;
    }

    //Finds the sum of the elements in the matrix, helper function for comparison operators
    double SquareMat:: find_sum() const{
        double sum = 0;

        for (int i = 0; i < this->size; i++){
            for (int j = 0; j < this-> size; j++){
                sum += this->mat[i][j];
            }
        } 
        return sum;
    }

    //Print the matrix
    std::ostream& operator<<(std::ostream& out, const SquareMat& mat){
        for (int i = 0; i < mat.size; i++){
            out<<std::endl;
            for (int j = 0; j < mat.size; j++){
                out<<mat[i][j]<<" ";
            }
        }
        std::cout << "Matrix ID: " << mat.id << "\n\n";
        return out;
    }




int SquareMat::ID = 1;

}