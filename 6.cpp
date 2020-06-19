#include <bits/stdc++.h>
#define ll long long int
#define MAX 10000
#define For(i, a, n) for (int i=a; i<=n; ++i)
using namespace std;
const ll MOD = 1e9 +7;

ll sum, n, cnt, m, k;
string s1, s2;
ll a[MAX];
ll f[MAX][MAX];

int bigMod(string s, ll a) {
    ll res = 0;
    For(i, 0, s.size()-1) {
        res = (res * 10 + s[i] - '0') % a;
    }
    return res;
}

void solve() {
    sum = 0; cnt = 0;
    cin >> n;
    queue<string> a;
    a.push("9");
    while(1) {
        string temp = a.front();
        a.pop();
        if (bigMod(temp, n) == 0) {
            cout << temp;
            break;
        }
        a.push(temp+"0");
        a.push(temp+"9");
    }

}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
        cout << endl;
    }

    return 0;
}