#include "state.h"
State:: State() {}
int State::getTotal() { return total_population; }
int State::getHispanic() { return hispanic_population; }
int State::getBlack() { return black_population; }
int State::getAsian() { return asian_population; }
int State::getWhite() { return white_population; }
int State::getNative() { return native_population; }

void State::setTotal(int){}
void State::setHispanic(int){}
void State::setBlack(int){}
void State::setAsian(int){}
void State::setWhite(int){}
void State::setNative(int){}
double State::calculatePercent(char, double[]) { return race_percentages[0]; }