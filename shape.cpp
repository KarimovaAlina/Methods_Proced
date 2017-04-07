#include "main.h"


void In(sphere &s, ifstream &ifst);
void In(parallelepiped &p, ifstream &ifst);

void Out(sphere &s, ofstream &ofst);
void Out(parallelepiped &p, ofstream &ofst);

shape* In(ifstream &ifst) {
	shape *sh;
	sphere* sp;
	parallelepiped* p;
	int type;
	ifst >> type;
	switch (type)
	{
	case 0:
		sp = new sphere;
		sp->t = SPHERE;
		In(*sp, ifst);
		ifst >> sp->destiny >> sp->temp;
		sh = (shape*)sp;
		return sh;
		break;
	case 1:
		p = new parallelepiped;
		p->t = PARALLELEPIPED;
		In(*p, ifst);
		ifst >> p->destiny >> p->temp;
		sh = (shape*)p;
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
		ofst << ", Destiny = " << ((sphere*)s)->destiny << ", Melting temperature = " << ((sphere*)s)->temp;
		break;
	case PARALLELEPIPED:
		Out(*((parallelepiped*)s), ofst);
		ofst << ", Destiny = " << ((parallelepiped*)s)->destiny << ", Melting temperature = " << ((parallelepiped*)s)->temp;
		break;
	default:
		ofst << "Incorrect shape!" << endl;
	}

}