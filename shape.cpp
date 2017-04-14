#include "main.h"


void In(sphere &s, ifstream &ifst);
void In(parallelepiped &p, ifstream &ifst);

void Out(sphere &s, ofstream &ofst);
void Out(parallelepiped &p, ofstream &ofst);

double Volume(parallelepiped *p);
double Volume(sphere *s);

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
	default:
		return NULL;
		break;
	}
}

void Out(shape *s, ofstream &ofst) {
	switch (s->t) {
	case SPHERE:
		Out(*((sphere*)s), ofst);
		ofst << ", Destiny = " << ((sphere*)s)->destiny;
		break;
	case PARALLELEPIPED:
		Out(*((parallelepiped*)s), ofst);
		ofst << ", Destiny = " << ((parallelepiped*)s)->destiny;
		break;
	default:
		ofst << "Incorrect shape!" << endl;
	}

}

double Volume(shape *s) {
	switch (s->t) {
	case SPHERE:
		return Volume(((sphere*)s));
	case PARALLELEPIPED:
		return Volume(((parallelepiped*)s));
	default:
		return -1;
	}
}