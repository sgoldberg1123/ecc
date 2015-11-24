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
#define RAND_MAX = 1267650600228229401496703205653;

int main() {

	printf("Hello World!");
	cout << endl;

	InfInt p = "1267650600228229401496703205653";


	//TEST PROMPT for getting a random point
	int x = rand();
	cout << (x) << endl;
	InfInt y;
	int i = 0;
	/*cout << ("Please enter an x: ");
	cin >> (x);*/
	cout << endl;
	while (i = 0) {
		y = getPoint(x);
		if ((y % 1) == 0) {
			i++;
		}
		else {
			x = rand();
			cout << (x) << endl;
		}
	}
	cout << y;
	cout << endl << endl;

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

InfInt getX(InfInt y) {
	//Given a point, get X?


	//return x;
	return 0;
}

InfInt getY(InfInt x) {
	//Given a point, get Y?
	//return y;
	return 0;
}

InfInt pointAdder(InfInt x1, InfInt y1, InfInt x2, InfInt y2) {
	//Adding two points together to get a new point?

	return 0;
}

InfInt getPoint(int x) {
	//if mod 1 = 0
	int xT = pow(x, 3) + x + 24;
	InfInt xTT = xT;
	InfInt y = xTT.InfInt::intSqrt();

	return y;
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



