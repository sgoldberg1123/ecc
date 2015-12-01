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
#include "InfInt.h"
#include "ttmath.h"

using namespace std;


ttmath::Big<1,2> prime = "1267650600228229401496703205653";
ttmath::Big<1,2> fastExponentiation(int mPlier, ttmath::Big<1,2> gX, ttmath::Big<1,2> gY, char cVar);
ttmath::Big<1,2> getPoint(int x);
ttmath::Big<1,2> pointAdder(ttmath::Big<1,2> x1, ttmath::Big<1,2> y1, ttmath::Big<1,2> x2, ttmath::Big<1,2> y2, char component);
ttmath::Big<1,2> getY(ttmath::Big<1,2> x);
ttmath::Big<1,2> getGenerator(char c);
ttmath::Big<1,2> pointDoubler(ttmath::Big<1,2> x, ttmath::Big<1,2> y, char call);
ttmath::Big<1,2> dhecc();
#define RAND_MAX = 1267650600228229401496703205653;

int main() {
	//our specific prime number
	ttmath::Big<1,2> p = "1267650600228229401496703205653";
	dhecc();

	//create the seed we need for "true" random x's
	srand(time(NULL));

	//variables need for trials
	ttmath::Big<1,2> x = rand();
	ttmath::Big<1,2> y, addedX, addedY;
	ttmath::Big<1,2> x1 = "123456789123456789123456789", y1 = "123456789123456789123456789", 
		   x2 ="987654321987654321987654321", y2 ="987654321987654321987654321";

	//PROMPT and PROCESS------------------------------------------------------------------
	cout << ("Welcome to our project on Elliptic Curve Cryptography!\n\nBelow we will operate a series of functions ")
		<< ("which will perform operations on our curve: Y^2 = x^3 + x + 24") << endl
		<< ("with our prime being: ") << p << endl << ("A demonstration of our following functions will proceed...\n\n");

	cout << ("--------------------------------------------------------------------------------")
		<< ("Given a random 'x', on our curve we will find our 'y' for said point utilizing \nour getY() function\n")
		<< ("Here is our random x: ") << x << endl;
	
	cout << ("Now we will complete our point on our elliptic curve \nby passing in our 'x' coordinate and getting our 'y'") << endl << endl;
	y = getY(x);
	cout << ("getY(x) = ") << y << endl << ("Therefore our point is (") << x << (",") << y << (")") << endl << endl
		 << ("--------------------------------------------------------------------------------");

	cout << ("We have also developed our own point adder which will take our mock points and  add them together") << endl;
	cout << ("Our first point being \n(x1,y1) = (123456789123456789123456789, 123456789123456789123456789)\n")
		<< ("and our second point being \n(x2, y2) = (987654321987654321987654321,987654321987654321987654321)") << endl << endl;
	
	addedX = pointAdder(x1, y1, x2, y2, 'x');
	addedY = pointAdder(x1, y1, x2, y2, 'y');

	cout << ("Our new point is: ") << ("(") << addedX << (",") << addedY << (")") << endl
		<< ("--------------------------------------------------------------------------------");

	cout << ("We have discovered a generator for our curve to be x = 12 and y = 42 which we use for our following DHECC example") << endl
		<< ("--------------------------------------------------------------------------------");

	//FAST EXPONENTIATION EXAMPLE HERE
	
	//DHECC EXAMPLE HERE

	//RANDOM POINT TEST-------------------------------------------------------------------
	/*
	int x = rand();
	cout << ("Given x: ") << (x) << endl <<endl;
	ttmath::Big<1,2> y;
	
	//TEST to get an exact point, not a decimal value

		y = getPoint(x);
		cout << ("Our point is: (") << (x) << (",") << (y) << (")") << endl;
	/*
	//POINT ADDER TEST-------------------------------------------------------------------
	/*	
		ttmath::Big<1,2> x3, y3;
		ttmath::Big<1,2> x1 = 5, y1 = 4, x2 = 7, y2 = 12;
		char xComponent = 'x', yComponent = 'y';
		cout << endl << endl << ("POINT ADDER TEST") << endl;
		x3 = pointAdder(x1, y1, x2, y2, xComponent);
		y3 = pointAdder(x1, y1, x2, y2, yComponent);

		cout << endl << ("Point x3: ") << (x3) << endl << ("Point y3: ") << (y3) << endl;
	*/

	//getY() TEST------------------------------------------------------------------------
	/*
		ttmath::Big<1,2> testX = 4, w;
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
ttmath::Big<1,2> dhecc(/**/) {
	//This function is for the Diffy-Hellman Key exchange w/ ECC

	cout << "This function, DHECC, emulates Diffy-Helman Elliptic Curve Cartography by using an elliptic curve to send a private key from Bob to Sarah." << endl;


	////Bob and Sarah each have g, a generator of our curve, and their own private value, K and L respectively.
	cout << "Bob and Sarah each have g, a generator of our curve, and their own private value, K and L respectively." << endl;
	ttmath::Big<1,2> gX = getGenerator('x'); //?
	ttmath::Big<1,2> gY = getGenerator('y'); //?
	int kk = rand() % 255;//?
	cout << "k = " << kk << endl;
	int ll = rand() % 255;//?
	cout << "l = " << ll << endl;
	cout << "For this instance, K = " << kk << ", and L = " << ll << "." << endl;

	////Bob is trying to send Sarah lesser encryption key, M
	int m = 8;
	cout << "Please enter a integer to be used as the Private key Bob is sharing with Sarah.";
	cin >> m;
	cout << "Secret Encryption key to be shared is:  " << m << endl;

	cout << "To start, Bob multiplies g by K, and sends it to Sarah. Sarah does likewise with g and L." << endl;
	////Bob sends Sarah Kg, and Sarah sends back Lg
	ttmath::Big<1, 2> gKX = fastExponentiation(kk, gX, gY, 'x');
	ttmath::Big<1, 2> gKY = fastExponentiation(kk, gX, gY, 'y');

	ttmath::Big<1, 2> gLX = fastExponentiation(ll, gX, gY, 'x');
	ttmath::Big<1, 2> gLY = fastExponentiation(ll, gX, gY, 'y');

	cout << "gK = " << gKX << ", " << gKY << endl;
	cout << "gL = " << gLX << ", " << gLY << endl;


	cout << "Next, Bob multiplies (K)Lg and Sarah multiplies (L)Kg" << endl;
	////Bob multiplies (K)Lg and Sarah multiplies (L)Kg
	ttmath::Big<1, 2> gKLX = fastExponentiation(ll, gKX, gKY, 'x');
	ttmath::Big<1, 2> gKLY = fastExponentiation(ll, gKX, gKY, 'y');

	ttmath::Big<1, 2> gLKX = fastExponentiation(kk, gLX, gLY, 'x');
	ttmath::Big<1, 2> gLKY = fastExponentiation(kk, gLX, gLY, 'y');

	cout << "gKL = " << gKLX << ", " << gKLY << endl;
	cout << "gLK = " << gLKX << ", " << gLKY << endl;

	cout << "Bob then adds M + KLg and sends it to Sarah" << endl;
	////Bob then adds M + KLg and sends it to Sarah
	ttmath::Big<1, 2> gKLXm = gKLX + m; 
	ttmath::Big<1, 2> gKLYm = gKLY + m;
	cout << "gKL + M = " << gKLXm << ", " << gKLYm << endl;
	
	/*ttmath::Big<1, 2> gLKm = gLKX + m;
	cout << endl;
	cout << endl;
	cout << "gKLX = " << gKLX;
	cout << endl;
	cout << "gLKX = " << gLKX;*/

	cout << "After receiving M+KLg, Sarah subtracts M+KLg-LKg to get M" << endl;
	////After receiving M+KLg, Sarah subtracts M+KLg-LKg to get M
	ttmath::Big<1,2> n = gKLXm - gLKX;

	//Small rounding Algorithm
	ttmath::Big<1, 2> oneone = 1;
	ttmath::Big<1, 2> oo = n - m;
	n = n - oo;

	////Sarah now has encryotion key M, and an onlooker, say Sneaks McGeeks,
	////only has knowledge of Kg, Lg, and M+KLg which cannot be easily used to
	////solve the encryption.
	cout << endl;
	cout << "And so the Private key Bob sent to Sarah should be: " << n ;
	return n;
}


