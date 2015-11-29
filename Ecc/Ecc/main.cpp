/* 
   ELLIPTIC CURVE CRYPTOGRAPHY PROJECT
   FOR MATH 370 with Seth Dutter
   Project completed by Sam Goldberg and Sam Goers 
   11/30/15
*/

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

	return 0;
}

/*
 * Function to run all operations for Diffie-Hellman's Elliptic Curve cryptography simulation
*/
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

/*
 * Equation used to double a point with the given components.
 */
InfInt pointDoubler(InfInt x, InfInt y, char call) {

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
/*
InfInt getX(InfInt y) {

	InfInt u,v,w,x;
	//MAY NEED TO DO SOME OVERLOADING FOR POW FUNCTION
	u = (InfInt)pow(((InfInt)9 * (y*y) + ((InfInt)3).InfInt::intSqrt()*((InfInt)27 * (y*y*y*y)
		- (InfInt)1296 * (y*y) + 15556).InfInt::intSqrt() - 216), (1 / 3));
	v = ((InfInt)pow(2, (1 / 3))*(InfInt)pow(3, (2 / 3)));
	w = (InfInt)pow((2 / 3), (1 / 3));

	x = (u / v) - (w / u);

	return x;
}
*/

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

/*
 * Given our x obtain our point on the curve
*/
InfInt getPoint(int x) {

	double xx = pow(x, 3) + x + 24;
	xx = sqrt(xx);

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

/*
 * Application of fast exponentiation in order to multiply a very big number very quickly
 */
InfInt fastExponentiation(int mPlier, InfInt gX, InfInt gY) {

	int nn = mPlier;
	string bin;
	char holder = ' ';
	while (nn != 0) {
		holder = nn % 2 + '0';
		bin = holder + bin;
		nn /= 2;
	}

	//Prints binary
	//cout << bin << endl;

	//multiply g by bin
	int cc = bin.length();
	int ii = 0;
	InfInt resultX;
	InfInt resultY;

	for (cc;cc > 0;cc--) {
		if (bin.at(ii) == '1') {
			//cout << cc << endl;
			//Multiply g by 2^(c-1), add to result.

			//This is technically the slow version of point adding, 
			//is like: gX^cc + gX^cc + ...
			//needs : cc*g + cc*g+...
			resultX = resultX + (gX * (pow(2, (cc - 1)))); //Replace this with a normal point multiplier?
			//resultX = resultX % prime;
			resultY = resultY + (gY * (pow(2, (cc - 1)))); //Replace this with a normal point multiplier?
			//resultY = resultY % prime;
		}
		else if (bin.at(ii) == '0') {
			//cout << "zero/" << endl;
			//nothing
		}

		ii++;
	}

	return resultX, resultY; //How return point?
}

void curve() {//maybe turn this into a funtion that given input returns x, y, a, b, etc?
	//Y^2 = x^3 + x + 24 under prime P = 1267650600228229401496703205653
	//P = 1267650600228229401496703205653
}



