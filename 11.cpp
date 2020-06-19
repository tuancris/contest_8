#include <bits/stdc++.h>
#define ll long long int
#define MAX 10000
#define For(i, a, n) for (int i=a; i<=n; ++i)
using namespace std;
const ll MOD = 1e9 +7;

ll sum, n, cnt, m, k;
string s1, s2;
vector<bool> prime;
struct node {
    string x;
    int y;
};

ll check(string s) {
    int val = 0;
    For(i, 0, s.size()-1) 
        val = val * 10 + s[i] - '0';
    return val;
}

vector<bool> seve() {
    vector<bool> temp(10000, true);
    temp[0] = 0;
    temp[1] = 0;
    for (int i = 2; i*i <= 10000; ++i) {
        if (temp[i]) 
            for (int j =i*i; j <= 10000; j+=i)
                temp[j] = false;
    }
    return temp;
}

int  solve() {
    sum = 0; cnt = 0;
    cin >> s1 >> s2;
    unordered_map<string, bool> vis;
    queue<node> a;
    vis[s1] = true;
    a.push({s1, 0});
    while(1) {
        node s = a.front(); a.pop();
        // cout << s.x << endl;
        if (s.x == s2) return s.y;
        For(i, 0, 3) {
            for (char j = '0'; j<='9'; ++j) {
                string temp = s.x;
                temp[i] = j;
                if (temp[0] != '0' && !vis[temp] && prime[check(temp)]) {
                    a.push({temp, s.y + 1});
                    vis[temp] = true;
                }
            }
        }
    }

}

int main() {
    int t; cin >> t;
    prime = seve();
    // cout << prime[1033];
    while(t--) {
        cout << solve();
        cout << endl;
    }
    return 0;
}