
#include<bits/stdc++.h>

//https://codeforces.com/contest/289/problem/B 
using namespace std;
 
void Solve(){
    int n, m, k;
    cin>>n>>m>>k;
    int N = m * n;
    vector<int> v(N);
    for(int i = 0; i < N; i++)
        cin>>v[i];
    if(N == 1){
        cout<<0<<'\n';
        return;
    }
    int d = abs(v[1] - v[0]);
    for(int i = 2; i < N; i++){
        d = __gcd(d, v[i] - v[i - 1]);
    }
    if(d % k != 0){
        cout<<-1<<'\n';
        return;
    }
    sort(v.begin(), v.end());
    int res = INT_MAX;
    int x = v[0];
    while(x <= 10000){
        int tmp = 0;
        for(int i = 0; i < N; i++){
            if(v[i] < x) tmp += (x - v[i]) / k;
            if(v[i] > x) tmp += (v[i] - x) / k;
        }
        if(res > tmp) res = tmp;
        x += k;
    }
    cout<<res<<'\n';
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