#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 82

int N;
char ans[MAXN];
int dbg=0;

void input()
{
	scanf("%d", &N);
	return;
}

void output() 
{
	int i;
	for(i=0; i <N; i++)
		printf("%c", ans[i]);
	printf("\n");
	return;
}

void dbg_output()
{
	int i;
	if(dbg==0) return;
	printf("not a good number:\n");
	for(i=0; i <N; i++)
		printf(" %c", ans[i]);
	printf("\n");
	return;
}

int check(int len)
{
	int i, j=0;
	char temp[MAXN] = {0,};
	if(len<4) return 0; //2자리는 따로 걸름 4자리 이상만 체크 시작
	
	//2부터 len까지 자리수 하나씩 눌려 가면서 
	for(i=2; i<=len/2; i++) 
	{
		//뒤로 한 자리씩 가면서 check 
		for(j=0; j+2*i<=len; j++)
		{
			if(dbg) 
			{
				strncpy(temp, &ans[j], i);
				printf("compare %s ", temp);
				strncpy(temp, &ans[i+j], i);
				printf("vs %s \n", temp);
			}
			if( strncmp(&ans[j], &ans[i+j], i) == 0)
				return 1;
		}
	}
	
	return 0;
}

int DFS(int start, int depth)
{
	int i;
	
	if(dbg) printf("DFS? start:%d, depth:%d\n", start, depth);

	//가지치기 조건(좋은 수열 아니면 return) 2자리는 밑에서 체크 여기선 4자리 이상일 경우 반띵하여 체크 
	if( check(depth) )
	{
		dbg_output();
		return 0;
	}

	//종료조건
	if(depth >= N) 
	{
		output();
		return 1;
	}

	for(i=1; i<=3; i++)
	{
		if(start==i) continue; //같은 수 두개 들어오면 좋은 수열 아님
		
		if(dbg) printf("i:%d\n", i);
		ans[depth] = '0'+i;
		if(dbg) printf("%s\n", ans);
		if( DFS( i, depth+1 ) ) return 1;
		ans[depth] = 0;
	}

	return 0;	
}

void solve()
{
	int i;
	DFS(0, 0);
}

void test()
{
	int n, i;
	scanf("%d", &n);
	for(i=0; i<n; i++)
		scanf(" %c", &ans[i]);
	
	if( check(n) ) printf("bad\n");
	else printf("good\n");	
	return;
}

int main()
{
#if 0
	test();
	return 0;
#endif

	input();
	solve();
	return 0;
}
