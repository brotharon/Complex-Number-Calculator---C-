/* complex.cpp: contains the functions for the complex class. This class stores
*  two doubles, a real number and an imaginary number, and is capable of performing
*  various operations on these numbers.
*
*  author: Calvin Evans
*  version: 10/6/2017
*/
#include "complex.h"
#include <iostream>


// ADD
// takes in a complex object as a parameter and adds it to the stored complex.
// returns a complex that has stored the sum. 
complex complex::add(const complex& a) {
	complex t;

	t.realNumber = a.realNumber + realNumber;
	t.imagineNumber = a.imagineNumber + imagineNumber;

	return t;
}

// SUBTRACT
// takes in a complex object as a parameter and subtracts it from the stored complex.
// returns a complex that has stored the difference. 
complex complex::subtract(const complex& s) {
	complex t;

	t.realNumber = realNumber - s.realNumber;
	t.imagineNumber = imagineNumber - s.imagineNumber;

	return t;
}

// MULTIPLY
// takes in a complex object as a parameter and mutiplies it with the stored complex.
// returns a complex that has stored the product. 
complex complex::multiply(const complex& m) {
	complex t;

	t.realNumber = (m.realNumber * realNumber) - (m.imagineNumber *
		imagineNumber);
	t.imagineNumber = (m.imagineNumber * realNumber) + (m.realNumber *
		imagineNumber);

	return t;
}

// DIVIDE
// takes in a complex object as a parameter and divides it into the stored complex.
// returns a complex that has stored the quotient. 
complex complex::divide(const complex& v) {
	complex conj(v.realNumber, v.imagineNumber * -1);
	complex t1(realNumber, imagineNumber);
	if (conj.realNumber == 0) {
		cout << "Error: Division by 0" << endl;
		return *this;
	}
	t1 = t1 * conj;
	complex t2(v.realNumber, v.imagineNumber);
	t2 = t2 * conj;

	complex output(t1.realNumber / t2.realNumber, t1.imagineNumber / t2.realNumber);
	return output;
}

// CONJUGATE
// takes in no parameters. creates a new complex that is the conjugate of
// the stored complex. returns a complex that is the conjugate. in this 
// case conjugate means that the sign has been switched for the imaginary
// number stored in this complex. 
complex complex::conjugate() {
	complex t(realNumber, -(imagineNumber));
	return t;
}

// PRINTCOMPLEXNUM
// outputs the stored values of this complex object to the console
void complex::printComplexNum(complex out) {
	if (out.realNumber != 0) {
		cout << out.realNumber;
		cout << " ";
	}

	if (out.imagineNumber != 0) {
		if (out.imagineNumber < 0) {
			out.realNumber == 0 ? cout << "-" : cout << "- ";
			cout << -1 * out.imagineNumber;
			cout << "i";
		}
		else if (out.imagineNumber == 1) {
			out.realNumber == 0 ? cout << "+ i" : cout << "i";
		}
		else {
			out.realNumber == 0 ? cout << "" : cout << "+ ";
			cout << out.imagineNumber;
			cout << "i";
		}
	}

	if (out.realNumber == 0 && out.imagineNumber == 0) {
		cout << 0;
	}
}

// GETIMAGINARY
// takes in no arguments. returns a copy of the double stored as the imaginary
// number of this complex object.
double complex::getImaginary() {
	return imagineNumber;
}

// GETREAL
// takes in no arguments. returns a copy of the double stored as the real
// number of the complex object. 
double complex::getReal() {
	return realNumber;
}

// OPERATOR+
// overloads the + operator to conduct the same operation as the add function
// of the complex class. returns a complex object that has stored the sum of
// the added objects. 
complex complex::operator+ (const complex& add) const {
	complex t;

	t.realNumber = add.realNumber + realNumber;
	t.imagineNumber = add.imagineNumber + imagineNumber;

	return t;
}

// OPERATOR*
// overloads the * operator to conduct the same operation as the multiply function
// of the complex class. returns a complex object that has stored the product of
// the two objects. 
complex complex::operator* (const complex& multiply) const {
	complex t;

	t.realNumber = (multiply.realNumber * realNumber) - (multiply.imagineNumber *
		imagineNumber);
	t.imagineNumber = (multiply.imagineNumber * realNumber) + (multiply.realNumber *
		imagineNumber);

	return t;
}

