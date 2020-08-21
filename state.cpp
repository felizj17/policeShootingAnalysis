#include "state.h"
State::State() {}
string State::getTotal() { return total_population; }
string State::getState() { return state_abbreviated; }
string State::getHispanic() { return hispanic_population; }
string State::getBlack() { return black_population; }
string State::getOther() { return other_population; }
string State::getAsian() { return asian_population; }
string State::getWhite() { return white_population; }
string State::getNative() { return native_population; }
void State::setState(string a) { state_abbreviated = a; }
void State::setTotal(string a) { total_population = a; }
void State::setHispanic(string a) { hispanic_population = a; }
void State::setBlack(string	a) { black_population = a; }
void State::setAsian(string a) { asian_population = a; }
void State::setWhite(string a) { white_population = a; }
void State::setOther(string a) { other_population = a; }
void State::setNative(string a) { native_population = a; }
void State::calculatePercent(int a, double b[]) {  
	

	
	/*switch (a) {
	case 0:
	
		b[0] = (hp/tp) * 100;
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
	}*/
}
void State::conversions() {
	int s, t, h, a, w, n, o;
	char *ptr, c[17];
	t = total_population.length();
	h = hispanic_population.length();
	a = asian_population.length();
	w = white_population.length();
	n = native_population.length();
	o = other_population.length();
	for (int i = 0; i <= t; i++) {
		c[i] = total_population[i];
	}
	c[t + 1] = 0;
	for (int j = 0; j < t; j++) {
		cout << c[j];
	}

	//tp = strtoul(c, &ptr, t+1);
	//cout << tp;
}