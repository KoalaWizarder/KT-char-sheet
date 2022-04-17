#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <random>
#include <windows.h>
#include <chrono>
#include <thread>

using namespace std;

//STATS**************************************
int basStr = 18, basDex = 10, basCon = 16, basInt = 14, basWis = 14, basCha = 14;
int enhStr = 4, enhDex = 0, enhCon = 2, enhInt = 0, enhWis = 0, enhCha = 2;
int bab = 12, CLpal = 9, CLwiz = 14, lvl = 14, pal = 13, wiz = 1;
int currHP = 170, maxHP = 116 + (lvl * modCon) + lvl;
//*******************************************
int modStr = ((basStr + enhStr) - 10) / 2, modDex = ((basDex + enhDex) - 10) / 2, modCon = ((basCon + enhCon) - 10) / 2;
int modInt = ((basInt + enhInt) - 10) / 2, modWis = ((basWis + enhWis) - 10) / 2, modCha = ((basCha + enhCha) - 10) / 2;

bool userInLoop(string title)
{
	string userIn;
	cout << "YES - Type '1' and press ENTER" << '\n';
	cout << " NO - Simply press ENTER" << '\n';
	getline(cin, userIn);
	while (userIn != "1" && userIn != "") {
		cout << title << '\n';
		cout << "YES - Type '1' and press ENTER" << '\n';
		cout << " NO - Simply press ENTER" << '\n';
		getline(cin, userIn);
	}//End of Choice Loop
	system("CLS");
	if (userIn == "1")
		return true;
	else if (userIn == "")
		return false;
}//End of Function
bool isNumber(const string& s) {
	for (char const& ch : s) {
		if (isdigit(ch) == 0)
			return false;
	}
	return true;
}