// OPERATOR-
// overloads the - operator to conduct the same operation as the subtract function
// of the complex class. returns a complex object that has stored the difference of
// the two objects. 
complex complex::operator- (const complex& subtract) const {
	complex t;

	t.realNumber = realNumber - subtract.realNumber;
	t.imagineNumber = imagineNumber - subtract.imagineNumber;

	return t;
}

// OPERATOR/
// overloads the / operator to conduct the same operation as the divide function
// of the complex class. returns a complex object that has stored the quotient of
// the two objects.
complex complex::operator/ (const complex& divide) const {
	complex conj(divide.realNumber, divide.imagineNumber * -1);
	complex t1(realNumber, imagineNumber);
	t1 = t1 * conj;
	if (conj.realNumber == 0) {
		cout << "Error: Division by 0" << endl;
		return *this;
	}
	complex t2(divide.realNumber, divide.imagineNumber);
	t2 = t2 * conj;

	complex output(t1.realNumber / t2.realNumber, t1.imagineNumber / t2.realNumber);
	return output;
}

complex complex::operator/ (const double& divide) const {
	complex t1(realNumber, imagineNumber);
	t1.realNumber /= divide;
	t1.imagineNumber /= divide;
	return t1;
}

// OPERATOR*=
// overloads the *= operator to multiply the parameter to the total of the stored
// object. returns a complex object that has stored the product of the two objects. 
complex& complex::operator*= (const complex& mEquals) {
	*this = this->multiply(mEquals);
	return *this;
}

// OPERATOR+=
// overloads the += operator to add the parameter to the total of the stored
// object. returns a complex object that has stored the sum of the two objects. 
complex& complex::operator+= (const complex& aEquals) {
	*this = this->add(aEquals);
	return *this;
}

// OPERATOR-=
// overloads the -= operator to subtract the parameter from the total of the stored
// object. returns a complex object that has stored the difference of the two objects. 
complex& complex::operator-= (const complex& sEquals) {
	*this = this->subtract(sEquals);
	return *this;
}

// OPERATOR/=
// overloads the /= operator to divide the parameter into the total of the stored
// object. returns a complex object that has stored the quotient of the two objects. 
complex& complex::operator/= (const complex& dEquals) {
	*this = this->divide(dEquals);
	return *this;
}

complex& complex::operator/= (const double& dEquals) {
	*this = this->divide(dEquals);
	return *this;
}

// OPERATOR==
// overloads the == operator to compare the stored variables of the parameter against
// this complex object. Returns true if they are equal and false if they are not. 
bool complex::operator== (const complex isEqual) {
	return (realNumber == isEqual.realNumber && imagineNumber == isEqual.imagineNumber);
}

// OPERATOR!=
// overloads the != operator to compare the stored variables of the parameter against
// this complex object. Returns true if they are not equal and false if they are. 
bool complex::operator!= (const complex notEqual) {
	return (realNumber != notEqual.realNumber || imagineNumber != notEqual.imagineNumber);
}

// OPERATOR<<
// overloads the << operator to create an output stream formatted to real +/- imaginary. 
// if the real or imaginary are 0 it does not output a value for the 0. If both are 0
// it outputs 0. if the imaginary is equal to 1 or -1 it only outputs i or -i.
ostream& operator << (ostream &outStream, const complex &output) {
	outStream << " ";
	if (output.realNumber != 0.0)
		outStream << output.realNumber;
	if (output.realNumber == 0.0 && output.imagineNumber == 0.0)
		outStream << "0";

	if (output.imagineNumber != 0.0)
	{
		if (output.imagineNumber < 0.0)
		{
			if (output.realNumber == 0.0)
			{
				outStream << "-";
			}
			else
			{
				outStream << " - ";
			}
			if (output.imagineNumber != -1) {
				outStream << -output.imagineNumber;
			}
		}
		else
		{
			if (output.realNumber != 0.0)
				outStream << " + ";
			if (output.imagineNumber != 1)
				outStream << output.imagineNumber;
		}
		outStream << 'i';
	}
	return outStream;

}

// OPERATOR>>
// Overloads the >> operator to take in the next 2 doubles and returns
// these values in the input stream. Will input default values if the 
// input is not two doubles. 
istream& operator>>(istream	&inStream, complex &input)
{
	inStream >> input.realNumber >> input.imagineNumber;
	return inStream;

}


