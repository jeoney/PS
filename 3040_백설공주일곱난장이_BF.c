//https://www.acmicpc.net/problem/3040

#include <stdio.h>
#define MAXN 9

int arr[MAXN];
int check[MAXN]; //check 1 if fake one

void check(int start, int depth)
{
	//next
}

int main()
{
	int i=0;
	
	//input
	for(i=0; i<MAXN; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	//check
	check();
	
	//print
	for(i=0; i<MAXN; i++)
	{
		if(check[i] != 1)
			printf("%d\n", arr[i]);
	}

	return 0;
}
