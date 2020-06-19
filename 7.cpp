#include <bits/stdc++.h> 
#define ll long long
using namespace std; 
  
ll dem(ll n) { 
    ll ctr = 1; 
    ll ans = 0; 
    while (n > 0) { 
        if (n % 10 == 1) 
            ans += pow(2, ctr - 1); 
        else if (n % 10 > 1) 
            ans = pow(2, ctr) - 1;
        ctr++; 
        n /= 10; 
    } 
    return ans; 
} 
int main() {
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        cout << dem(n) << endl;
    }
    return 0;
}