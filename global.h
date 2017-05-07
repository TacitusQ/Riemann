#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <iostream>

using namespace std;

int fact(int); 		
int gcf(int, int, int); 
int alt(int);

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
	Poly& operator+=(const Poly&);
	Poly& operator*=(const Poly&);
	Frac& operator[](int);
    const Frac& operator[](int i) const;
	
	friend ostream& operator<<(ostream& os, const Poly& p);
	friend Poly operator+(const Poly&, const Poly&);
	friend Poly operator*(const Poly&, const Poly&);

	void fill();
	void fill1(); //constant 1
	void fill2(); //exp(x) expansion
	void fill3(); //1 - exp(-x) expansion
	
  private:
	size_t n;
	Frac* term; //is this the best data type?
};

#endif
