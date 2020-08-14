#pragma once
//#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Case {
private:
	//mod(manner of death) somi(signs of mental illness)
	string gender, id, age, body_cam, fleeing, somi, race, name, date, mod, weapon, city, state, threatlevel, arms;
	

public:
	Case();
	void setId(string);
	void setAge(string);
	void setName(string);
	void setRace(string);
	void setThreatlevel(string);
	void setArms(string);
	void setDate(string);
	void setMod(string);
	void setWeapon(string);
	void setCity(string);
	void setState(string);
	void setGender(string);
	void setBody_cam(string);
	void setFleeing(string);
	void setSomi(string);
	string getId();
	string getAge();
	string getName();
	string getRace();
	string getThreatlevel();
	string getArms();
	string getDate();
	string getMod();
	string getWeapon();
	string getCity();
	string getState();
	string getGender();
	string getBody_cam();
	string getFleeing();
	string getSomi();
};