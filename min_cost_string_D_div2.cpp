#include<bits/stdc++.h>
 
using namespace std;
//https://codeforces.com/contest/1511/problem/D
 
#define fi first
#define se second
#define pb push_back
#define nl '\n'
#define bug cout<<"bug here!"<<nl
typedef long long ll;
 
const int N = 2e5 + 1;
 
void Solve(){
    int n, k;
    cin>>n>>k;
    vector<int> g[k];
    vector<vector<int>> v(k, vector<int> (k));
    string res = "a";
    n--;
    while(n--){
    	int pre = (int)(res[res.size() - 1] - 'a');
    	int maxx = N;
    	int next = 0;
    	int degree = N;
    	for(int i = 0; i < k; i++){
    		if(v[pre][i] < maxx){
    			maxx = v[pre][i];
    			next = i;
    		}
    		else if(v[pre][i] == maxx && g[i].size() < degree){
    			degree = g[i].size();
    			maxx = v[pre][i];
    			next = i;
    		}
    	}
    	v[pre][next]++;
    	g[pre].pb(next);
    	res += 'a' + next;
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