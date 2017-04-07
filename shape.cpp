#include "main.h"


void In(sphere &s, ifstream &ifst);
void In(parallelepiped &p, ifstream &ifst);

void Out(sphere &s, ofstream &ofst);
void Out(parallelepiped &p, ofstream &ofst);

//New:
void Out(tetrahedron &t, ofstream &ofst);
void In(tetrahedron &t, ifstream &ifst);

shape* In(ifstream &ifst) {
	shape *sh;
	sphere* sp;
	parallelepiped* p;
	tetrahedron* t;
	int type;
	ifst >> type;
	switch (type)
	{
	case 0:
		sp = new sphere;
		sp->t = SPHERE;
		In(*sp, ifst);
		ifst >> sp->destiny;
		sh = (shape*)sp;
		return sh;
		break;
	case 1:
		p = new parallelepiped;
		p->t = PARALLELEPIPED;
		In(*p, ifst);
		ifst >> p->destiny;
		sh = (shape*)p;
		return sh;
		break;
	case 2:
		t = new tetrahedron;
		t->t = TETRAHEDRON;
		In(*t, ifst);
		ifst >> t->destiny;
		sh = (shape*)t;
		return sh;
		break;
	default:
		return NULL;
		break;
	}
}

void Out(shape *s, ofstream &ofst) {
	switch (s->t) {
	case SPHERE:
		Out(*((sphere*)s), ofst);
		ofst << ", Destiny = " << ((sphere*)s)->destiny << endl;
		break;
	case PARALLELEPIPED:
		Out(*((parallelepiped*)s), ofst);
		ofst << ", Destiny = " << ((parallelepiped*)s)->destiny << endl;
		break;
	case TETRAHEDRON:
		Out(*((tetrahedron*)s), ofst);
		ofst << ", Destiny = " << ((tetrahedron*)s)->destiny << endl;
		break;
	default:
		ofst << "Incorrect shape!" << endl;
	}

}