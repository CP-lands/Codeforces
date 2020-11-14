#include<bits/stdc++.h>

//https://codeforces.com/contest/1433/problem/E
using namespace std;
 
long long comb(int n, int k)
{
    long long res = 1;
    for(int i = 1; i <= k; i++){
        res *= (n - i + 1);
        res /= i;
    }
    return res;
}
 
void Solve(){
    int n;
    cin>>n;
    long long res = comb(n, n / 2);
    res /= 2;
    long long ans = 1;
    for(int i = 2; i < n / 2; i++)
        ans *= i;
    ans *= ans;
    cout<<res * ans<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    //cin>>T;
    while(T--){
        Solve();
    }
}