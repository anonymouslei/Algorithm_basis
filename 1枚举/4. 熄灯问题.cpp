#include <memory>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int GetBit(char c, int i)
{
	// 取c的第i位
	return (c >> i) & i;
}

void SetBit(char & c, int i, int v)
{
	if(v)
		c |= (1 << i);
	else
		c &= ~(1 << i)
}

void Flip(char & c, int i)
{
	
}
