#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/problem/567/C
using namespace std;

int v[200001];
map<long long, vector<int>> mm;

void Solve(){
    int n, k;
    cin>>n>>k;
    for(int i = 1; i <= n; i++){
        cin>>v[i];
        mm[v[i]].push_back(i);
    }
    long long res = 0;
    for(int i = 1; i <= n; i++){
        long long k1 = (long long)v[i] * k;
        long long k2 = (long long)v[i] / k;
        if(!mm.count(k1) || !mm.count(k2) || v[i] % k != 0) continue;
        int p1 = upper_bound(mm[k1].begin(), mm[k1].end(), i) - mm[k1].begin();
        p1 = mm[k1].size() - p1;
        int p2 = lower_bound(mm[k2].begin(), mm[k2].end(), i) - mm[k2].begin();
        res += (long long)p1 * p2;
        //cout<<v[i]<<" "<<p1<<" "<<p2<<'\n';
        //cout<<k1<<" "<<k2<<'\n';
    }
    cout<<res<<'\n';

	return;
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