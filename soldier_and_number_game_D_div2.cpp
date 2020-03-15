#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/problem/546/D
using namespace std;

const int N = 5000001;
bool isPrime[N];
int factor[N];
int dp[N];
int divv[N];

void Solve(){
    int a, b;
    cin>>a>>b;
    if(a <= b){
        cout<<0<<'\n';
        return;
    }
    cout<<dp[a] - dp[b]<<'\n';

	return;
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(isPrime, true, N);
    for(int i = 2; i * i < N; i++){
        if(!isPrime[i]) continue;
        int p = i;
        for(int j = 2 * p; j < N; j += p){
            isPrime[j] = false;
            divv[j] = j / p;
        }
    }
    for(int i = 2; i < N; i++){
        if(isPrime[i]) factor[i] = 1;
        else{
            factor[i] = factor[divv[i]] + 1;
        }
    }
    dp[1] = 0;
    for(int i = 2; i < N; i++)
        dp[i] = factor[i] + dp[i - 1];
    int q;
    cin>>q;
    while(q--){
    	Solve();
    }
}