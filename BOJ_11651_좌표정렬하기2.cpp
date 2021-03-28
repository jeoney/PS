#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//C에서 structure compare함수 만드는 것과 비슷. pair이므로 first, second로 빼서 사용
//2개 이상이면 structure로 사용 하는게 좋음 https://hydroponicglass.tistory.com/33 참고 
bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}

int main()
{
	int x, y, N; 
	vector<pair<int, int>>v;
	
	cin >> N;
	for(int i=0; i<N; i++)
	{
		cin >> x >> y;
		v.push_back( pair<int, int>(x, y) ); //vector에 push back시 pair인 경우 type지정해서 묶어야 함 
	}
	
	sort( v.begin(), v.end(), compare );

#if 0
	//vector의 range loop
	for(auto i : v)
	{
		cout << i.first << " " << i.second << "\n"; //출력시 endln은 사용하지 않아야 함 (timeout) 
	}
#else
	//iterator 사용 
	vector<pair<int, int> >::iterator iter;
	for(iter=v.begin(); iter!=v.end(); iter++)
	{
		cout << iter->first << " " << iter->second << "\n";
	}
#endif

	return 0;
}
