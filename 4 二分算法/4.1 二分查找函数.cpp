int LowerBound(int a[], int size, int p) //查找下标元素
{
	int l = 0, r = size - 1;
	while(l <= r)
	{
		int mid = l + (r - l) / 2;
		if (a[mid] == p)
			return mid;
		if (a[mid] > p)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
} // 复杂度O(log(n))

int LowerBound(int a[], int size, int p)// 查找下标比p小的最大的元素
{
	int l = 0, r = size - 1;
	int lastPosition = -1;
	while(l <= r)
	{
		int mid = l + (r - l) / 2;
		if (a[mid] >= p)
		{
			r = mid - 1;
		} else {
			lastPosition = mid;
			l = mid + 1;
		}
	}
	return lastPosition;
}