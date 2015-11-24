#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <stack>


using namespace std;



int main() {

	printf("Hello World!");

	////Demos
	//Getting X and Y coordinates of a point
	//Adding a point to itself
	//Getting a generator of the curve
	//Fast exponentiation
	//DHECC!!!

	system("pause");
	return 0;
}


int dhecc(/**/) {
	//This function is for the Diffy-Hellman Key exchange w/ ECC

	////Bob and Sarah each have g,(a value on the curve?), and their own key, K and L respectively. //?
	/** BigInt g = getGenerater(); //?
	 *  Int kk = rand();//?
	 *  Int ll = rand();//?
	 */
	////Bob is trying to send Sarah lesser encryption key, M
	int m = 8;

	////Bob sends Sarah Kg, and Sarah sends back Lg
	//Bigint gK = kk * g; //These'll probably use Fast exponentiation
	//Bigint gL = ll * g; //These'll probably use Fast exponentiation

	////Bob multiplies (K)Lg and Sarah multiplies (L)Kg
	//Bigint gKL = gL * kk; //These'll probably use Fast exponentiation
	//Bigint gLK = gK * ll; //These'll probably use Fast exponentiation

	////Bob then adds M + KLg and sends it to Sarah
	//int gKLm = m + gKL;

	////After receiving M+KLg, Sarah subtracts M+KLg-LKg to get M
	//int n = gKLm - gLK;
	int n = 0;
	////Sarah now has encryotion key M, and an onlooker, say Sneaks McGeeks,
	////only has knowledge of Kg, Lg, and M+KLg which cannot be easily used to
	////solve the encryption.
	
	return n;
}


int pointDoubler(int x, int y) {
	//This should be just the equation for doubling a point.

	int l = 0; //Lambda
	int xp = 0;
	int yp = 0;
	int a = 0; //?
	
	//Lambda = 3x(p)^2+a/2y(p)
	l = (3 * (xp ^ 2) + a) / (2*yp);
	//X(r)=Lambda^2 + x(p)
	int xd = (l ^ 2) + xp;
	//Y(r)=Lambda[x(p)]-y(p)
	int yd = (l*xp) - yp;


	return xp;//change to one point, may have to invent Point for bigint?
	return yp;//change to one point, or maybe Point using pointers?
}

int getX() {
	//Given a point, get X?
	return 0;
}

int getY() {
	//Given a point, get Y?
	return 0;
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
	stack <bool> bin;

	if (mPlier<=255) { //Limit of 255? (2^7) //in progress
		do
		{
			if ((mPlier - (2 ^ pp))>=0) {
				mPlier = mPlier - (2 ^ pp);
				pp--;
				bin.push(1);
			}
			else if(remainder = 0 && pp>0) {
				
			}

		} while (remainder != 0);
	}
	else {
		printf("Error: Multiplier too big (<255)");
	}

	return 0;
}

void curve() {//maybe turn this into a funtion that given input returns x, y, a, b, etc?
	//Y^2 = x^3 + x + 24 under prime P = 1267650600228229401496703205653
	//P = 1267650600228229401496703205653
}



