#pragma once

#include "shape_atd.h"
#include "parallelepiped_atd.h"
#include "sphere_atd.h"
#include "container_atd.h"
#include "shape_type.h"
#include "list.h"
#include "tetrahedron_atd.h"
#include "Secure.h"

#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>


using namespace std;


void ClearContainer(container &c);
void In(container &c, ifstream &ifst);
void Out(container &c, ofstream &ofst);
void MultiMethod(container* cont, ofstream &file);
void Sort(container &c);

void OutSpheres(container &c, ofstream &ofst);

