#include<bits/stdc++.h>  
 
//https://codeforces.com/contest/1454/problem/D
using namespace std; 
 
bool isPrime(int n){
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}
vector<int> primes;
void Solve(){
    long long n;
    cin>>n;
    bool good = false;
    for(long long i = 2; i * i <= n; i++){
        if(n % i == 0) good = true;
    }
    if(!good){
        cout<<1<<'\n'<<n<<'\n';
        return;
    }
    vector<long long> res;
 
    for(int i = 0; i < primes.size(); i++){
        if(n % primes[i]) continue;
        //cout<<n<<" "<<primes[i]<<endl;
        vector<long long> tmp;
        long long k = n;
        while(k % primes[i] == 0){
            tmp.push_back(primes[i]);
            k /= primes[i];
        }
        tmp.back() *= k;
        if(tmp.size() > res.size()) res = tmp;
    }
    cout<<res.size()<<'\n';
    for(auto x: res) cout<<x<<" ";
    cout<<'\n';
}
int main()  
{  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    for(int i = 2; i <= 100000; i++){
        if(isPrime(i)) primes.push_back(i);
    }
    while(T--){
        Solve();
    }
}