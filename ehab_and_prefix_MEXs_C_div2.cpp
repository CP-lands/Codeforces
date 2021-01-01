#include<bits/stdc++.h>
 
//https://codeforces.com/contest/1364/problem/C
using namespace std;
 
void Solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin>>v[i];
	vector<bool> vst(1000001);
	set<int> s;
	for(auto x: v) s.insert(x);
	vector<int> res(n);
	int low = 0;
	int pre = 0;
	for(int i = 0; i < n; i++){
		if(v[i] > i + 1){
			cout<<-1<<'\n';
			return;
		}
		if(i > 0 && v[i] != v[i - 1]){
			res[i] = v[i - 1];
			continue;
		}
		while(s.find(low) != s.end()){
			low++;
		}
		res[i] = low;
		s.insert(low);
	}
 
	for(auto x: res) cout<<x<<" ";
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin>>T;
	while(T--){
		Solve();
	}
}