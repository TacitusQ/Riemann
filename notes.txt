5 May 2017

Lots of ground covered

class Frac;
class Poly;

class Frac {
	
	public:
	Frac();
	Frac(int,int);
	Frac& operator=(const Frac&);
	Frac& operator+=(const Frac&);
	
	friend Frac operator+(const Frac&, const Frac&);
	friend Frac operator-(const Frac&, const Frac&);
	friend Frac operator*(const Frac&, const Frac&);

	friend ostream& operator<<(ostream& os, const Frac& f);
	friend ostream& operator<<(ostream& os, const Poly& p);

	void reduce();

	private:
	int a, b;

};

class Poly {

	public:
	Poly(int n);
	Frac& operator[](int);
    const Frac& operator[](int i) const;

	friend ostream& operator<<(ostream& os, const Poly& p);
	friend Poly operator*(const Poly&, const Poly&);

	void fill();
	void fill2();
	
	private:
	size_t n;
	Frac* term; //is this the best data type?
};

This was FANTASTIC exercise for the final

I learned about 
member:
 Frac& operator=(const Frac&);
 Frac& operator+=(const Frac&);

friend:
 ostream& operator<<(ostream& os, const Frac& f);

friends are just random functions which are allowed to touch privates
members must be declared with Class::Function, and this gives them a THIS pointer param automatically

Frac& operator[](int);
const Frac& operator[](int) const;

OK, so I get that ONLY const funcs are allowed to act on const objs
but Why is 'const' put where it is in terms of syntax?
-> Suhyun, can you explain this in terms of C 5.11

Also I learned this funky technicality
const Frac& Poly::operator[](int i) const 
{
	return ( (Poly&)*this )[i];
}


---
NEXT Step:
implement gcf for reduce (called before cout << )
add operator+ for Polynomials
make up some more P generators, and try my hand at 1/12

Where did pi/90 come from? That's zeta(4) right?


----
Split program into separately compiled Parts
when did Makefile
CC = g++

???

