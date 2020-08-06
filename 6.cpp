#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll binary(ll n) {
	if(n == 1) return 1;
	if(n%2 == 0) return 10*binary(n/2);
	else return 10*binary(n/2) + 1;
}
int main() {
	int t; cin >> t;
	while(t--) {
		int a=1, b=9;
		ll n; cin >> n;
		while(b%n != 0) {
			a++;
			b = binary(a);
			b *= 9;
		}
		cout << b << endl;
	}
	return 0;
}
