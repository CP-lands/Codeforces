#include<bits/stdc++.h>
 
using namespace std;
//https://codeforces.com/contest/1512/problem/D
 
#define fi first
#define se second
#define pb push_back
#define nl '\n'
#define bug cout<<"bug here!"<<nl
typedef long long ll;
 
void Alice(){
    int n;
    cin>>n;
    vector<int> b(n + 2);
    ll sum = 0;
    for(int i = 0; i < n + 2; i++){
        cin>>b[i];
        sum += b[i];
    }
    sort(b.begin(), b.end());
    int idx = 0;
    //case1 right most value
    int k = b.back();
    ll s = sum - k;
    for(int i = 0; i < n + 1; i++){
        if(s - b[i] == k){
            idx = i;
            for(int j = 0; j < n + 1; j++){
                if(j != idx) cout<<b[j]<<" ";
            }
            cout<<nl;
            return;
        }
    }
    //case2 right most - 1
    s = sum - k - b[n];
    if(s == b[n]){
        for(int i = 0; i < n; i++){
            cout<<b[i]<<" ";
        }
        cout<<nl;
        return;
    }
    cout<<-1<<nl;
    return;
 
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        Alice();
    }
}