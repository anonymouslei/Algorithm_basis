#include <iostream>

using namespace std;

void QuickSort(int a[], int start, int end)
{
	if (start > end)
		return;
	int k = a[start], i = start, j = end;
	while(i != j)
	{
		while(i < j && a[j] >= k)
			--j;
		swap(a[i], a[j]);
		while(i < j && a[i] <= k) // 注意！这里是i<j，不是i<=j
			++i;
		swap(a[i], a[j]);
	}
	QuickSort(a, start, i-1); //中间那个数的位置已经确定了，所以只需要算到i-1
	QuickSort(a, i+1, end);
}

int a[] = {93, 27, 30, 2, 8, 12, 2, 8, 30, 89};
int main()
{
	int size = sizeof(a)/sizeof(int);
	QuickSort(a, 0, size-1);
	for(int i = 0; i < size; ++i)
	{
		cout << a[i] << ",";
	}
	cout << endl;
	return 0;
}
