//TC: approximately O(t * sqrt(r))
//SC: O(l-r)

#include<bits/stdc++.h>

using namespace std;


int maxN = (int)1e6;
vector<bool> isPrime(maxN + 1, true);

void sieve() {
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i <= maxN; i++) {
		if (isPrime[i] == true) {
			for (int j = i * i; j <= maxN; j += i) {
				isPrime[j] = false;
			}
		}
	}
}

vector<int> generatePrimes(int n) {
	vector<int> p;
	for (int i = 2; i <= n; i++)
		if (isPrime[i]) p.push_back(i);
	return p;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif

	sieve();
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;

		// step1
		vector<int> primes = generatePrimes(sqrt(r));

		//step2
		vector<int> dummy(r - l + 1, 1);
		if (l == 0) { dummy[0] = 0; dummy[1] = 0;}
		else if (l == 1) dummy[0] = 0;

		//step3
		for (auto &pr : primes) {
			int firstMultiple = (l / pr) * pr;
			if (firstMultiple < l) firstMultiple += pr;

			for (int j = max(firstMultiple, pr * pr); j <= r; j += pr) {
				dummy[j - l] = 0;
			}
		}

		//step4
		for (int i = l; i <= r; i++) {
			if (dummy[i - l] == 1) cout << i << " ";
		}

	}

	return 0;
}


