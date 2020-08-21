#pragma once
#include "case.h"
class State {
private:
	string total_population , hispanic_population, black_population, asian_population, white_population, native_population, other_population;
	string state_abbreviated;
	unsigned long int tp, hp, bp, ap, wp, np, op;
	double race_percentages[6] = {0.0,0.0,0.0,0.0,0.0,0.0};
public:
	State();
	string getTotal();
	string getState();
	string getHispanic();
	string getBlack();
	string getAsian();
	string getWhite();
	string getNative();
	string getOther();
	void setState(string);
	void setTotal(string);
	void setHispanic(string);
	void setBlack(string);
	void setAsian(string);
	void setWhite(string);
	void setNative(string);
	void setOther(string);
	void calculatePercent(int, double[]);
};