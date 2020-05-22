#include<bits/stdc++.h>
 
//https://codeforces.com/contest/804/problem/B
using namespace std;
 
const int MOD = 1e9 + 7;
 
void Solve(){
	string s;
	cin>>s;
	long long res = 0;
	long long b = 0;
	int i = s.size() - 1;
	while(i >= 0){
		if(s[i] == 'b') b++;
		else{
			res += b;
			b *= 2;
		}
		res = res % MOD;
		b = b % MOD;
		i--;
	}
	cout<<res<<'\n';
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin>>T;
	while(T--){
		Solve();
	}
}