#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        queue<ll> q;
        q.push(1);
        while(!q.empty()) {
            ll x = q.front(); q.pop();
            if(x%n == 0) {
                cout << x << endl;
                break;
            }
            q.push(x*10);
            q.push(x*10+1);
        }
    }
    return 0;
}
