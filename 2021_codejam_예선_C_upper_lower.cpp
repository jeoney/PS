#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string.h>

using namespace std;

#define MAXN 100010
#define MAXP_NUM 12

int T, N, A[MAXN];
long long ans;
int dbg = 0;

//peace number 정의 
int peace_num[MAXP_NUM] = {
	202021,
	20202021,
	202002021,
	202012021,
	202022021,
	202032021,
	202042021,
	202052021,
	202062021,
	202072021,
	202082021,
	202092021
};

void reset_arr()
{
	memset(A, 0, MAXN*sizeof(int));
}

void input()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++)
	{
		scanf("%d", &A[i]);
	}
	
	//이진탐색을 위하여 오름차순 정렬
	sort(A, A+N);
	
	if(dbg==0) return;
	for(int i=0; i<N; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}

void solve()
{
	// ans 초기화 
	// peace number loop 돌면서
	//   A[] 끝까지 loop
	// 	   A[i] 배열 loop 돌면서 숫자 하나 pick해서 안녕숫자-pick 해서 찾을 숫자 정함 
	// 	   찾을 숫자가 구간내(pick idx+1 ~ 끝) 존재 하는지 upper_bound lower_bound로 찾아서 count 
	// 	   ans += 개수 
	ans = 0;
	
	//peace num loop
	for(int i=0; i<MAXP_NUM; i++)
	{
		//입력받은 수 loop 
		for(int j=0; j<N; j++)
		{
			int target = peace_num[i] - A[j];
/*
			//target이 배열 max보다 크면 skip
			if(target > A[N-1])
			{
				//skip
				if(dbg) printf("skip!\n");
				break;
			}
*/	
			int cnt = upper_bound(A+j, A+N, target) - lower_bound(A+j, A+N, target);
			ans += cnt;
			if(dbg) printf("i:%d, j:%d, A[j]:%d, target:%d, cnt:%d\n", i, j, A[j], target, cnt);
		}
	}

	printf("%lld\n", ans);

	return;
}

int main()
{
	int i;
	scanf("%d", &T);
	for(i=0; i<T; i++)
	{
		reset_arr();
		input();
		solve();
	}
	
	return 0;
}
