//--------my brain isn't at home right now------------------
#include<bits/stdc++.h>  

//https://codeforces.com/contest/777/problem/D
 
using namespace std; 
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;
 
void Solve(){
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    for(int i = n - 2; i >= 0; i--){
        int k = min(v[i].size(), v[i + 1].size());
        string s = "#";
        for(int j = 1; j < k; j++){
            if(v[i][j] == v[i + 1][j]){
                s += v[i][j];
            }
            else if(v[i][j] < v[i + 1][j]){
                s = v[i];
                break;
            }
            else{
                break;
            }
        }
        v[i] = s;
    }
    for(int i = 0; i < n; i++){
        cout<<v[i]<<nl;
    }
 
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solve();
}