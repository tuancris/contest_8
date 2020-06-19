#include<bits/stdc++.h>
#define ii pair<int,int>
using namespace std;
int a[501][501];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int day[501][501];
int r,c, songay = 0;
queue<ii> q;
bool check() {
    for(int i = 1; i<=r; i++) {
        for(int j = 1; j<=c; j++)
           if(a[i][j] == 1) return false;
    }
    return true;
}
int main() {
    cin >> r >> c;
    for(int i=1; i<=r; i++) {
       for(int j=1; j<=c; j++) {
           cin >> a[i][j];
           if(a[i][j] == 2) {
               q.push(ii(i,j));
               day[i][j] = 0;
           }
       }
    }
    while(!q.empty()) {
        ii t = q.front(); q.pop();
        int x = t.first, y = t.second;
        for(int i = 0; i<4; i++) {
            int u = x + dx[i];
            int v = y + dy[i];
            if(a[u][v] == 1) {
                a[u][v] = 2;
                day[u][v] = day[x][y] + 1;
                if(day[u][v] > songay) songay = day[u][v];
                q.push(ii(u,v));
            }
        }
    }
    if(check()) cout << songay;
    else cout << "-1";
    return 0;
}