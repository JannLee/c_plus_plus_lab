#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void printNum(int in);

int main() {
	int in = 0;
	cin >> in;
	if (in >= -999999 && in <= 999999) {
		if (in < 0) {
			cout << "¸¶ÀÌ³Ê½º ";
			in = in * -1;
		}
		if (in == 0) {
			cout << "¿µ";
		}
		else {
			int th = in / 1000;
			int hu = in % 1000;
			if (th != 0) {
				printNum(th);
				cout << " ½Î¿ìÀüµå ";
			}
			if (hu != 0)
			{
				printNum(hu);
			}
		}
	}
	cout << endl;
	cin.get();
	return 0;
}

void printNum(int in) {
	int num = 0;
	if (in / 100 != 0)
	{
		if (in / 100 == 1) cout << "¿ø";
		else if (in / 100 == 2)  cout << "Åõ";
		else if (in / 100 == 3)  cout << "¾²¸®";
		else if (in / 100 == 4)  cout << "Æ÷";
		else if (in / 100 == 5)  cout << "ÆÄÀÌºê";
		else if (in / 100 == 6)  cout << "¾¿½º";
		else if (in / 100 == 7)  cout << "¼¼ºì";
		else if (in / 100 == 8)  cout << "¿¡ÀÕ";
		else if (in / 100 == 9)  cout << "³ªÀÎ";
		cout << " Çåµå·¹µå ";
		in = in % 100;
	}
	num = in % 100;
	if (num >= 20)
	{
		if (num / 10 == 2)  cout << "ÅõÀ¢Æ¼ ";
		else if (num / 10 == 3)  cout << "½äÆ¼ ";
		else if (num / 10 == 4)  cout << "¾ŸÆ¼ ";
		else if (num / 10 == 5)  cout << "ÇÇÇÁÆ¼ ";
		else if (num / 10 == 6)  cout << "½Ä½ºÆ¼ ";
		else if (num / 10 == 7)  cout << "¼¼ºìÆ¼ ";
		else if (num / 10 == 8)  cout << "¿¡ÀÕÆ¼ ";
		else if (num / 10 == 9)  cout << "³ªÀÎÆ¼ ";
		num = num % 10;
	}
	if (num == 1) cout << "¿ø";
	else if (num == 2)  cout << "Åõ";
	else if (num == 3)  cout << "¾²¸®";
	else if (num == 4)  cout << "Æ÷";
	else if (num == 5)  cout << "ÆÄÀÌºê";
	else if (num == 6)  cout << "¾¿½º";
	else if (num == 7)  cout << "¼¼ºì";
	else if (num == 8)  cout << "¿¡ÀÕ";
	else if (num == 9)  cout << "³ªÀÎ";
	else if (num == 10)  cout << "ÅÙ";
	else if (num == 11)  cout << "ÀÏ·¹ºì";
	else if (num == 12)  cout << "ÅõÀ£ºê";
	else if (num == 13)  cout << "½äÆ¾";
	else if (num == 14)  cout << "ÈÎÆ¾";
	else if (num == 15)  cout << "ÈÖÇÁÆ¾";
	else if (num == 16)  cout << "½Ä½ºÆ¾";
	else if (num == 17)  cout << "¼¼ºìÆ¾";
	else if (num == 18)  cout << "¿¡ÀÕÆ¾";
	else if (num == 19)  cout << "³ªÀÎÆ¾";
}