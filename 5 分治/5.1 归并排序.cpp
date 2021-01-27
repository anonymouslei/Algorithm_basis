#include <iostream>

using namespace std;

void Merge(int a[], int s, int m, int e, int tmp[])
{
	int p1 = s, p2 = m+1;
	int p = s;
	while(p1 <= m && p2 <= e)
	{
		if(a[p1] < a[p2])
		{
			tmp[p++] = a[p1++];
		} else 
		{
			tmp[p++] = a[p2++];
		}
	}
	while(p1 <= m)
	{
		tmp[p++] = a[p1++];
	}
	while(p2 <= e)
	{
		tmp[p++] = a[p2++];
	}
	for (int i = 0; i < e-s+1; ++i)
		a[s+i] = tmp[s+i];
}

void MergeSort(int a[], int s, int e, int tmp[])
{
	if (s >= e)
		return;
	int m = s + (e - s)/2;
	MergeSort(a, s, m, tmp);
	MergeSort(a, m+1, e, tmp);
	Merge(a, s, m, e, tmp);

	return;
}

int a[10] = {13, 27, 19, 2, 8, 12, 2, 8, 30, 89};
int b[10];

int main()
{
	int size = sizeof(a)/sizeof(int);
	MergeSort(a, 0, size-1, b);
	for (int i = 0; i < size; ++i)
		cout << a[i] << ", ";
	cout << endl;
	return 0;
}
