#include<iostream> 
using namespace std; 

const int Q = 5; 
const int R = 4; 

void calculateNeed(int need[Q][R], int maxm[Q][R], 
				int allot[Q][R]) 
{ 
	for (int i = 0 ; i < Q ; i++) 
		for (int j = 0 ; j < R ; j++) 

			
			need[i][j] = maxm[i][j] - allot[i][j]; 
} 
bool isSafe(int processes[], int avail[], int maxm[][R], 
			int allot[][R]) 
{ 
	int need[Q][R]; 
	calculateNeed(need, maxm, allot); 
	bool finish[Q] = {0}; 
	int safeSeq[Q]; 
	int work[R]; 
	for (int i = 0; i < R ; i++) 
		work[i] = avail[i]; 
	
	int count = 0; 
	while (count < Q) 
	{ 
			bool found = false; 
		for (int p = 0; p < Q; p++) 
		{ 
				if (finish[p] == 0) 
			{ 
				int j; 
				for (j = 0; j < R; j++) 
					if (need[p][j] > work[j]) 
						break; 

			
				if (j == R) 
				{ 
					for (int k = 0 ; k < R ; k++) 
						work[k] += allot[p][k]; 
					safeSeq[count++] = p; 
						finish[p] = 1; 

					found = true; 
				} 
			} 
		} 	 
		if (found == false) 
		{ 
			cout << "System is not in safe state"; 
			return false; 
		} 
	} 
	cout << "System is in safe state.\nSafe"
		" sequence is: "; 
	for (int i = 0; i < Q ; i++) 
		cout<<"P"<<safeSeq[i] << " "; 

	return true; 
} 
int main() 
{ 
	int processes[] = {0, 1, 2, 3, 4}; 
	int avail[]={1, 5, 2, 0};
	
	int maxm[][R] = {{0, 0, 1, 2},
	               {1, 7, 5, 0},
	               {2, 3, 5, 6},
	               {0, 6, 5, 2},
	               {0, 6, 5, 6}};
	               
	int allot[][R] ={{0, 0, 1, 2},
	                 {1, 0, 0, 0},
	                 {1, 3, 5, 4},
	                 {0, 6, 3, 2},
	                 {0, 0, 1, 4}};

	isSafe(processes, avail, maxm, allot); 
	return 0; 
} 

