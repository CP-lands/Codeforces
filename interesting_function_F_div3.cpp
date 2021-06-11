#include<bits/stdc++.h>
 
using namespace std;
//https://codeforces.com/contest/1538/problem/F
 
#define fi first
#define se second
#define pb push_back
#define nl '\n'
#define bug cout<<"bug here!"<<nl
typedef long long ll;
 
void Solve(){
	int l, r;
	cin>>l>>r;
	ll res = 0;
	ll low = 0, high = 0;
	vector<ll> v(10);
	v[1] = 11;
	v[0] = 1;
	for(int i = 2; i < 10; i++){
		v[i] = 9 * v[i - 1] + 1 + v[i - 1];
	}
 
	double x = 9;
	while(l > 0){
		int k = l / pow(10, x);
		low += k * v[x];
		l = l % (ll)pow(10, x);
		x--;
	}
	x = 9;
	while(r > 0){
		int k = r / pow(10, x);
		high += k * v[x];
		r = r % (ll)pow(10, x);
		x--;
	}
	//cout<<low<<" "<<high<<nl;
	cout<<high - low<<nl;
 
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        Solve();
    }
}