#include "state.h"
State::State(){}
int State::getTotal() { return total_population; }
int State::getHispanic() { return hispanic_population; }
int State::getBlack() { return black_population; }
int State::getAsian() { return asian_population; }
int State::getWhite() { return white_population; }
int State::getNative() { return native_population; }
void State::setTotal(int a){}
void State::setHispanic(int a){}
void State::setBlack(int a){}
void State::setAsian(int a){}
void State::setWhite(int a){}
void State::setNative(int a){}
double State::calculatePercent(char a, double b[]) { return race_percentages[0]; }