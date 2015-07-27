#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <string>
int main()
{
	srand(time(NULL));

	int rands[3] = { 0, };
	std::string buf;
	std::cout << "돌릴려면 1 종료 0" << std::endl;

	while (true)
	{
		std::cin >> buf;

		if (buf.c_str()[0] == '1')
		{
			rands[0] = (rand() % 10);
			rands[1] = (rand() % 10);
			rands[2] = (rand() % 10);

			std::cout << rands[0]<< "\t" << rands[1] << "\t" << rands[2] << std::endl;
			if (	(rands[0] == rands[1])
				&&	(rands[1] == rands[2]))
			{
				std::cout << "당첨" << std::endl;
			}
			else if ((rands[0] == 7) && (rands[1] == 7) && (rands[2] == 7) )
			{
				std::cout << "따따블" << std::endl;
			}
			else
			{
				std::cout << "꽝" << std::endl;
			}

		}
		else if (buf.c_str()[0] == '0')
		{
			break;
		}
		else
		{
			std::cout << "잘못된 수 입력.. 종료" << std::endl;
			break;
		}
		
	}
	return 0;
}
