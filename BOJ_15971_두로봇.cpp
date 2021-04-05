#include <stdio.h>
#include <iostream>     // std::cout
#include <algorithm>    // std::max
#include <vector>
#include <utility>

using namespace std;

#define MAXN 100010

int N, X, Y; // 방 개수, 로봇 start, 로봇 end 
int s, e, l; //start end long

vector<pair<int, int> > v[MAXN];
int visit[MAXN];

void DFS(int node, int sum, int max)
{
	//printf("node:%d sum:%d, max:%d\n", node, sum, max);
	
	if(node == Y)
	{
		cout << sum - max << endl;
		return;
	}
	
	visit[node] = 1;
	
	//for( auto i : v[node] )
	for( pair<int, int> i : v[node] ) //vector에서 pair로 뽑아 옴. 앞에건 .first, 뒤에건 .second로 읽으면 됨 
	{
		if(visit[i.first] == 0)
		{
			DFS(i.first, sum+i.second, std::max(max, i.second));
		}
	}
}

int main()
{
	cin >> N >> X >> Y;
	
	for(int i; i<N-1; i++)
	{
		cin >> s >> e >> l;
		v[s].push_back( {e, l} ); //start vector에  end랑 end까지 거리 넣음 
		v[e].push_back( {s, l} ); //양방향 가능하므로 end vector에 start랑 end까지 거리 넣음
	}
	
	DFS(X, 0, 0);
	
	return 0;
}


