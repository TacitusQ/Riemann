#include "global.h"

Frac::Frac() { a=0; b=1; }

Frac::Frac(int n1, int n2) {
	a = n1;
	b = n2;

	reduce();
}

void Frac::reduce() {
//Frac& Frac::reduce() {

	int n = gcf(a,b,1);
	a = a/n;
	b = b/n;

}


Frac operator+(const Frac& f, const Frac& g) 
{
	int c = (f.a*g.b) + (f.b*g.a);
	int d = f.b * g.b;

	return Frac(c,d);
}

Frac operator-(const Frac& f, const Frac& g) 
{
	int c = (f.a*g.b) - (f.b*g.a);
	int d = f.b * g.b;

	return Frac(c,d);
}

Frac operator*(const Frac& f, const Frac& g) 
{
	int c = f.a * g.a;
	int d = f.b * g.b;

	return Frac(c,d);
}

ostream& operator<<(ostream& os, const Frac& f) 
{
	os << "[ " << f.a
	   << "/"<< f.b
   	   << " ]" ;

	return os;
}

Frac& Frac::operator=(const Frac& f) 
{
	a = f.a;
	b = f.b;

	//need I deallocate prexisting stuff first?
	//no, y menya tol'ka primative!

	return *this; 
}

Frac & Frac::operator+=(const Frac& that) 
{
	*this = (*this + that);
	return *this;
}

Frac& Poly::operator[](int i) {

	if (i > n) {
		perror("Poly() Term");
		Frac *blank = new Frac(); // messy, I just want to return a 0
		return *blank; 
	}

	return term[i];
}

const Frac& Poly::operator[](int i) const {

	//return ( *this )[i];
	return ( (Poly&)*this )[i];
}

