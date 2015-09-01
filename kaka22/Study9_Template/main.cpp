#include "VectorSort.h"
#include <vector>
int main()
{
	std::vector<double>			VecDouble;
	std::vector<int>			VecINT;
	std::vector<unsigned char>	VecUCHAR;




	VectorSort::Sort<double>		(VecDouble);
	VectorSort::Sort<int>			(VecINT);
	VectorSort::Sort<unsigned char>	(VecUCHAR);
	return 0;
}