#include<bits/stdc++.h>
 
using namespace std;
//https://codeforces.com/contest/1517/problem/C
 
#define fi first
#define se second
#define pb push_back
#define nl '\n'
#define bug cout<<"bug here!"<<nl
typedef long long ll;
 
int movee1[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int movee2[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
int n;
 
bool vst[500][500];
int res[500][500];
 
bool isValid(int x, int y){
	if(x >= 0 && x < n && y >= 0 && y < n && !vst[x][y]) return true;
	return false;
}
 
int need = 0;
int now = 0;
void dfs(int x, int y, int type){
	if(need == 0) return;
	if(type == 1){
		for(int i = 0; i < 4; i++){
			if(need == 0) return;
			int xx = x + movee1[i][0];
			int yy = y + movee1[i][1];
			if(isValid(xx, yy)){
				res[xx][yy] = now;
				need--;
				vst[xx][yy] = true;
				dfs(xx, yy, type);
			}
		}
	}
	if(type == 2){
		for(int i = 0; i < 4; i++){
			if(need == 0) return;
			int xx = x + movee2[i][0];
			int yy = y + movee2[i][1];
			if(isValid(xx, yy)){
				res[xx][yy] = now;
				need--;
				vst[xx][yy] = true;
				dfs(xx, yy, type);
			}
		}
	}
}
 
void Solve(){
	for(int i = 0; i < 500; i++){
		for(int j = 0; j < 500; j++){
			vst[i][j] = false;
			res[i][j] = 0;
		}
	}
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    	cin>>v[i];
 
    for(int i = 0; i < n; i++){
    	vst[i][i] = true;
    	res[i][i] = v[i];
    	for(int j = i + 1; j < n; j++){
    		vst[i][j] = true;
    	}
    }
 
 	int low = 0, high = n - 1;
 	while(low <= high){
 		if(v[low] >= v[high]){
 			need = v[low] - 1;
 			now = v[low];
 			dfs(low, low, 1);
 			low++;
 		}
 		else{
 			need = v[high] - 1;
 			now = v[high];
 			dfs(high, high, 2);
 			high--;
 		}
 		if(need != 0){
 			cout<<-1<<nl;
 			return;
 		}
 	}
 	for(int i = 0; i < n; i++){
 		for(int j = 0; j <= i; j++){
 			cout<<res[i][j]<<" ";
 		}
 		cout<<nl;
 	}
 
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    //cin>>T;
    while(T--){
        Solve();
    }
}