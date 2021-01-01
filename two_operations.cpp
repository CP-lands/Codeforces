#include<bits/stdc++.h>  
 
//https://codeforces.com/gym/102263/problem/M
using namespace std; 
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;
 
void Solve(){
    string s;
    cin>>s;
    sort(s.rbegin(), s.rend());
    while(true){
        int n = s.size();
        string tmp = "";
        int count = 0;
        for(int i = 0; i < n - 1; i++){
            if(s[i] == s[i + 1] && s[i] != 'z'){
                tmp += (char)(s[i] + 1);
                i++;
                count++;
            }
            else tmp += s[i];
        }
        if(tmp.size() + count < n) tmp += s[n - 1];
        bool good = true;
        s = tmp;
        for(int i = 0; i < s.size() - 1; i++){
            if(s[i] == s[i + 1] && s[i] != 'z') good = false;
        }
        if(good) break;
    }
    cout<<s<<nl;
 
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    //cin>>T;
    while(T--){
        Solve();
    }
}