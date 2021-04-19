//https://www.acmicpc.net/problem/21318
//피아노 체조
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string.h>

using namespace std;

#define MAXN 100010

int v[MAXN];
int psum[MAXN];

int N, Q, dbg=0;

void print_psum()
{
	if(dbg==0) return;
	
	printf("psum:\n");
	for(int i=1; i<=N; i++)
	{
		printf("%d ", psum[i]);
	}
	printf("\n");

	printf("v(%d):\n", N);
	for(int i=1; i<=N; i++)
	{
		printf("%d ", v[i]);
	}
	printf("\n");
}

int input_solve()
{
	//N, 악보 난이도 숫자 입력 
	scanf("%d", &N);

	for(int i=1; i<=N; i++) {
		int d;
		scanf("%d", &d);
		v[i] = d;

		//psum update
		if(i>1)
		{
			if(v[i-1] > v[i]) {
				psum[i] = psum[i-1]+1;
			}
			else {
				psum[i] = psum[i-1];
			}
		}
	}

	print_psum();

	scanf("%d", &Q);
	for(int i=0; i<Q; i++)
	{
		int S, E;
		scanf("%d %d", &S, &E);
		if(dbg) printf("ans: ");
		printf("%d\n", psum[E]-psum[S]);
	}
	
	return 0;
}

int main()
{
	input_solve();
	return 0;
}
