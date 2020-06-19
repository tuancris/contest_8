#include<bits/stdc++.h>
#define ll long long
#define ii pair<int,int> 
#define fi first
#define se second
using namespace std;

ll tinh(ll n) {
    set<int> v;
    v.insert(n);
    queue<ii> q;
    q.push(ii(n,0));
    while(!q.empty()) {
        ii t = q.front(); q.pop();
        if(t.fi == 1) return t.se;
        if(t.fi-1 == 1) return t.se+1;
        if(v.find(t.fi-1) == v.end()) 
            q.push(ii(t.fi-1, t.se+1));
        for(int i=2; i*i<=t.fi; i++) {
            if(t.fi%i == 0) {
                if(v.find(t.fi/i) == v.end())
                   q.push(ii(t.fi/i, t.se+1));
            }
        }
    }
}
int main() {
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        cout << tinh(n) << endl;
    }
    return 0;
}
/*

#include <bits/stdc++.h>
#define ll long long int
#define MAX 10000
#define For(i, a, n) for (int i=a; i<=n; ++i)
using namespace std;

int sum, n, cnt, m, k;


struct node
{
    int x;
    int sl;
};


int solve() {
    sum = 0; cnt = 0;
    cin >> n;
    unordered_set<int> vis;
    queue<node> q;
    q.push({n, 0});
    while(!q.empty()) {
        node temp = q.front();
        q.pop();
        if (temp.x == 1) return temp.sl;
        if (temp.x - 1==1) return temp.sl + 1;
        if (vis.find(temp.x - 1) == vis.end() && temp.x - 1 > 0) {
            q.push({temp.x-1, temp.sl + 1});
            vis.insert(temp.x-1);
        }
        for(int i =2; i*i<=temp.x; ++i) {
            if (temp.x % i == 0) {
                if (vis.find(temp.x/i) == vis.end()) {
                    q.push({temp.x/i, temp.sl + 1});
                    vis.insert(temp.x/i);
                }
            }
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
}/