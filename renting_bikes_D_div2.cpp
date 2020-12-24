#include<bits/stdc++.h>  
 
//https://codeforces.com/contest/363/problem/D
using namespace std; 
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;
 
void Solve(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++)
        cin>>a[i];
    for(int i = 0; i < m; i++)
        cin>>b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int res = 0;
    int minn = 0;
    int low = 0, high = min(n, m);
    int exit = 0;
    while(low < high){
        int mid = low + (high - low) / 2;
        if(exit == 2) mid = high;
        bool isPossible = true;
        int left = n - mid;
        int tmp = k;
        int sum = 0;
        for(int i = 0; i < mid; i++){
            sum += b[i];
            if(a[left] >= b[i]){
                left++;
                continue;
            }
            else if(a[left] + tmp >= b[i]){
                tmp -= b[i] - a[left];
                left++;
                continue;
            }
            else{
                isPossible = false;
                break;
            }
        }
        if(isPossible){
            low = mid;
            if(res < mid){
                res = mid;
                if(k >= sum) minn = 0;
                else minn = sum - k;
            }
        }
        else{
            high = mid;
        }
        if(high - low == 1) exit++;
        if(exit == 3) break;
    }
    cout<<res<<" "<<minn<<nl;
 
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solve();
}