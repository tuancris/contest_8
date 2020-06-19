#include <bits/stdc++.h>
#define ll long long int
#define MAX 200
#define For(i, a, n) for (int i=a; i<=n; ++i)
using namespace std;
const ll MOD = 1e9 +7;

ll sum, n, cnt, m, k;
string s1, s2;
string s;
int f[MAX][MAX][MAX];
bool vis[MAX][MAX][MAX];

struct node {
    int x, y, z;
    int sl;
};

bool check (int x, int n) {
    if (x >= 1 && x <= n)
        return true;
    return false;
}

void solve() {
    sum = 0; cnt = 0;
    cin >> k>> n >> m;
    node s1, s2;
    node res[6] = {{-1,0,0}, {1,0,0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1}};
    queue<node> q;
    For(t,1,k) {
        // cout << t << endl;
        For(i,1,n) {
            string s;
            cin >> s;
            // cout << s << endl;
            For(j,1,m) {
                if (s[j-1] == '#')
                    f[i][j][t] = 0;
                else  {
                    f[i][j][t] = 1;
                    if (s[j-1] == 'S') {
                        s1 = {i, j, t, 0};
                    }
                    if (s[j-1] == 'E') {
                        s2 = {i, j, t};
                    }
                }
                vis[i][j][t] = false;
            }
        }
    }
    q.push(s1);
    vis[s1.x][s1.y][s1.z] = true;
    while(!q.empty()) {
        node s = q.front(); q.pop();
        // cout << s2.x << s2.y << s2.z << endl;
        if (s.x == s2.x && s.y==s2.y && s.z == s2.z) {
            cout << s.sl;
            return;
        }
        For(i, 0, 5) {
            int x = s.x + res[i].x;
            int y = s.y + res[i].y;
            int z = s.z + res[i].z;
                // cout << x << " " << y << " " << z << endl;
            if (x == s2.x && y == s2.y && z == s2.z) {
                cout << s.sl + 1;
                return;
            }
            if (check(x,n) && check(y,m) && check(z,k) && f[x][y][z] == 1 && !vis[x][y][z]) {
                //  cout << x << " " << y << " " << z << endl;
                vis[x][y][z] = true;
                q.push({x, y, z, s.sl + 1});
            }
        }
    }
    cout << -1;
}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
        cout << endl;
    }

    return 0;
}