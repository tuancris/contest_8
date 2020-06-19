#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	string s; queue<int> q;
	while(n--) {
		cin >> s;
		if(s == "PUSH") {
			int x; cin >> x;
			q.push(x);
		}
		else if(s == "POP") {
			if(!q.empty()) q.pop();
		}
		else if(s == "PRINTFRONT") {
			if(!q.empty()) cout << q.front() << endl;
			else cout << "NONE\n";
		}
	}
}
int main() {
	solve();
	return 0;
}
