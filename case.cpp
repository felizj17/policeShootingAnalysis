#include "case.h"
Case::Case() {}
void Case::setId(string a) { id = a; }
void Case::setAge(string a) { age = a; }
void Case::setName(string a) { name = a; }
void Case::setDate(string a) { date = a; }
void Case::setMod(string a) { mod = a; }
void Case::setWeapon(string a) { weapon = a; }
void Case::setRace(string a) { race = a; }
void Case::setThreatlevel(string a) { threatlevel = a; }
void Case::setArms(string a) { arms = a; }
void Case::setCity(string a) { city = a; }
void Case::setState(string a) { state = a; }
void Case::setGender(string a) { gender = a; }
void Case::setBody_cam(string a) { body_cam = a; }
void Case::setFleeing(string a) { fleeing = a; }
void Case::setSomi(string a) { somi = a; }
string Case::getId() { return id; }
string Case::getAge() { return age; }
string Case::getName() { return name; }
string Case::getDate() { return date; }
string Case::getMod() { return mod; }
string Case::getWeapon() { return weapon; }
string Case::getCity() { return city; }
string Case::getRace() { return race; }
string Case::getThreatlevel() { return threatlevel; }
string Case::getArms() { return arms; }
string Case::getState() { return state; }
string Case::getGender() { return gender; }
bool Case::getBody_cam() { 
	if (body_cam == "True")
		return "True";
	else
		return "False"; 
}
bool Case::getFleeing() { 
	if (fleeing == "True")
		return "True";
	else
		return "False";
}
bool Case::getSomi() { 
	if (somi == "True")
		return "True";
	else
		return "False"; 
}