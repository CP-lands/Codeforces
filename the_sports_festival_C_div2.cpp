#include<bits/stdc++.h>
 
using namespace std;
//https://codeforces.com/contest/1509/problem/C
 
#define fi first
#define se second
#define pb push_back
#define nl '\n'
#define bug cout<<"bug here!"<<nl
typedef long long ll;
 
const int N = 2001;
 
int v[N];
ll dp[N][N];
 
void Solve(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    	cin>>v[i];
    sort(v, v + n);
   	for(int i = 0; i < N; i++)
   		for(int j = 0; j < N; j++)
   			dp[i][j] = 1e18;
 
   	for(int i = 0; i < n; i++)
   		dp[i][i] = 0;
   	for(int i = n - 1; i >= 0; i--){
   		for(int j = i + 1; j < n; j++){
   			dp[i][j] = v[j] - v[i] + min(dp[i + 1][j], dp[i][j - 1]);
   		}
   	}
   	cout<<dp[0][n - 1]<<nl;
 
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    //cin>>T;
    while(T--){
        Solve();
    }
}