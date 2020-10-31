#include "case.h"
#include "state.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> 
#include <cctype>
#include <locale>
#include "function.h"
using namespace std;

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
	//dynamic creation of arrays for transfer 
	State* a = NULL;
	a = new State[norcd];
	Case* b = NULL;
	b = new Case[nor];
	
	dataExtractPoliceShooting(b, nor, ps);	
	racePercent(b, nor, race_percentages);
	/*for (int f = 0; f < 6; f++) {
		cout << race_percentages[f] << '\n';
	}*/
	dataExtractCensusData(a, norcd, cd);
	//cout << '\n' << a[50].getOther();
	a[0].calculatePercent(0);
	//cout << '\n' << race_percentages[0];
	string s = b[4].getState();
	string t = a[6].getState();
	cout << b[4].getState() << a[6].getState()<<endl;
	cout << s.compare(t) << endl;
	cout << t[0] << endl << t[1];
	cout << strcmp1(s, t) << endl;
	cout << t.compare(s) << endl;
	cout << strcmp1(t, s) << endl;
	cout << t.compare("CO") << endl;
	cout << strcmp1(t, "CO") << endl;
	cout << s.compare("CO") << endl;
	cout << strcmp1(s, "CO") << endl;
	
		
}
