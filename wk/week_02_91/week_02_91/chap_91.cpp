#include <iostream>
#include <string>

using namespace std;

void printENG(int num);



int main()
{
	int input = 0;

	cin >> input;

	if (input == 0)
	{
		cout << "zero" << endl;
	}

	if (input < -999999 || input > 999999)
	{
		cout << "I can't do it. bye" << endl;		
	}
	
	if (input < 0)
	{
		cout << "minus ";
		input = input * -1;
	}

	int quotient = input / 1000;
	int remainder = input % 1000;


	if (quotient != 0)
	{
		printENG(quotient);
		cout << " thousand ";
	}
	
	if (remainder != 0)
	{
		printENG(remainder);
	}

	return 0;
}

void printENG(int num)
{
	
	if (num < 20)
	{
		if (num == 1) cout << "one";
		else if (num == 2)  cout << "two";
		else if (num == 3)  cout << "three";
		else if (num == 4)  cout << "four";
		else if (num == 5)  cout << "five";
		else if (num == 6)  cout << "six";
		else if (num == 7)  cout << "seven";
		else if (num == 8)  cout << "eight";
		else if (num == 9)  cout << "nine";
		else if (num == 10)  cout << "ten";
		else if (num == 11)  cout << "eleven";
		else if (num == 12)  cout << "twelve";
		else if (num == 13)  cout << "thirteen";
		else if (num == 14)  cout << "fourteen";
		else if (num == 15)  cout << "fifteen";
		else if (num == 16)  cout << "sixteen";
		else if (num == 17)  cout << "seventeen";
		else if (num == 18)  cout << "eighteen";
		else if (num == 19)  cout << "nineteen";
	}

	if (num >= 20)
	{
		int innum = num / 100;
		if (innum != 0)
		{
			if (innum == 1) cout << "one";
			else if (innum == 2)  cout << "two";
			else if (innum == 3)  cout << "three";
			else if (innum == 4)  cout << "four";
			else if (innum == 5)  cout << "five";
			else if (innum == 6)  cout << "six";
			else if (innum == 7)  cout << "seven";
			else if (innum == 8)  cout << "eight";
			else if (innum == 9)  cout << "nine";
			cout << " hundred ";
			innum = num % 100;
		}
		if (innum >= 20)
		{
			if (innum / 10 == 2)  cout << "twenty ";
			else if (innum / 10 == 3)  cout << "thirty ";
			else if (innum / 10 == 4)  cout << "fourty ";
			else if (innum / 10 == 5)  cout << "fifty ";
			else if (innum / 10 == 6)  cout << "sixty ";
			else if (innum / 10 == 7)  cout << "seventy ";
			else if (innum / 10 == 8)  cout << "eighty ";
			else if (innum / 10 == 9)  cout << "ninety ";
			innum = innum % 10;
			
			if (innum == 1) cout << "one";
			else if (innum == 2)  cout << "two";
			else if (innum == 3)  cout << "three";
			else if (innum == 4)  cout << "four";
			else if (innum == 5)  cout << "five";
			else if (innum == 6)  cout << "six";
			else if (innum == 7)  cout << "seven";
			else if (innum == 8)  cout << "eight";
			else if (innum == 9)  cout << "nine";



		}
	}
	


	
	

}
