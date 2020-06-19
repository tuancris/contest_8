#include<bits/stdc++.h>
#define ll pair<int,int> 
#define fi first
#define se second
using namespace std;
int tinh(int s, int t) {
    set<int> v;
    v.insert(s);
    ll a;
    a.fi = s; a.se = 0;
    queue<ll> q;
    q.push(a);
    while(!q.empty()) {
        ll tmp = q.front(); q.pop();
        if(tmp.fi == t) return tmp.se;
        if(tmp.fi - 1 == t || tmp.fi*2 == t) return tmp.se+1;
        if(v.find(tmp.fi-1) == v.end()) {
            q.push(ll(tmp.fi-1, tmp.se+1));
            v.insert(tmp.fi-1);
        }
        if(v.find(tmp.fi*2) == v.end() && tmp.fi < t) {
            q.push(ll(tmp.fi*2, tmp.se+1));
            v.insert(tmp.fi*2);
        }
    
    }
}
int main() {
    int t; cin >> t;
    while(t--) {
        int s, t; cin >> s >> t;
        cout << tinh(s,t) << endl;
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
ll a[MAX];
ll f[MAX][MAX];

struct node {
    ll x, y;
};

int solve() {
    sum = 0; cnt = 0;
    cin >> n >> k;
    node res; res.x = n; res.y = 0;
    queue<node> a;
    set<ll> visit;
    a.push(res);
    while(!a.empty()) {
        node temp = a.front();
        a.pop();
        if (temp.x == k)
            return temp.y;
        visit.insert(temp.x);
        if (temp.x * 2 == k || temp.x - 1 == k) {
            return temp.y + 1;
        }

        if (visit.find(temp.x * 2) == visit.end()) {
            res.x = temp.x * 2;
            res.y = temp.y + 1;
            a.push(res);
        }
        if (visit.find(temp.x - 1) == visit.end() && temp.x-1 >=0) {
            res.x = temp.x - 1;
            res.y = temp.y + 1;
            a.push(res);
        }
    } 
    
}

int main() {
    int t; cin >> t;
    while(t--) {
        cout << solve();
        cout << endl;
    }

    return 0;
}
*/