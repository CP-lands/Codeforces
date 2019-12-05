//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/1263/problem/C
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;
 
void Anivia_kid(){
	int n;
	cin>>n;
	vector<int> res;
	res.pb(0);
	for(int i = 1; i <= sqrt(n); i++){
		if(i * i == n){
			res.pb(i);
			continue;
		}
		else{
			res.pb(i);
			if(n / i != i) res.pb(n / i);
		}
	}
	sort(res.begin(), res.end());
	cout<<res.size()<<"\n";
	for(auto x: res)
		cout<<x<<" ";
	cout<<"\n";
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
		Anivia_kid();
	}
}