#include <string>
#include <vector>
#include <iostream>
using namespace std;

class CatAndRat {
	public:
	const double pi = 3.141592653589793;
	double getTime(int R, int T, int Vrat, int Vcat) {
		
		if (Vcat <= Vrat)
			return -1.0L;

		double initDis = 0;
		if (T * Vrat >= pi * R)
			initDis = pi * R;
		else
			initDis = T * Vrat;

		return initDis / (Vcat - Vrat);
	}
};
