#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,k,tmp;
	cin>>n>>k;
	set<int> s;
	queue<int> res;
	for(int i = 0; i < n; i++)
	{
		int m = s.size();
		cin>>tmp;
		s.insert(tmp);
		if(s.size() <= k && m != s.size())
			res.push(tmp);
		if(s.size() > k)
		{
			s.erase(res.front());
			res.pop();
			res.push(tmp);
		}
	}
	tmp = s.size();
	cout<<min(k,tmp)<<endl;
	vector<int> ans;
	while(!res.empty())
	{
		ans.push_back(res.front());
		res.pop();
	}
	for(int i = ans.size() - 1; i >= 0; i--)
		cout<<ans[i]<<" ";
	return 0;
}
/*
int main()
{
	int n, k;
	set<int> s;
	cin>>n>>k;
	vector<int> ans(n);
	for(int i = 0; i < n; i++)
	{
		cin>>ans[i]; 
		s.insert(ans[i]);
	}
	int count = 0;
	int tmp;
	while(!s.empty())
	{
		count++;
		tmp = *s.begin();
		s.erase(tmp);
	}
	tmp = min(count, k);
	cout<<tmp<<endl;
	queue<int> res;
	count = 0;
	for(int i = 0; i < n; i++)
	{
		int m = s.size();
		s.insert(ans[i]);
		if(s.size() <= tmp && m != s.size())
			res.push(ans[i]);
		if(s.size() > tmp)
		{
			s.erase(res.front());
			res.pop();
			res.push(ans[i]);
		}
	}
	vector<int> t;
	while(!res.empty())
	{
		t.push_back(res.front());
		res.pop();
	}
	for(int i = t.size() - 1; i >=0; i--)
		cout<<t[i]<<" ";
	return 0;
}*/