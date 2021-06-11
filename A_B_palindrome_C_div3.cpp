#include<bits/stdc++.h>
 
using namespace std;
//https://codeforces.com/contest/1512/problem/C
 
#define fi first
#define se second
#define pb push_back
#define nl '\n'
#define bug cout<<"bug here!"<<nl
typedef long long ll;
 
void Alice(){
    int a, b;
    string s;
    cin>>a>>b>>s;
    int n = s.size();
    int low = 0, high = n - 1;
    while(low < high){
        if(s[low] == '?' || s[high] == '?'){
            if(s[low] == '?' && s[high] == '?'){
                low++;
                high--;
            }
            else{
                if(s[low] == '?') s[low] = s[high];
                else s[high] = s[low];
                low++;
                high--;
            }
        }
        else{
            if(s[low] != s[high]){
                cout<<-1<<nl;
                return;
            }
            low++;
            high--;
        }
    }
    int aa = 0, bb = 0;
    for(auto x: s){
        if(x == '0') aa++;
        if(x == '1') bb++;
    }
    if(aa > a || bb > b){
        cout<<-1<<nl;
        return;
    }
    aa = a - aa;
    bb = b - bb;
    low = 0, high = n - 1;
    while(low < high){
        if(s[low] != '?'){
            low++;
            high--;
            continue;
        }
        if(aa >= bb){
            s[low] = s[high] = '0';
            aa -= 2;
        }
        else{
            s[low] = s[high] = '1';
            bb -= 2;
        }
    }
    if(low == high && s[low] == '?'){
        if(aa >= bb){
            s[low] = '0';
            aa--;
        }
        else{
            s[low] = '1';
            bb--;
        }
    }
    //cout<<aa<<" "<<bb<<nl;
    if(aa == 0 && bb == 0) cout<<s<<nl;
    else cout<<-1<<nl;
    
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        Alice();
    }
}