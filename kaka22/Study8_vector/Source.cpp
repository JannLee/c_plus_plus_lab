#include "VectorOfInt.h"

int main()
{
	{
		CVectorOfInt vector;

		vector.set(32, 1);

		int i1 = vector.get(32);

		vector.pushback(25);
		int i2 = vector.get(33);
		vector.pushfront(36);
		int i3 = vector.get(34);
		

	}

	{
		CVectorOfInt vector(-2);

		int i1 = vector.get(32);

		vector.pushback(25);
		int i2 = vector.get(33);
		vector.pushfront(36);
		int i3 = vector.get(34);
	}
	return 0; 
}