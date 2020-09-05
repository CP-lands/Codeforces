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

//https://codeforces.com/problemset/problem/621/C
using namespace std;

typedef long long ll; 
const int MOD = 1e9 + 7;

int main()
{
	int n, p, low, high;
	cin>>n>>p;
	vector<vector<int>> res(n, vector<int>(2));
	for(int i = 0; i < n; i++)
	{
		cin>>low>>high;
		if(low % p == 0) res[i][0] = high / p - low / p + 1;
		else res[i][0] = high / p - low / p;
		res[i][1] = high - low + 1;
	}

	double sum = 0;
	for(int i = 0; i < n - 1; i++)
		sum += 1 - (((double)res[i][1] - res[i][0]) / res[i][1]) * (((double)res[i + 1][1] - res[i + 1][0]) / res[i + 1][1]);
	sum += 1 - (((double)res[0][1] - res[0][0]) / res[0][1]) * (((double)res[n - 1][1] - res[n - 1][0]) / res[n - 1][1]);
	cout<<fixed<<setprecision(6)<<sum * 2000<<endl;
	return 0;
}
