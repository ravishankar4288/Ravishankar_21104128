#include<bits/stdc++.h>
using namespace std;

// Simple binary search algorithm
int binarySearch(int arr[], int l, int r, int x)
{
	if (r>=l)
	{
		int mid = l + (r - l)/2;
		if (arr[mid] == x)
			return mid;
		if (arr[mid] > x)
			return binarySearch(arr, l, mid-1, x);
		return binarySearch(arr, mid+1, r, x);
	}
	return -1;
}


int findPos(int arr[], int key)
{
	int l = 0, h = 1;
	int val = arr[0];

	// Find h to do binary search
	while (val < key)
	{
		l = h;	 // store previous high
		h = 2*h;	 // double high index
		val = arr[h]; // update new val
	}


	return binarySearch(arr, l, h, key);
}


int main()
{
	int arr[] = {1,2,3 ,4,5,6,7,8,9,10,11,15,16,20,30,40,50,60,70,80,90,100};
	int ans = findPos(arr, 50);
	if (ans==-1)
		cout << " Sorry, this number is not avail in this array ";
	else
		cout << " Element found at index " << ans;
	return 0;
}

