#include "global.h"

Poly::Poly(int j) {
	n = j;
	term = new Frac[n];
}

void Poly::fill() {
	for(int i=0;i<n;i++) {
		term[i] = Frac(1, 1);
	}
}

void Poly::fill1() {
	(this->term)[0] = Frac(1,1);
}

void Poly::fill2() {
	for(int i=0;i<n;i++) {
		term[i] = Frac( 1, fact(i) ); 
	}
}

void Poly::fill3() {

	size_t N = this->n;
	for(int i=1; i<N; i++) {
		(this->term)[i] = Frac( alt(i) , fact(i+1) );
	}
}


ostream& operator<<(ostream& os, const Poly& p) 
{
	Frac f;
	for (int i=0; i < p.n; i++) {
	
		f = p.term[i];
		if (f.a == 0) {
			os << "[ 0 ]"; 
			continue;
		}
		
		if ( (f.a % f.b) == 0 ) {
			if (f.b == 0) {
				cerr << f << endl;
				exit(1);
			}
			os << "[ " << f.a/f.b << " ]";
			continue;
		}
		os << f << " ";
	}
	return os;
}

Poly operator+(const Poly& p, const Poly& q) 
{
	//assume p = q
	size_t N = p.n;
	Poly t(N); //all 0 init
	
	int i;
	for (i=0; i<N; i++) {
		t[i] += (p[i] + q[i]);
	}
	return t;
}
	
Poly operator*(const Poly& p, const Poly& q) 
{
	//assume p = q
	size_t N = p.n;
	Poly t(N); //all 0 init
	
	int i,j;
	for (i=0; i<N; i++) {
		for (j=0; j< i+1; j++) {
			//fraction algebra
			t[i] += ( p[j] * q[i-j] );
			//cout << p[j] << " " << q[i-j] << endl;
		}
	}
	
	//cerr << "finished +=" << endl;
	return t;
}

Poly& Poly::operator+=(const Poly& rhs) {

	*this = *this + rhs;
	return (Poly &)*this;
}

Poly& Poly::operator*=(const Poly& rhs) {

	*this = *this * rhs;
	return (Poly &)*this;
}
