/*
 * Nearly everything in mathematics and statistical analysis
 * is based on matrices. This is a workhorse structure for
 * many applications.
 *
 * The matrices created with this structure can be defined
 * in familiar Matlab and Mathematica style.
 *
 * Matrices can be multidimensional and easly operated by
 * familiar C array addresing.
 *
 */

#ifndef MATRIX_H
#define MATRIX_H


#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>
#include <sstream>

#include "common.h"
#include "matrix/matrix.hpp"

#define MatrixN Matrix<T>


// optimization definitions
//#define _eye(a) #if (a==2) ? [1,0;0,1] : eye(a)
#include <boost/algorithm/string.hpp>


namespace Matrix {
using namespace std;

template<typename T>
struct Matrix { // public access

    int dim = 0;
    vector<int> dims;

    vector<T> buf;

    // convert string to matrix with matlab notation
    Matrix(const char *chrMatrix)
    {
        std::string strMatrix(chrMatrix);
        std::string s(strMatrix);
        std::regex e ("\\[(\\d+[\\.\\,\\;]?)+\\]");

        if (std::regex_match (s,e))
        {
            // strip strings cols and rows
            std::vector<std::string> strs,strs2;
            int lenght=0;
            boost::split(strs, s, boost::is_any_of("[];"));

            std::regex z ("^((\\d)+(\\.)?(\\d)*(\\,)?)+$");

            for(vector<std::string>::iterator it = strs.begin(); it != strs.end(); ++it)
            {
                if ( std::regex_match ( *it, z) )
                {
                    strs2.push_back(*it);
                    lenght++;
                }
            }
            dim++;
            dims.push_back(lenght);

            // find numbers and convert
            std::smatch sm;
            std::regex n ("^(\\d)+(\\.)?(\\d)*$");
            int i;

            for(vector<std::string>::iterator it = strs2.begin(); it != strs2.end(); ++it)
            {
                if ( std::regex_match ( *it, sm,  n) )
                {
                    istringstream iss(sm[0]);
                    iss >> i;
                    buf.push_back( i );
                }
            }

        } else
            std::cout << endl << "-- matrix error --";

    }

    void set(int i, int j, T val)
    {
        buf[i*dims[1]+j] = val;
    }

    inline void add(const MatrixN &A)
    {

    }
    inline void sub(const MatrixN &A) {}

    inline void inc(const MatrixN &A) {}
    inline void dec(const MatrixN &A) {}

    inline void multi(int skalar) // multiply by scalar value
    {
        for(typename vector<T>::iterator it=buf.begin(); it!=buf.end(); ++it)
            *it *= skalar;
    }
    inline void multi(const MatrixN &A)
    {
        x(A);
    }
    inline void x(const MatrixN &A) // multiply by other matrix
    {

    }
    inline void t() // transposition the matrix
    {
        vector<T> tmpM;

        for(int i=0; i < dim; ++i)
            for(int j=0; j < dims[i]; ++j)
                tmpM.push_back( buf.get() );

        buf.clear();

        for(typename vector<T>::iterator it=tmpM.buf.begin(); it!=tmpM.buf.end(); ++it)
            buf.push_back(*it);
    }


    inline void transposition(const MatrixN &A) // same function different name
    {
        t(A);
    }

    const MatrixN &operator+(const MatrixN &A) const {}
    const MatrixN &operator-(const MatrixN &A) const {}
    const MatrixN &operator*(const MatrixN &A) const {}
    const MatrixN &operator=(const MatrixN &A) const {}
    const MatrixN &operator=(const char *strMatrix) const
    {
        //cout << strMatrix << endl;
    }

    T &operator()(int i, int j) {
        return buf[i*dims[1]+j];
    }

    T &operator[](const int idx)
    {
        cout << idx << endl;
        return idx;
    }
    const T &operator[](const int idx) const
    {
        cout << idx << endl;
        return idx;
    }
    bool operator==(const MatrixN &A) const {}
    void operator<<(const char ) {}
};

template<typename T>
const MatrixN &zero(int dim); // square matrix 0 filled

template<typename T>
const MatrixN &eye(int dim); // square matrix with 1 on diagonal

template<typename T>
int det(MatrixN A); // determinant of matrix A

template<typename T>
inline const MatrixN &Transpose(const MatrixN &A);

template<typename T>
inline const MatrixN &add(const MatrixN &A, const MatrixN &B);

template<typename T>
inline const MatrixN &sub(const MatrixN &A, const MatrixN &B);

template<typename T>
inline const MatrixN &x(const MatrixN &A, const MatrixN &B);

template<typename T>
inline const MatrixN &multi(const MatrixN &A, int scalar);
}

#endif // MATRIX_H
