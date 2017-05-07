#include "global.h"
#include <stdlib.h>

int main(int argc, char** argv) {

	int N;
	if (argc > 1) 
		N = atoi(argv[1]);
	else N = 8;

	Poly a(N);
	Poly n(N);
	Poly x(N);
	
	n.fill1();
	a.fill3();
	x.fill1();

	cout << n << endl;

	for(int j=1; j<N; j++) {
		x *= a;
		n += x;
		cout << n << endl;
	}

	return 0;
}

/* Finds the greatest common factor (a,b)
 * to call use gcf(a,b,1) */
int gcf(int a, int b, int n) {

	if (a==b) return a;
	if (b>a)  return gcf(b,a,n);
	//WLOG assume a<b

	int j=1;
	while (j < a) { 
		j++; //allows for j=2

		if (a%j == 0 && b%j == 0) {
				return gcf(a/j, b/j, n*j);
		}
	} 
	return n;
}

/* factorial, returns j! */
int fact(int j) {

	int n = 1;
	while (j > 0) {
		n *= j;
		j--;
	}
	return n;
}

/* even: returns -1
   odd:  returns +1  */
int alt(int j) {

	if (j%2) return 1;
	else return -1;

}
