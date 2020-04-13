#include<bits/stdc++.h>
 
//https://codeforces.com/contest/1334/problem/C
using namespace std;
 
long long maxx(long long a, long long b){
    if(a >= b) return a;
    else return b;
}
void Solve(){
    int n;
    cin>>n;
    vector<long long> a(n), b(n);
    for(int i = 0; i < n; i++)
        cin>>a[i]>>b[i];
    long long sum = 0;
    for(int i = 1; i < n; i++){
        sum += maxx(0, a[i] - b[i - 1]);
    }
    sum += maxx(0, a[0] - b[n - 1]);
    long long res = 1e18;
    for(int i = 0; i < n; i++){
        if(i > 0){
            long long tmp = a[i] - maxx(0, a[i] - b[i - 1]);
            tmp += sum;
            if(tmp < res) res = tmp;
        }
        if(i == 0){
            long long tmp = a[i] - maxx(0, a[i] - b[n - 1]);
            tmp += sum;
            if(tmp < res) res = tmp;
        }
    }
    cout<<res<<'\n';
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        Solve();
    }
}