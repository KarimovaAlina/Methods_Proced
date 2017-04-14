
#include "main.h"

void In(tetrahedron &t, ifstream &ifst)
{
	ifst >> t.side;
}


void Out(tetrahedron &t, ofstream &ofst)
{
	ofst << "It is tetrahedron: side = " << t.side;
}

