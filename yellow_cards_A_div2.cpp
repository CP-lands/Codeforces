#include<iostream>

using namespace std;

int max_case(int a1, int a2, int k1, int k2, int n)
{
	if(k1 <= k2)
	{
		if(n/k1 <= a1)
			return n/k1;
		else
			return a1 + (n - k1*a1)/k2;
	}
	else
		if(n/k2 <= a2)
			return n/k2;
		else
			return a2 + (n - k2*a2)/k1;
}
int min_case(int a1, int a2, int k1, int k2, int n)
{
	if((k1 - 1)*a1 + (k2 - 1)*a2 >= n)
		return 0;
	else 
		return (n - (k1 - 1)*a1 - (k2 - 1)*a2);
}
int main()
{
	int a1, a2, k1, k2, n;
	cin>>a1>>a2>>k1>>k2>>n;
	cout<<min_case(a1, a2, k1, k2, n);
	cout<<max_case(a1, a2, k1, k2, n)<<" ";
	return 0;
}