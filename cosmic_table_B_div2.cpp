//------Anivia_kid----------
#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/problem/222/B
using namespace std;
 
#define fi first
#define se second
typedef long long ll; 

int v[1000][1000];
int row[1000], col[1000];

void Anivia_kid(){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			scanf("%d", &v[i][j]);
	}
	for(int i = 0; i < n; i++)
		row[i] = i;
	for(int i = 0; i < m; i++)
		col[i] = i;
	for(int i = 0; i < k; i++){
		char c;
		int x, y;
		scanf(" %c%d%d", &c, &x, &y);
		if(c == 'c') swap(col[x - 1], col[y - 1]);
		else if(c == 'r') swap(row[x - 1], row[y - 1]);
		else if(c == 'g')
			printf("%d \n",v[row[x - 1]][col[y - 1]]);
	}

	return;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q = 1;
	//cin>>q;
	while(q--){
		Anivia_kid();
	}
	return 0;
}
