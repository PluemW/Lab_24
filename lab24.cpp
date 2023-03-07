#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

//Write your code here.
ComplexNumber operator+(double a,const ComplexNumber &c){
    return ComplexNumber(a+c.real, c.imag);
}

ComplexNumber operator-(double a,const ComplexNumber &c){
    return ComplexNumber(a-c.real, -c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	return ComplexNumber((real*c.real)-(imag*c.imag),(real*c.imag)+(imag*c.real));
}

ComplexNumber operator*(double a,const ComplexNumber &c){
    return ComplexNumber((a*c.real)-(0*c.imag),(a*c.imag)+(0*c.real));
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	return ComplexNumber(((real*c.real)+(imag*c.imag))/(pow(c.real,2)+pow(c.imag,2)),((imag*c.real)-(real*c.imag))/(pow(c.real,2)+pow(c.imag,2)));
}

ComplexNumber operator/(double a,const ComplexNumber &c){
    return ComplexNumber(((a*c.real)+(0*c.imag))/(pow(c.real,2)+pow(c.imag,2)),((0*c.real)-(a*c.imag))/(pow(c.real,2)+pow(c.imag,2)));
}

bool ComplexNumber::operator==(const ComplexNumber &c){
	if((real==c.real) && (imag==c.imag)) return 1;
	else return 0;
}

bool operator==(int a,const ComplexNumber &c){
	if((a==c.real) && (a==c.imag)) return 1;
	else return 0;
}

ostream & operator<<(ostream &os, const ComplexNumber &c){
    if(c.real!=0&&c.imag!=0){
        if(c.imag>0) return os << c.real << "+" << c.imag << "i";
        else return os << c.real << c.imag << "i";
    }
    else if(c.real==0&&c.imag!=0){  return os << c.imag <<"i";  }
    else if(c.real!=0&&c.imag==0){  return os << c.real ;  }
    else return os << 0;
}

double ComplexNumber::abs(){
    double ab = pow((pow(real,2)+pow(imag,2)),1/2.0);
    return ab;
}

double ComplexNumber::angle(){
    double res = atan2 (imag,real)*180/M_PI;
    return res;
}
