#include<bits/stdc++.h>
 
//https://codeforces.com/contest/1326/problem/C
using namespace std;
 
void Solve(){
    int n, k;
    cin>>n>>k;
    vector<int> v(n);
    vector<long long> a;
    for(int i = 0; i < n; i++){
        cin>>v[i];
        if(v[i] > n - k) a.push_back(i + 1);
    }
    long long res = 0;
    int tmp = n;
    for(int i = 0; i < k; i++){
        res += tmp;
        tmp--;
    }
    long long ans = 1;
    for(int i = 1; i < a.size(); i++){
        ans *= (a[i] - a[i - 1]);
        ans = ans % 998244353;
    }
    cout<<res<<" "<<ans<<'\n';
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q = 1;
    //cin>>q;
    while(q--){
    	Solve();
    }
}