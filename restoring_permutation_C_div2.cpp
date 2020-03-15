//https://codeforces.com/contest/1315/problem/C
#include<bits/stdc++.h>
 
using namespace std;
 
void Solve(){
 
	set<int> s;
	set<int> ans;
	int n;
	cin>>n;
	vector<int> v(n + 1);
	for(int i = 1; i <= n; i++)
		cin>>v[i];
	vector<int> res(2 * n + 1);
	for(int i = 1; i <= n; i++){
		res[2 * i - 1] = v[i];
		res[2 * i] = v[i];
		s.insert(v[i]);
	}
	for(int i = 2; i <= 2 * n; i = i + 2){
		int k = res[i] + 1;
		while(true){
			if(s.find(k) == s.end()){
				res[i] = k;
				s.insert(k);
				break;
			}
			k++;
		}
	}
	for(int i = 1; i <= 2 * n; i++)
		ans.insert(i);
	for(int i = 1; i <= 2 * n; i++){
		if(ans.find(res[i]) == ans.end()){
			cout<<-1<<'\n';
			return;
		}
	}
	for(int i = 1; i <= 2 * n; i++)
		cout<<res[i]<<" ";
	cout<<'\n';
	ans.clear();
	s.clear();
 
	return;
}
 
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q;
	cin>>q;
	while(q--){
		Solve();
	}
}