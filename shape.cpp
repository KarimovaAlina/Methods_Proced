#include "main.h"


void In(sphere &s, ifstream &ifst);
void In(parallelepiped &p, ifstream &ifst);

void Out(sphere &s, ofstream &ofst);
void Out(parallelepiped &p, ofstream &ofst);


double Volume(parallelepiped *p);
double Volume(sphere *s);
double Volume(tetrahedron *t);
//New:
void Out(tetrahedron &t, ofstream &ofst);
void In(tetrahedron &t, ifstream &ifst);



shape* In(ifstream &ifst) 
{
	ChckInFile(ifst);
	if (ifst.eof())
	{
		cout << "Error. Too many shapes is specified." << endl;
		system("pause");
		exit(1);
	}
	shape *sh;
	sphere* sp;
	parallelepiped* p;
	tetrahedron* t;
	int type;
	ifst >> type;
	ChckInValue(ifst);
	ChckNegative(type);
	if (type > 2)
	{
		cout << "Error. Incorrect values. The key can take the values 0, 1, 2." << endl;
		system("pause");
		exit(1);
	}
	switch (type)
	{
	case 0:
		sp = new sphere;
		sp->t = SPHERE;
		In(*sp, ifst);
		ifst >> sp->destiny;
		ChckInValue(ifst);
		ChckNegative(sp->destiny);
		ifst >> sp->temp;
		ChckInValue(ifst);
		ChckNegative(sp->temp);
		sh = (shape*)sp;
		return sh;
		break;
	case 1:
		p = new parallelepiped;
		p->t = PARALLELEPIPED;
		In(*p, ifst);
		ifst >> p->destiny;
		ChckInValue(ifst);
		ChckNegative(p->destiny);
		ifst >> p->temp;
		ChckInValue(ifst);
		ChckNegative(p->temp);
		sh = (shape*)p;
		return sh;
		break;
	case 2:
		t = new tetrahedron;
		t->t = TETRAHEDRON;
		In(*t, ifst);
		ifst >> t->destiny;
		ChckInValue(ifst);
		ChckNegative(t->destiny);
		ifst >> t->temp;
		ChckInValue(ifst);
		ChckNegative(t->temp);
		sh = (shape*)t;
		return sh;
		break;
	default:
		return NULL;
		break;
	}
}

void Out(shape *s, ofstream &ofst) 
{
	switch (s->t) 
	{
	case SPHERE:
		Out(*((sphere*)s), ofst);
		ofst << ", Destiny = " << ((sphere*)s)->destiny << ", Melting temperature = " << ((sphere*)s)->temp;
		break;
	case PARALLELEPIPED:
		Out(*((parallelepiped*)s), ofst);
		ofst << ", Destiny = " << ((parallelepiped*)s)->destiny << ", Melting temperature = " << ((parallelepiped*)s)->temp;
		break;
	case TETRAHEDRON:
		Out(*((tetrahedron*)s), ofst);
		ofst << ", Destiny = " << ((tetrahedron*)s)->destiny << ", Melting temperature = " << ((tetrahedron*)s)->temp;
		break;
	default:
		ofst << "Incorrect shape!" << endl;
	}

}

double Volume(shape *s) 
{
	switch (s->t) 
	{
	case SPHERE:
		return Volume(((sphere*)s));
	case PARALLELEPIPED:
		return Volume(((parallelepiped*)s));
	case TETRAHEDRON:
		return Volume(((tetrahedron*)s));
	default:
		return -1;
	}
}