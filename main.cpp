#include "case.h"
#include "functions.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main() {
	string fs;
	fs = "C:\\Users\\feliz\\Downloads\\policeshootings.csv";
	char str[32];
	string data[15];
	ifstream a;
	a.open(fs);
	if (a.is_open()) {
		cout << "File is Open\n";
	}
	else {
		cout << "File not found!\n Try entering full path of document with '\' replaced with '\\' \n";
	}
	//nor will store the number of lines extracted from the file
	int nor = rowCount(fs);
	//change to vector of type Case arrays not as easy to manipulate 
	Case *b[4896];
	for (int i = 0; i <= 14;i++) {
		b[i] = new Case();
	}
	/*======================================================================================================================================================*/
	//currently troubleshooting
	/*======================================================================================================================================================*/
	//while (!a.eof()) {
	for (int i = 0; i <= nor;i++) {
		for (int j = 0;j < 15;j++) {
			a.getline(str, 32, ',');
			data[j] = str;
		}
		//assigning the data to the case class variables 
		b[i]->setId(data[0]);
		b[i]->setName(data[1]);
		b[i]->setDate(data[2]);
		b[i]->setMod(data[3]);
		b[i]->setWeapon(data[4]);
		b[i]->setAge(data[5]);
		b[i]->setGender(data[6]);
		b[i]->setRace(data[7]);
		b[i]->setCity(data[8]);
		b[i]->setState(data[9]);
		b[i]->setSomi(data[10]);
		b[i]->setThreatlevel(data[11]);
		b[i]->setFleeing(data[12]);
		b[i]->setBody_cam(data[13]);
		b[i]->setArms(data[14]);
	}
	//testing the extraction of the data
	cout << b[4]->getCity();
}
