//https://codeforces.com/contest/1315/problem/B
#include<bits/stdc++.h>
 
using namespace std;
 
void Solve(){
	int a, b, p;
	string s;
	cin>>a>>b>>p>>s;
	int n = s.size();
	if(p < a && p < b){
		cout<<n<<'\n';
		return;
	}
	int res = 1;
	int i = n - 2;
	while(i >= 0 && p > 0){
		if(s[i] == 'A'){
			if(p >= a){
				p -= a;
				while(i >= 0 && s[i] == 'A'){
					i--;
				}
			}
			else{
				res = max(res, i + 2);
				cout<<res<<'\n';
				return;
			}
		}
		else{
			if(p >= b){
				p -= b;
				while(i >= 0 && s[i] == 'B'){
					i--;
				}
			}
			else{
				res = max(res, i + 2);
				cout<<res<<'\n';
				return;
			}
		}
	}
	cout<<i + 2<<'\n';
 
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