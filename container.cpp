#include "main.h"

void Out(shape *s, ofstream &ofst);
shape* In(ifstream &ifst);

double Volume(shape *s);

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