/*
 * Equation used to double a point with the given components.
 */
ttmath::Big<1,2> pointDoubler(ttmath::Big<1,2> x, ttmath::Big<1,2> y, char call) {//11/30-SamGo-modify this to allow a point to be doubled n times? Also maybe to return a ttmath::Big<1,2> Array?

	ttmath::Big<1,2> l = 0; //Lambda
	int a = 1; //?
	
	//Lambda = 3x(p)^2+a/2y(p)
	l = (((x*x)*3 )+ a) / (y*2);
	//X(r)=Lambda^2 - 2x(p)
	ttmath::Big<1,2> xd = (l*l) - x - x; //
	//Y(r)=Lambda[x(p)]-y(p)
	ttmath::Big<1,2> yd = (l*(x - xd)) - y;

	if (call == 'x') { // if error try = //?
		return ttmath::Mod(xd,prime);
	}
	else if (call == 'y') { // if error try = //?
		return ttmath::Mod(yd,prime);
	}
	else {
		return 0;
	}


	//How to handle multiplication by even 'n'
	//Break even into a power of 2, n = 2^m
	//Perform function, repeat m times
}

/*
 * Given component y, get x;
 */
/*
ttmath::Big<1,2> getX(ttmath::Big<1,2> y) {

	ttmath::Big<1,2> u,v,w,x;
	//MAY NEED TO DO SOME OVERLOADING FOR POW FUNCTION
	u = (ttmath::Big<1,2>)pow(((ttmath::Big<1,2>)9 * (y*y) + ((ttmath::Big<1,2>)3).ttmath::Big<1,2>::intSqrt()*((ttmath::Big<1,2>)27 * (y*y*y*y)
		- (ttmath::Big<1,2>)1296 * (y*y) + 15556).ttmath::Big<1,2>::intSqrt() - 216), (1 / 3));
	v = ((ttmath::Big<1,2>)pow(2, (1 / 3))*(ttmath::Big<1,2>)pow(3, (2 / 3)));
	w = (ttmath::Big<1,2>)pow((2 / 3), (1 / 3));

	x = (u / v) - (w / u);

	return x;
}
*/

