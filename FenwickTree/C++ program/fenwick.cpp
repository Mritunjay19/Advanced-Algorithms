// C++ code to demonstrate operations of Binary Index Tree
#include <iostream>

using namespace std;


int getSum(int BITree[], int index)
{
	int sum = 0; // Initialize result

	// index in BITree[] is 1 more than the index in arr[]
	index = index + 1;

	// Traverse ancestors of BITree[index]
	while (index>0)
	{
		// Add current element of BITree to sum
		sum += BITree[index];

		// Move index to parent node in getSum View
		index -= index & (-index);
	}
	return sum;
}

void updateBIT(int BITree[], int n, int index, int val)
{
	// index in BITree[] is 1 more than the index in arr[]
	index = index + 1;

	// Traverse all ancestors and add 'val'
	while (index <= n)
	{
	// Add 'val' to current node of BI Tree
	BITree[index] += val;

	// Update index to that of parent in update View
	index += index & (-index);
	}
}

// Constructs and returns a Binary Indexed Tree for given
// array of size n.
int *constructBITree(int arr[], int n)
{
	// Create and initialize BITree[] as 0
	int *BITree = new int[n+1];
  
	for (int i= 1; i <= n; i++)
		BITree[i] = 0;

	// Store the actual values in BITree[] using update()
	for (int i=0; i<n; i++)
		updateBIT(BITree, n, i, arr[i]);

	return BITree;
}

int main()
{
	int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
	int n = sizeof(freq)/sizeof(freq[0]);
	int *BITree = constructBITree(freq, n);
	cout << "Sum of elements in arr[0 to 5] is "
		<< getSum(BITree, 5);

	freq[3] += 6;
	updateBIT(BITree, n, 3, 6); 

	cout << "\nSum of elements in arr[0 to 5] after update is "
		<< getSum(BITree, 5);

	return 0;
}
