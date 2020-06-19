#include <bits/stdc++.h>
#define ll long long int
#define MAX 10000
#define For(i, a, n) for (int i=a; i<=n; ++i)
using namespace std;
const ll MOD = 1e9 +7;

ll sum, n, cnt, m, k;
string s1, s2;

bool check(ll a) {
    string s = to_string(a);
    set<char> res;
    For(i, 0, s.size()-1) {
        res.insert(s[i]);
    }
    // cout << res.size() << endl;
    if (res.size() != s.size())
        return false;
    else return true;
}

vector<ll> sol() {
    queue<ll> q;
    vector<ll> a;
    unordered_map<ll, bool> vis;
    for (char i = 0; i<=5; ++i) {
        q.push(i);
        a.push_back(i);
        vis[i] = true;
    }
    while(a[a.size() - 1] < n && !q.empty()) {
        ll temp = q.front(); q.pop();
        // cout << temp << endl;
        For(i, 0, 5) {
            ll s = temp * 10 + i;
            // cout << temp << " " << s << endl;
            if (!vis[s] && check(s) && s<=n && s != 0) {
            // cout << s << endl;
                q.push(s);
                a.push_back(s);
                vis[s] = true;
            }
        }
    }
   
    return a;
}

void solve() {
    sum = 0; cnt = 0;
    cin >> k >> n;
    // cout << check(n);
    vector<ll> a  = sol();
    int i = 0;
    while(k > a[i]) {
        ++i;
    }
    cnt = 0;
    while(n >= a[i] && i <= a.size() - 1) {
        // cout << a[i] << endl;
        ++cnt;
        ++i;
    }
    cout << cnt;

}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
        cout << endl;
    }

    return 0;
}