#include<bits/stdc++.h>

//https://codeforces.com/contest/1118/problem/D2
using namespace std;

void Solve(){
    int n, m;
    cin>>n>>m;
    vector<int> v(n);
    long long least = 0;
    for(int i = 0; i < n; i++){
        cin>>v[i];
        least += v[i];
    }
    if(least < m){
        cout<<-1<<'\n';
        return;
    }
    sort(v.rbegin(), v.rend());
    int res = n;
    int low = 1, high = n;
    int count = 0;
    while(low < high){
        int mid = low + (high - low) / 2;
        if(count > 1) mid = high;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            int k = i / mid;
            sum += max(v[i] - k, 0);
        }
        if(sum >= m){
            if(res > mid) res = mid;
            high = mid;
        }
        else low = mid;
        if(high - low == 1) count++;
        if(count == 3) break;
    }
    cout<<res<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q = 1;
    //cin>>q;
    while(q--){
    	Solve();
    }
}