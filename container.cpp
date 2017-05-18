#include "main.h"

void Out(shape *s, ofstream &ofst);
shape* In(ifstream &ifst);

void Out(container &c, ofstream &ofst) {
	ofst << "Container contains " << c.n << " elements." << endl;
	list* cur = c.cont;
	int s = 0;
	while (cur != NULL && s < c.n)
	{
		ofst << s + 1 << " :  ";
		Out(cur->shape, ofst);
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

void MultiMethod(container* l, ofstream &f)
{
	f << endl << "Multimethod:" << endl;
	list *temp1 = l->cont;
	list *temp2 = l->cont->next;
	while (temp1->next != NULL)
	{
		temp2 = temp1->next;
		while (temp2->next != NULL)
		{
			switch (temp1->shape->t)
			{
			case SPHERE:
			{
				switch (temp2->shape->t)
				{
				case SPHERE:
				{
					f << "Sphere and Sphere:" << endl;
					break;
				}
				case PARALLELEPIPED:
				{
					f << "Sphere and Parallelepiped:" << endl;
					break;
				}
				default:
				{
					f << "Unknown type" << endl;
					break;
				}
				}
				break;
			}
			case PARALLELEPIPED:
			{
				switch (temp2->shape->t)
				{
				case SPHERE:
				{
					f << "Box and Sphere:" << endl;
					break;
				}
				case PARALLELEPIPED:
				{
					f << "Box and Parallelepiped:" << endl;
					break;
				}
				default:
				{
					f << "Unknown type" << endl;
					break;
				}
				}
				break;
			}
			default:
			{
				f << "Unknown type" << endl;
				break;
			}
			}
			Out(temp1->shape, f);
			Out(temp2->shape, f);
			f << endl;
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}

}