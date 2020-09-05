//___1 WA == 5 Push up___
//------Anivia_kid----------
#include<iostream>
#include<math.h>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
#include<set>
#include<string.h>
#include<map>
#include<iomanip>
#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/problem/1249/B2
using namespace std;
 
typedef long long ll; 
const int MOD = 1e9 + 7;
 
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int q;
	cin>>q;
	for(int j = 0; j < q; j++)
	{
		int n;
		set<int> s;
		cin>>n;
		vector<vector<int>> v(n + 1, vector<int> (2));
		for(int i = 1; i < n + 1; i++)
		{
			v[i][0] = i;
			s.insert(i);
			cin>>v[i][1];
		}
 
		while(!s.empty())
		{
			int count = 1;
			int tmp1 = v[*s.begin()][1];
			int k = *s.begin();
			int tmp = tmp1;
			vector<int> res;
			while(tmp != v[k][0])
			{
				count++;
				tmp = v[tmp][1];
				res.push_back(tmp);
				s.erase(tmp);
			}
			res.push_back(tmp1);
			s.erase(tmp1);
			for(auto x : res)
				v[x][0] = count;
		}
		for(int i = 1; i < n + 1; i++)
			cout<<v[i][0]<<" ";
		cout<<endl;
	}
 
 
	return 0;
}
