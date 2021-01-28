/*
我觉得这道题的解题思路是不对的。老师的思路只能验证只有最后一行的灯都熄灭了。。。
*/
#include <iostream>
#include <string>
#include <cstring>
#include <memory>

using namespace std;

void setBit(char& c, int i, int v)
{
	if (v)
	{
		c |= (1 << i);
	} else 
	{
		c &= ~(1 << i);
	}
}

int getBit(char c, int i)
{
	return (c >> i) & 1;
}

void flip(char& c, int i)
{
	c ^= (1 << i);
}

void outputResult(int t, char result[])
{
	cout << "PUZZLE #" << t + 1 << endl;
	for(int i = 0; i < 5; ++i)
	{
		for(int j = 0; j < 6; ++j)
		{
			cout << getBit(result[i], j);
			if(j < 5)
				cout << " ";
		}
		cout << endl;
	}
}


int main()
{
	char result[5], origLight[5], light[5];
	int num;
	cin >> num;
	for(int i = 0; i < num; i++)
	{
		memset(origLight, 0, sizeof origLight);
		for (int i = 0; i < 5; ++i)
		{
			for( int j = 0; j < 6; j++)
			{
				int s;
				cin >> s;
				setBit(origLight[i], j, s);
			}
		}

		char switchs;
		for(int k = 0; k < 64; ++k)
		{
			memcpy(light, origLight, sizeof origLight);
			switchs = k;

			for(int i = 0; i < 5; i++)
			{
				result[i] = switchs;
				// 修改当前行的灯
				for(int j = 0; j < 6; j++)
				{	
					if(getBit(switchs, j))
					{
						// 修改该灯
						flip(light[i], j);
	
						// 修改左边的灯
						if(j > 0)
							flip(light[i], j-1);
	
						// 修改右边的灯
						if(j < 5)
							flip(light[i], j+1);
					}
				}
	
				if (i < 4)
				// 修改下一行的灯
					light[i+1] ^= switchs;
	
				// 定义下一行switch
				switchs = light[i];
			}
			// 判断最后一行是不是都熄灭了，如果是，break
			if(light[4] == 0 && light[0] == 0)
			{
				cout << "find the best answer! \n";
				break;
			}
		}

		outputResult(i, result);	
		outputResult(i, light);	
	}

	return 0;
}
