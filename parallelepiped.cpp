#include "main.h"


void In(parallelepiped &p, ifstream &ifst) {
	ifst >> p.e1 >> p.e2 >> p.e3;
}

void Out(parallelepiped &p, ofstream &ofst) {
	ofst << "It is parallelepiped:  a = " << p.e1 << ", b = " << p.e2 << ", c = " << p.e3;
}

