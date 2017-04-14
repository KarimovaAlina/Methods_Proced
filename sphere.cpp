#include "main.h"


void In(sphere &s, ifstream &ifst) {
	ifst >> s.rad;
}

void Out(sphere &s, ofstream &ofst) {
	ofst << "It is sphere: radius = " << s.rad;
	
}

double Volume(sphere &s)
{
	return (s.rad * s.rad *s.rad * 3.1415 * 4 / 3);
}