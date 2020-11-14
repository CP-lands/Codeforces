#include<bits/stdc++.h>
 
//http://codeforces.com/gym/102569/problem/I
using namespace std;
 
set<int> s[200005];
void Solve(){
	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		int a, b;
		cin>>a>>b;
		set<int>::iterator it = s[b].upper_bound(a);
		if(it != s[b].end()){
			cout<<"NO\n";
			return;
		}
		s[b].insert(a);
	}
	cout<<"YES\n";
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	while(t--){
		Solve();
	}
	return 0;
}