/*
 * Given component x, get y;
 */
ttmath::Big<1,2> getY(ttmath::Big<1,2> x) {

	ttmath::Big<1,2> y;

	y = (x*x*x) + x + 24;

	y = ttmath::Sqrt(y);

	return y;
}

/* 
 * Adds two points together component wise to get a new component for given point
 */
ttmath::Big<1,2> pointAdder(ttmath::Big<1,2> x1, ttmath::Big<1,2> y1, ttmath::Big<1,2> x2, ttmath::Big<1,2> y2, char component) {
	ttmath::Big<1,2> x3, y3;

	//Lambda
	ttmath::Big<1,2> lambda = (y2-y1)/(x2-x1);
	x3 = (lambda*lambda)-x1-x2;
	y3 = (lambda*(x1-x3))-y1;

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
ttmath::Big<1,2> getPoint(int x) { //11/30 - SamGo - Maybe either change this to be able to return 'true' y values(to a point) or ?

	double xx = pow(x, 3) + x + 24;
	xx = sqrt(xx);

	//if (xx == int(xx)) {
	//	y = int(xx);

	//} else {
	//	cout << ("Failed!");
	//		y = NULL;
	//}
	//ttmath::Big<1,2> y = xxx.ttmath::Big<1,2>::intSqrt();
	long long y = xx;
	return ttmath::Big<1,2>(y);
}
ttmath::Big<1,2> getGenerator(char c) {
	//Returns a point that generates the curve.
	ttmath::Big<1,2> x = 12;
	ttmath::Big<1,2> y = 42;
	if (c == 'x') {
		return x;
	}
	else if (c == 'y') {
		return y;
	}
	return 0;
}


/*
* Application of fast exponentiation in order to multiply a very big number very quickly
*/
ttmath::Big<1,2> fastExponentiation(int mPlier, ttmath::Big<1,2> gX, ttmath::Big<1,2> gY, char cVar) {

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
	int count = 0;
	ttmath::Big<1,2> resultX;
	ttmath::Big<1,2> resultY;
	ttmath::Big<1,2> resArray[2];
	resArray[0] = 0; // Double check that 0-1 is ok, instead of 1-2
	resArray[1] = 0;

	for (cc;cc > 0;cc--) {
		if (bin.at(ii) == '1') {
			//cout << cc << endl;
			//Multiply g by 2^(c-1), add to result.

			//This is technically Scalar multiplication?
			//resultX = resultX + (gX * (pow(2, (cc - 1)))); //Replace this with a normal point multiplier?
														   //resultX = resultX % prime;
			//resultY = resultY + (gY * (pow(2, (cc - 1)))); //Replace this with a normal point multiplier?
														   //resultY = resultY % prime;
			ttmath::Big<1,2> tempX = gX;
			ttmath::Big<1,2> tempY = gY;
			int pp = cc - 1;
			////Point multiplication below
			
			for (pp; pp > 0;pp--) {
				ttmath::Big<1,2> ttX = tempX; 
				ttmath::Big<1,2> ttY = tempY;
				tempX = pointDoubler(ttX,ttY, 'x');
				tempY = pointDoubler(ttX,ttY, 'y');
			}
			if ((mPlier == 2) || count == 0) {
				resArray[0] = tempX;
				resArray[1] = tempY;
			}else if (mPlier > 2) {
				//Add result to resArray
				ttmath::Big<1, 2> tttX = resArray[0];
				ttmath::Big<1, 2> tttY = resArray[1];
				resArray[0] = pointAdder(tttX, tttY, tempX, tempY, 'x');
				resArray[1] = pointAdder(tttX, tttY, tempX, tempY, 'y');
			}
			count = count + 1;
			
		}
		else if (bin.at(ii) == '0') {
			//cout << "zero/" << endl;
			//nothing
		}

		ii++;
	}
	ttmath::Big<1,2> ttttX = resArray[0];
	ttmath::Big<1,2> ttttY = resArray[1];
	if (mPlier == 1) {
		resArray[0] = pointAdder(ttttX, ttttY, gX, gY, 'x');
		resArray[1] = pointAdder(ttttX, ttttY, gX, gY, 'y');
	}

	if (cVar == 'x') {
		return Mod(resArray[0], prime);
	}
	else if (cVar == 'y') {
		return Mod(resArray[1], prime);
	}
	return 0;

	//return resArray[0], resArray[1]; //How return point?
}

void curve() {//maybe turn this into a funtion that given input returns x, y, a, b, etc?
		//Y^2 = x^3 + x + 24 under prime P = 1267650600228229401496703205653
		//P = 1267650600228229401496703205653
		//Order of curve (according to Sage Math): 1267650600228228129735869379373;
}




