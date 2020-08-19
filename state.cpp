#include "state.h"
State::State() {}
double State::getTotal() { return total_population; }
double State::getHispanic() { return hispanic_population; }
double State::getBlack() { return black_population; }
double State::getOther() { return other_population; }
double State::getAsian() { return asian_population; }
double State::getWhite() { return white_population; }
double State::getNative() { return native_population; }
void State::setTotal(double a) { total_population = a; }
void State::setHispanic(double a) { hispanic_population = a; }
void State::setBlack(double a) { black_population = a; }
void State::setAsian(double a) { asian_population = a; }
void State::setWhite(double a) { white_population = a; }
void State::setOther(double a) { other_population = a; }
double State::calcOther() { 
	double b;
	b = hispanic_population + black_population + asian_population + white_population + native_population;
	if (b < total_population) {
		other_population = total_population - b;
		return other_population;
	}
	else {
		other_population = b - total_population;
		return other_population;
	}
}
void State::setNative(double a) { native_population = a; }
void State::calculatePercent(int a, double b[]) {  
	switch (a) {
	case 0:
		b[0] = (hispanic_population / total_population) * 100;
		break;
	case 1:
		b[1] = (black_population / total_population) * 100;
		break;
	case 2:
		b[2] = (asian_population / total_population) * 100;
		break;
	case 3:
		b[3] = (white_population / total_population) * 100;
		break;
	case 4:
		b[4] = (native_population / total_population) * 100;
		break;
	case 5:
		b[5] = (other_population / total_population) * 100;
		break;
	}
}