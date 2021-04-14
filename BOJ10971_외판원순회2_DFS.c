#include <stdio.h> 

#define MAXN 11

int N, ans=987654321;
int dbg=1;
int map[MAXN][MAXN];
int visit[MAXN];

void input()
{
	int i, j;
	scanf("%d", &N);
	for(j=0; j<N; j++)
		for(i=0; i<N; i++)
			scanf("%d", &map[j][i]);
}

void print_visit()
{
	int i;
	if(dbg==0) return;
	printf("visit:\n");
	for(i=0; i<N; i++)
		printf("%d ", visit[i]);
	printf("\n------\n");
}

void output() { printf("%d\n", ans); }
int min(int a, int b) { return a>b?b:a; }

void DFS(int s, int depth, int price, int final_dst)
{
	int e;
	
	//이미 price가 sum보다 크면 가지치기 (중요) 
	if(price >= ans) return; 

	//종료조건 모든도시 탐색 완료 
	if(depth>=N)
	{
		//이 경로도 있는지 check 필요 (fail) 
		if( map[s][final_dst] == 0 ) return;
		
		if(dbg) printf("DFS return, ans:%d, calc price:%d\n", ans, price + map[s][final_dst]);
		ans = min( ans, price + map[s][final_dst] );
		return;
	}
	
	//DFS재귀 모든 도시 순회 
	for(e=0; e<N; e++)
	{
		//길이 없는 경우 skip
		if( s != e && map[s][e] == 0 ) {
			if(dbg) printf("no way to proceed s:%d, e:%d\n", s, e);
			continue;
		}
		
		if(visit[e]) continue; //기 방문 도시 skip (중요)
		//방문 표시 
		visit[e] = depth+1;
		print_visit();
		
		//depth가 아직 0이면 출발지. 나중에 돌아와야 함
		if(depth==0) final_dst = e;

		//s는 출발지 e는 도착지 
		DFS(e, depth+1, price+map[s][e], final_dst);
		
		//방문 해제 
		visit[e] = 0;
	}
	
	return;
}

void solve()
{
	int i;
	DFS(0, 0, 0, 0); //start, depth, price, final_dest
}

int main()
{
	input();
	solve();
	output();
	return 0;
}

/*
4
0 10 15 20
5 0 9 10
6 13 0 12
8 8 9 0

0->1 길없음 
4
0 0 15 20
5 0 9 10
6 13 0 12
8 8 9 0

4
0 10 15 20
5 0 9 10
6 13 0 12
8 8 0 0
*/
