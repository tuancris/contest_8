#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dem[50];
ll tinh(string s, ll k) {
    if(k >= s.length()) return 0;
    ll res = 0;
    for(int i=0; i<='Z'-'A'; i++) dem[i] = 0;
    for(int i=0; i<s.length(); i++) dem[s[i]-'A']++;
    priority_queue<int> pq;
    for(int i=0; i<='Z'-'A'; i++) {
        if(dem[i]!=0) pq.push(dem[i]);
    }
    while(k--) {
        ll t = pq.top(); pq.pop();
        t--;
        pq.push(t);
    }
    while(!pq.empty()) {
        int t = pq.top(); pq.pop();
        res += pow(t,2);
    }
    return res;
}
int main() {
    int t; cin >> t;
    while(t--) {
        ll k; cin >> k;
        string s; cin >> s;
        cout << tinh(s,k) << endl;
    }
    return 0;
}
/*
#include <bits/stdc++.h>
#define ll long long int
#define MAX 10000
#define For(i, a, n) for (int i=a; i<=n; ++i)
using namespace std;
const ll MOD = 1e9 +7;

ll sum, n, cnt, m, k;
string s1, s2;
// ll a[MAX];
// ll f[MAX][MAX];

void solve() {
    sum = 0; cnt = 0;
    cin >> k;
    string s;
    cin >> s;
    vector<ll> a(27, 0);
    For(i, 0, s.size()) {
        ++a[s[i] - 'A'];
    }
    priority_queue<ll,vector<ll>,  less<ll> > b;
    For(i, 0, a.size()-1)
        if (a[i]!=0)
            b.push(a[i]);
    while(!b.empty() && k != 0) {
        ll temp = b.top();
        // cout << temp << endl;
        b.pop();
        --temp;
        // cout << temp << endl;
        if (temp != 0)
        b.push(temp);
        --k;
    }
    while(!b.empty()) {
        sum += b.top() * b.top();
        // cout << sum << endl;
        b.pop();
    }
    cout << sum;
}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
        cout << endl;
    }

    return 0;
}
*/