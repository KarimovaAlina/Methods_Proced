#include "main.h"


void In(sphere &s, ifstream &ifst) {
	ifst >> s.rad;
}

void Out(sphere &s, ofstream &ofst) {
	ofst << "It is sphere: radius = " << s.rad;
	
}