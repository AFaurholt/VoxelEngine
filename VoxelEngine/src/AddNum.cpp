#include "AddNum.h"

int add(int args...)
{
	int tmp = 0;
	for each (int num in args)
	{
		tmp += num;
	}

	return tmp;
}