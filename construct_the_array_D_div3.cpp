#include<bits/stdc++.h>
 
//https://codeforces.com/contest/1353/problem/D
using namespace std;
 
void Solve(){
	int n;
	cin>>n;
	vector<int> res(n);
	int k = 1;
	set<pair<int, pair<int, int>>> s;
	s.insert({n, {0, n - 1}});
	while(!s.empty()){
		pair<int, pair<int, int>> p = *s.begin();
		s.erase(s.begin());
		int left = p.second.first;
		int right = p.second.second;
		if((right - left + 1) % 2 == 1){
			res[(right + left) / 2] = k++;
			int l = left;
			int r = (right + left) / 2 - 1;
			if(r >= l){
				s.insert({-(r - l + 1), {l, r}});
			}
			l = (right + left) / 2 + 1;
			r = right;
			if(r >= l){
				s.insert({-(r - l + 1), {l, r}});
			}
		}
		else{
			res[(left + right - 1) / 2] = k++;
			int l = left;
			int r = (left + right - 1) / 2 - 1;
			if(r >= l){
				s.insert({-(r - l + 1), {l, r}});
			}
			l = (left + right - 1) / 2 + 1;
			r = right;
			if(r >= l){
				s.insert({-(r - l + 1), {l, r}});
			}
		}
	}
	for(auto x: res) cout<<x<<" ";
	cout<<'\n';
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin>>T;
	while(T--){
		Solve();
	}
}