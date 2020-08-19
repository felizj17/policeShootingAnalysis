#pragma once
#include "case.h"
class State {
private:
	double total_population = 0, hispanic_population = 0, black_population = 0, asian_population = 0, white_population = 0, native_population = 0, other_population = 0;
	string state_abbreviated = "  ";
	double race_percentages[6] = {0.0,0.0,0.0,0.0,0.0,0.0};
public:
	State();
	double getTotal();
	double getHispanic();
	double getBlack();
	double getAsian();
	double getWhite();
	double getNative();
	double getOther();
	void setTotal(double);
	void setHispanic(double);
	void setBlack(double);
	void setAsian(double);
	void setWhite(double);
	void setNative(double);
	void setOther(double);
	double calcOther();
	void calculatePercent(int, double[]);
};