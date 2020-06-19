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

struct node
{
    string x;
    int y;
};


void solve() {
    sum = 0; cnt = 0;
    cin >> n;
    vector<string> v;
    cin >> s1 >> s2;
    For(i, 0, n-1) {
        string temp;
        cin >> temp;
        v.push_back(temp);
    }
    unordered_set<string> res(v.begin(), v.end());
    queue<node> q;
    unordered_map<string, bool> vis;
    q.push({s1, 1});
    vis[s1] = true;
    while(!q.empty()) {
        node temp = q.front(); q.pop();
        // cout << temp.x << endl;
        For(i, 0, temp.x.length()-1) {
            string s = temp.x;
        
            for (char j = 'A'; j<='Z'; ++j) {
                s[i] = j;
                if (res.find(s) != res.end()) {
                    if (s == s2) {
                        cout << temp.y+1;
                        return;
                    }
                    if (!vis[s]) {
                        q.push({s, temp.y+1});
                        vis[s] = true;
                    }
                }
               
            }
        } 
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