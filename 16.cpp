#include<bits/stdc++.h>
#define vii pair<vector<int>, int>
using namespace std;
vector<int> a(6), b(6);
int minstep(vector<int> a, vector<int> b) {
    set<vector<int> > v;
    queue<vii> q;
    q.push(vii(a,0));
    v.insert(a);
    while(!q.empty()) {
        vii t = q.front(); q.pop();
        if(t.first == b) return t.second;
        vector<int> l = t.first;
        l.at(0) = t.first.at(3);
        l.at(3) = t.first.at(4);
        l.at(4) = t.first.at(1);
        l.at(1) = t.first.at(0);
        vector<int> r = t.first;
        r.at(1) = t.first.at(4);
        r.at(4) = t.first.at(5);
        r.at(5) = t.first.at(2);
        r.at(2) = t.first.at(1);
        if(l == b || r == b) return t.second + 1;
        if(v.find(l) == v.end()) {
            q.push(vii(l,t.second+1));
            v.insert(l);
        }
        if(v.find(r) == v.end()) {
            q.push(vii(r,t.second+1));
            v.insert(r);
        }
    }
}
int main() {
    for(int i=0; i<6; i++) cin >> a.at(i);
    for(int i=0; i<6; i++) cin >> b.at(i);
    cout << minstep(a,b);
    return 0;
}
