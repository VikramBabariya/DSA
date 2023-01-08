// if maxN = 1e8 then this code will give tle

#include<bits/stdc++.h>

using namespace std;

int maxN = 86028121;
vector<bool> isPrime(maxN + 1, true);
vector<int> primes;

void sieve() {
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i <= maxN; i++) {
		if (isPrime[i] == true) {
			for (int j = i * i; j <= maxN; j += i) {
				isPrime[j] = false;
			}
		}
	}
	for (int i = 2; i <= maxN; i++) {
		if (isPrime[i]) primes.push_back(i);
	}

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
		int k;
		cin >> k;
		cout << primes[k - 1] << endl;
	}

	return 0;
}


