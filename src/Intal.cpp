#include "../include/Intal.h" 

//PRIVATE FUNCTIONS
string Intal::add(string num1, string num2) {

	// Reference: http://stackoverflow.com/a/14578764/5671364
	string add = (num1.length() > num2.length()) ? num1 : num2;
	char carry = '0';
	int offset = abs( (int)(num1.size() - num2.size()) );

	// padding
	if(num1.size() > num2.size())
	num2.insert(0, offset, '0');

	else
	num1.insert(0, offset, '0');

	for(int i = num1.size() - 1; i >= 0; i--) {
		add[i] = ((carry - '0') + (num1[i] - '0') + (num2[i] - '0')) + '0';

		if(i != 0) {
			if(add[i] > '9') {
				add[i] -= 10;
				carry = '1';
			} else
			carry = '0';
		}
	}

	if(add[0] > '9') {
		add[0]-= 10;
		add.insert(0,1,'1');
	}

	return add;
}

string Intal::subtract(string number1, string number2) {

	// Reference: http://www.dreamincode.net/forums/topic/343469-how-to-subtract-two-string-containing-numbers/
	string sub = (number1.length() > number2.length())? number1 : number2;
	int offset = abs( (int)(number1.size() - number2.size()) );

	if(number1.size() > number2.size())
	number2.insert(0, offset, '0');

	else
	number1.insert(0, offset, '0');

	for(int i=number1.length()-1; i>=0; --i)
	{
		if(number1[i] < number2[i])
		{
			number1[i] += 10;
			number1[i-1]--;
		}
		sub[i] = ((number1[i]-'0')-(number2[i]-'0')) + '0';
	}

	while(sub[0]=='0' && sub.length()!=1) // erase leading zeros
	sub.erase(0,1);

	return sub;
}

#if 0 // With boost
string Intal::multiply(string num1, string num2) {
	boost::multiprecision::cpp_int s1(num1);
	boost::multiprecision::cpp_int s2(num2);
	boost::multiprecision::cpp_int S=s1/s2;
	return patch::to_string(S);
}
#endif

#if 0 // With karat
Intal karat(Intal X, Intal Y) {
	int n = (X > Y) ? X.getInteger().length() : X.getInteger().length();

	if(n < 10)
	return X*Y;

	int fh = n/2;
	int sh = (n-fh);

	string xl_str = X.getInteger().substr(0, fh);
	string xr_str = X.getInteger().substr(fh, sh);
	string yl_str = Y.getInteger().substr(0, fh);
	string yr_str = Y.getInteger().substr(fh, sh);

	xl_str = xl_str.erase(0, xl_str.find_first_not_of('0'));
	xr_str = xr_str.erase(0, xr_str.find_first_not_of('0'));
	yl_str = yl_str.erase(0, yl_str.find_first_not_of('0'));
	yr_str = yr_str.erase(0, yr_str.find_first_not_of('0'));

	Intal Xl = Intal(xl_str);
	Intal Xr = Intal(xr_str);

	Intal Yl = Intal(yl_str);
	Intal Yr = Intal(yr_str);

	// cout << "Xl: "<< Xl << "Xr: " << Xr << "Yl: " << Yl << "Yr: " << Yr << " ";

	// cout << Intal(X.getInteger().substr(0, fh)) << " ";
	// cout << X.getInteger().substr(fh, sh);

	//.erase(0, str.find_first_not_of('0'));

	Intal P2 = karat(Xr, Yr);
	Intal P1 = karat(Xl, Yl);
	Intal P3 = karat(Xl+Xr, Yl+Yr);

	// Intal P2 = Xr * Yr;
	// Intal P1 = Xl * Yl;
	// Intal P3 = (Xl+Xr) * (Yl+Yr);

	// cout << P1 << " " << P2 << " " << P3;
	return (P1*(Intal("10") ^ Intal(patch::to_string(n)))) + (P3 - P1 - P2)*(Intal("10") ^ Intal(patch::to_string(fh))) + P2;

}
#endif

string Intal::multiply(string num1, string num2) {

	if(num1.length() > num2.length())
	num1.swap(num2);

	string res = "0";
	for(int i=num1.length()-1; i>=0; --i) {
		string temp = num2;
		int currentDigit = num1[i]-'0';
		int carry = 0;

		for(int j=temp.length()-1; j>=0; --j) {
			temp[j] = ((temp[j]-'0') * currentDigit) + carry;

			if(temp[j] > 9) {
				carry = (temp[j]/10);
				temp[j] -= (carry*10);
			} else
			carry = 0;

			temp[j] += '0';
		}

		if(carry > 0)
		temp.insert(0, 1, (carry+'0'));

		temp.append((num1.length()-i-1), '0');

		res = add(res, temp);
	}

	while(res[0] == '0' && res.length()!=1)
	res.erase(0,1);

	return res;
}

string Intal::division(string num1, string num2) {

	//Reference: https://www.quora.com/How-do-I-multiply-two-large-numbers-stored-as-strings-in-the-C-C++-language
	boost::multiprecision::cpp_int s1(num1);
	boost::multiprecision::cpp_int s2(num2);
	boost::multiprecision::cpp_int S=s1/s2;
	return patch::to_string(S);
}

