#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <string>

char strbuf[10][10] = {"ZERO", "ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
char strbuf2[10][10] = {"ZERO", "TEEN",
"TWENTY-",
"THIRTY-",
"FORTY-",
"FIFTY-",
"SIXTY-",
"SEVNETY-",
"EIGHTY-",
"NINETY-",

};

int Conv(int _one, int _two,std::string& str2, std::string& str1 )
{
	int temp = 0;
	temp = (_one * 10) + (_two);
	switch (temp)
	{
	case 10:	str2 = "TEN"; str1.clear(); break;

	case 11:	str2 = "ELEVEN"; str1.clear(); break;
	case 12:	str2 = "TWELVE"; str1.clear(); break;
	case 13:	str2 = "THIR TEEN";	 break;
	case 14:	str2 = "FOUR TEEN";	 break;
	case 15:	str2 = "FIF TEEN";		 break;
	case 16:	str2 = "SIX TEEN";		 break;
	case 17:	str2 = "SEVEN TEEN";		 break;
	case 18:	str2 = "EIGH TEEN";	 break;
	case 19:	str2 = "NINE TEEN";		 break;
	default:
		str2 = strbuf2[_one];
		break;
	}
	return temp;
}

int main()
{

	int input = 0;
	std::cout << "ÀÔ·ÂÇÏ¼À." << std::endl;
	std::cin >> input;
	if (!( (input <= 999999)&& (input >= -999999)))
	{

		return 1;
	}
	
	int buf = input;
	int bufx[11] = { 0, };
	int i = 0;
	int j = 10;

	while (buf)
	{
		bufx[i] = buf % j;
		buf = (buf-bufx[i])/ 10;
		i++;
		
	}
	std::string str1;
	std::string str2;
	std::string str3;
	std::string str4;
	std::string str5;
	std::string str6;


	if(bufx[0] != 0)
	{
		str1 = strbuf[bufx[0]];
	}
	if (bufx[1] != 0)
	{
		Conv(bufx[1], bufx[0], str2, str1);
	}
	if (bufx[2] != 0)
	{
		str3 = strbuf[bufx[2]];
		str3 = str3 + " hundred ";
	}
	if (bufx[3] != 0)
	{
		str4 = strbuf[bufx[3]];
		str4 = str4 + " thosand ,";
	}
	if (bufx[4] != 0)
	{
		Conv(bufx[4], bufx[3], str5, str4);
	}
	if (bufx[5] != 0)
	{
		str6 = strbuf[bufx[5]];
		str6 = str6 + " hundred ";
	}

	if (input < 0)
	{
		std::cout << "- ";
	}
	std::cout << str6 << str5 << str4 << str3 << str2 << str1 << std::endl;
	return 0;
}
