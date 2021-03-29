//https://www.acmicpc.net/problem/2309
//일곱난쟁이 백준

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 9, sum=0;
vector<int>v;

int dbg=0;

void print_picked(vector<int>& picked)
{
	if(dbg==0) return;
	
	cout << "picked:\n -------------\n";
	
	for(int i=0; i<picked.size(); i++)
	{
		cout << picked[i] << "\n";
	}
}

int check_picked(vector<int>& picked)
{
	int temp_sum=0;
	for(int i=0; i<picked.size(); i++)
	{
		temp_sum += picked[i];
	}
	
	if(dbg==1) cout << "picked cur sum:" << temp_sum << "\n";
	
	return temp_sum;
}

int pick(int s, int depth, vector<int>& picked)
{
	//
	if(depth == 2) //다 찾음 계산 필요
	{
		if( check_picked(picked) == sum)
		{
			if(dbg==1) cout << "found sum:" << sum << "\n";
			return 1;
		}
		return 0;
	}
	
	for(int i = s; i < v.size(); i++ ) //v.size = 9일걸  
	{
		//if(dbg==1) cout << "next:" << i << "\n";
		picked.push_back(v[i]);
		print_picked(picked);
		if( pick(i+1, depth+1, picked) ) return 1;
		picked.pop_back();
	}
	
	return 0;
}

int main()
{
	int n;
	vector<int>picked;

	for(int i=0; i<N; i++)
	{
		cin >> n;
		v.push_back(n);
		sum += n;
	}
	
	sum -= 100; //sum에 찾아야 하는 키만 남김 
	
	pick(0, 0, picked); //2명 뽑아야 함   
	
	sort(v.begin(), v.end());

	//출력
	for(int i=0; i<N; i++)
	{
		int check=0;
		for(int j=0; j<picked.size(); j++)
		{
			if(v[i] == picked[j]) check = 1;
		}
		
		if(check) continue;
		cout << v[i] << "\n";
	}
	
	return 0;
}
