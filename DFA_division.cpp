#include <bits/stdc++.h> 
using namespace std; 

void preprocess(int k, int Table[][2]) 
{ 
	int trans0, trans1; 

	for (int state = 0; state < k; ++state) 
	{ 
		trans0 = state << 1; 
		Table[state][0] = (trans0 < k) ? 
								trans0 : trans0 - k; 

		trans1 = (state << 1) + 1; 
		Table[state][1] = (trans1 < k) ? 
								trans1 : trans1 - k; 
	} 
} 

void isDivisibleUtil(int num, int* state, 
					int Table[][2]) 
{ 
	if (num != 0) 
	{ 
		isDivisibleUtil(num >> 1, state, Table); 
		*state = Table[*state][num & 1]; 
	} 
} 
int isDivisible (int num, int k) 
{ 
	int (*Table)[2] = (int (*)[2])malloc(k*sizeof(*Table)); 

	preprocess(k, Table); 

	int state = 0; 
	isDivisibleUtil(num, &state, Table); 

	return state; 
} 

int main() 
{ 
	int num = 47; 
	int k = 5; 

	int remainder = isDivisible (num, k); 

	if (remainder == 0) 
		cout << "Divisible\n"; 
	else
		cout << "Not Divisible: Remainder is "
			<< remainder; 

	return 0; 
} 
