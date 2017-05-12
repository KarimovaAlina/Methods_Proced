
#include "main.h"

void In(tetrahedron &t, ifstream &ifst)
{
	ChckInFile(ifst);
	ifst >> t.side;
	ChckInValue(ifst);
	ChckNegative(t.side);
}


void Out(tetrahedron &t, ofstream &ofst)
{
	ofst << "It is tetrahedron: side = " << t.side;
}

double Volume(tetrahedron *t)
{
	return (t->side * t->side * t->side * sqrt((double)2) / 12);
}

