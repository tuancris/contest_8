#include <bits/stdc++.h> 
using namespace std; 
  
string pure(int n) { 
    string p;  
    while (n > 0) {  
        n--;  
        if (n % 2 == 0)  p.append("4"); 
        else    p.append("5"); 
        n /= 2;  
    } 
    int len = p.length();  
    reverse(p.begin(), p.end()); 
    for (int i = len - 1; i >= 0; i--) 
        p += p[i]; 
    return p; 
} 
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) 
             cout << pure(i) << " ";
        cout << endl;
    }
    return 0;
}
