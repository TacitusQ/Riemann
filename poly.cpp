#include "global.h"

Poly::Poly(int j) {
	n = j;
	term = new Frac[n];
}

Poly::~Poly() { delete [] term;}

Poly::Poly(const Poly &p) {
	n = p.n;
	term = new Frac[n];
	for(int j=0; j<n; j++) {
		term[j] = p.term[j];
	}
}

Poly& Poly::operator=(const Poly& rhs) 
{
	for(int j=0; j<n; j++) {
		term[j] = rhs.term[j];
	}

	return (Poly&) *this;
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
	//assume dim p = q
	size_t N = p.n;
	Poly t(N); //all 0 init
	
	int i,j;
	for (i=0; i<N; i++) {
		for (j=0; j< i+1; j++) {
			//fraction algebra
			t[i] += ( p[j] * q[i-j] );
		}
	}
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

// fills all terms with ones (not used)
void Poly::fill() {
	for(int i=0;i<n;i++) {
		term[i] = Frac(1, 1);
	}
}

// only constant non-zero
void Poly::fill1() {
	term[0] = Frac(1,1);
}

// exponential init
void Poly::fill2() {
	for(int i=0;i<n;i++) {
		term[i] = Frac( 1, fact(i) ); 
	}
}

// 1 - exp(-x) init
void Poly::fill3() {

	for(int i=1; i<n; i++) {
		term[i] = Frac( alt(i) , fact(i+1) );
	}
}

