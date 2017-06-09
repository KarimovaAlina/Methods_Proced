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


void ClearContainer(container &c);
void In(container &c, ifstream &ifst);
void Out(container &c, ofstream &ofst);

void Sort(container &c, bool napr);

void OutSpheres(container &c, ofstream &ofst);

double Volume(shape *s);

void Out(shape *s, ofstream &ofst);
shape* In(ifstream &ifst);

double Volume(shape *s);

bool Compare(shape *first, shape *second, bool napr);

