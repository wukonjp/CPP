#include <ComA/AddClass.h>
#include <ComB/SubClass.h>
#include "MultiClass.h"

int MultiClass::Multi(int add1, int add2, int sub1, int sub2)
{
	AddClass add;
	SubClass sub;
	return add.Add(add1, add2) * sub.Sub(sub1, sub2);
}
