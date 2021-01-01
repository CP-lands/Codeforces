#include<bits/stdc++.h>  
 
//https://codeforces.com/contest/1203/problem/D2
using namespace std; 
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;
 
void Solve(){
    string s, t;
    cin>>s>>t;
    int n = s.size();
    vector<int> left, right;
    int i = 0;
    for(auto x: t){
        while(s[i] != x){
            i++;
        }
        left.pb(i);
        i++;
    }
    i = s.size() - 1;
    for(int j = t.size() - 1; j >= 0; j--){
        while(s[i] != t[j]){
            i--;
        }
        right.pb(i);
        i--;
    }
    int res = max(left[0], n - left[left.size() - 1] - 1);
    int low = 0, high = right.size() - 1;
    while(low < high){
        int tmp = right[low];
        right[low] = right[high];
        right[high] = tmp;
        low++;
        high--;
    }
    res = max(res, right[0]);
    res = max(res, n - right[right.size() - 1] - 1);
 
    for(int i = 0; i < left.size() - 1; i++){
        res = max(res, right[i + 1] - left[i] - 1);
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