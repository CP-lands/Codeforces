//--------------my brain isn't at home right now------------------
#include<bits/stdc++.h>  
 
using namespace std; 
//https://codeforces.com/contest/1473/problem/C
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
#define bug cout<<"bug here\n"
typedef long long ll;
 
void Solve(){
    int n, k;
    cin>>n>>k;
    int inv = n - k;
    vector<int> res(k);
    int s = k - 1 - inv;
    int maxx = k;
    for(int i = s; i < k; i++)
        res[i] = maxx--;
    int minn = 1;
    for(int i = 0; i < s; i++){
        res[i] = minn++;
    }
    for(auto x: res) cout<<x<<" ";
    cout<<nl;
 
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        Solve();
    }
}