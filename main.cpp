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
	
	//int nor = rowCount(fs);
	Case *b[15];
	for (int i = 0; i <= 14;i++) {
		b[i] = new Case();
	}
	
	//while (!a.eof()) {
	for (int i = 0; i <= 14;i++) {
		for (int j = 0;j < 15;j++) {
			a.getline(str, 32, ',');
			data[j] = str;
		}
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
	//cout << "Enter the path of the file to open.";
	//cin >> path;
	//extraction(fs, caseV, 15);
	cout << b[4]->getCity();
}
