#include<iostream>

using namespace std;

int badges(int b, int g, int n)
{
	int count_b;
	int count_g;
	if(b + g == n)
		return 1;
	if(n - g > 0)
		if(n <= b)
			count_b = g + 1;
		else
			count_b = b - n + g + 1;
	else
		count_b = n + 1;
	if(n - b > 0)
		if(n <= g)
			count_g = b + 1;
		else
			count_g = g - n + b + 1;
	else
		count_g = n + 1;
	return min(count_b, count_g);
}
int main()
{
	int b,g,n;
	cin>>b>>g>>n;
	cout<<badges(b,g,n);
	return 0;
}