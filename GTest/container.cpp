#include "main.h"


void Out(shape *s, ofstream &ofst);
shape* In(ifstream &ifst);

double Volume(shape *s);

bool Compare(shape *first, shape *second);

void Out(container &c, ofstream &ofst) {
	ofst << "Container contains " << c.n << " elements." << endl;
	list* cur = c.cont;
	int s = 0;
	while (cur != NULL && s < c.n)
	{
		ofst << s + 1 << " :  ";
		Out(cur->shape, ofst);
		ofst << ", Volume = " << Volume(cur->shape);
		ofst << endl;
		cur = cur->next;
		++s;
	}

}


void In(container &c, ifstream &ifst) {
	list* cur = c.cont;
	if (c.cont == NULL)
	{
		c.cont = new list;
		cur = c.cont;
	}
	else
	{
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new list;
		cur = cur->next;
	}
	list* prev = cur;
	while (!ifst.eof())
	{

		if ((cur->shape = In(ifst)) != 0)
		{
			++c.n;
			prev = cur;
			cur->next = new list;
			cur = cur->next;
		}
	}
	prev->next = NULL;
}


void ClearContainer(container &c) {
	list* a;
	while (c.cont != NULL && c.n > 0)
	{
		a = c.cont->next;
		delete c.cont;
		c.cont = a;
		--c.n;
	}
	c.n = 0;
	c.cont = NULL;
}


void Sort(container &c) {
	for (int i = 0; i < c.n - 1; i++) {
		list* cur = c.cont;
		for (int j = i + 1; j < c.n; j++) {
			if (Compare(cur->shape, cur->next->shape)) {
				shape *tmp = cur->shape;
				cur->shape = cur->next->shape;
				cur->next->shape = tmp;
			}
			cur = cur->next;
		}
	}
}

void OutSpheres(container &c, ofstream &ofst) {
	ofst << "Only spheres:" << endl;

	list* cur = c.cont;
	int s = 0;
	while (cur != NULL && s < c.n)
	{
		
		if (cur->shape->t == SPHERE)
		{
			ofst << s + 1 << " :  ";
			Out(cur->shape, ofst);
			ofst << endl;
			++s;
		}
		

		cur = cur->next;
		
	}
}

bool CompareContainer(container *c1, container *c2)
{
	
	if (c1->n != c2->n)
		return false;
	else
	{
		int n = c1->n;
		for (int i = 0; i < n; i++)
		{
			if (c1->cont->shape->t == SPHERE && c2->cont->shape->t == SPHERE)
				if (((sphere*)c1->cont->shape)->rad != ((sphere*)c2->cont->shape)->rad)
					return false;
			if (c1->cont->shape->t == PARALLELEPIPED && c2->cont->shape->t == PARALLELEPIPED)
				if (((parallelepiped*)c1->cont->shape)->e1 != ((parallelepiped*)c2->cont->shape)->e1 || ((parallelepiped*)c1->cont->shape)->e2 != ((parallelepiped*)c2->cont->shape)->e2 || ((parallelepiped*)c1->cont->shape)->e3 != ((parallelepiped*)c2->cont->shape)->e3)
					return false;
			if (c1->cont->shape->t == TETRAHEDRON && c2->cont->shape->t == TETRAHEDRON)
				if (((tetrahedron*)c1->cont->shape)->side != ((tetrahedron*)c2->cont->shape)->side)
					return false;
			if ((c1->cont->shape->t != c2->cont->shape->t) || (c1->cont->shape->destiny != c2->cont->shape->destiny) || (c1->cont->shape->temp != c2->cont->shape->temp))
				return false;
			c1->cont = c1->cont->next;
			c2->cont = c2->cont->next;
		}
	}
	return true;
}

