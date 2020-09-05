//___1 WA == 5 Push up___
#include<iostream>
#include<math.h>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
#include<set>
#include<string.h>
#include<map>
#include<iomanip>
 
//https://codeforces.com/problemset/problem/1236/C
using namespace std;
 
typedef long long ll; 
 
const int MOD = 1e9 + 7;
 
int main()
{
	int n;
	cin>>n;
	vector<vector<int>> res(n, vector<int>(n));
	int k = 1;
	for(int i = 0; i < n; i++)
	{
		if(i % 2 == 0)
			for(int j = 0; j < n; j++)
				res[i][j] = k++;
			
		else
			for(int j = n - 1; j >= 0; j--)
				res[i][j] = k++;
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout<<res[j][i]<<" ";
		cout<<endl;
	}
	return 0;
}
