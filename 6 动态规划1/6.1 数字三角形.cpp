// source: bailian 2760
#include <iostream>
#include <algorithm>

#define MAX 101

using namespace std;

int D[MAX][MAX], result[MAX][MAX];
int N;

int calculatePath(int i, int j)
{
	if(result[i][j] != -1)
		return result[i][j];

	if (i < N-1)
		return result[i][j] = max(calculatePath(i+1, j), calculatePath(i+1, j+1)) + D[i][j];
	else 
		return result[i][j] = D[i][j];
}

int main()
{
	cin >> N;


	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			cin >> D[i][j];
			result[i][j] = -1;
		}
	}

	cout << calculatePath(0, 0) << endl;

	return 0;

}