void ContainerPattern(container *c)
{
	c->n = 6;
	c->cont = new list;
	list* cur = c->cont;
	cur->shape = new shape;
	cur->next = new list;
	((tetrahedron*)c->cont->shape)->t = TETRAHEDRON;
	((tetrahedron*)c->cont->shape)->side = 9;
	((tetrahedron*)c->cont->shape)->destiny = 98;
	((tetrahedron*)c->cont->shape)->temp = 354;
	cur = cur->next;

	cur->shape = new shape;
	cur->next = new list;
	((sphere*)cur->shape)->t = SPHERE;
	((sphere*)cur->shape)->rad = 10;
	((sphere*)cur->shape)->destiny = 100;
	((sphere*)cur->shape)->temp = 500;

	cur = cur->next;
	cur->shape = new shape;
	cur->next = new list;
	((tetrahedron*)cur->shape)->t = TETRAHEDRON;
	((tetrahedron*)cur->shape)->side = 15;
	((tetrahedron*)cur->shape)->destiny = 150;
	((tetrahedron*)cur->shape)->temp = 1000;

	cur = cur->next;
	cur->shape = new shape;
	cur->next = new list;
	((parallelepiped*)cur->shape)->t = PARALLELEPIPED;
	((parallelepiped*)cur->shape)->e1 = 1;
	((parallelepiped*)cur->shape)->e2 = 10;
	((parallelepiped*)cur->shape)->e3 = 100;
	((parallelepiped*)cur->shape)->destiny = 300;
	((parallelepiped*)cur->shape)->temp = 1500;

	cur = cur->next;
	cur->shape = new shape;
	cur->next = new list;
	((sphere*)cur->shape)->t = SPHERE;
	((sphere*)cur->shape)->rad = 25;
	((sphere*)cur->shape)->destiny = 250;
	((sphere*)cur->shape)->temp = 3000;

	cur = cur->next;
	cur->shape = new shape;
	cur->next = NULL;
	((parallelepiped*)cur->shape)->t = PARALLELEPIPED;
	((parallelepiped*)cur->shape)->e1 = 2;
	((parallelepiped*)cur->shape)->e2 = 20;
	((parallelepiped*)cur->shape)->e3 = 200;
	((parallelepiped*)cur->shape)->destiny = 600;
	((parallelepiped*)cur->shape)->temp = 5000;

	
}

void SortedContainerPattern(container *c)
{
	c->n = 6;
	c->cont = new list;
	list* cur = c->cont;
	cur->shape = new shape;
	cur->next = new list;
	((sphere*)c->cont->shape)->t = SPHERE;
	((sphere*)c->cont->shape)->rad = 25;
	((sphere*)c->cont->shape)->destiny = 250;
	((sphere*)c->cont->shape)->temp = 3000;

	cur = cur->next;
	cur->shape = new shape;
	cur->next = new list;
	((parallelepiped*)cur->shape)->t = PARALLELEPIPED;
	((parallelepiped*)cur->shape)->e1 = 2;
	((parallelepiped*)cur->shape)->e2 = 20;
	((parallelepiped*)cur->shape)->e3 = 200;
	((parallelepiped*)cur->shape)->destiny = 600;
	((parallelepiped*)cur->shape)->temp = 5000;

	cur = cur->next;
	cur->shape = new shape;
	cur->next = new list;
	((sphere*)cur->shape)->t = SPHERE;
	((sphere*)cur->shape)->rad = 10;
	((sphere*)cur->shape)->destiny = 100;
	((sphere*)cur->shape)->temp = 500;

	cur = cur->next;
	cur->shape = new shape;
	cur->next = new list;
	((parallelepiped*)cur->shape)->t = PARALLELEPIPED;
	((parallelepiped*)cur->shape)->e1 = 1;
	((parallelepiped*)cur->shape)->e2 = 10;
	((parallelepiped*)cur->shape)->e3 = 100;
	((parallelepiped*)cur->shape)->destiny = 300;
	((parallelepiped*)cur->shape)->temp = 1500;

	cur = cur->next;
	cur->shape = new shape;
	cur->next = new list;
	((tetrahedron*)cur->shape)->t = TETRAHEDRON;
	((tetrahedron*)cur->shape)->side = 15;
	((tetrahedron*)cur->shape)->destiny = 150;
	((tetrahedron*)cur->shape)->temp = 1000;

	cur = cur->next;
	cur->shape = new shape;
	cur->next = NULL;
	((tetrahedron*)cur->shape)->t = TETRAHEDRON;
	((tetrahedron*)cur->shape)->side = 9;
	((tetrahedron*)cur->shape)->destiny = 98;
	((tetrahedron*)cur->shape)->temp = 354;

	

}


