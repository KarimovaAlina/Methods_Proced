#pragma once

#include "shape_atd.h"
#include "parallelepiped_atd.h"
#include "sphere_atd.h"
#include "container_atd.h"
#include "shape_type.h"
#include "list.h"

#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>


using namespace std;


void ClearContainer(container &c);
void In(container &c, ifstream &ifst);
void Out(container &c, ofstream &ofst);
void OutSpheres(container &c, ofstream &ofst);
