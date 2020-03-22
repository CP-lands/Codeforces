#include<bits/stdc++.h>

//https://codeforces.com/contest/1326/problem/D1 
using namespace std;
 
void Solve(){
    string s;
    cin>>s;
    int n = s.size();
    string res = "";
    string a = "", b = "";
    string tmp = "";
    //case1 a = "";
    for(int i = n - 1; i >= 0; i--){
        b = s[i] + b;
        string t = b;
        reverse(t.begin(), t.end());
        if(t == b){
            if(res.size() < b.size()) res = b;
        }
    }
    //case2 b = "";
    for(int i = 0; i < n; i++){
        a += s[i];
        string t = a;
        reverse(t.begin(), t.end());
        if(t == a){
            if(res.size() < a.size()) res = a;
        }
    }
    //case3
    string left = "";
    string right = "";
    int low = 0, high = n - 1;
    while(s[low] == s[high] && low < high){
        left += s[low];
        right = s[high] + right;
        low++;
        high--;
    }
    //case1
    string k1 = "", k2 = "";
    for(int i = low; i < high; i++){
        tmp += s[i];
        string t = tmp;
        reverse(t.begin(), t.end());
        if(t == tmp) k1 = tmp;
    }
    tmp = "";
    for(int i = high; i > low; i--){
        tmp = s[i] + tmp;
        string t = tmp;
        reverse(t.begin(), t.end());
        if(t == tmp) k2 = tmp;
    }
    if(k2.size() >= k1.size()){
        tmp = left + k2 + right;
    }
    else tmp = left + k1 + right;
    if(tmp.size() > res.size()) res = tmp;
    cout<<res<<'\n';
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    while(q--){
    	Solve();
    }
}