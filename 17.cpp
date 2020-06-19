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
bool vis[MAX][MAX];
struct node
{
    int x, y;
    int sl;
};
void solve() {
    sum = 0; cnt = 0;
    cin >> n;

    For(i, 0, n-1) {
        string s;
        cin >> s;
        For(j, 0, s.size()-1) {
            if (s[j]=='.') 
                f[i][j] = 0;
            else f[i][j] = 1;
            vis[i][j] = false;
        }
    }
    node s1, s2;
    cin >> s1.x >> s1.y >> s2.x >> s2.y;
    queue<node> q;
    q.push({s1.x, s1.y, 0});
    vis[s1.x][s1.y] = true;
    while(!q.empty()) {
        node temp = q.front(); q.pop();
        if (temp.x == s2.x && temp.y == s2.y) {
            cout << temp.sl;
            return;
        }
        for(int i=temp.x + 1; i<n; ++i) {
            if (f[i][temp.y])
                break;
            if (!vis[i][temp.y]) {
                vis[i][temp.y] = true;
                // cout << i << " " << temp.y << endl;
                q.push({i, temp.y, temp.sl + 1});
            }
        }
        for(int i=temp.x - 1; i>=0; --i) {
            if (f[i][temp.y])
                break;
            if (!vis[i][temp.y]) {
                vis[i][temp.y] = true;
                q.push({i, temp.y, temp.sl + 1});
            }
        }
        for(int i=temp.y + 1; i<n; ++i) {
            if (f[temp.x][i])
                break;
            if (!vis[temp.x][i]) {
                vis[temp.x][i] = true;
                q.push({temp.x, i, temp.sl + 1});
            }
        }
        for(int i=temp.y - 1; i>=0; --i) {
            if (f[temp.x][i])
                break;
            if (!vis[temp.x][i]) {
                vis[temp.x][i] = true;
                q.push({temp.x, i, temp.sl + 1});
            }
        }
    }

}

int main() {
    int t=1; 
    while(t--) {
        solve();
        cout << endl;
    }

    return 0;
}