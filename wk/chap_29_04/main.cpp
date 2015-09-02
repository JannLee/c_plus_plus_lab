#include <iostream>
#include <vector>

#include "sort.hpp"

using std::vector;
using namespace wk;



int main()
{

	vector<int> number;
	number.push_back(1);
	number.push_back(5);
	number.push_back(3);
	number.push_back(4);
	number.push_back(2);
	
	sort<int>(number);
	

	return 0;	
}