/* complex.h: contains the declarations for the complex class. This class stores
*  two doubles, a real number and an imaginary number, and is capable of performing
*  various operations on these numbers.
*
*  author: Calvin Evans
*  version: 10/6/2017
*/

#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;

class complex {                           
public:
	// CONSTRUCTOR
	// Capable of taking in 0, 1, or 2 parameters. Default value of 0, 0 if no input.
	// if only one input it is placed in the real number container. 
	complex(double real = 0, double imaginary = 0)
		:realNumber(real), imagineNumber(imaginary) {}           

	// ARITHMATIC FUNCTIONS
	// these functions contain the algorithms to perform these basic arithmatic functions
	// on a pair of complex numbers. 
   complex add(const complex &);
   complex subtract(const complex &);
   complex multiply(const complex &);
   complex divide(const complex &);

   // CONJUGATE
   // The conjugate of a complex number is required to divide two complex numbers
   complex conjugate();

   // PRINTCOMPLEXNUM
   // A basic print function for the complex class
   void printComplexNum(complex output);

   // GETTERS
   // allow you to get copies of the values stored in the complex class
   double getReal();
   double getImaginary();

   // ARITHMATIC OPERATORS
   // overload the basic arithmatic operators to provide similar functionality
   // when used with two complex objects
   complex operator + (const complex& add)const;
   complex operator - (const complex& subtract)const;
   complex operator / (const complex& divide)const;
   complex operator / (const double& divide)const;
   complex operator * (const complex& multiply) const;

   // COMPLEX ASSIGNMENT OPERATORS
   // overload the complex assignment operators to provide the expected
   // functionality when used with two complex objects
   complex& operator += (const complex& aEquals);
   complex& operator -= (const complex& sEquals);
   complex& operator /= (const complex& dEquals);
   complex& operator /= (const double& dEquals);
   complex& operator *= (const complex& mEquals);

   // COMPARISON OPERATORS
   // overload the comparison operators to provide the expected functionality
   // when used with two complex objects
   bool operator == (const complex isEqual);
   bool operator != (const complex notEqual);

   // IN/OUT STREAM OPERATORS
   // overload the input and output stream operators to provide the expected
   // functionality for the complex object
   friend ostream& operator << (ostream &outStream, const complex &output);
   friend istream& operator >> (istream &inStream, complex &input);

private:
	// STORED VARIABLES
	// these two doubles represent the values for the real number and the 
	// imaginary number of the complex number stored in the complex object
   double realNumber;
   double imagineNumber;
       
};

#endif

