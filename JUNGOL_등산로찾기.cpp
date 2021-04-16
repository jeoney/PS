//http://jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=391&sca=4070
//등산로 찾기

//가장 높은 곳에서 출발
//1. map은 1부터 N까지 기록
//2. visit은 0부터 N+1까지 기록 visit은 INF로 초기화
//3. 중복 방문 허용 (w가 낮으면 update 가능) 
//4. 이동시 동일 높이면 w가 동일, 낮은 높이는 +로, 높은 높이면 + 제곱수
//5. BFS로 탐색 in visit
//6. que에 tuple(int x, int y, int w) 로 넣기 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
#include <utility>
#include <string.h>

using namespace std;

#define MAXN 110
//#define INF 0x3fffffff //987654321
#define INF 10000

int N, SX, SY, dbg=1;
int map[MAXN][MAXN], visit[MAXN][MAXN];
queue<tuple<int,int,int>> q; //x, y, w(이동시 드는 힘) 

void input()
{
	scanf("%d", &N);
	scanf("%d %d", &SY, &SX);
	//1
	for(int j=1; j<=N; j++) {
		for(int i=1; i<=N; i++) {
			scanf("%d", &map[j][i]);
		}
	}
	//2, 3
	for(int j=0; j<=N+1; j++) {
		for(int i=0; i<=N+1; i++) {
			visit[j][i] = INF;
		}
	}
}

int calcW(int s_h, int e_h, int cur_w )
{
	//old는 que의 front에 있음 
	//이동 예정인 곳이 낮으면 실제로 등산시에는 올라가는 것 이므로 제곱수 더함 
	if(s_h > e_h) return cur_w+(s_h-e_h)*(s_h-e_h);
	else return cur_w+e_h-s_h; //이동 예정인 곳이 높으면 제곱수 더함 
}

void print_visit()
{
	if(dbg==0) return;

	printf("print visit:\n");
	for(int j=0; j<=N+1; j++) {
		for(int i=0; i<=N+1; i++) {
			printf("%d ", visit[j][i]);
		}
		printf("\n");
	}
	printf("--------------\n");
}

void BFS()
{
	//상하좌우 
	int dx[4] = {0, 0, -1, 1};
	int dy[4] = {-1, 1, 0, 0};

	while( !q.empty() )
	{
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		q.pop();
		
		//조건 check후 4방항 push 
		for(int i=0; i<4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			//range check해서 skip 
			if(nx<0 || ny<0 || nx>N+1 || ny>N+1) continue;

			int nw = calcW(map[y][x], map[ny][nx], visit[y][x]);
			if(dbg) printf("push? (x:%d,y:%d) (nx:%d,ny:%d) nw:%d, old nw:%d\n", x, y, nx, ny, nw, visit[ny][nx]);
			if(nw < visit[ny][nx])
			{
				if(dbg) printf("OK to push\n");
				q.push(make_tuple(nx, ny, nw));
				visit[ny][nx] = nw;
				print_visit();
			}
		}
	}
}

int main() 
{
	input();

	q.push(make_tuple(SX, SY, 0));
	visit[SY][SX] = 0;
	BFS();

	printf("%d\n", visit[0][0]);
	return 0;
}