string Intal::expo(string num1, string num2) {
	// Assume num2 is +v
	string e = num2;
	string m = num1;
	while(Intal(e = (subtract(e, "1"))) > Intal("0")) {
		m = multiply(m, num1);
	}

	return m;
}

bool Intal::less(Intal &num1, Intal &num2) {
	bool sign1 = num1.getSign();
	bool sign2 = num2.getSign();

	if(sign1 && ! sign2)
	return true;

	else if(! sign1 && sign2)
	return false;

	else if(!sign1) {
		if(num1.getInteger().length() < num2.getInteger().length() )
		return true;
		if(num1.getInteger().length() > num2.getInteger().length() )
		return false;
		return num1.getInteger() < num2.getInteger();
	} else {
		if(num1.getInteger().length() > num2.getInteger().length())
		return true;
		if(num1.getInteger().length() < num2.getInteger().length())
		return false;
		return num1.getInteger().compare( num2.getInteger() ) > 0;
	}
}

bool Intal::equals(Intal &num1, Intal &num2) {
	return num1.getInteger() == num2.getInteger() && num1.getSign() == num2.getSign();
}

bool Intal::greater(Intal &num1, Intal &num2) {
	return ! equals(num1, num2) && ! less(num1, num2);
}

// PUBLIC FUNCTIONS
Intal::Intal() {
	integer = "0";
	sign = false;
}

Intal::Intal(string s) {
	if(isdigit(s[0])) {
		setInteger(s);
		sign = false;
	}
	else {
		setInteger(s.substr(1));
		sign = (s[0] == '-') ? true : false;
	}
}

const bool& Intal::getSign() {
	return sign;
}

void Intal::setSign(bool s) {
	sign = s;
}

const string& Intal::getInteger() { // retrieves the number
	return integer;
}

void Intal::setInteger(string s) {
	integer = s;
}

Intal Intal::absolute() {
	return Intal( getInteger() );
}
Intal Intal::operator + (Intal &number) {

	//Reference: https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm
	Intal sum;
	if( getSign() == number.getSign() )
	{
		sum.setInteger( add(getInteger(), number.getInteger() ) );
		sum.setSign( getSign() );
	}
	else
	{
		if( absolute() > number.absolute() )
		{
			sum.setInteger( subtract(getInteger(), number.getInteger() ) );
			sum.setSign( getSign() );
		}
		else
		{
			sum.setInteger( subtract(number.getInteger(), getInteger() ) );
			sum.setSign( number.getSign() );
		}
	}
	if(sum.getInteger() == "0")
	sum.setSign(false);

	return sum;
}

Intal Intal::operator - (Intal &num2) {

	//Reference: https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm
	num2.setSign( ! num2.getSign() );
	return (*this) + num2;
}

Intal Intal::operator * (Intal &num2) {

	//Reference: https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm
	Intal mul;

	mul.setInteger( multiply(getInteger(), num2.getInteger() ) );
	mul.setSign( getSign() != num2.getSign() ? 1 : 0 );

	if(mul.getInteger() == "0")
	mul.setSign(false);

	return mul;
}

#if 1 //Boost
Intal Intal::operator / (Intal &num2) {
	//Reference: https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm
	Intal mul;

	mul.setInteger( division(getInteger(), num2.getInteger() ) );
	mul.setSign( getSign() != num2.getSign() ? 1 : 0 );

	if(mul.getInteger() == "0")
	mul.setSign(false);

	return mul;
}
#endif

#if 0 // Slow
Intal Intal::operator / (Intal &num2) {

	if(num2 == Intal("0")) {
		cout << "Error: Divide by zero";
		return Intal("-1");
	}

	Intal dividend(getInteger()); // copy of self, handles aliasing
	Intal tempDivisor(num2);
	Intal quotient("0");

	while(dividend > tempDivisor || dividend == tempDivisor) {
		dividend = dividend - tempDivisor;
		quotient = quotient + Intal("1");
	}

	quotient.setSign(getSign() != num2.getSign());

	return quotient;

}
#endif

Intal Intal::operator ^ (Intal &num2) {
	//Reference: https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm
	Intal res;
	res.setInteger(expo(getInteger(), num2.getInteger()));
	return res;
}

bool Intal::operator < (Intal &num2) {
	//Reference: https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm
	return less((*this) , num2);
}

bool Intal::operator > (Intal number) {
	//Reference: https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm
	return greater((*this) , number);
}

bool Intal::operator == (Intal &num2) {
	//Reference: https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm
	return (bool)equals((*this) , num2);
}

ostream& operator << (ostream& os, const Intal& I) {

	//Reference: https://msdn.microsoft.com/en-us/library/1z2f6c2k.aspx
	os << ((I.sign) ? '-' : ' ') << I.integer;
	return os;
}

char Intal::getSignCharformat() {
	return sign ? '-' : '+';
}
