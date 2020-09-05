#include<bits/stdc++.h>
 
//https://codeforces.com/contest/1409/problem/D
using namespace std;
 
void Solve(){
    string n;
    int s;
    cin>>n>>s;
    int sum = 0;
    for(auto x: n)
        sum += x - '0';
    if(sum <= s){
        cout<<0<<'\n';
        return;
    }
    int i = n.size() - 1;
    while(i >= 0 && sum >= s){
        sum -= n[i] - '0';
        i--;
    }
    long long res = 0;
    int j = n.size() - 1;
    //cout<<n[j]<<endl;
    while(j > i){
        long long k = n.size() - j - 1;
        long long tmp = pow(10, k) * (n[j] - '0');
        res = res + tmp;
        j--;
        //cout<<k<<" "<<res<<endl;
    }
    long long ans = 1;
    for(j = i + 1; j < n.size(); j++)
        ans *= 10;
    //cout<<ans<<" "<<res<<endl;
    cout<<ans - res<<endl;
    
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        Solve();
    }
}