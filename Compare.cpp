#include <stdio.h>
#include "shape_atd.h"

double Volume(shape *s);

bool Compare(shape *first, shape *second) {
	if (Volume(first) < Volume(second))
		return 1;
	else
		return 0;
}