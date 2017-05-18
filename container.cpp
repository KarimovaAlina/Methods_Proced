#include "main.h"


void Out(shape *s, ofstream &ofst);
shape* In(ifstream &ifst);

double Volume(shape *s);

bool Compare(shape *first, shape *second);

void Out(container &c, ofstream &ofst) 
{
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


void In(container &c, ifstream &ifst) 
{
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


void ClearContainer(container &c) 
{
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


void Sort(container &c) 
{
	for (int i = 0; i < c.n - 1; i++) 
	{
		list* cur = c.cont;
		for (int j = i + 1; j < c.n; j++) 
		{
			if (Compare(cur->shape, cur->next->shape)) 
			{
				shape *tmp = cur->shape;
				cur->shape = cur->next->shape;
				cur->next->shape = tmp;
			}
			cur = cur->next;
		}
	}
}

void OutSpheres(container &c, ofstream &ofst) 
{
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

void MultiMethod(container* cont, ofstream &file)
{
	file << endl << "Multimethod:" << endl;
	list *temp1 = new list;
	temp1 = cont->cont;
	list *temp2 = new list;
	temp2 = cont->cont->next;
	while (temp1->next != NULL)
	{
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
					file << "Sphere and Sphere:" << endl;
					break;
				}
				case PARALLELEPIPED:
				{
					file << "Sphere and Parallelepiped:" << endl;
					break;
				}
				case TETRAHEDRON:
				{
					file << "Sphere and Tetrahedron:" << endl;
					break;
				}
				default:
				{
					file << "Unknown type" << endl;
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
					file << "Parallelepiped and Sphere:" << endl;
					break;
				}
				case PARALLELEPIPED:
				{
					file << "Parallelepiped and Parallelepiped:" << endl;
					break;
				}
				case TETRAHEDRON:
				{
					file << "Parallelepiped and Tetrahedron:" << endl;
					break;
				}
				default:
				{
					file << "Unknown type" << endl;
					break;
				}
				}
				break;
			}
			case TETRAHEDRON:
			{
				switch (temp2->shape->t)
				{
				case SPHERE:
				{
					file << "Tetrahedron and Sphere:" << endl;
					break;
				}
				case PARALLELEPIPED:
				{
					file << "Tetrahedron and Parallelepiped:" << endl;
					break;
				}
				case TETRAHEDRON:
				{
					file << "Tetrahedron and Tetrahedron:" << endl;
					break;
				}
				default:
				{
					file << "Unknown type" << endl;
					break;
				}
				}
				break;
			}
			default:
			{
				file << "Unknown type" << endl;
				break;
			}
			}
			Out(temp1->shape, file);
			file << ", V = " << Volume(temp1->shape) << endl;
			Out(temp2->shape, file);
			file << ", V = " << Volume(temp2->shape) << endl << endl;;
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}

