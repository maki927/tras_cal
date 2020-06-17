#include "LOAD_SAVE.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

void LOAD_SAVE::DataLoad() {
	char str[100], fid[200];
	char c;
	int i = 0, jump = 0;
	formnum = 0;

	cout << "読み込むファイルを指定:";
	cin >> fid;

	ifstream loadfile(fid);
	if (!loadfile) {
		cout << "can't open the file\n";
	}

	while (loadfile.get(c)) {
		if (isalpha(c) || ispunct(c) || isdigit(c)) {
			switch (jump)
			{
			case 0:
				str[i] = c; str[i + 1] = '\0';
				i++;
				if (strcmp(str, "formula:") == 0) {
					jump = 1; i = 0;
				}
				if (strcmp(str, "density:") == 0) {
					jump = 2; i = 0;
				}
				if (strcmp(str, "thickness:") == 0) {
					jump = 3; i = 0;
				}
				if (strcmp(str, "Energy_min:") == 0) {
					jump = 4; i = 0;
				}
				if (strcmp(str, "Energy_inter:") == 0) {
					jump = 5; i = 0;
				}
				if (strcmp(str, "Energy_max:") == 0) {
					jump = 6; i = 0;
				}
				break;
			case 1:
				if (c == ';') {
					i = 0; jump = 0;
					strcpy(formula, str);
					break;
				}
				str[i] = c; str[i + 1] = '\0';
				i++; formnum++;
				break;
			case 2:
				if ((c == ';')) {
					i = 0; jump = 0;
					density = atof(str);
					break;
				}
				str[i] = c; str[i + 1] = '\0';
				i++;
				break;
			case 3:
				if ((c == ';')) {
					i = 0; jump = 0;
					thickness = atof(str);
					break;
				}
				str[i] = c; str[i + 1] = '\0';
				i++;
				break;
			case 4:
				if ((c == ';')) {
					i = 0; jump = 0;
					Energy_min = atof(str);
					break;
				}
				str[i] = c; str[i + 1] = '\0';
				i++;
				break;
			case 5:
				if ((c == ';')) {
					i = 0; jump = 0;
					Energy_inter = atof(str);
					break;
				}
				str[i] = c; str[i + 1] = '\0';
				i++;
				break;
			case 6:
				if ((c == ';')) {
					i = 0; jump = 0;
					Energy_max = atof(str);
					break;
				}
				str[i] = c; str[i + 1] = '\0';
				i++;
				break;
			}
		}
		
		
	}
	return;
}


void LOAD_SAVE::DataSave(char* name, int namenum, float* Xdata, float* Ydata, int datanum) {

	time_t timedata = time(NULL);
	struct tm* local = localtime(&timedata);


	string YEAR = to_string(local->tm_year);
	
	ostringstream mon;
	mon << setw(2) << setfill('0') << local->tm_mon + 1;
	string MON(mon.str());

	ostringstream day;
	day << setw(2) << setfill('0') << local->tm_mday;
	string DAY(day.str());

	ostringstream hour;
	hour << setw(2) << setfill('0') << local->tm_hour;
	string HOUR(hour.str());

	ostringstream min;
	min << setw(2) << setfill('0') << local->tm_min;
	string MIN(min.str());

	ostringstream sec;
	sec << setw(2) << setfill('0') << local->tm_sec;
	string SEC(sec.str());

	ostringstream file;
	file << name << '(' << formula << ')' << YEAR << MON << DAY << HOUR << MIN << SEC << ".txt";
	string FILE = file.str();


	ofstream writing_file;
	writing_file.open(FILE, ios::app);
	
	writing_file << "Density = " << density << "[g/cm^3]\t" << "Thickness = " << thickness << "[micron]\n";
	writing_file << "Energy[eV]" << '\t' << "Parameter" << '\n';

	for (int i = 0; i < datanum; i++) {
		writing_file << Xdata[i] << '\t' << Ydata[i] << '\n';
	}

	return;

}

void LOAD_SAVE::dispinfo() {

	cout << "formula = " << formula << '\n';
	cout << "density = " << density << '\n';
	cout << "thickness = " << thickness << '\n';
	cout << "Energy_min = " << Energy_min << '\n';
	cout << "Energy_inter = " << Energy_inter << '\n';
	cout << "Energy_max = " << Energy_max << '\n';

	return;
}

