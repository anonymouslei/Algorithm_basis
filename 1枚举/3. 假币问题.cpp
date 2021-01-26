#include <iostream>
#include <cstring>

using namespace std;

char Left[3][7]; //天平左边硬币
char Right[3][7]; //天平右边硬币
char result[3][7]; //结果
bool IsFake(char c, bool light); 
// light 为真表示假设假币为轻，否则表示假设假币为重

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		for(int i = 0; i < 3; ++i)
			cin >> Left[i] >> Right[i] >> result[i];
		for(char c='A'; c<='L'; c++)
		{
			if (IsFake(c, true))
			{
				cout << c << "is the counterfeit coin and it is light. \n";
				break;
			}
			else if (IsFake(c, false))
			{
				cout << c << " is the counterfeit coin and it is heavy. \n";
				break;
			}
		}
	}

	return 0;
}

bool IsFake(char c, bool light)
{
	for(int i = 0; i < 3; ++i)
	{
		char * pLeft, *pRight; // 指向天平两边的字符串
		if(light)
		{
			pLeft = Left[i];
			pRight = Right[i];
		}
		else // 如果假设假币是重的，则把称重结果左右对换
		{
			pLeft = Right[i];
			pRight = Left[i];
		}

		switch(result[i][0])
		{
			case 'u':
				if (strchr(pRight, c) == NULL)
					return false;
				break;
			case 'e':
				if (strchr(pLeft, c) || strchr(pRight, c))
					return false;
				break;
			case 'd':
				if (strchr(pLeft, c) == NULL)
					return false;
				break;
		}
	}

	return true;
}