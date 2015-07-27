#include <iostream>
#include <ctime>


using namespace std;


struct Miro
{
	char **set;
	int sizex;
	int sizey;
	int nowx;
	int nowy;
};

int make_miro(Miro& miro);
void set_miro(Miro& miro);
void set_path(Miro& miro);
void print_miro(Miro& miro);

int main()
{
	srand(time(NULL));


	Miro miro;
	miro.set = NULL;

	make_miro(miro);
	set_miro(miro);
	set_path(miro);
	print_miro(miro);





	return 0;
}


int make_miro(Miro& miro)
{
	cout << "미로의 너비를 입력하세요. : " << endl;
	cin >> miro.sizex;

	cout << "미로의 높이를 입력하세요. : " << endl;
	cin >> miro.sizey;

	if (miro.sizex <= 0 || miro.sizey <= 0 || miro.sizex > 60 || miro.sizey > 60)
	{
		cout << "I can't it~~ bye bye //" << endl;
		return -1;
	}

}

void set_miro(Miro& miro)
{
	miro.set = new char*[miro.sizex];
	for (int i = 0; i < miro.sizex; ++i)
	{
		miro.set[i] = new char[miro.sizey];
		memset(miro.set[i], '0', miro.sizey * sizeof(char));
	}


}

void set_path(Miro& miro)
{

	miro.set[0][0] = 'S';
	miro.nowx = 0;
	miro.nowy = 0;
	for (int i = 0; ((miro.nowx < miro.sizex) && (miro.nowy < miro.sizey)); ++i)
	{
		int go = rand() % 3;
		if (go == 1)
		{
			++miro.nowx;
			miro.set[miro.nowx][miro.nowy] = ' ';
		}
		else
		{
			++miro.nowy;
			miro.set[miro.nowx][miro.nowy] = ' ';
		}


	}
}



void print_miro(Miro& miro)
{
	for (int i = 0; i < miro.sizex; ++i)
	{
		for (int j = 0; j < miro.sizey; ++j)
		{
			cout << miro.set[i][j];
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}

