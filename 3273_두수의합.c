//두 수의 합
//https://www.acmicpc.net/problem/3273
#include <stdio.h>
#include <stdlib.h>

#define MAXN 100010
int N; //num of input
int a[MAXN]; //array for input
int X; //target

int dbg = 0;

int compare (const void * a, const void * b)
{
  if ( *(int *)a <  *(int *)b ) return -1;
  else return 1;
}

int search_num()
{
	int result=0, s=0, e=N-1, temp=0;
	
	while(s<e)
	{
		temp = a[s] + a[e];
		
		if(temp == X)
		{
			result++;
			s++;
			e--;
		}
		else if(temp > X)
		{
			e--;
		}
		else
		{
			s++;
		}
	}
	
	return result;
}

int main()
{
	int i=0;
	//input
	scanf("%d", &N);
	for(i=0; i<N; i++)
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &X);
	
	//sort
	qsort(a, N, sizeof(int), compare);
	
	if(dbg)
	{
		for(i=0; i<N; i++)
			printf("%d ", a[i]);
		printf("\n");
	}

	//search & print
	printf("%d\n", search_num() );

	return 0;
}
