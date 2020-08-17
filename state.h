#pragma once
#include "case.h"
class State {
private:
	int total_population = 0, hispanic_population = 0, black_population = 0, asian_population = 0, white_population = 0, native_population = 0;
	string state_abbreviated = "  ";
	double race_percentages[5]; 
public:
	State();
	int getTotal();
	int getHispanic();
	int getBlack();
	int getAsian();
	int getWhite();
	int getNative();
	void setTotal(int);
	void setHispanic(int);
	void setBlack(int);
	void setAsian(int);
	void setWhite(int);
	void setNative(int);
	double calculatePercent(char, double[]);
};