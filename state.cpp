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
void State::calculatePercent(int x, double b[]) {  
	int s, t, h, a, w, n, o, f;
	char m[17], c[17];
	t = total_population.length();
	h = hispanic_population.length();
	f = black_population.length();
	a = asian_population.length();
	w = white_population.length();
	n = native_population.length();
	o = other_population.length();
	for (int i = 0; i <= t; i++) {
		c[i] = total_population[i];
	}
	c[t + 1] = 0;
	tp = strtoul(c, NULL, NULL);
	//0 for Hispanic; 1 for Black; 2 for White; 3 for Asian; 4 for Native; 5 for Other
	switch(x) {
	case 0:
		for (int j = 0; j <= h; j++) {
			m[j] = hispanic_population[j];
		}
		m[h + 1] = 0;
		hp = strtoul(m, NULL, NULL);
		b[0] = double((hp/tp)) * 100;
		break;
	case 1:
		for (int j = 0; j <= f; j++) {
			m[j] = black_population[j];
		}
		m[f + 1] = 0;
		bp = strtoul(m, NULL, NULL);
		b[1] = double(bp/tp) * 100;
		break;
//0 for Hispanic; 1 for Black; 2 for White; 3 for Asian; 4 for Native; 5 for Other
	case 2:
		for (int j = 0; j <= w; j++) {
			m[j] = white_population[j];
		}
		m[w + 1] = 0;
		wp = strtoul(m, NULL, NULL);
		b[2] = double(wp/tp) * 100;
		break;
	case 3:
		for (int j = 0; j <= a; j++) {
			m[j] = asian_population[j];
		}
		m[a + 1] = 0;
		ap = strtoul(m, NULL, NULL);
		b[3] = double(ap/tp) * 100;
		break;
	case 4:
		for (int j = 0; j <= n; j++) {
			m[j] = native_population[j];
		}
		m[n + 1] = 0;
		np = strtoul(m, NULL, NULL);
		b[4] = double(np/tp) * 100;
		break;
	case 5:
		for (int j = 0; j <= o; j++) {
			m[j] = other_population[j];
		}
		m[w + 1] = 0;
		op = strtoul(m, NULL, NULL);
		b[5] = double(op/tp) * 100;
		break;
	}
}

	