#include<bits/stdc++.h>  

//https://codeforces.com/contest/778/problem/A
using namespace std; 
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;
 
void Solve(){
    string t, s;
    cin>>t>>s;
    int n = t.size();
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];
    int low = 0, high = n;
    int res = 0;
    int exit = 0;
    while(low < high){
        int mid = low + (high - low) / 2;
        if(exit == 2) mid = high;
        string a = "";
        vector<int> tmp;
        for(int i = 0; i < mid; i++)
            tmp.pb(v[i]);
        sort(tmp.begin(), tmp.end());
        int index = 0;
        for(int i = 0; i < n; i++){
            if(index < tmp.size() && i + 1 == tmp[index]){
                index++;
                continue;
            }
            a += t[i];
        }
        bool good = true;
        if(a.size() < s.size()) good = false;
        if(good){
            int i = 0;
            int j = 0;
            while(i < s.size() && j < a.size()){
                if(s[i] == a[j]){
                    i++;
                    j++;
                }
                else{
                    j++;
                }
            }
            if(i < s.size()) good = false;
        }
        if(good){
            res = max(res, mid);
            low = mid;
        }
        else high = mid;
        if(high - low == 1) exit++;
        if(exit == 3) break;
    }
    cout<<res<<nl;
 
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    //cin>>T;
    while(T--){
        Solve();
    }
}