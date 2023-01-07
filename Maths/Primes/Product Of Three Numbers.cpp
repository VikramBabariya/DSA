/*
Suppose a<b<c. Let's try to minimize a and maximize c. Let a be the minimum divisor of n greater than 1. 
Then let b be the minimum divisor of na that isn't equal a and 1. If nab isn't equal a, b and 1 then the answer is "YES", otherwise the answer is "NO".
Time complexity: O(n−−√) per query.

*/

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int n;
		cin >> n;
		set<int> used;
		for (int i = 2; i * i <= n; ++i) {
			if (n % i == 0 && !used.count(i)) {
				used.insert(i);
				n /= i;
				break;
			}
		}
		for (int i = 2; i * i <= n; ++i) {
			if (n % i == 0 && !used.count(i)) {
				used.insert(i);
				n /= i;
				break;
			}
		}
		if (int(used.size()) < 2 || used.count(n) || n == 1) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
			used.insert(n);
			for (auto it : used) cout << it << " ";
			cout << endl;
		}
	}
	
	return 0;
}
