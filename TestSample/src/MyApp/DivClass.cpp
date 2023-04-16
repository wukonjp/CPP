#include <ComA/AddClass.h>
#include <ComB/SubClass.h>
#include "MultiClass.h"
#include "DivClass.h"

int DivClass::Div(int add1, int add2, int sub1, int sub2)
{
	MultiClass multi;
	return multi.Multi(add1, add2, sub1, sub2) / 2;
}
