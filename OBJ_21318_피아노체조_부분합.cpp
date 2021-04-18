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

vector<int> v;
int psum[MAXN];

int N, Q, dbg=1;

void print_psum()
{
	if(dbg==0) return;
	
	printf("psum:\n");
	for(int i=0; i<N; i++)
	{
		printf("%d ", psum[i]);
	}
	printf("\n");

	printf("v(%d):\n", v.size());
	for(int i=0; i<v.size(); i++)
	{
		printf("%d ", v[i]);
	}
	printf("\n");
}

int input_solve()
{
	//N, 악보 난이도 숫자 입력 
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		int d;
		scanf("%d", &d);
		v.push_back(d);
		if(dbg) printf("v.size():%d, v[i]:%d\n", v.size(), v[i]);
	}

	//psum update
	for(int i=1; i<N; i++) {
		if(v[i-1] > v[i]) {
			psum[i] = psum[i-1]+1;
		}
		else {
			psum[i] = psum[i-1];
		}
	}
	
	print_psum();

	scanf("%d", &Q);
	for(int i=0; i<Q; i++)
	{
		int S, E;
		scanf("%d %d", &S, &E);
		if(dbg) printf("ans: ");
		if(S==E) printf("0\n");
		else printf("%d\n", psum[E-1]-psum[S-1]);
	}
}

int main()
{
	input_solve();
	return 0;
}
