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

InfInt prime = "1267650600228229401496703205653";
InfInt fastExponentiation(int mPlier, InfInt gX, InfInt gY);
InfInt getPoint(int x);
InfInt pointAdder(InfInt x1, InfInt y1, InfInt x2, InfInt y2, char component);
InfInt getY(InfInt x);
InfInt getGenerator(char c);
#define RAND_MAX = 1267650600228229401496703205653;

int main() {
	//our specific prime number
	InfInt p = "1267650600228229401496703205653";
	
	//create the seed we need for "true" random x's
	srand(time(NULL));

	//variables need for trials
	InfInt x = rand();
	InfInt y, addedX, addedY;
	InfInt x1 = "123456789123456789123456789", y1 = "123456789123456789123456789", 
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
	InfInt y;
	
	//TEST to get an exact point, not a decimal value

		y = getPoint(x);
		cout << ("Our point is: (") << (x) << (",") << (y) << (")") << endl;
	/*
	//POINT ADDER TEST-------------------------------------------------------------------
	/*	
		InfInt x3, y3;
		InfInt x1 = 5, y1 = 4, x2 = 7, y2 = 12;
		char xComponent = 'x', yComponent = 'y';
		cout << endl << endl << ("POINT ADDER TEST") << endl;
		x3 = pointAdder(x1, y1, x2, y2, xComponent);
		y3 = pointAdder(x1, y1, x2, y2, yComponent);

		cout << endl << ("Point x3: ") << (x3) << endl << ("Point y3: ") << (y3) << endl;
	*/

	//getY() TEST------------------------------------------------------------------------
	/*
		InfInt testX = 4, w;
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
InfInt dhecc(/**/) {
	//This function is for the Diffy-Hellman Key exchange w/ ECC

	////this may be wrong as is, I believe I must change it such that 
	////g is different? Must research.

	////Bob and Sarah each have g,(a value on the curve?), and their own key, K and L respectively. //?
	InfInt gX = getGenerator('x'); //?
	InfInt gY = getGenerator('y'); //?
	int kk = rand() % 255;//?
	cout << "k = " << kk << endl;
	int ll = rand() % 255;//?
	cout << "l = " << ll << endl;

	////Bob is trying to send Sarah lesser encryption key, M
	int m = 8;
	cout << "Secret Encryption key to be shared is:  " << m << endl;

	////Bob sends Sarah Kg, and Sarah sends back Lg
	InfInt gKX, gKY = fastExponentiation(kk, gX, gY); // Careful about this
													  //Fast Expont?
	InfInt gLX, gLY = fastExponentiation(ll, gX, gY);

	////Bob multiplies (K)Lg and Sarah multiplies (L)Kg
	InfInt gKLX, gKLY = fastExponentiation(kk, gKX, gKY); //These names will get confusing quick.
	InfInt gLKX, gLKY = fastExponentiation(kk, gLX, gLY);

	////Bob then adds M + KLg and sends it to Sarah
	InfInt gKLm = gKLX + m; //this is only the x value of gKL for now, point multiplication is wierd.

							////After receiving M+KLg, Sarah subtracts M+KLg-LKg to get M
	InfInt n = gKLm - gLKX;
	////Sarah now has encryotion key M, and an onlooker, say Sneaks McGeeks,
	////only has knowledge of Kg, Lg, and M+KLg which cannot be easily used to
	////solve the encryption.

	return n;
}


/*
 * Equation used to double a point with the given components.
 */
InfInt pointDoubler(InfInt x, InfInt y, char call) {//11/30-SamGo-modify this to allow a point to be doubled n times? Also maybe to return a InfInt Array?

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


	//How to handle multiplication by even 'n'
	//Break even into a power of 2, n = 2^m
	//Perform function, repeat m times
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
InfInt getPoint(int x) { //11/30 - SamGo - Maybe either change this to be able to return 'true' y values(to a point) or ?

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
InfInt getGenerator(char c) {
	//Returns a point that generates the curve.
	InfInt x = 12;
	InfInt y = 42;
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
	InfInt resArray[2];
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
			InfInt tempX = gX;
			InfInt tempY = gY;
			int pp = cc-1;
			////Point multiplication below
			//if power at index ii(starts as left most digit and moves right) is a 1,  
			//call pointDoubler (cc-1) times, calling tempX/Y, when finished, add to resArray using pointAdder
			for (pp; pp > 0;pp--) {
				InfInt ttX = tempX; //This is kinda weird, but nessesary given the weird way we return values.
				InfInt ttY = tempY;
				tempX = pointDoubler(ttX,ttY, 'x'); //temp contains 2g, ect
				tempY = pointDoubler(ttX,ttY, 'y');
			} //at the end of this loop, tempX/Y = n*g
			
			//Add result to resArray
			InfInt tttX = resArray[0];
			InfInt tttY = resArray[1];
			resArray[0] = pointAdder(tttX, tttY, tempX, tempY, 'x');
			resArray[1] = pointAdder(tttX, tttY, tempX, tempY, 'y');
			//
			//
			//How to handle multiplication by even 'n'
			//Break even into a power of 2, n = 2^m
			//Perform function, repeat m times
			//Note: in this loop/if, cc-1 = power of 2 (check if cc-1 or cc)
//Remaining:: Make sure that if mPliers is odd, a 1g is added at the end
//This may already happen as a result of how the loop works, but make sure.
			
		}
		else if (bin.at(ii) == '0') {
			//cout << "zero/" << endl;
			//nothing
		}

		ii++;
	}

	return resArray[0], resArray[1]; //How return point?
}

void curve() {//maybe turn this into a funtion that given input returns x, y, a, b, etc?
		//Y^2 = x^3 + x + 24 under prime P = 1267650600228229401496703205653
		//P = 1267650600228229401496703205653
		//Order of curve (according to Sage Math): 1267650600228228129735869379373;
}




