#pragma once

#include "shape_atd.h"
#include "parallelepiped_atd.h"
#include "sphere_atd.h"
#include "container_atd.h"
#include "shape_type.h"
#include "list.h"
#include "tetrahedron_atd.h"

#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>


using namespace std;

bool Compare(shape *first, shape *second);

void ClearContainer(container &c);
void In(container &c, ifstream &ifst);
void Out(container &c, ofstream &ofst);

void Sort(container &c);

void OutSpheres(container &c, ofstream &ofst);

bool CompareContainer(container *c1, container *c2);
void ContainerPattern(container *c);
void SortedContainerPattern(container *c);

shape* In(ifstream &ifst);
void Out(shape *s, ofstream &ofst);
double Volume(shape *s);

void In(sphere &s, ifstream &ifst);
void Out(sphere &s, ofstream &ofst);
double Volume(sphere *s);

void In(parallelepiped &p, ifstream &ifst);
void Out(parallelepiped &p, ofstream &ofst);
double Volume(parallelepiped *p);

void In(tetrahedron &t, ifstream &ifst);
void Out(tetrahedron &t, ofstream &ofst);
double Volume(tetrahedron *t);

