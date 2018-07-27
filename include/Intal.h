#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include <ctype.h>
#include <boost/multiprecision/cpp_int.hpp>

namespace patch
{
	// Reference: http://stackoverflow.com/a/20861692/5671364
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

using namespace std;

#ifndef INTAL_H
#define INTAL_H

class Intal {
	private:
		bool sign;
		string integer;
		string add(string num1, string num2);
		string subtract(string num1, string num2);
		string multiply(string num1, string num2);
		string division(string num1, string num2);
		string expo(string num1, string num2);
		bool equals(Intal &num1, Intal &num2);
		bool less(Intal num1, Intal num2);
		bool greater(Intal num1, Intal num2);
	public:
		Intal();
		Intal(string num);
		const bool& getSign();
		const string& getInteger();
		void setSign(bool s);
		Intal absolute();
		Intal operator + (Intal num);
		Intal operator - (Intal num);
		Intal operator * (Intal num);
		Intal operator ^ (Intal num);
		Intal operator / (Intal num);
		bool operator > (Intal num2);
		bool operator < (Intal num2);
		bool operator == (Intal &num2);
		friend ostream& operator << (ostream& os, const Intal& dt);
		void setInteger(string s);
		char getSignCharformat();
		
};

#endif
