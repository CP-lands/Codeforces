#include<bits/stdc++.h>
 
//https://codeforces.com/contest/1443/problem/C
using namespace std;
 
bool isPossible(int target, int n, vector<int> &a, vector<int> &b){
    long long sum = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > target){
            sum += b[i];
        }
    }
    if(sum > target) return false;
    else return true;
}
void Solve(){
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)
        cin>>a[i];
    for(int i = 0; i < n; i++)
        cin>>b[i];
    int res = INT_MAX;
    int low = 0, high = INT_MAX;
    int exit = 0;
    while(low < high){
        int mid = low + (high - low) / 2;
        if(exit == 2) mid = high;
        if(isPossible(mid, n, a, b)){
            res = min(res, mid);
            high = mid;
        }
        else low = mid;
        if(high - low == 1) exit++;
        if(exit == 3) break;
    }
    cout<<res<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        Solve();
    }
}
