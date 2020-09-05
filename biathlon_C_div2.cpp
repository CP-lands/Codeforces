//--------Anivia_kid---------//
#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/problem/84/C
using namespace std;
 
#define fi first
#define se second
#define pb push_back
typedef long long ll; 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;

void Anivia_kid(){
	int n, m;
	cin>>n;
	vector<vector<int>> tg(n, vector<int>(3));
	
	for(int i = 0; i < n; i++){
		cin>>tg[i][0]>>tg[i][1];
		tg[i][2] = i;
	}
	sort(tg.begin(), tg.end());
	cin>>m;
	int shot[m][2];
	for(int i = 0; i < m; i++)
		cin>>shot[i][0]>>shot[i][1];
	vector<int> res(n);
	int ans = 0;
	for(int i = 0; i < m; i++){
		//if(shot[i][0] > tg[n - 1][0] + tg[n - 1][1] || shot[i][0] < tg[0][0] + tg[0][1]) continue; 
		int st = 0; int end = n - 1;
		while(end > st + 1){
			int mid = st + (end - st) / 2;
			if(tg[mid][0] > shot[i][0]) end = mid;
			else st = mid; 
		}

		ll l1 = (shot[i][0] - tg[st][0]) * (shot[i][0] - tg[st][0]) + shot[i][1] * shot[i][1];

		if(l1 <= tg[st][1] * tg[st][1] && res[tg[st][2]] == 0){
			res[tg[st][2]] = i + 1;
			ans++;
		}
		if(st < n - 1){
			ll l2 = (shot[i][0] - tg[st + 1][0]) * (shot[i][0] - tg[st + 1][0]) + shot[i][1] * shot[i][1];
			if(l2 <= tg[st + 1][1] * tg[st + 1][1] && res[tg[st + 1][2]] == 0){
				res[tg[st + 1][2]] = i + 1;
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	for(int i = 0; i < n; i++){
		if(res[i] == 0) cout<<-1<<" ";
		else cout<<res[i]<<" ";
	}

	return;

}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q = 1;
	//cin>>q;
	while(q--){
		Anivia_kid();
	}
	return 0;
}
