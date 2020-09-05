#include<bits/stdc++.h>

//https://codeforces.com/problemset/problem/1234/B2
using namespace std;

int main() {
	int n,k,tmp;
	cin>>n>>k;
	set<int> s;
	queue<int> res;
	for(int i = 0; i < n; i++) {
		int m = s.size();
		cin>>tmp;
		s.insert(tmp);
		if(s.size() <= k && m != s.size())
			res.push(tmp);
		if(s.size() > k) {
			s.erase(res.front());
			res.pop();
			res.push(tmp);
		}
	}
	tmp = s.size();
	cout<<min(k,tmp)<<endl;
	vector<int> ans;
	while(!res.empty()) {
		ans.push_back(res.front());
		res.pop();
	}
	for(int i = ans.size() - 1; i >= 0; i--)
		cout<<ans[i]<<" ";
	return 0;
}
