#include "case.h"
#include "state.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
void dataExtractPoliceShooting(Case a[], int b, string c);
void dataExtractCensusData(State a[], int b, string c);
int rowCount(string a);
void bodyCamPercent(Case a[], double b, double c[]);
void racePercent(Case a[], double b, double c[]);
void stateRacePopComp(Case a[], double b, double c[]);

int main() {
	//percentage arrays 
	double race_percentages[6];
	double body_cam_percentages[3];
	//set-up for moving data from csv files 
	string ps,cd;
	ps = "policeshootings.csv";
	cd = "CensusData2017.csv";
	int nor = rowCount(ps);
	int norcd = rowCount(cd);


	State* a = NULL;
	a = new State[norcd - 1];
	Case* b = NULL;
	b = new Case[nor];

	dataExtractPoliceShooting(b, nor, ps);	
	racePercent(b, nor, race_percentages);
	for (int f = 0; f < 6; f++) {
		cout << race_percentages[f] << '\n';
	}
	dataExtractCensusData(a, norcd, cd);
	cout << '\n' << a[51].getOther();
	/*testing the extraction of the data 
	cout << "\t" << b[4894].getId();
	cout << "\t" << b[4894].getName();
	cout << "\t" << b[4894].getDate();
	cout << "\t" << b[4894].getMod();
	cout << "\t" << b[4894].getWeapon();
	cout << "\t" << b[4894].getAge();
	cout << "\t" << b[4894].getGender();
	cout << "\t" << b[4894].getRace();
	cout << "\t" << b[4894].getCity();
	cout << "\t" << b[4894].getState(); 
	cout << "\t" << b[4894].getSomi();
	cout << "\t" << b[4894].getThreatlevel();
	cout << "\t" << b[4894].getFleeing();
	cout << "\t" << b[4894].getBody_cam();
	cout << '\t' << b[4894].getArms();
	*/
	
}

void racePercent(Case a[], double b, double c[]) {
	string r = "  ";
	double white = 0.0, black = 0.0, asian = 0.0, native = 0.0, hispanic = 0.0, other = 0.0;
	for (int i = 0; i < b;i++) {
		
		r = a[i].getRace();
		if (r.compare("White") == 0) {
			white++;
		}
		else if (r.compare("Black") == 0) {
			black++;
		}
		else if (r.compare("Asian") == 0){
			asian++;
		}
		else if (r.compare("Native") == 0) {
			native++;
		}
		else if (r.compare("Hispanic") == 0) {
			hispanic++;
		}
		else if (r.compare("Other") == 0){
			other++;
		}
	}
	c[0] = (white / b) * 100;
	c[1] = (black / b) * 100;
	c[2] = (asian / b) * 100;
	c[3] = (native / b) * 100;
	c[4] = (hispanic / b) * 100;
	c[5] = (other / b) * 100;
	 
}

void bodyCamPercent(Case a[], double b, double c[]) {
	string bc;
	string t = "TRUE";
	string f = "FALSE";
	int bodyCam_t = 0;
	int	bodyCam_f = 0;
	int other = 0;
	for (int i = 0; i < b; i++) {
		bc = a[i].getBody_cam();
		if (bc.compare(t) == 0) {
			bodyCam_t++;
			}
		else if(bc.compare(f) == 0){
			bodyCam_f++;
		}
		else {
			other++;
		}
	}
	c[0] = (bodyCam_t / b) * 100;
	c[1] = (bodyCam_f / b) * 100;
	c[2] = (other / b) * 100;

}

void stateRacePopComp(Case a[], double b, double c[] ){
	string s;
	for (int i = 0; i < b; i++) {
		s = a[i].getState();

	}

}

int rowCount(string a)
{
	int count = 0;
	string line;
	ifstream ds;
	ds.open(a);
	if (ds.is_open()) {
		cout << "File is Open\n";
	}
	else {
		cout << "File not found!\n Try entering full path of document with '\' replaced with '\\' \n";
	}
	while (!ds.eof()) {
		getline(ds, line);
		count++;
	}
	ds.close();
	return count;
}
void dataExtractPoliceShooting(Case a[], int b, string c) {
	ifstream ds;
	char str[64];
	string data[15];
	ds.open(c);
	if (ds.is_open()) {
		cout << "File is Open\n";
		ds.seekg(0, ds.beg);
	}
	else {
		cout << "Bad File, Try Again! \n";
	}
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < 15; j++) {
			ds.getline(str, 64, ',');
			data[j] = str;

		}
		//assigning the data to the Case class variables 
		a[i].setId(data[0]);
		a[i].setName(data[1]);
		a[i].setDate(data[2]);
		a[i].setMod(data[3]);
		a[i].setWeapon(data[4]);
		a[i].setAge(data[5]);
		a[i].setGender(data[6]);
		a[i].setRace(data[7]);
		a[i].setCity(data[8]);
		a[i].setState(data[9]);
		a[i].setSomi(data[10]);
		a[i].setThreatlevel(data[11]);
		a[i].setFleeing(data[12]);
		a[i].setBody_cam(data[13]);
		a[i].setArms(data[14]);
	}
	ds.close();
}
void dataExtractCensusData(State a[], int b, string c) {
	ifstream ft;
	char str[256];
	string str1[8];
	ft.open(c);
	if (ft.is_open()) {

		cout << "File is Open! \n";
		ft.seekg(0, ft.beg);
		ft.ignore(256, '\n');
	}
	else {
		cout << "Bad File, Try Again! \n";
	}
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < 8; j++) {
			ft.getline(str, 8, ',');
			str1[j] = str;
	
		}
		a[i].setState(str1[0]);
		a[i].setTotal(str1[1]);
		a[i].setHispanic(str1[2]);
		a[i].setWhite(str1[3]);
		a[i].setBlack(str1[4]);
		a[i].setAsian(str1[5]);
		a[i].setNative(str1[6]);
		a[i].setOther(str1[7]);
	}
	ft.close();
}