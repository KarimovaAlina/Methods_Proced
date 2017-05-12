#include "main.h"


void In(parallelepiped &p, ifstream &ifst) 
{
	ChckInFile(ifst);
	ifst >> p.e1;
	ChckInValue(ifst);
	ChckNegative(p.e1);
	ifst >> p.e2;
	ChckInValue(ifst);
	ChckNegative(p.e2);
	ifst >> p.e3;
	ChckInValue(ifst);
	ChckNegative(p.e3);
}

void Out(parallelepiped &p, ofstream &ofst) 
{
	ofst << "It is parallelepiped:  a = " << p.e1 << ", b = " << p.e2 << ", c = " << p.e3;
}

double Volume(parallelepiped *p)
{
	return (p->e1 * p->e2 * p->e3);
}