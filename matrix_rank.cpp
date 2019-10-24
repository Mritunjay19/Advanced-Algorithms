#include <bits/stdc++.h> 
using namespace std; 
#define R 3 
#define C 3 

void swap(int mat[R][C], int row1, int row2, 
		int col) 
{ 
	for (int i = 0; i < col; i++) 
	{ 
		int temp = mat[row1][i]; 
		mat[row1][i] = mat[row2][i]; 
		mat[row2][i] = temp; 
	} 
} 

void display(int mat[R][C], int row, int col); 

int rankOfMatrix(int mat[R][C]) 
{ 
	int rank = C; 

	for (int row = 0; row < rank; row++) 
	{ 

		if (mat[row][row]) 
		{ 
		for (int col = 0; col < R; col++) 
		{ 
			if (col != row) 
			{ 
				double mult = (double)mat[col][row] / 
									mat[row][row]; 
				for (int i = 0; i < rank; i++) 
				mat[col][i] -= mult * mat[row][i]; 
			} 
		} 
		} 

		else
		{ 
			bool reduce = true; 

			for (int i = row + 1; i < R; i++) 
			{ 
				if (mat[i][row]) 
				{ 
					swap(mat, row, i, rank); 
					reduce = false; 
					break ; 
				} 
			} 

			if (reduce) 
			{ 
				rank--; 

				for (int i = 0; i < R; i ++) 
					mat[i][row] = mat[i][rank]; 
			} 

			row--; 
		} 

	} 
	return rank; 
} 

void display(int mat[R][C], int row, int col) 
{ 
	for (int i = 0; i < row; i++) 
	{ 
		for (int j = 0; j < col; j++) 
			printf(" %d", mat[i][j]); 
		printf("\n"); 
	} 
} 

int main() 
{ 
int mat[][3] = {{10, 20, 10}, 
				{-20, -30, 10}, 
				{30, 50, 0}}; 
	printf("Rank of the matrix is : %d", 
		rankOfMatrix(mat)); 
	return 0; 
} 
