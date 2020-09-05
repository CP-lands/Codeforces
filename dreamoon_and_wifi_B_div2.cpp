#include<bits/stdc++.h>

//https://codeforces.com/problemset/problem/476/B
using namespace std;

typedef long long ll; 

const int MOD = 1e9 + 7;

int sum = 0;
void backtrack(vector<vector<int>> &path, vector<int> &res, int st)
{
	for(auto i = 0; i < path[st].size(); i++)
	{
		int a = st;
		int b = i;
		sum += path[st][i];
		if(st == path.size() - 1) res.push_back(sum);
		else backtrack(path, res, st + 1);
		sum -= path[a][b];
	}
}

int main()
{
	string send, receive;
	cin>>send>>receive;
	int pos = 0;
	for(auto x : send)
	{
		if(x == '+') pos++;
		else pos--;
	}
	int count = 0;
	vector<vector<int>> path;
	vector<int> res;
	for(auto x : receive)
	{
		if(x == '-') path.push_back({-1});
		if(x == '+') path.push_back({1});
		if(x == '?') 
		{
			path.push_back({-1, 1});
			count++;
		}
	}
	int prob = pow(2, count);
	double k = 0;
	backtrack(path, res, 0);
	for(auto x : res)
		if(x == pos) k++;
	k = (double)k/prob;
	cout<<fixed<<setprecision(9)<<k<<endl;

	return 0;
}
/*
int main()
{
	int n, m, k, r, l;
	cin>>n>>m>>k;
	map<int, int> mp;
	for(int i = 0; i < k; i++)
	{
		cin>>r>>l;
		mp.insert({r, l});
	}
	for(auto x : mp)
		cout<<x.first<<" "<<x.second<<endl;
	return 0;

}
