static inline void ltrim(string &s);
static inline void rtrim(std::string &s);
static inline void trim(std::string &s);
void dataExtractPoliceShooting(Case a[], int b, string c);
void dataExtractCensusData(State a[], int b, string c);
void bodyCamPercent(Case a[], double b, double c[]);
void racePercent(Case a[], int b, double c[]);
void stateRacePopComp(Case a[], int b, int d, double c[]);
int rowCount(string a);
int strcmp1(string a1, string a2);


void racePercent(Case a[], int b, double c[]) {
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
	char str[64];
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
			ft.getline(str, 16, ',');
			//cout << str << '\n';
			str1[j] = str;

			//cout << str1[j] << '\n';

		}

		trim(str1[0]);
		a[i].setState(str1[0]);
		//cout << a[1].getState() << '\n';
		a[i].setTotal(str1[1]);
		//cout << a[1].getTotal() << '\n';
		a[i].setHispanic(str1[2]);
		//cout << a[1].getHispanic() << '\n';
		a[i].setWhite(str1[3]);
		//cout << a[1].getWhite() << '\n';
		a[i].setBlack(str1[4]);
		//cout << a[1].getBlack() << '\n';
		a[i].setAsian(str1[5]);
		//cout << a[1].getAsian() << '\n';
		a[i].setNative(str1[6]);
		//cout << a[1].getNative() << '\n';
		a[i].setOther(str1[7]);
		//cout << a[1].getOther() << '\n';
		for (int k = 0; k < 6; k++) {
			a[i].calculatePercent(k);
		}
	}
	ft.close();
}
/*void stateRacePopComp(Case a[], State b[], int c, int d, double e[]) {
	string s;
	int count = 0;
	for (int i = 0; i < c; i++) {
		s = a[i].getState();
		for (int j = 0; j < d; j++) {
			if (s.compare(b[j].getState()) == 0) {
				count++;
			}
			else if(s.compare)
		}



	}

}*/
int strcmp1(string a1, string a2) {
	int s = 0, n = 0 ;
	if (a1.size() == a2.size()) {
		for (int j = 0; j < a1.size(); j++) {
			while(n != 0){
				if (int(a1[j] == a2[j])) {
					n = 0;
				}
				else if (int(a1[j]) <= int(a2[j])) {
					return -1;

				}
				else {
					return 1;
				}
			}

		}
		return 0;
	}
}
static inline void ltrim(std::string &s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
		return !std::isspace(ch);
		}));
}
static inline void rtrim(std::string &s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
		return !std::isspace(ch);
		}).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
	ltrim(s);
	rtrim(s);
}


