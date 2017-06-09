#include "main.h"



bool Compare(shape *first, shape *second, bool napr) {
	if (napr)
	{
		if (Volume(first) < Volume(second))
			return 1;
		else
			return 0;
	}
	else
	{
		if (Volume(first) < Volume(second))
			return 0;
		else
			return 1;
	}
}