//dice
int dice(int n = 0, int s = 0) {
	if (n == 0) {
		cout << "How many dice would you like to throw?\n";
		cout << "(Accepts any positive whole number)\n";
		string userIn;
		int x;
		do {
			getline(cin, userIn);
			if (isNumber(userIn) == true) {
				x = stoi(userIn);
				if (x > 0)
					n = x;
				else {
					cout << "Please enter a valid positive number\n";
					n = 0;
				}
			}
			else {
				cout << "Please enter a valid positive number\n";
				n = 0;
			}
		} while (n == 0);
	}
	if (s == 0) {
		cout << "What size of die would you like to throw?\n";
		cout << "(Accepts any positive whole number)\n";
		string userIn;
		int x;
		do {
			getline(cin, userIn);
			if (isNumber(userIn) == true) {
				x = stoi(userIn);
				if (x > 0)
					s = x;
				else {
					cout << "Please enter a valid positive number\n";
					s = 0;
				}
			}
			else {
				cout << "Please enter a valid positive number\n";
				s = 0;
			}
		} while (s == 0);
	}
	int total = 0;
	for (int x = 0; x < n; x++) {
		int roll = (1 + rand() / ((RAND_MAX / (s)+1)));
		total += roll;
		cout << "ROLLING\n";
		this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	return total;
}

//Misc Functions
int sizeF() {
	system("CLS");
	cout << "What is your current size?\n";
	cout << left << setw(17) << "1 - FINE" << setw(17) << "2 - DIMINUTIVE" << "3 - TINY\n";
	cout << left << setw(17) << "4 - SMALL" << setw(17) << "5 - MEDIUM" << "6 - LARGE\n";
	cout << left << setw(17) << "7 - HUGE" << setw(17) << "8 - HUGE" << "9 - GARGANTUAN\n";
	string x;
	getline(cin, x);
	while (x != "1" && x != "2" && x != "3" && x != "4" && x != "5" && x != "6" && x != "7" && x != "8" && x != "9" && x != "") {
		cout << "Please enter a valid selection\n";
		getline(cin, x);
	}
	if (x == "1")
		return 8;
	else if (x == "2")
		return 4;
	else if (x == "3")
		return 2;
	else if (x == "4")
		return 1;
	else if (x == "5" || x == "")
		return 0;
	else if (x == "6")
		return -1;
	else if (x == "7")
		return -2;
	else if (x == "8")
		return -4;
	else if (x == "9")
		return -8;
}
int handChoiceF() {
	system("CLS");
	string userIn;
	cout << "Are you wielding this weapon in 1-Hand or 2?\n";
	cout << "1 - Type '1' and press ENTER\n";
	cout << "2 - Type '2' and press ENTER\n";
	getline(cin, userIn);
	while (userIn != "1" && userIn != "2") {
		cout << "1-Hand or 2-Hand?" << '\n';
		cout << "1 - Type '1' and press ENTER" << '\n';
		cout << "2 - Type '2' and press ENTER" << '\n';
		getline(cin, userIn);
	}//End of Choice Loop
	if (userIn == "1")
		return 1;
	else if (userIn == "2")
		return 2;
}
bool lightWeaponF() {
	system("CLS");
	string userIn;
	cout << "Is this a Light Weapon?\n";
	cout << "YES - Type '1' and press ENTER\n";
	cout << " NO - Simply press ENTER\n";
	getline(cin, userIn);
	while (userIn != "1" && userIn != "") {
		cout << "Light Weapon?" << '\n';
		cout << "YES - Type '1' and press ENTER" << '\n';
		cout << " NO - Simply press ENTER" << '\n';
		getline(cin, userIn);
	}//End of Choice Loop
	if (userIn == "1")
		return true;
	else if (userIn == "")
		return false;
}
bool fullAttkF(){
	system("CLS");
	string userIn;
	cout << "Is this a Full Attack?\n";
	cout << "YES - Type '1' and press ENTER\n";
	cout << " NO - Simply press ENTER\n";
	getline(cin, userIn);
	while (userIn != "1" && userIn != "") {
		cout << "1-Hand or 2-Hand?" << '\n';
		cout << "YES - Type '1' and press ENTER" << '\n';
		cout << " NO - Simply press ENTER" << '\n';
		getline(cin, userIn);
	}//End of Choice Loop
	if (userIn == "1")
		return true;
	else if (userIn == "")
		return false;
}
int enhBF() {
	system("CLS");
	cout << "What is the enhancement bonus of the weapon?\n";
	cout << "Please leave blank if none\n";
	string userIn;
	int x;
	while (true) {
		getline(cin, userIn);
		if (userIn == "")
			return 0;
		if (isNumber(userIn) == true) {
			x = stoi(userIn);
			if (x > -1 && x <= 5)
				return x;
			else
				cout << "Enhancement Bonus?\n" << "Can leave blank if none: ";
		}
		else
			cout << "Enhancement Bonus?\n" << "Can leave blank if none: ";
	}
}
int critF(){
	system("CLS");
	cout << "What is the critical threshold for this weapon?\n";
	cout << "Can leave blank if only threatens on 20: ";
	string userIn;
	int x;
	while (true) {
		getline(cin, userIn);
		if (userIn == "")
			return 20;
		if (isNumber(userIn) == true) {
			x = stoi(userIn);
			if (x > 0 && x <= 20)
				return x;
			else
				cout << "Critical Threshold?\n" << "Can leave blank if only threatens on 20: ";
		}
		else
			cout << "Critical Threshold?\n" << "Can leave blank if only threatens on 20: ";
	}
}
int multF() {
	system("CLS");
	cout << "What is the critical multiplier for this weapon?\n";
	cout << "Can leave blank if x2: ";
	string userIn;
	int x;
	while (true) {
		getline(cin, userIn);
		if (userIn == "")
			return 2;
		if (isNumber(userIn) == true) {
			x = stoi(userIn);
			return x;
		}
		else
			cout << "Critical Multiplier?\n" << "Can leave blank if x2: ";
	}
}
bool offHandF() {
	system("CLS");
	string userIn;
	cout << "Is this attack from your off-hand?\n";
	cout << "YES - Type '1' and press ENTER\n";
	cout << " NO - Simply press ENTER\n";
	getline(cin, userIn);
	while (userIn != "1" && userIn != "") {
		cout << "Off-Hand Attack?" << '\n';
		cout << "YES - Type '1' and press ENTER" << '\n';
		cout << " NO - Simply press ENTER" << '\n';
		getline(cin, userIn);
	}//End of Choice Loop
	system("CLS");
	if (userIn == "1")
		return true;
	else if (userIn == "")
		return false;
}
int weaponDMG(string &base, int size = 0) {
	if (base == "1d2") {
		switch(size) {
		case 8: //FINE
		case 4: //DIMINUTIVE
		case 2: //TINY
			base = "0"; 
			return 0;
		case 1: //SMALL
			base = "1";
			return 1;
		case 0:  //MEDIUM
			base = "1d2";
			return dice(1, 2);
		case -1:  //LARGE
			base = "1d3";
			return dice(1, 3);
		case -2:  //HUGE
			base = "1d4";
			return dice(1, 4);
		case -4: //GARGANTUAN
			base = "1d6";
			return dice(1, 6);
		case -8:  //COLOSSAL
			base = "1d8";
			return dice(1, 8);
		}
	}
	if (base == "1d3")
	{
		switch (size) {
		case 8: //FINE
		case 4: //DIMINUTIVE
			base = "0";
			return 0;
		case 2: //TINY
			base = "1";
			return 1;
		case 1: //SMALL
			base = "1d2";
			return dice(1, 2);
		case 0:  //MEDIUM
			base = "1d3";
			return dice(1, 3);
		case -1:  //LARGE
			base = "1d4";
			return dice(1, 4);
		case -2:  //HUGE
			base = "1d6";
			return dice(1, 6);
		case -4:  //GARGANTUAN
			base = "1d8";
			return dice(1, 8);
		case -8:  //COLOSSAL
			base = "2d6";
			return dice(2, 6);
		}
	}
	if (base == "1d4")
	{
		switch (size) {
		case 8: //FINE
			base = "0";
			return 0;
		case 4: //DIMINUTIVE
			base = "1";
			return 1;
		case 2: //TINY
			base = "1d2";
			return dice(1, 2);
		case 1: //SMALL
			base = "1d3";
			return dice(1, 3);
		case 0:  //MEDIUM
			base = "1d4";
			return dice(1, 4);
		case -1:  //LARGE
			base = "1d6";
			return dice(1, 6);
		case -2:  //HUGE
			base = "1d8";
			return dice(1, 8);
		case -4:  //GARGANTUAN
			base = "2d6";
			return dice(2, 6);
		case -8:  //COLOSSAL
			base = "3d6";
			return dice(3, 6);
		}
	}
	if (base == "1d6")
	{
		switch (size) {
		case 8: //FINE
			base = "1";
			return 1;
		case 4: //DIMINUTIVE
			base = "1d2";
			return dice(1, 2);
		case 2: //TINY
			base = "1d3";
			return dice(1, 3);
		case 1: //SMALL
			base = "1d4";
			return dice(1, 4);
		case 0:  //MEDIUM
			base = "1d6";
			return dice(1, 6);
		case -1:  //LARGE
			base = "1d8";
			return dice(1, 8);
		case -2:  //HUGE
			base = "2d6";
			return dice(2, 6);
		case -4:  //GARGANTUAN
			base = "3d6";
			return dice(3, 6);
		case -8:  //COLOSSAL
			base = "4d6";
			return dice(4, 6);
		}
	}
	if (base == "2d4")
	{
		switch (size) {
		case 8: //FINE
			base = "1d2";
			return dice(1, 2);
		case 4: //DIMINUTIVE
			base = "1d3";
			return dice(1, 3);
		case 2: //TINY
			base = "1d4";
			return dice(1, 4);
		case 1: //SMALL
			base = "1d6";
			return dice(1, 6);
		case 0:  //MEDIUM
			base = "2d4";
			return dice(2, 4);
		case -1:  //LARGE
			base = "2d6";
			return dice(2, 6);
		case -2:  //HUGE
			base = "3d6";
			return dice(3, 6);
		case -4:  //GARGANTUAN
			base = "4d6";
			return dice(4, 6);
		case -8:  //COLOSSAL
			base = "6d6";
			return dice(6, 6);
		}
	}
	if (base == "1d8")
	{
		switch (size) {
		case 8: //FINE
			base = "1d2";
			return dice(1, 2);
		case 4: //DIMINUTIVE
			base = "1d3";
			return dice(1, 3);
		case 2: //TINY
			base = "1d4";
			return dice(1, 4);
		case 1: //SMALL
			base = "1d6";
			return dice(1, 6);
		case 0:  //MEDIUM
			base = "1d8";
			return dice(1, 8);
		case -1:  //LARGE
			base = "2d6";
			return dice(2, 6);
		case -2:  //HUGE
			base = "3d6";
			return dice(3, 6);
		case -4:  //GARGANTUAN
			base = "4d6";
			return dice(4, 6);
		case -8:  //COLOSSAL
			base = "6d6";
			return dice(6, 6);
		}
	}
	if (base == "1d10")
	{
		switch (size) {
		case 8: //FINE
			base = "1d3";
			return dice(1, 3);
		case 4: //DIMINUTIVE
			base = "1d4";
			return dice(1, 4);
		case 2: //TINY
			base = "1d6";
			return dice(1, 6);
		case 1: //SMALL
			base = "1d8";
			return dice(1, 8);
		case 0:  //MEDIUM
			base = "1d10";
			return dice(1, 10);
		case -1:  //LARGE
			base = "2d8";
			return dice(2, 8);
		case -2:  //HUGE
			base = "3d8";
			return dice(3, 8);
		case -4:  //GARGANTUAN
			base = "4d8";

			return dice(4, 8);
		case -8:  //COLOSSAL
			base = "6d8";
			return dice(6, 8);
		}
	}
	if (base == "1d12")
	{
		switch (size) {
		case 8: //FINE
			base = "1d4";
			return dice(1, 4);
		case 4: //DIMINUTIVE
			base = "1d6";
			return dice(1, 6);
		case 2: //TINY
			base = "1d8";
			return dice(1, 8);
		case 1: //SMALL
			base = "1d10";
			return dice(1, 10);
		case 0:  //MEDIUM
			base = "1d12";
			return dice(1, 12);
		case -1:  //LARGE
			base = "3d6";
			return dice(3, 6);
		case -2:  //HUGE
			base = "4d6";
			return dice(4, 6);
		case -4:  //GARGANTUAN
			base = "6d6";
			return dice(6, 6);
		case -8:  //COLOSSAL
			base = "8d6";
			return dice(8, 6);
		}
	}
	if (base == "2d6")
	{
		switch (size) {
		case 8: //FINE
			base = "1d4";
			return dice(1, 4);
		case 4: //DIMINUTIVE
			base = "1d6";
			return dice(1, 6);
		case 2: //TINY
			base = "1d8";
			return dice(1, 8);
		case 1: //SMALL
			base = "1d10";
			return dice(1, 10);
		case 0:  //MEDIUM
			base = "1d12";
			return dice(2, 6);
		case -1:  //LARGE
			base = "3d6";
			return dice(3, 6);
		case -2:  //HUGE
			base = "4d6";
			return dice(4, 6);
		case -4:  //GARGANTUAN
			base = "6d6";
			return dice(6, 6);
		case -8:  //COLOSSAL
			base = "8d6";
			return dice(8, 6);
		}
	}
}


//Power Attack Functions
int pwrAttkF(){
	system("CLS");
	cout << "Power Attack? (MAX:" << bab << ")\n" << "Type in the penalty to the attack roll without(-): ";
	string userIn;
	int x;
	while (true) {
		getline(cin, userIn);
		if (userIn == "")
			return 0;
		if (isNumber(userIn) == true) {
			x = stoi(userIn);
			if (x >= 0 && x <= bab)
				return x;
			else 
				cout << "Please enter a valid number between 0 and " << bab << ": ";
		}
		else 
			cout << "Please enter a valid number between 0 and " << bab << ": ";
	}
}
int pwrDmg1F(int pen){
	return pen;
}
int pwrDmgLF(int pen){
	return pen * 0.5;
}
int pwrDmg2F(int pen){
	return pen * 2;
}
int pwrDmgChoiceF(int pen, int hands) {
	if (hands == 1)
		return pen;
	else if (hands == 2)
		return pen * 2;
}
int pwrDmgF(int pen, int hands, bool light = false) {
	if (light == true) {
		return 0;
	}
	if (hands == 1) {
		return pen;
	}
	else if (hands == 2) {
		return pen * 2;
	}
}

//Conditional Buffs
int hasteF() {
	system("CLS");
	cout << "Is Haste active?\n";
	return userInLoop("Haste?");
}
int chargeF() {
	system("CLS");
	cout << "Are you charging?\n";
	return userInLoop("Charging?") * 2;
}
int flankF(){
	system("CLS");
	cout << "Are you flanking?\n";
	return userInLoop("Flanking?") * 2;
}
int oneMindF() {
	system("CLS");
	cout << "Is One Mind active?\n";
	return (userInLoop("One Mind?") * 2);
}
int divFavorF() {
	system("CLS");
	cout << "Is Divine Favor active?\n";
	int x = userInLoop("Divine Favor?") * ((int)CLpal / 3);
	if (x > 3)
		return 3;
	else
		return x;
}
int prayerF() {
	system("CLS");
	cout << "Is Prayer active?\n";
	return userInLoop("Prayer?");
}
int xtraAttkF() {
	system("CLS");
	cout << "Misc extra ATTACK bonus?\n";
	cout << " -leave blank if none-\n";
	string userIn;
	int x;
	while (true) {
		getline(cin, userIn);
		if (userIn == "")
			return 0;
		if (isNumber(userIn) == true) {
			x = stoi(userIn);
			return x;
		}
		else
			cout << "Misc ATTACK bonus?\n";
	}
}
int xtraDmgF() {
	cout << "Misc extra DAMAGE bonus?\n";
	cout << " -leave blank if none-\n";
	string userIn;
	int x;
	while (true) {
		getline(cin, userIn);
		if (userIn == "")
			return 0;
		if (isNumber(userIn) == true) {
			x = stoi(userIn);
			return x;
		}
		else
			cout << "Misc DAMAGE bonus?\n";
	}
}
int smiteAttkF(string smt) {
	system("CLS");
	cout << "Smite Attack [" << smt << "]?\n";
	return userInLoop("Smite Attack?");
}
int divSacF() {
	system("CLS");
	cout << "Is Divine Sacrifice active?\n";
	return userInLoop("Divine Sacrifice?") * dice(5, 6);
}
int valorousF() {
	system("CLS");
	cout << "Is Valorous applicable?\n";
	return userInLoop("Valorous?");
}
int rhinoRushF() {
	system("CLS");
	cout << "Is Rhino's Rush active?\n";
	return userInLoop("Rhino Rush?");
}
int spiritChgF() {
	system("CLS");
	cout << "Is Spirited Charge applicable?\n";
	return userInLoop("Spirited Charge?");
}
int rubicondF() {
	if (currHP <= (maxHP / 2))
		return 3;
	else
		return 0;
}
int armbandsF(int pwrAttk) {
	if (pwrAttk >= 2)
		return 2;
	else
		return 0;
}

//Weapon Macros
void sharrash(string dmg = "1d10", int hands = 2, int enh = 2, int crit = 17, int mult = 4, bool light = false) {
	bool toggle = true;
	if (light == true) {
		hands = 1;
	}
	else if (hands != 1 && hands != 2) {
		hands = handChoiceF();
	}
	int size = sizeF();
	while (toggle) {
		//ATTACK ROLLS vvvv
		int AR[25], DR[40];
		for (int i = 0; i < 25; i++) {
			AR[i] = dice(1, 20);
		}
		//DAMAGE ROLLS vvvv
		string damage = dmg;
		for (int i = 0; i < 25; i++) {
			DR[i] = weaponDMG(damage, size);
			if (i < 39)
				damage = dmg;
		}
		int cc[5] = { 0, 0, 0, 0, 0 }, cd[5] = { 0, 0, 0, 0, 0 };
		int pwrAttk = pwrAttkF();
		int pwrDmg = pwrDmgF(pwrAttk, hands, light);
		bool fullAttk;
		int charge = chargeF();
		int rhinoRush = 0, spiritChg = 0, valor = 0;
		if (charge == 2)
			fullAttk = false, rhinoRush = rhinoRushF(), spiritChg = spiritChgF(), valor = valorousF();
		else
			fullAttk = fullAttkF();
		int haste = hasteF();
		int smtAttk[5] = { smiteAttkF("1"), 0, 0, 0, 0};
		if (fullAttk == true) {
			if (bab >= 5)
				smtAttk[1] = smiteAttkF("2");
			if (bab >= 10)
				smtAttk[2] = smiteAttkF("3");
			if (bab >= 15)
				smtAttk[3] = smiteAttkF("4");
			if (haste == true)
				smtAttk[4] = smiteAttkF("H");
		}
		int flank = flankF();
		int xtraAttk = xtraAttkF(), xtraDmg = xtraDmgF();
		int oneMind = oneMindF();
		int divSac = divSacF();
		int prayer = prayerF();
		int divFavor = divFavorF();
		int rubicond = rubicondF();
		int armbands = armbandsF(pwrAttk);
		int critR[25];
		int a = bab + modStr + size + enh + flank - pwrAttk + oneMind + divFavor + haste + prayer + xtraAttk;
		int d = enh + pwrDmg + oneMind + divFavor + prayer + armbands + rubicond + xtraDmg;
		if (hands == 1) {
			if (light == true && offHandF() == true) {
				d += (int)modStr * .5;
			}
			else
				d += modStr;
		}
		else if (hands == 2)
			d += ((int)modStr * 1.5);
		int A[5], D[5];
		//ATTACK ONE vvvv
		int di = 5, critI = 0;
		A[0] = AR[0] + a + (smtAttk[0] * pal) + charge;
		D[0] = DR[0] + d + (smtAttk[0] * modCha) + divSac + (rhinoRush * ((DR[di++] + d) + (smtAttk[0] * modCha))) + //Rhino Rush = DR[5]
			(spiritChg * ((DR[di++] + d) + (smtAttk[0] * modCha))) + //Spirited Charge = DR[6]
			(valor * ((DR[di++] + d) + (smtAttk[0] * modCha))); //Valorous = DR[7]
		if (AR[0] >= crit) {
			cc[0] = AR[5] + a + (smtAttk[0] * pal) + charge;
			for (int x = 1; x <= mult - 1; x++) {
				cd[0] += DR[di] + d + (smtAttk[0] * modCha);
				critR[critI++] = DR[di++];
			}
		}
		if (fullAttk == true) {
			//ATTACK TWO vvvv
			A[1] = AR[1] + a + (smtAttk[1] * pal) - 5;
			D[1] = DR[1] + d + (smtAttk[1] * modCha);
			if (AR[1] >= crit) {
				cc[1] = AR[6] + a + (smtAttk[1] * pal) - 5;
				for (int x = 1; x <= mult - 1; x++) {
					cd[1] += DR[di] + d + (smtAttk[1] * modCha);
					critR[critI++] = DR[di++];
				}
			}
			//ATTACK THREE vvvv
			A[2] = AR[2] + a + (smtAttk[2] * pal) - 10;
			D[2] = DR[2] + d + (smtAttk[2] * modCha);
			if (AR[2] >= crit) {
				cc[2] = AR[7] + a + (smtAttk[2] * pal) - 10;
				for (int x = 1; x <= mult - 1; x++) {
					cd[2] += DR[di] + d + (smtAttk[2] * modCha);
					critR[critI++] = DR[di++];
				}
			}
			//ATTACK FOUR vvvv
			A[3] = AR[3] + a + (smtAttk[3] * pal) - 15;
			D[3] = DR[3] + d + (smtAttk[3] * modCha);
			if (AR[3] >= crit) {
				cc[3] = AR[8] + a + (smtAttk[3] * pal) - 15;
				for (int x = 1; x <= mult - 1; x++) {
					cd[3] += DR[di] + d + (smtAttk[3] * modCha);
					critR[critI++] = DR[di++];
				}
			}
			if (haste == 1) {
				//ATTACK HASTE vvvv
				A[4] = AR[4] + a + (smtAttk[4] * pal);
				D[4] = DR[4] + d + (smtAttk[4] * modCha);
				if (AR[4] >= crit) {
					cc[4] = AR[9] + a + (smtAttk[4] * pal);
					for (int x = 1; x <= mult - 1; x++) {
						cd[4] += DR[di] + d + (smtAttk[4] * modCha);
						critR[critI++] = DR[di++];
					}
				}
			}
		}
		critI = 0;
		//ATTACK ONE OUTPUT vvvv
		cout << " A1:" << right << setw(3) << A[0] << "(" << setw(2) << AR[0] << ") |";
		cout << " D1:" << setw(3) << D[0] << "(" << setw(2) << DR[0] << ") || ";
		if (AR[0] >= crit) {
			cout << "CA1:" << setw(3) << cc[0] << "(" << setw(2) << AR[5] << ") | ";
			cout << "CD1:" << setw(3) << cd[0] << "(";
			for (int n = 1; n <= mult - 1; n++) {
				if (n > 1)
					cout << '+';
				cout << critR[critI++];
			}
			cout << ')';
		}
		cout << '\n';
		if (fullAttk == true) {
			//ATTACK TWO OUTPUT vvvv
			if (bab >= 5) {
				cout << " A2:" << setw(3) << A[1] << "(" << setw(2) << AR[1] << ") |";
				cout << " D2:" << setw(3) << D[1] << "(" << setw(2) << DR[1] << ") || ";
				if (AR[1] >= crit) {
					cout << "CA2:" << setw(3) << cc[1] << "(" << setw(2) << AR[6] << ") | ";
					cout << "CD2:" << setw(3) << cd[1] << "(";
					for (int n = 1; n <= mult - 1; n++) {
						if (n > 1)
							cout << '+';
						cout << critR[critI++];
					}
					cout << ')';
				}
				cout << '\n';
			}
			//ATTACK THREE OUTPUT vvvv
			if (bab >= 10) {
				cout << " A3:" << setw(3) << A[2] << "(" << setw(2) << AR[2] << ") |";
				cout << " D3:" << setw(3) << D[2] << "(" << setw(2) << DR[2] << ") || ";
				if (AR[2] >= crit) {
					cout << "CA3:" << setw(3) << cc[2] << "(" << setw(2) << AR[7] << ") | ";
					cout << "CD3:" << setw(3) << cd[2] << "(";
					for (int n = 1; n <= mult - 1; n++) {
						if (n > 1)
							cout << '+';
						cout << critR[critI++];
					}
					cout << ')';
				}
				cout << '\n';
			}
			//ATTACK FOUR OUTPUT vvvv
			if (bab >= 15) {
				cout << " A4:" << setw(3) << A[3] << "(" << setw(2) << AR[3] << ") |";
				cout << " D4:" << setw(3) << D[3] << "(" << setw(2) << DR[3] << ") || ";
				if (AR[3] >= crit) {
					cout << "CA4:" << setw(3) << cc[3] << "(" << setw(2) << AR[8] << ") | ";
					cout << "CD4:" << setw(3) << cd[3] << "(";
					for (int n = 1; n <= mult - 1; n++) {
						if (n > 1)
							cout << '+';
						cout << critR[critI++];
					}
					cout << ')';
				}
				cout << '\n';
			}
			//ATTACK HASTE OUTPUT vvvv
			if (haste == 1) {
				cout << " AH:" << setw(3) << A[4] << "(" << setw(2) << AR[4] << ") |";
				cout << " DH:" << setw(3) << D[4] << "(" << setw(2) << DR[4] << ") || ";
				if (AR[4] >= crit) {
					cout << "CAH:" << setw(3) << cc[4] << "(" << setw(2) << AR[9] << ") | ";
					cout << "CDH:" << setw(3) << cd[4] << "(";
					for (int n = 1; n <= mult - 1; n++) {
						if (n > 1)
							cout << '+';
						cout << critR[critI++];
					}
					cout << ')';
				}
				cout << '\n';
			}
		}
		cout << setfill('*') << setw(45) << '\n';
		setfill(' ');
		//ATTACK/DAMAGE OUTPUT EQUATIONS vvvv 
		cout << "-Attack: " << a << " {";
		if (bab != 0)
			cout << bab << "[BAB]";
		if (modStr != 0)
			cout << " + " << modStr << "[STR]";
		if (size != 0)
			cout << " + " << size << "[SIZE]";
		if (enh != 0)
			cout << " + " << enh << "[ENH]";
		if (pwrAttk != 0)
			cout << " + (-" << pwrAttk << ")[PWR]";
		if (flank != 0)
			cout << " + " << flank << "[FLNK]";
		if (oneMind != 0)
			cout << " + " << oneMind << "[OneMind]";
		if (divFavor != 0)
			cout << " + " << divFavor << "[DivFav]";
		if (haste != 0)
			cout << " + " << haste << "[HST]";
		if (prayer != 0)
			cout << " + " << prayer << "[PRYR]";
		if (xtraAttk != 0)
			cout << " + " << xtraAttk << "[MISC]";
		cout << "}\n";

		cout << "-Cond. ATK Bonuses: ";
		if (charge != 0)
			cout << '+' << charge << "[CHRG]";
		if (smtAttk[0] != 0)
			cout << "//" << '+' << pal << "[SMT1]";
		if (smtAttk[1] != 0)
			cout << "//" << '+' << pal << "[SMT2]";
		if (smtAttk[2] != 0)
			cout << "//" << '+' << pal << "[SMT3]";
		if (smtAttk[3] != 0)
			cout << "//" << '+' << pal << "[SMT4]";
		if (smtAttk[4] != 0)
			cout << "//" << '+' << pal << "[SMT-H]";
		cout << '\n';

		cout << "-Damage: " << d << " {";
		if (modStr != 0) {
			switch (hands) {
			case 1:
				cout << modStr;
				break;
			case 2:
				cout << ((int)modStr * 1.5);
				break;
			}
			cout << "[STR]";
		}
		if (enh != 0)
			cout << " + " << enh << "[ENH]";
		if (pwrDmg != 0)
			cout << " + " << pwrDmg << "[PWR]";
		if (oneMind != 0)
			cout << " + " << oneMind << "[OneMind]";
		if (divFavor != 0)
			cout << " + " << divFavor << "[DivFav]";
		if (prayer != 0)
			cout << " + " << prayer << "[PRYR]";
		if (armbands != 0)
			cout << " + " << armbands << "[ArmBnds]";
		if (rubicond != 0)
			cout << " + " << rubicond << "[Rbicnd]";
		if (xtraDmg != 0)
			cout << " + " << xtraDmg << "[MISC]";
		cout << "}\n";

		cout << "-Cond. DMG Bonuses: ";
		if (smtAttk[0] != 0)
			cout << '+' << modCha << "[SMT1]";
		if (smtAttk[1] != 0)
			cout << "//" << '+' << modCha << "[SMT2]";
		if (smtAttk[2] != 0)
			cout << "//" << '+' << modCha << "[SMT3]";
		if (smtAttk[3] != 0)
			cout << "//" << '+' << modCha << "[SMT4]";
		if (smtAttk[4] != 0)
			cout << "//" << '+' << modCha << "[SMT-H]";
		if (divSac != 0)
			cout << "//" << '+' << divSac << "[DivSac]";
		if (rhinoRush != 0)
			cout << "//" << '+' << (rhinoRush * ((DR[5] + d) + (smtAttk[0] * modCha))) << "(" << setw(2) << DR[5] << ")[RHINO]";
		if (spiritChg != 0)
			cout << "//" << '+' << (spiritChg * ((DR[6] + d) + (smtAttk[0] * modCha))) << "(" << setw(2) << DR[6] << ")[SprtCHRG]";
		if (valor != 0)
			cout << "//" << '+' << (valor * ((DR[7] + d) + (smtAttk[0] * modCha))) << "(" << setw(2) << DR[7] << ")[VALOR]";
		cout << '\n';

		cout << "-WEAPON DAMAGE: " << damage << '\n';
		cout << "-CRIT = Damage x" << mult << '\n';
		cout << "-Do not multiply:\n";
		if (divSac != 0)
			cout << "---Divine Sacrifice\n";
		if (rhinoRush != 0)
			cout << "---Rhino Rush\n";
		if (spiritChg != 0)
			cout << "---Spirited Charge\n";
		if (valor != 0)
			cout << "---Valorous\n";
		cout << "\n\n";
		system("pause");
		cout << '\n';
		cout << "Would you like to run this attack macro again?\n";
		toggle = userInLoop("Attack Again?");
	}
}
void waraxe(string dmg = "1d10", int hands = 0, int enh = 2, int crit = 20, int mult = 3, bool light = false) {
	bool toggle = true;
	if (light == true) {
		hands = 1;
	}
	else if (hands != 1 && hands != 2) {
		hands = handChoiceF();
	}
	int size = sizeF();
	while (toggle) {
		//ATTACK ROLLS vvvv
		int AR[25], DR[40];
		for (int i = 0; i < 25; i++) {
			AR[i] = dice(1, 20);
		}
		//DAMAGE ROLLS vvvv
		string damage = dmg;
		for (int i = 0; i < 40; i++) {
			DR[i] = weaponDMG(damage, size);
			if (i < 39)
				damage = dmg;
		}
		int cc[5] = { 0, 0, 0, 0, 0 }, cd[5] = { 0, 0, 0, 0, 0 };
		int pwrAttk = pwrAttkF();
		int pwrDmg = pwrDmgF(pwrAttk, hands, light);
		bool fullAttk;
		int charge = chargeF();
		int rhinoRush = 0, spiritChg = 0, valor = 0;
		if (charge == 2)
			fullAttk = false, rhinoRush = rhinoRushF(), spiritChg = spiritChgF(), valor = 0;
		else
			fullAttk = fullAttkF();
		int haste = hasteF();
		int smtAttk[5] = { smiteAttkF("1"), 0, 0, 0, 0 };
		if (fullAttk == true) {
			if (bab >= 5)
				smtAttk[1] = smiteAttkF("2");
			if (bab >= 10)
				smtAttk[2] = smiteAttkF("3");
			if (bab >= 15)
				smtAttk[3] = smiteAttkF("4");
			if (haste == true)
				smtAttk[4] = smiteAttkF("H");
		}
		int flank = flankF();
		int xtraAttk = xtraAttkF(), xtraDmg = xtraDmgF();
		int oneMind = oneMindF();
		int divSac = divSacF();
		int prayer = prayerF();
		int divFavor = divFavorF();
		int rubicond = rubicondF();
		int armbands = armbandsF(pwrAttk);
		int critR[25];
		int a = bab + modStr + size + enh + flank - pwrAttk + oneMind + divFavor + haste + prayer + xtraAttk;
		int d = enh + pwrDmg + oneMind + divFavor + prayer + armbands + rubicond + xtraDmg;
		if (hands == 1) {
			if (light == true && offHandF() == true) {
				d += (int)modStr * .5;
			}
			else
				d += modStr;
		}
		else if (hands == 2)
			d += ((int)modStr * 1.5);
		int A[5], D[5];
		//ATTACK ONE vvvv
		int di = 5, critI = 0;
		A[0] = AR[0] + a + (smtAttk[0] * pal) + charge;
		D[0] = DR[0] + d + (smtAttk[0] * modCha) + divSac + (rhinoRush * ((DR[di++] + d) + (smtAttk[0] * modCha))) + //Rhino Rush = DR[5]
			(spiritChg * ((DR[di++] + d) + (smtAttk[0] * modCha))) + //Spirited Charge = DR[6]
			(valor * ((DR[di++] + d) + (smtAttk[0] * modCha))); //Valorous = DR[7]
		if (AR[0] >= crit) {
			cc[0] = AR[5] + a + (smtAttk[0] * pal) + charge;
			for (int x = 1; x <= mult - 1; x++) {
				cd[0] += DR[di] + d + (smtAttk[0] * modCha);
				critR[critI++] = DR[di++];
			}
		}
		if (fullAttk == true) {
			//ATTACK TWO vvvv
			A[1] = AR[1] + a + (smtAttk[1] * pal) - 5;
			D[1] = DR[1] + d + (smtAttk[1] * modCha);
			if (AR[1] >= crit) {
				cc[1] = AR[6] + a + (smtAttk[1] * pal) - 5;
				for (int x = 1; x <= mult - 1; x++) {
					cd[1] += DR[di] + d + (smtAttk[1] * modCha);
					critR[critI++] = DR[di++];
				}
			}
			//ATTACK THREE vvvv
			A[2] = AR[2] + a + (smtAttk[2] * pal) - 10;
			D[2] = DR[2] + d + (smtAttk[2] * modCha);
			if (AR[2] >= crit) {
				cc[2] = AR[7] + a + (smtAttk[2] * pal) - 10;
				for (int x = 1; x <= mult - 1; x++) {
					cd[2] += DR[di] + d + (smtAttk[2] * modCha);
					critR[critI++] = DR[di++];
				}
			}
			//ATTACK FOUR vvvv
			A[3] = AR[3] + a + (smtAttk[3] * pal) - 15;
			D[3] = DR[3] + d + (smtAttk[3] * modCha);
			if (AR[3] >= crit) {
				cc[3] = AR[8] + a + (smtAttk[3] * pal) - 15;
				for (int x = 1; x <= mult - 1; x++) {
					cd[3] += DR[di] + d + (smtAttk[3] * modCha);
					critR[critI++] = DR[di++];
				}
			}
			if (haste == 1) {
				//ATTACK HASTE vvvv
				A[4] = AR[4] + a + (smtAttk[4] * pal);
				D[4] = DR[4] + d + (smtAttk[4] * modCha);
				if (AR[4] >= crit) {
					cc[4] = AR[9] + a + (smtAttk[4] * pal);
					for (int x = 1; x <= mult - 1; x++) {
						cd[4] += DR[di] + d + (smtAttk[4] * modCha);
						critR[critI++] = DR[di++];
					}
				}
			}
		}
		critI = 0;
		//ATTACK ONE OUTPUT vvvv
		cout << " A1:" << right << setw(3) << A[0] << "(" << setw(2) << AR[0] << ") |";
		cout << " D1:" << setw(3) << D[0] << "(" << setw(2) << DR[0] << ") || ";
		if (AR[0] >= crit) {
			cout << "CA1:" << setw(3) << cc[0] << "(" << setw(2) << AR[5] << ") | ";
			cout << "CD1:" << setw(3) << cd[0] << "(";
			for (int n = 1; n <= mult - 1; n++) {
				if (n > 1)
					cout << '+';
				cout << critR[critI++];
			}
			cout << ')';
		}
		cout << '\n';
		if (fullAttk == true) {
			//ATTACK TWO OUTPUT vvvv
			if (bab >= 5) {
				cout << " A2:" << setw(3) << A[1] << "(" << setw(2) << AR[1] << ") |";
				cout << " D2:" << setw(3) << D[1] << "(" << setw(2) << DR[1] << ") || ";
				if (AR[1] >= crit) {
					cout << "CA2:" << setw(3) << cc[1] << "(" << setw(2) << AR[6] << ") | ";
					cout << "CD2:" << setw(3) << cd[1] << "(";
					for (int n = 1; n <= mult - 1; n++) {
						if (n > 1)
							cout << '+';
						cout << critR[critI++];
					}
					cout << ')';
				}
				cout << '\n';
			}
			//ATTACK THREE OUTPUT vvvv
			if (bab >= 10) {
				cout << " A3:" << setw(3) << A[2] << "(" << setw(2) << AR[2] << ") |";
				cout << " D3:" << setw(3) << D[2] << "(" << setw(2) << DR[2] << ") || ";
				if (AR[2] >= crit) {
					cout << "CA3:" << setw(3) << cc[2] << "(" << setw(2) << AR[7] << ") | ";
					cout << "CD3:" << setw(3) << cd[2] << "(";
					for (int n = 1; n <= mult - 1; n++) {
						if (n > 1)
							cout << '+';
						cout << critR[critI++];
					}
					cout << ')';
				}
				cout << '\n';
			}
			//ATTACK FOUR OUTPUT vvvv
			if (bab >= 15) {
				cout << " A4:" << setw(3) << A[3] << "(" << setw(2) << AR[3] << ") |";
				cout << " D4:" << setw(3) << D[3] << "(" << setw(2) << DR[3] << ") || ";
				if (AR[3] >= crit) {
					cout << "CA4:" << setw(3) << cc[3] << "(" << setw(2) << AR[8] << ") | ";
					cout << "CD4:" << setw(3) << cd[3] << "(";
					for (int n = 1; n <= mult - 1; n++) {
						if (n > 1)
							cout << '+';
						cout << critR[critI++];
					}
					cout << ')';
				}
				cout << '\n';
			}
			//ATTACK HASTE OUTPUT vvvv
			if (haste == 1) {
				cout << " AH:" << setw(3) << A[4] << "(" << setw(2) << AR[4] << ") |";
				cout << " DH:" << setw(3) << D[4] << "(" << setw(2) << DR[4] << ") || ";
				if (AR[4] >= crit) {
					cout << "CAH:" << setw(3) << cc[4] << "(" << setw(2) << AR[9] << ") | ";
					cout << "CDH:" << setw(3) << cd[4] << "(";
					for (int n = 1; n <= mult - 1; n++) {
						if (n > 1)
							cout << '+';
						cout << critR[critI++];
					}
					cout << ')';
				}
				cout << '\n';
			}
		}
		cout << setfill('*') << setw(45) << '\n';
		setfill(' ');
		//ATTACK/DAMAGE OUTPUT EQUATIONS vvvv 
		cout << "-Attack: " << a << " {";
		if (bab != 0)
			cout << bab << "[BAB]";
		if (modStr != 0)
			cout << " + " << modStr << "[STR]";
		if (size != 0)
			cout << " + " << size << "[SIZE]";
		if (enh != 0)
			cout << " + " << enh << "[ENH]";
		if (pwrAttk != 0)
			cout << " + (-" << pwrAttk << ")[PWR]";
		if (flank != 0)
			cout << " + " << flank << "[FLNK]";
		if (oneMind != 0)
			cout << " + " << oneMind << "[OneMind]";
		if (divFavor != 0)
			cout << " + " << divFavor << "[DivFav]";
		if (haste != 0)
			cout << " + " << haste << "[HST]";
		if (prayer != 0)
			cout << " + " << prayer << "[PRYR]";
		if (xtraAttk != 0)
			cout << " + " << xtraAttk << "[MISC]";
		cout << "}\n";

		cout << "-Cond. ATK Bonuses: ";
		if (charge != 0)
			cout << '+' << charge << "[CHRG]";
		if (smtAttk[0] != 0)
			cout << "//" << '+' << pal << "[SMT1]";
		if (smtAttk[1] != 0)
			cout << "//" << '+' << pal << "[SMT2]";
		if (smtAttk[2] != 0)
			cout << "//" << '+' << pal << "[SMT3]";
		if (smtAttk[3] != 0)
			cout << "//" << '+' << pal << "[SMT4]";
		if (smtAttk[4] != 0)
			cout << "//" << '+' << pal << "[SMT-H]";
		cout << '\n';

		cout << "-Damage: " << d << " {";
		if (modStr != 0) {
			switch (hands) {
			case 1:
				cout << modStr;
				break;
			case 2:
				cout << ((int)modStr * 1.5);
				break;
			}
			cout << "[STR]";
		}
		if (enh != 0)
			cout << " + " << enh << "[ENH]";
		if (pwrDmg != 0)
			cout << " + " << pwrDmg << "[PWR]";
		if (oneMind != 0)
			cout << " + " << oneMind << "[OneMind]";
		if (divFavor != 0)
			cout << " + " << divFavor << "[DivFav]";
		if (prayer != 0)
			cout << " + " << prayer << "[PRYR]";
		if (armbands != 0)
			cout << " + " << armbands << "[ArmBnds]";
		if (rubicond != 0)
			cout << " + " << rubicond << "[Rbicnd]";
		if (xtraDmg != 0)
			cout << " + " << xtraDmg << "[MISC]";
		cout << "}\n";

		cout << "-Cond. DMG Bonuses: ";
		if (smtAttk[0] != 0)
			cout << '+' << modCha << "[SMT1]";
		if (smtAttk[1] != 0)
			cout << "//" << '+' << modCha << "[SMT2]";
		if (smtAttk[2] != 0)
			cout << "//" << '+' << modCha << "[SMT3]";
		if (smtAttk[3] != 0)
			cout << "//" << '+' << modCha << "[SMT4]";
		if (smtAttk[4] != 0)
			cout << "//" << '+' << modCha << "[SMT-H]";
		if (divSac != 0)
			cout << "//" << '+' << divSac << "[DivSac]";
		if (rhinoRush != 0)
			cout << "//" << '+' << (rhinoRush * ((DR[5] + d) + (smtAttk[0] * modCha))) << "(" << setw(2) << DR[5] << ")[RHINO]";
		if (spiritChg != 0)
			cout << "//" << '+' << (spiritChg * ((DR[6] + d) + (smtAttk[0] * modCha))) << "(" << setw(2) << DR[6] << ")[SprtCHRG]";
		if (valor != 0)
			cout << "//" << '+' << (valor * ((DR[7] + d) + (smtAttk[0] * modCha))) << "(" << setw(2) << DR[7] << ")[VALOR]";
		cout << '\n';

		cout << "-WEAPON DAMAGE: " << damage << '\n';
		cout << "-CRIT = Damage x" << mult << '\n';
		cout << "-Do not multiply:\n";
		if (divSac != 0)
			cout << "---Divine Sacrifice\n";
		if (rhinoRush != 0)
			cout << "---Rhino Rush\n";
		if (spiritChg != 0)
			cout << "---Spirited Charge\n";
		if (valor != 0)
			cout << "---Valorous\n";
		cout << "\n\n";
		system("pause");
		cout << '\n';
		cout << "Would you like to run this attack macro again?\n";
		toggle = userInLoop("Attack Again?");
	}
}
void swordbow(string dmg = "2d6", int hands = 2, int enh = 1, int crit = 19, int mult = 2, bool light = false) {
	bool toggle = true;
	if (light == true) {
		hands = 1;
	}
	else if (hands != 1 && hands != 2) {
		hands = handChoiceF();
	}
	int size = sizeF();
	while (toggle) {
		//ATTACK ROLLS vvvv
		int AR[25], DR[40];
		for (int i = 0; i < 25; i++) {
			AR[i] = dice(1, 20);
		}
		//DAMAGE ROLLS vvvv
		string damage = dmg;
		for (int i = 0; i < 25; i++) {
			DR[i] = weaponDMG(damage, size);
			if (i < 39)
				damage = dmg;
		}
		int cc[5] = { 0, 0, 0, 0, 0 }, cd[5] = { 0, 0, 0, 0, 0 };
		int pwrAttk = pwrAttkF();
		int pwrDmg = pwrDmgF(pwrAttk, hands, light);
		bool fullAttk;
		int charge = chargeF();
		int rhinoRush = 0, spiritChg = 0, valor = 0;
		if (charge == 2)
			fullAttk = false, rhinoRush = rhinoRushF(), spiritChg = spiritChgF(), valor = 0;
		else
			fullAttk = fullAttkF();
		int haste = hasteF();
		int smtAttk[5] = { smiteAttkF("1"), 0, 0, 0, 0 };
		if (fullAttk == true) {
			if (bab >= 5)
				smtAttk[1] = smiteAttkF("2");
			if (bab >= 10)
				smtAttk[2] = smiteAttkF("3");
			if (bab >= 15)
				smtAttk[3] = smiteAttkF("4");
			if (haste == true)
				smtAttk[4] = smiteAttkF("H");
		}
		int flank = flankF();
		int xtraAttk = xtraAttkF(), xtraDmg = xtraDmgF();
		int oneMind = oneMindF();
		int divSac = divSacF();
		int prayer = prayerF();
		int divFavor = divFavorF();
		int rubicond = rubicondF();
		int armbands = armbandsF(pwrAttk);
		int critR[25];
		int a = bab + modStr + size + enh + flank - pwrAttk + oneMind + divFavor + haste + prayer + xtraAttk;
		int d = enh + pwrDmg + oneMind + divFavor + prayer + armbands + rubicond + xtraDmg;
		if (hands == 1) {
			if (light == true && offHandF() == true) {
				d += (int)modStr * .5;
			}
			else
				d += modStr;
		}
		else if (hands == 2)
			d += ((int)modStr * 1.5);
		int A[5], D[5];
		//ATTACK ONE vvvv
		int di = 5, critI = 0;
		A[0] = AR[0] + a + (smtAttk[0] * pal) + charge;
		D[0] = DR[0] + d + (smtAttk[0] * modCha) + divSac + (rhinoRush * ((DR[di++] + d) + (smtAttk[0] * modCha))) + //Rhino Rush = DR[5]
			(spiritChg * ((DR[di++] + d) + (smtAttk[0] * modCha))) + //Spirited Charge = DR[6]
			(valor * ((DR[di++] + d) + (smtAttk[0] * modCha))); //Valorous = DR[7]
		if (AR[0] >= crit) {
			cc[0] = AR[5] + a + (smtAttk[0] * pal) + charge;
			for (int x = 1; x <= mult - 1; x++) {
				cd[0] += DR[di] + d + (smtAttk[0] * modCha);
				critR[critI++] = DR[di++];
			}
		}
		if (fullAttk == true) {
			//ATTACK TWO vvvv
			A[1] = AR[1] + a + (smtAttk[1] * pal) - 5;
			D[1] = DR[1] + d + (smtAttk[1] * modCha);
			if (AR[1] >= crit) {
				cc[1] = AR[6] + a + (smtAttk[1] * pal) - 5;
				for (int x = 1; x <= mult - 1; x++) {
					cd[1] += DR[di] + d + (smtAttk[1] * modCha);
					critR[critI++] = DR[di++];
				}
			}
			//ATTACK THREE vvvv
			A[2] = AR[2] + a + (smtAttk[2] * pal) - 10;
			D[2] = DR[2] + d + (smtAttk[2] * modCha);
			if (AR[2] >= crit) {
				cc[2] = AR[7] + a + (smtAttk[2] * pal) - 10;
				for (int x = 1; x <= mult - 1; x++) {
					cd[2] += DR[di] + d + (smtAttk[2] * modCha);
					critR[critI++] = DR[di++];
				}
			}
			//ATTACK FOUR vvvv
			A[3] = AR[3] + a + (smtAttk[3] * pal) - 15;
			D[3] = DR[3] + d + (smtAttk[3] * modCha);
			if (AR[3] >= crit) {
				cc[3] = AR[8] + a + (smtAttk[3] * pal) - 15;
				for (int x = 1; x <= mult - 1; x++) {
					cd[3] += DR[di] + d + (smtAttk[3] * modCha);
					critR[critI++] = DR[di++];
				}
			}
			if (haste == 1) {
				//ATTACK HASTE vvvv
				A[4] = AR[4] + a + (smtAttk[4] * pal);
				D[4] = DR[4] + d + (smtAttk[4] * modCha);
				if (AR[4] >= crit) {
					cc[4] = AR[9] + a + (smtAttk[4] * pal);
					for (int x = 1; x <= mult - 1; x++) {
						cd[4] += DR[di] + d + (smtAttk[4] * modCha);
						critR[critI++] = DR[di++];
					}
				}
			}
		}
		critI = 0;
		//ATTACK ONE OUTPUT vvvv
		cout << " A1:" << right << setw(3) << A[0] << "(" << setw(2) << AR[0] << ") |";
		cout << " D1:" << setw(3) << D[0] << "(" << setw(2) << DR[0] << ") || ";
		if (AR[0] >= crit) {
			cout << "CA1:" << setw(3) << cc[0] << "(" << setw(2) << AR[5] << ") | ";
			cout << "CD1:" << setw(3) << cd[0] << "(";
			for (int n = 1; n <= mult - 1; n++) {
				if (n > 1)
					cout << '+';
				cout << critR[critI++];
			}
			cout << ')';
		}
		cout << '\n';
		if (fullAttk == true) {
			//ATTACK TWO OUTPUT vvvv
			if (bab >= 5) {
				cout << " A2:" << setw(3) << A[1] << "(" << setw(2) << AR[1] << ") |";
				cout << " D2:" << setw(3) << D[1] << "(" << setw(2) << DR[1] << ") || ";
				if (AR[1] >= crit) {
					cout << "CA2:" << setw(3) << cc[1] << "(" << setw(2) << AR[6] << ") | ";
					cout << "CD2:" << setw(3) << cd[1] << "(";
					for (int n = 1; n <= mult - 1; n++) {
						if (n > 1)
							cout << '+';
						cout << critR[critI++];
					}
					cout << ')';
				}
				cout << '\n';
			}
			//ATTACK THREE OUTPUT vvvv
			if (bab >= 10) {
				cout << " A3:" << setw(3) << A[2] << "(" << setw(2) << AR[2] << ") |";
				cout << " D3:" << setw(3) << D[2] << "(" << setw(2) << DR[2] << ") || ";
				if (AR[2] >= crit) {
					cout << "CA3:" << setw(3) << cc[2] << "(" << setw(2) << AR[7] << ") | ";
					cout << "CD3:" << setw(3) << cd[2] << "(";
					for (int n = 1; n <= mult - 1; n++) {
						if (n > 1)
							cout << '+';
						cout << critR[critI++];
					}
					cout << ')';
				}
				cout << '\n';
			}
			//ATTACK FOUR OUTPUT vvvv
			if (bab >= 15) {
				cout << " A4:" << setw(3) << A[3] << "(" << setw(2) << AR[3] << ") |";
				cout << " D4:" << setw(3) << D[3] << "(" << setw(2) << DR[3] << ") || ";
				if (AR[3] >= crit) {
					cout << "CA4:" << setw(3) << cc[3] << "(" << setw(2) << AR[8] << ") | ";
					cout << "CD4:" << setw(3) << cd[3] << "(";
					for (int n = 1; n <= mult - 1; n++) {
						if (n > 1)
							cout << '+';
						cout << critR[critI++];
					}
					cout << ')';
				}
				cout << '\n';
			}
			//ATTACK HASTE OUTPUT vvvv
			if (haste == 1) {
				cout << " AH:" << setw(3) << A[4] << "(" << setw(2) << AR[4] << ") |";
				cout << " DH:" << setw(3) << D[4] << "(" << setw(2) << DR[4] << ") || ";
				if (AR[4] >= crit) {
					cout << "CAH:" << setw(3) << cc[4] << "(" << setw(2) << AR[9] << ") | ";
					cout << "CDH:" << setw(3) << cd[4] << "(";
					for (int n = 1; n <= mult - 1; n++) {
						if (n > 1)
							cout << '+';
						cout << critR[critI++];
					}
					cout << ')';
				}
				cout << '\n';
			}
		}
		cout << setfill('*') << setw(45) << '\n';
		setfill(' ');
		//ATTACK/DAMAGE OUTPUT EQUATIONS vvvv 
		cout << "-Attack: " << a << " {";
		if (bab != 0)
			cout << bab << "[BAB]";
		if (modStr != 0)
			cout << " + " << modStr << "[STR]";
		if (size != 0)
			cout << " + " << size << "[SIZE]";
		if (enh != 0)
			cout << " + " << enh << "[ENH]";
		if (pwrAttk != 0)
			cout << " + (-" << pwrAttk << ")[PWR]";
		if (flank != 0)
			cout << " + " << flank << "[FLNK]";
		if (oneMind != 0)
			cout << " + " << oneMind << "[OneMind]";
		if (divFavor != 0)
			cout << " + " << divFavor << "[DivFav]";
		if (haste != 0)
			cout << " + " << haste << "[HST]";
		if (prayer != 0)
			cout << " + " << prayer << "[PRYR]";
		if (xtraAttk != 0)
			cout << " + " << xtraAttk << "[MISC]";
		cout << "}\n";

		cout << "-Cond. ATK Bonuses: ";
		if (charge != 0)
			cout << '+' << charge << "[CHRG]";
		if (smtAttk[0] != 0)
			cout << "//" << '+' << pal << "[SMT1]";
		if (smtAttk[1] != 0)
			cout << "//" << '+' << pal << "[SMT2]";
		if (smtAttk[2] != 0)
			cout << "//" << '+' << pal << "[SMT3]";
		if (smtAttk[3] != 0)
			cout << "//" << '+' << pal << "[SMT4]";
		if (smtAttk[4] != 0)
			cout << "//" << '+' << pal << "[SMT-H]";
		cout << '\n';

		cout << "-Damage: " << d << " {";
		if (modStr != 0) {
			switch (hands) {
			case 1:
				cout << modStr;
				break;
			case 2:
				cout << ((int)modStr * 1.5);
				break;
			}
			cout << "[STR]";
		}
		if (enh != 0)
			cout << " + " << enh << "[ENH]";
		if (pwrDmg != 0)
			cout << " + " << pwrDmg << "[PWR]";
		if (oneMind != 0)
			cout << " + " << oneMind << "[OneMind]";
		if (divFavor != 0)
			cout << " + " << divFavor << "[DivFav]";
		if (prayer != 0)
			cout << " + " << prayer << "[PRYR]";
		if (armbands != 0)
			cout << " + " << armbands << "[ArmBnds]";
		if (rubicond != 0)
			cout << " + " << rubicond << "[Rbicnd]";
		if (xtraDmg != 0)
			cout << " + " << xtraDmg << "[MISC]";
		cout << "}\n";

		cout << "-Cond. DMG Bonuses: ";
		if (smtAttk[0] != 0)
			cout << '+' << modCha << "[SMT1]";
		if (smtAttk[1] != 0)
			cout << "//" << '+' << modCha << "[SMT2]";
		if (smtAttk[2] != 0)
			cout << "//" << '+' << modCha << "[SMT3]";
		if (smtAttk[3] != 0)
			cout << "//" << '+' << modCha << "[SMT4]";
		if (smtAttk[4] != 0)
			cout << "//" << '+' << modCha << "[SMT-H]";
		if (divSac != 0)
			cout << "//" << '+' << divSac << "[DivSac]";
		if (rhinoRush != 0)
			cout << "//" << '+' << (rhinoRush * ((DR[5] + d) + (smtAttk[0] * modCha))) << "(" << setw(2) << DR[5] << ")[RHINO]";
		if (spiritChg != 0)
			cout << "//" << '+' << (spiritChg * ((DR[6] + d) + (smtAttk[0] * modCha))) << "(" << setw(2) << DR[6] << ")[SprtCHRG]";
		if (valor != 0)
			cout << "//" << '+' << (valor * ((DR[7] + d) + (smtAttk[0] * modCha))) << "(" << setw(2) << DR[7] << ")[VALOR]";
		cout << '\n';

		cout << "-WEAPON DAMAGE: " << damage << '\n';
		cout << "-CRIT = Damage x" << mult << '\n';
		cout << "-Do not multiply:\n";
		if (divSac != 0)
			cout << "---Divine Sacrifice\n";
		if (rhinoRush != 0)
			cout << "---Rhino Rush\n";
		if (spiritChg != 0)
			cout << "---Spirited Charge\n";
		if (valor != 0)
			cout << "---Valorous\n";
		cout << "\n\n";
		system("pause");
		cout << '\n';
		cout << "Would you like to run this attack macro again?\n";
		toggle = userInLoop("Attack Again?");
	}
}
void lightmace(string dmg = "1d6", int hands = 1, int enh = 1, int crit = 20, int mult = 2, bool light = true) {
	bool toggle = true;
	if (light == true) {
		hands = 1;
	}
	else if (hands != 1 && hands != 2) {
		hands = handChoiceF();
	}
	int size = sizeF();
	while (toggle) {
		//ATTACK ROLLS vvvv
		int AR[25], DR[40];
		for (int i = 0; i < 25; i++) {
			AR[i] = dice(1, 20);
		}
		//DAMAGE ROLLS vvvv
		string damage = dmg;
		for (int i = 0; i < 25; i++) {
			DR[i] = weaponDMG(damage, size);
			if (i < 39)
				damage = dmg;
		}
		int cc[5] = { 0, 0, 0, 0, 0 }, cd[5] = { 0, 0, 0, 0, 0 };
		int pwrAttk = pwrAttkF();
		int pwrDmg = pwrDmgF(pwrAttk, hands, light);
		bool fullAttk;
		int charge = chargeF();
		int rhinoRush = 0, spiritChg = 0, valor = 0;
		if (charge == 2)
			fullAttk = false, rhinoRush = rhinoRushF(), spiritChg = spiritChgF(), valor = 0;
		else
			fullAttk = fullAttkF();
		int haste = hasteF();
		int smtAttk[5] = { smiteAttkF("1"), 0, 0, 0, 0 };
		if (fullAttk == true) {
			if (bab >= 5)
				smtAttk[1] = smiteAttkF("2");
			if (bab >= 10)
				smtAttk[2] = smiteAttkF("3");
			if (bab >= 15)
				smtAttk[3] = smiteAttkF("4");
			if (haste == true)
				smtAttk[4] = smiteAttkF("H");
		}
		int flank = flankF();
		int xtraAttk = xtraAttkF(), xtraDmg = xtraDmgF();
		int oneMind = oneMindF();
		int divSac = divSacF();
		int prayer = prayerF();
		int divFavor = divFavorF();
		int rubicond = rubicondF();
		int armbands = armbandsF(pwrAttk);
		int critR[25];
		int a = bab + modStr + size + enh + flank - pwrAttk + oneMind + divFavor + haste + prayer + xtraAttk;
		int d = enh + pwrDmg + oneMind + divFavor + prayer + armbands + rubicond + xtraDmg;
		if (hands == 1) {
			if (light == true && offHandF() == true) {
				d += (int)modStr * .5;
			}
			else
				d += modStr;
		}
		else if (hands == 2)
			d += ((int)modStr * 1.5);
		int A[5], D[5];
		//ATTACK ONE vvvv
		int di = 5, critI = 0;
		A[0] = AR[0] + a + (smtAttk[0] * pal) + charge;
		D[0] = DR[0] + d + (smtAttk[0] * modCha) + divSac + (rhinoRush * ((DR[di++] + d) + (smtAttk[0] * modCha))) + //Rhino Rush = DR[5]
			(spiritChg * ((DR[di++] + d) + (smtAttk[0] * modCha))) + //Spirited Charge = DR[6]
			(valor * ((DR[di++] + d) + (smtAttk[0] * modCha))); //Valorous = DR[7]
		if (AR[0] >= crit) {
			cc[0] = AR[5] + a + (smtAttk[0] * pal) + charge;
			for (int x = 1; x <= mult - 1; x++) {
				cd[0] += DR[di] + d + (smtAttk[0] * modCha);
				critR[critI++] = DR[di++];
			}
		}
		if (fullAttk == true) {
			//ATTACK TWO vvvv
			A[1] = AR[1] + a + (smtAttk[1] * pal) - 5;
			D[1] = DR[1] + d + (smtAttk[1] * modCha);
			if (AR[1] >= crit) {
				cc[1] = AR[6] + a + (smtAttk[1] * pal) - 5;
				for (int x = 1; x <= mult - 1; x++) {
					cd[1] += DR[di] + d + (smtAttk[1] * modCha);
					critR[critI++] = DR[di++];
				}
			}
			//ATTACK THREE vvvv
			A[2] = AR[2] + a + (smtAttk[2] * pal) - 10;
			D[2] = DR[2] + d + (smtAttk[2] * modCha);
			if (AR[2] >= crit) {
				cc[2] = AR[7] + a + (smtAttk[2] * pal) - 10;
				for (int x = 1; x <= mult - 1; x++) {
					cd[2] += DR[di] + d + (smtAttk[2] * modCha);
					critR[critI++] = DR[di++];
				}
			}
			//ATTACK FOUR vvvv
			A[3] = AR[3] + a + (smtAttk[3] * pal) - 15;
			D[3] = DR[3] + d + (smtAttk[3] * modCha);
			if (AR[3] >= crit) {
				cc[3] = AR[8] + a + (smtAttk[3] * pal) - 15;
				for (int x = 1; x <= mult - 1; x++) {
					cd[3] += DR[di] + d + (smtAttk[3] * modCha);
					critR[critI++] = DR[di++];
				}
			}
			if (haste == 1) {
				//ATTACK HASTE vvvv
				A[4] = AR[4] + a + (smtAttk[4] * pal);
				D[4] = DR[4] + d + (smtAttk[4] * modCha);
				if (AR[4] >= crit) {
					cc[4] = AR[9] + a + (smtAttk[4] * pal);
					for (int x = 1; x <= mult - 1; x++) {
						cd[4] += DR[di] + d + (smtAttk[4] * modCha);
						critR[critI++] = DR[di++];
					}
				}
			}
		}
		critI = 0;
		//ATTACK ONE OUTPUT vvvv
		cout << " A1:" << right << setw(3) << A[0] << "(" << setw(2) << AR[0] << ") |";
		cout << " D1:" << setw(3) << D[0] << "(" << setw(2) << DR[0] << ") || ";
		if (AR[0] >= crit) {
			cout << "CA1:" << setw(3) << cc[0] << "(" << setw(2) << AR[5] << ") | ";
			cout << "CD1:" << setw(3) << cd[0] << "(";
			for (int n = 1; n <= mult - 1; n++) {
				if (n > 1)
					cout << '+';
				cout << critR[critI++];
			}
			cout << ')';
		}
		cout << '\n';
		if (fullAttk == true) {
			//ATTACK TWO OUTPUT vvvv
			if (bab >= 5) {
				cout << " A2:" << setw(3) << A[1] << "(" << setw(2) << AR[1] << ") |";
				cout << " D2:" << setw(3) << D[1] << "(" << setw(2) << DR[1] << ") || ";
				if (AR[1] >= crit) {
					cout << "CA2:" << setw(3) << cc[1] << "(" << setw(2) << AR[6] << ") | ";
					cout << "CD2:" << setw(3) << cd[1] << "(";
					for (int n = 1; n <= mult - 1; n++) {
						if (n > 1)
							cout << '+';
						cout << critR[critI++];
					}
					cout << ')';
				}
				cout << '\n';
			}
			//ATTACK THREE OUTPUT vvvv
			if (bab >= 10) {
				cout << " A3:" << setw(3) << A[2] << "(" << setw(2) << AR[2] << ") |";
				cout << " D3:" << setw(3) << D[2] << "(" << setw(2) << DR[2] << ") || ";
				if (AR[2] >= crit) {
					cout << "CA3:" << setw(3) << cc[2] << "(" << setw(2) << AR[7] << ") | ";
					cout << "CD3:" << setw(3) << cd[2] << "(";
					for (int n = 1; n <= mult - 1; n++) {
						if (n > 1)
							cout << '+';
						cout << critR[critI++];
					}
					cout << ')';
				}
				cout << '\n';
			}
			//ATTACK FOUR OUTPUT vvvv
			if (bab >= 15) {
				cout << " A4:" << setw(3) << A[3] << "(" << setw(2) << AR[3] << ") |";
				cout << " D4:" << setw(3) << D[3] << "(" << setw(2) << DR[3] << ") || ";
				if (AR[3] >= crit) {
					cout << "CA4:" << setw(3) << cc[3] << "(" << setw(2) << AR[8] << ") | ";
					cout << "CD4:" << setw(3) << cd[3] << "(";
					for (int n = 1; n <= mult - 1; n++) {
						if (n > 1)
							cout << '+';
						cout << critR[critI++];
					}
					cout << ')';
				}
				cout << '\n';
			}
			//ATTACK HASTE OUTPUT vvvv
			if (haste == 1) {
				cout << " AH:" << setw(3) << A[4] << "(" << setw(2) << AR[4] << ") |";
				cout << " DH:" << setw(3) << D[4] << "(" << setw(2) << DR[4] << ") || ";
				if (AR[4] >= crit) {
					cout << "CAH:" << setw(3) << cc[4] << "(" << setw(2) << AR[9] << ") | ";
					cout << "CDH:" << setw(3) << cd[4] << "(";
					for (int n = 1; n <= mult - 1; n++) {
						if (n > 1)
							cout << '+';
						cout << critR[critI++];
					}
					cout << ')';
				}
				cout << '\n';
			}
		}
		cout << setfill('*') << setw(45) << '\n';
		setfill(' ');
		//ATTACK/DAMAGE OUTPUT EQUATIONS vvvv 
		cout << "-Attack: " << a << " {";
		if (bab != 0)
			cout << bab << "[BAB]";
		if (modStr != 0)
			cout << " + " << modStr << "[STR]";
		if (size != 0)
			cout << " + " << size << "[SIZE]";
		if (enh != 0)
			cout << " + " << enh << "[ENH]";
		if (pwrAttk != 0)
			cout << " + (-" << pwrAttk << ")[PWR]";
		if (flank != 0)
			cout << " + " << flank << "[FLNK]";
		if (oneMind != 0)
			cout << " + " << oneMind << "[OneMind]";
		if (divFavor != 0)
			cout << " + " << divFavor << "[DivFav]";
		if (haste != 0)
			cout << " + " << haste << "[HST]";
		if (prayer != 0)
			cout << " + " << prayer << "[PRYR]";
		if (xtraAttk != 0)
			cout << " + " << xtraAttk << "[MISC]";
		cout << "}\n";

		cout << "-Cond. ATK Bonuses: ";
		if (charge != 0)
			cout << '+' << charge << "[CHRG]";
		if (smtAttk[0] != 0)
			cout << "//" << '+' << pal << "[SMT1]";
		if (smtAttk[1] != 0)
			cout << "//" << '+' << pal << "[SMT2]";
		if (smtAttk[2] != 0)
			cout << "//" << '+' << pal << "[SMT3]";
		if (smtAttk[3] != 0)
			cout << "//" << '+' << pal << "[SMT4]";
		if (smtAttk[4] != 0)
			cout << "//" << '+' << pal << "[SMT-H]";
		cout << '\n';

		cout << "-Damage: " << d << " {";
		if (modStr != 0) {
			switch (hands) {
			case 1:
				cout << modStr;
				break;
			case 2:
				cout << ((int)modStr * 1.5);
				break;
			}
			cout << "[STR]";
		}
		if (enh != 0)
			cout << " + " << enh << "[ENH]";
		if (pwrDmg != 0)
			cout << " + " << pwrDmg << "[PWR]";
		if (oneMind != 0)
			cout << " + " << oneMind << "[OneMind]";
		if (divFavor != 0)
			cout << " + " << divFavor << "[DivFav]";
		if (prayer != 0)
			cout << " + " << prayer << "[PRYR]";
		if (armbands != 0)
			cout << " + " << armbands << "[ArmBnds]";
		if (rubicond != 0)
			cout << " + " << rubicond << "[Rbicnd]";
		if (xtraDmg != 0)
			cout << " + " << xtraDmg << "[MISC]";
		cout << "}\n";

		cout << "-Cond. DMG Bonuses: ";
		if (smtAttk[0] != 0)
			cout << '+' << modCha << "[SMT1]";
		if (smtAttk[1] != 0)
			cout << "//" << '+' << modCha << "[SMT2]";
		if (smtAttk[2] != 0)
			cout << "//" << '+' << modCha << "[SMT3]";
		if (smtAttk[3] != 0)
			cout << "//" << '+' << modCha << "[SMT4]";
		if (smtAttk[4] != 0)
			cout << "//" << '+' << modCha << "[SMT-H]";
		if (divSac != 0)
			cout << "//" << '+' << divSac << "[DivSac]";
		if (rhinoRush != 0)
			cout << "//" << '+' << (rhinoRush * ((DR[5] + d) + (smtAttk[0] * modCha))) << "(" << setw(2) << DR[5] << ")[RHINO]";
		if (spiritChg != 0)
			cout << "//" << '+' << (spiritChg * ((DR[6] + d) + (smtAttk[0] * modCha))) << "(" << setw(2) << DR[6] << ")[SprtCHRG]";
		if (valor != 0)
			cout << "//" << '+' << (valor * ((DR[7] + d) + (smtAttk[0] * modCha))) << "(" << setw(2) << DR[7] << ")[VALOR]";
		cout << '\n';

		cout << "-WEAPON DAMAGE: " << damage << '\n';
		cout << "-CRIT = Damage x" << mult << '\n';
		cout << "-Do not multiply:\n";
		if (divSac != 0)
			cout << "---Divine Sacrifice\n";
		if (rhinoRush != 0)
			cout << "---Rhino Rush\n";
		if (spiritChg != 0)
			cout << "---Spirited Charge\n";
		if (valor != 0)
			cout << "---Valorous\n";
		cout << "\n\n";
		system("pause");
		cout << '\n';
		cout << "Would you like to run this attack macro again?\n";
		toggle = userInLoop("Attack Again?");
	}
}
void melee(int hands = 0, int enh = enhBF(), int crit = critF(), int mult = multF(), bool light = lightWeaponF()) {
	bool toggle = true;
	if (light == true)
		hands = 1;
	else if (hands != 1 && hands != 2)
		hands = handChoiceF();
	int size = sizeF();
	while (toggle) {
		//ATTACK & DAMAGE ROLLS vvvv
		cout << "Please have ready the listed damage dice for the weapon being used\n\n";
		system("pause");
		int n, s;
		system("CLS");
		cout << "How many dice would you like to throw?\n";
		cout << "(Accepts any positive whole number)\n";
		do {
			cin >> n;
			if (cin.fail() || n < 0) {
				cin.clear();
				cin.ignore(10000, '\n');
				n = 0;
				cout << "Please enter a valid positive number\n";
			}
		} while (n == 0);
		cout << "What size of die would you like to throw?\n";
		cout << "(Accepts any positive whole number)\n";
		do {
			cin >> s;
			if (cin.fail() || n < 0) {
				cin.clear();
				cin.ignore(10000, '\n');
				s = 0;
				cout << "Please enter a valid positive number\n";
			}
		} while (s == 0);
		int AR[25], DR[40];
		for (int i = 0; i < 25; i++) {
			AR[i] = dice(1, 20);
		}
		for (int i = 0; i < 40; i++) {
			DR[i] = dice(n, s);
		}
		cin.ignore(10000, '\n');
		int cc1 = 0, cc2 = 0, cc3 = 0, ccH = 0, cc4 = 0, cd1 = 0, cd2 = 0, cd3 = 0, cd4 = 0, cdH = 0;
		int pwrAttk = pwrAttkF();
		int pwrDmg = pwrDmgF(pwrAttk, hands, light);
		int charge = chargeF();
		bool fullAttk;
		int rhinoRush = 0, spiritChg = 0;
		if (charge == 2)
			fullAttk = false, rhinoRush = rhinoRushF(), spiritChg = spiritChgF();
		else if (charge == 0)
			fullAttk = fullAttkF();
		int haste = hasteF();
		int smtAttk1 = smiteAttkF("1"), smtAttk2 = 0, smtAttk3 = 0, smtAttk4 = 0, smtAttkH = 0;
		if (fullAttk == true) {
			smtAttk2 = smiteAttkF("2"), smtAttk3 = smiteAttkF("3"), smtAttk4 = smiteAttkF("4");
			if (haste == true)
				smtAttkH = smiteAttkF("H");
		}
		int flank = flankF();
		int xtraAttk = xtraAttkF(), xtraDmg = xtraDmgF();
		int oneMind = oneMindF();
		int divSac = divSacF();
		int prayer = prayerF();
		int divFavor = divFavorF();
		int rubicond = rubicondF();
		int armbands = armbandsF(pwrAttk);
		int critR[25];
		int a = bab + modStr + size + enh + flank - pwrAttk + oneMind + divFavor + haste + prayer + xtraAttk;
		int d = enh + pwrDmg + oneMind + divFavor + prayer + armbands + rubicond + xtraDmg;
		if (offHandF() == true)
			d += (int)modStr * .5;
		else {
			if (hands == 1)
				d += modStr;
			else if (hands == 2)
				d += ((int)modStr * 1.5);
		}
		int A[5], D[5];
		//ATTACK ONE vvvv
		int di = 5, critI = 0;
		A[0] = AR[0] + a + (smtAttk1 * pal) + charge;
		D[0] = DR[0] + d + (smtAttk1 * modCha) + divSac + (rhinoRush * ((DR[di++] + d) + (smtAttk1 * modCha))) + //Rhino Rush = DR[5]
			(spiritChg * ((DR[di++] + d) + (smtAttk1 * modCha))); //Spirited Charge = DR[6]
		if (AR[0] >= crit) {
			cc1 = AR[5] + a + (smtAttk1 * pal) + charge;
			for (int x = 1; x <= mult - 1; x++) {
				cd1 += DR[di] + d + (smtAttk1 * modCha);
				critR[critI++] = DR[di++];
			}
		}
		if (fullAttk == true) {
			//ATTACK TWO vvvv
			A[1] = AR[1] + a + (smtAttk2 * pal) - 5;
			D[1] = DR[1] + d + (smtAttk2 * modCha);
			if (AR[1] >= crit) {
				cc2 = AR[6] + a + (smtAttk2 * pal) - 5;
				for (int x = 1; x <= mult - 1; x++) {
					cd2 += DR[di] + d + (smtAttk2 * modCha);
					critR[critI++] = DR[di++];
				}
			}
			//ATTACK THREE vvvv
			A[2] = AR[2] + a + (smtAttk3 * pal) - 10;
			D[2] = DR[2] + d + (smtAttk3 * modCha);
			if (AR[2] >= crit) {
				cc3 = AR[7] + a + (smtAttk3 * pal) - 10;
				for (int x = 1; x <= mult - 1; x++) {
					cd3 += DR[di] + d + (smtAttk3 * modCha);
					critR[critI++] = DR[di++];
				}
			}
			//ATTACK FOUR vvvv
			A[3] = AR[3] + a + (smtAttk4 * pal) - 15;
			D[3] = DR[3] + d + (smtAttk4 * modCha);
			if (AR[3] >= crit) {
				cc4 = AR[8] + a + (smtAttk4 * pal) - 15;
				for (int x = 1; x <= mult - 1; x++) {
					cd4 += DR[di] + d + (smtAttk4 * modCha);
					critR[critI++] = DR[di++];
				}
			}
			if (haste == 1) {
				//ATTACK HASTE vvvv
				A[4] = AR[4] + a + (smtAttkH * pal);
				D[4] = DR[4] + d + (smtAttkH * modCha);
				if (AR[4] >= crit) {
					ccH = AR[9] + a + (smtAttkH * pal);
					for (int x = 1; x <= mult - 1; x++) {
						cdH += DR[di] + d + (smtAttkH * modCha);
						critR[critI++] = DR[di++];
					}
				}
			}
		}
		critI = 0;
		//ATTACK ONE OUTPUT vvvv
		cout << " A1:" << right << setw(3) << A[0] << "(" << setw(2) << AR[0] << ") |";
		cout << " D1:" << setw(3) << D[0] << "(" << setw(2) << DR[0] << ") || ";
		if (AR[0] >= crit) {
			cout << "CA1:" << setw(3) << cc1 << "(" << setw(2) << AR[5] << ") | ";
			cout << "CD1:" << setw(3) << cd1 << "(";
			for (int n = 1; n <= mult - 1; n++) {
				if (n > 1)
					cout << '+';
				cout << critR[critI++];
			}
			cout << ')';
		}
		cout << '\n';
		if (fullAttk == true) {
			//ATTACK TWO OUTPUT vvvv
			if (bab >= 5) {
				cout << " A2:" << setw(3) << A[1] << "(" << setw(2) << AR[1] << ") |";
				cout << " D2:" << setw(3) << D[1] << "(" << setw(2) << DR[1] << ") || ";
				if (AR[1] >= crit) {
					cout << "CA2:" << setw(3) << cc2 << "(" << setw(2) << AR[6] << ") | ";
					cout << "CD2:" << setw(3) << cd2 << "(";
					for (int n = 1; n <= mult - 1; n++) {
						if (n > 1)
							cout << '+';
						cout << critR[critI++];
					}
					cout << ')';
				}
				cout << '\n';
			}
			//ATTACK THREE OUTPUT vvvv
			if (bab >= 10) {
				cout << " A3:" << setw(3) << A[2] << "(" << setw(2) << AR[2] << ") |";
				cout << " D3:" << setw(3) << D[2] << "(" << setw(2) << DR[2] << ") || ";
				if (AR[2] >= crit) {
					cout << "CA3:" << setw(3) << cc3 << "(" << setw(2) << AR[7] << ") | ";
					cout << "CD3:" << setw(3) << cd3 << "(";
					for (int n = 1; n <= mult - 1; n++) {
						if (n > 1)
							cout << '+';
						cout << critR[critI++];
					}
					cout << ')';
				}
				cout << '\n';
			}
			//ATTACK FOUR OUTPUT vvvv
			if (bab >= 15) {
				cout << " A4:" << setw(3) << A[3] << "(" << setw(2) << AR[3] << ") |";
				cout << " D4:" << setw(3) << D[3] << "(" << setw(2) << DR[3] << ") || ";
				if (AR[3] >= crit) {
					cout << "CA4:" << setw(3) << cc3 << "(" << setw(2) << AR[8] << ") | ";
					cout << "CD5:" << setw(3) << cd3 << "(";
					for (int n = 1; n <= mult - 1; n++) {
						if (n > 1)
							cout << '+';
						cout << critR[critI++];
					}
					cout << ')';
				}
				cout << '\n';
			}
			//ATTACK HASTE OUTPUT vvvv
			if (haste == 1) {
				cout << " AH:" << setw(3) << A[4] << "(" << setw(2) << AR[4] << ") |";
				cout << " DH:" << setw(3) << D[4] << "(" << setw(2) << DR[4] << ") || ";
				if (AR[4] >= crit) {
					cout << "CAH:" << setw(3) << ccH << "(" << setw(2) << AR[9] << ") | ";
					cout << "CDH:" << setw(3) << cdH << "(";
					for (int n = 1; n <= mult - 1; n++) {
						if (n > 1)
							cout << '+';
						cout << critR[critI++];
					}
					cout << ')';
				}
				cout << '\n';
			}
		}
		cout << setfill('*') << setw(45) << '\n';
		setfill(' ');
		//ATTACK/DAMAGE OUTPUT EQUATIONS vvvv 
		cout << "-Attack: " << a << " {";
		if (bab != 0)
			cout << bab << "[BAB]";
		if (modStr != 0)
			cout << " + " << modStr << "[STR]";
		if (size != 0)
			cout << " + " << size << "[SIZE]";
		if (enh != 0)
			cout << " + " << enh << "[ENH]";
		if (pwrAttk != 0)
			cout << " + (-" << pwrAttk << ")[PWR]";
		if (flank != 0)
			cout << " + " << flank << "[FLNK]";
		if (oneMind != 0)
			cout << " + " << oneMind << "[OneMind]";
		if (divFavor != 0)
			cout << " + " << divFavor << "[DivFav]";
		if (haste != 0)
			cout << " + " << haste << "[HST]";
		if (prayer != 0)
			cout << " + " << prayer << "[PRYR]";
		if (xtraAttk != 0)
			cout << " + " << xtraAttk << "[MISC]";
		cout << "}\n";

		cout << "-Cond. ATK Bonuses: ";
		if (charge != 0)
			cout << '+' << charge << "[CHRG]";
		if (smtAttk1 != 0)
			cout << "//" << '+' << pal << "[SMT1]";
		if (smtAttk2 != 0)
			cout << "//" << '+' << pal << "[SMT2]";
		if (smtAttk3 != 0)
			cout << "//" << '+' << pal << "[SMT3]";
		if (smtAttk4 != 0)
			cout << "//" << '+' << pal << "[SMT4]";
		if (smtAttkH != 0)
			cout << "//" << '+' << pal << "[SMT-H]";
		cout << '\n';

		cout << "-Damage: " << d << " {";
		if (modStr != 0) {
			switch (hands) {
			case 1:
				cout << modStr;
				break;
			case 2:
				cout << ((int)modStr * 1.5);
				break;
			}
			cout << "[STR]";
		}
		if (enh != 0)
			cout << " + " << enh << "[ENH]";
		if (pwrDmg != 0)
			cout << " + " << pwrDmg << "[PWR]";
		if (oneMind != 0)
			cout << " + " << oneMind << "[OneMind]";
		if (divFavor != 0)
			cout << " + " << divFavor << "[DivFav]";
		if (prayer != 0)
			cout << " + " << prayer << "[PRYR]";
		if (armbands != 0)
			cout << " + " << armbands << "[ArmBnds]";
		if (rubicond != 0)
			cout << " + " << rubicond << "[Rbicnd]";
		if (xtraDmg != 0)
			cout << " + " << xtraDmg << "[MISC]";
		cout << "}\n";

		cout << "-Cond. DMG Bonuses: ";
		if (smtAttk1 != 0)
			cout << '+' << modCha << "[SMT1]";
		if (smtAttk2 != 0)
			cout << "//" << '+' << modCha << "[SMT2]";
		if (smtAttk3 != 0)
			cout << "//" << '+' << modCha << "[SMT3]";
		if (smtAttk4 != 0)
			cout << "//" << '+' << modCha << "[SMT4]";
		if (smtAttkH != 0)
			cout << "//" << '+' << modCha << "[SMT-H]";
		if (divSac != 0)
			cout << "//" << '+' << divSac << "[DivSac]";
		if (rhinoRush != 0)
			cout << "//" << '+' << (rhinoRush * ((DR[5] + d) + (smtAttk1 * modCha))) << "(" << setw(2) << DR[5] << ")[RHINO]";
		if (spiritChg != 0)
			cout << "//" << '+' << (spiritChg * ((DR[6] + d) + (smtAttk1 * modCha))) << "(" << setw(2) << DR[6] << ")[SprtCHRG]";
		cout << '\n';

		cout << "-WEAPON DAMAGE: " << n << 'd' << s << '\n';
		cout << "-CRIT = Damage x" << mult << '\n';
		cout << "-Do not multiply:\n";
		if (divSac != 0)
			cout << "---Divine Sacrifice\n";
		if (rhinoRush != 0)
			cout << "---Rhino Rush\n";
		if (spiritChg != 0)
			cout << "---Spirited Charge\n";
		cout << "\n\n";
		system("pause");
		cout << '\n';
		cout << "Would you like to run this attack macro again?\n";
		toggle = userInLoop("Attack Again?");
	}
}

//Menus
int mainMenu() {
	system("CLS");
	cout << " ------------------------------Kula-Tai------------------------------ \n";
	cout << "| Defender of the Weave, Knight of The Mystic Fire, Rider of Dragons |\n";
	cout << " -------------------------------------------------------------------- \n";
	cout << "    HP: " << currHP << "\\" << maxHP << '\n';
	cout << "What would you like to do?\n";
	cout << "1 - ATTACKS\n";
	cout << "2 - DEFENSES\n";
	cout << "3 - ABILITIES\n";
	cout << "4 - SKILLS\n";
	cout << "5 - SPELLS\n";
	string choice;
	getline(cin, choice);
	while (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5") {
		cout << "Please enter a valid selection" << '\n';
		getline(cin, choice);
	}//End of Choice Loop
	system("CLS");
	if (choice == "1")
		return 1;
	else if (choice == "2")
		return 2;
	else if (choice == "3")
		return 3;
	else if (choice == "4")
		return 4;
	else if (choice == "5")
		return 5;
}
bool weapons(int choice) {
	switch (choice) {
	case 1:
		sharrash();
		break;
	case 2:
		waraxe();
		break;
	case 3:
		swordbow();
		break;
	case 4:
		lightmace();
		break;
	case 5:
		melee();
		break;
	case 0:
	default:
		return false;
		break;
	}
}
int attacks(int attacks = 5) {
	int y;
	while (true) {
	cout << "Which weapon would you like to attack with?\n";
	cout << "1 - (+2) TALENTA SHARRASH\n";
	cout << "2 - (+2) ADAMANTINE WARAXE\n";
	cout << "3 - (+1) GREAT (SWORD)BOW\n";
	cout << "4 - (+1) LIGHT MACE\n";
	cout << "5 - MISC MELEE\n";
	cout << "Leave blank and press enter to return to previous screen\n";
	string userIn;
	int x;
		getline(cin, userIn);
		if (userIn == "" || userIn == "0")
			return 0;
		if (isNumber(userIn) == true) {
			x = stoi(userIn);
			if (x >= 0 && x <= attacks)
				return x;
			else
				cout << "Please enter a valid number between 0 and " << attacks << ": ";
		}
		else
			cout << "Please enter a valid number between 0 and " << attacks << ": ";
	}//End of Choice Loop
	system("CLS");
}

int main()
{
	srand(GetTickCount64());
	while (true) {
		int menu;
		menu = mainMenu();
		switch (menu) {
		case 1:
			bool weaponScreen;
			weaponScreen = true;
			while (weaponScreen) {
				weaponScreen = weapons(attacks());
			}
		}
	}
}
