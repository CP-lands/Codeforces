//--------my brain isn't at home right now------------------
#include<bits/stdc++.h>  

//https://codeforces.com/contest/479/problem/D
 
using namespace std; 
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;
 
void Solve(){
    int n, l, x, y;
    cin>>n>>l>>x>>y;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    bool xx = false, yy = false;
    for(int i = 0; i < n - 1; i++){
        if(binary_search(v.begin(), v.end(), v[i] + x)) xx = true;
        if(binary_search(v.begin(), v.end(), v[i] + y)) yy = true;
    }
    if(xx && yy) cout<<0<<nl;
    else if(xx || yy){
        if(xx){
            cout<<1<<nl;
            cout<<y<<nl;
        }
        else{
            cout<<1<<nl;
            cout<<x<<nl;
        }
    }
    else{
        if(x > y) swap(x, y);
        for(int i = 0; i < n; i++){
            int k = v[i] + x;
            if(k < l){
                if(binary_search(v.begin(), v.end(), k - y) || binary_search(v.begin(), v.end(), k + y)){
                    cout<<1<<nl;
                    cout<<k<<nl;
                    return;
                }
            }
            k = v[i] - x;
            if(k > 0){
                if(binary_search(v.begin(), v.end(), k + y) || binary_search(v.begin(), v.end(), k - y)){
                    cout<<1<<nl;
                    cout<<k<<nl;
                    return;
                }
            }
        }
        cout<<2<<nl;
        cout<<x<<" "<<y<<nl;
    }
    
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    //cin>>T;
    while(T--){
        Solve();
    }
}