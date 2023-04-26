#pragma once
#include <cmath>
#include <string>
#define character_h
using namespace std;

class character {
private:
	int stat[6][17] = {0}; //0-STR|1-DEX|2-CON|3-INT|4-WIS|5-CHA
public:
	//
	void setStat(int ability, string type, int num) {
		string type2[17] = { "bas", "alc", "cir", "dod", "enh", "inh", "ins", "luc", "mor", "pro", "rac", "sac", "siz", "unt", "dmg", "dra", "mis" };
		for (int i = 0; i < 17; i++) {
			if (type == type2[i]) {
				stat[ability][i] += num;
				return;
			}
		}

	}

	int getStat(int ability) {
		int total = 0;
		for (int i = 0; i < 17; i++) {
			total += stat[ability][i];
		}
		return total;
	}
	int getMod(int ability) {
		return floor(0.5 * (getStat(ability) - 10));
	}
};

