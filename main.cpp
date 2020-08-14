#include "case.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int rowCount(string a);
void bodyCamPercent(Case a[], double b, double c[]);
void racePercent(Case a[], double b, double c[]);
void stateRacePopulationComparision(Case a[], double b, double c[]);

int main() {
	string fs;
	int i = 0;
	fs = "C:\\Users\\feliz\\Downloads\\policeshootings.csv";
	char str[64];
	double race_percentages[6];
	double body_cam_percentages[3];
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
	Case* b = NULL;
	b = new Case[nor];
	/*======================================================================================================================================================*/
	//currently troubleshooting
	/*======================================================================================================================================================*/
	for(int i =0;i<nor;i++){
		for ( int j = 0;j < 15;j++) {
			a.getline(str, 64, ',');
			data[j] = str;
			
		}
		//assigning the data to the Case class variables 
		b[i].setId(data[0]);
		b[i].setName(data[1]);
		b[i].setDate(data[2]);
		b[i].setMod(data[3]);
		b[i].setWeapon(data[4]);
		b[i].setAge(data[5]);
		b[i].setGender(data[6]);
		b[i].setRace(data[7]);
		b[i].setCity(data[8]);
		b[i].setState(data[9]);
		b[i].setSomi(data[10]);
		b[i].setThreatlevel(data[11]);
		b[i].setFleeing(data[12]);
		b[i].setBody_cam(data[13]);
		b[i].setArms(data[14]);		
	}
	
	
	racePercent(b, nor, race_percentages);
	for (int f = 0; f < 6; f++) {
		cout << race_percentages[f] << '\n';
	}

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
	c[0] = (white / b)*100;
	c[1] = (black / b)*100;
	c[2] = (asian / b)*100;
	c[3] = (native / b)*100;
	c[4] = (hispanic / b)*100;
	c[5] = (other / b)*100;
	 
}

void bodyCamPercent(Case a[], double b, double c[]) {
	string bc;
	string t = "True";
	string f = "False";
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
