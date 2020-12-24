#include<bits/stdc++.h>  
 
//https://codeforces.com/contest/1461/problem/C
using namespace std; 
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;
 
void Solve(){
	int n, m;
	cin>>n>>m;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin>>v[i];
	int last = n;
	int i = n - 1;
	while(i >= 0 && v[i] == i + 1){
		last = i;
		i--;
	}
	vector<double> res;
	while(m--){
		int index;
		double pro;
		cin>>index>>pro;
		if(index >= last){
			res.pb(pro);
		}
	}
	if(last == 0){
		cout<<1<<nl;
		return;
	}
	if(res.size() == 0){
		cout<<0<<nl;
		return;
	}
	double ans = res[0];
	for(int i = 1; i < res.size(); i++){
		ans += res[i] - ans * res[i];
	}
	cout<<fixed<<setprecision(7)<<ans<<nl;
	
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        Solve();
    }
}