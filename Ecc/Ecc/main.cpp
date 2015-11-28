#define INFINF_USE_EXCEPTIONS

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <stack>

#include "Infint.h"

using namespace std;


int fastExponentiation(int mPlier, int g);
InfInt getPoint(int x);
InfInt pointAdder(InfInt x1, InfInt y1, InfInt x2, InfInt y2, char component);
InfInt getY(InfInt x);
#define RAND_MAX = 1267650600228229401496703205653;

int main() {

	InfInt p = "1267650600228229401496703205653";
	InfInt x3, y3;
	InfInt x1 = 5, y1 = 4, x2 = 7, y2 = 12;
	char xComponent = 'x', yComponent = 'y';

	//create the seed we need for "true" random x's
	srand(time(NULL));

	//TEST PROMPT for getting a random point
	int x = rand();
	cout << ("Given x: ") << (x) << endl <<endl;
	InfInt y;
	
	//TEST to get an exact point, not a decimal value

		y = getPoint(x);
		cout << ("Our point is: (") << (x) << (",") << (y) << (")") << endl;

	//POINT ADDER TEST-------------------------------------------------------------------
	/*	cout << endl << endl << ("POINT ADDER TEST") << endl;
		x3 = pointAdder(x1, y1, x2, y2, xComponent);
		y3 = pointAdder(x1, y1, x2, y2, yComponent);

		cout << endl << ("Point x3: ") << (x3) << endl << ("Point y3: ") << (y3) << endl;
	*/

	//getY() TEST------------------------------------------------------------------------
	/*InfInt testX = 4, w;
	w = getY(testX);

	cout << ("OUR NEW POINT: ") << (testX) << (",") << (w) << endl;
	*/

	//cout << (255 - (pow(2, 7)));

	//fastExponentiation(250, 0); //works, but finishing need work.


	////Demos
	//Getting X and Y coordinates of a point
	//Adding a point to itself
	//Getting a generator of the curve
	//Fast exponentiation
	//DHECC!!!

	//system("pause");
	return 0;
}


int dhecc(/**/) {
	//This function is for the Diffy-Hellman Key exchange w/ ECC

	////this may be wrong as is, I believe I must change it such that 
	////g is different? Must research.

	////Bob and Sarah each have g,(a value on the curve?), and their own key, K and L respectively. //?
	/** InfInt g = getGenerater(); //?
	 *  Int kk = rand();//?
	 *  Int ll = rand();//?
	 */
	////Bob is trying to send Sarah lesser encryption key, M
	int m = 8;

	////Bob sends Sarah Kg, and Sarah sends back Lg
	//Infint gK = kk * g; //These'll probably use Fast exponentiation
	//InfInt gL = ll * g; //These'll probably use Fast exponentiation

	////Bob multiplies (K)Lg and Sarah multiplies (L)Kg
	//InfInt gKL = gL * kk; //These'll probably use Fast exponentiation
	//InfInt gLK = gK * ll; //These'll probably use Fast exponentiation

	////Bob then adds M + KLg and sends it to Sarah
	//InfInt gKLm = m + gKL;

	////After receiving M+KLg, Sarah subtracts M+KLg-LKg to get M
	//int n = gKLm - gLK;
	int n = 0;
	////Sarah now has encryotion key M, and an onlooker, say Sneaks McGeeks,
	////only has knowledge of Kg, Lg, and M+KLg which cannot be easily used to
	////solve the encryption.
	
	return n;
}


InfInt pointDoubler(InfInt x, InfInt y, char call) {
	//This should be just the equation for doubling a point.

	InfInt l = 0; //Lambda
	int a = 24; //?
	
	//Lambda = 3x(p)^2+a/2y(p)
	l = (((x*x)*3 )+ a) / (y*2);
	//X(r)=Lambda^2 + x(p)
	InfInt xd = (l*l) + x;
	//Y(r)=Lambda[x(p)]-y(p)
	InfInt yd = (l*x) - y;

	if (call == 'x') { // if error try = //?
		return xd;
	}
	else if (call == 'y') { // if error try = //?
		return yd;
	}
	else {
		return 0;
	}
}

/*
 * Given component y, get x;
 */
double getX(int y) {

	double x;
	x = 0;
	return x;
}

/*
* Given component x, get y;
*/
InfInt getY(InfInt x) {

	InfInt y;

	y = (x*x*x) + x + 24;

	y = y.InfInt::intSqrt();

	return y;
}

/* 
 * Adds two points together component wise to get a new component for given point
*/
InfInt pointAdder(InfInt x1, InfInt y1, InfInt x2, InfInt y2, char component) {
	InfInt x3, y3;

	x3 = x1 + x2;
	y3 = y1 + y2;

	if (component == 'x') {
		return x3;
	}
	else if (component == 'y') {
		return y3;
	}
	else {
		cout << ("ERROR: Only use x or y for component request");
		return 0;
	}
}

InfInt getPoint(int x) {

	double xx = pow(x, 3) + x + 24;

	xx = sqrt(xx);
	cout << (xx) << endl;
	//if (xx == int(xx)) {
	//	y = int(xx);

	//} else {
	//	cout << ("Failed!");
	//		y = NULL;
	//}
	//InfInt y = xxx.InfInt::intSqrt();
	long long y = xx;
	return InfInt(y);
}
int getGenerator() {
	//Generate a point that generates the curve.
	////Does any point work? If not, what qualities does
	////the point need?
	return 0;
}

int fastExponentiation(int mPlier, int g) {
	//Multiply a big number fast. Like,
	//Given 100g, break up the coefficient
	//into binary, then multiply that by g?
	//Note: need a little more research on topic.
	int remainder = 0;
	int pp = 7;
	stack<int> bin = {};

	if (mPlier<256) { //Limit of 255? (2^7) //in progress
		do
		{
			if ((mPlier - (pow(2, pp)))>=0) {
				mPlier = mPlier - (pow(2,pp));
				remainder = mPlier;
				pp--;
				bin.push(1);
			}
			else if(remainder = 0 && pp>0) {
				for (pp;pp > 0;pp--) {
					bin.push(0);
				}
			}

		} while (remainder != 0);
	}
	else {
		printf("Error: Multiplier too big (<255)");
	}

	for (pp;pp > 0;pp--) {
		bin.push(0);
	}
	
	for (int ii = 7;ii >= 0;ii--) {
		int qq = bin.top();
		bin.pop();
		cout << qq;
	}

	//multiply g by bin

	return 0;
}

void curve() {//maybe turn this into a funtion that given input returns x, y, a, b, etc?
	//Y^2 = x^3 + x + 24 under prime P = 1267650600228229401496703205653
	//P = 1267650600228229401496703205653
}



