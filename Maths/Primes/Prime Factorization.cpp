#include<bits/stdc++.h>

using namespace std;

int maxN = 1e6;
vector<int> minPrimeFactor(maxN + 1, 0);

void sieve() {
	for (int i = 0; i <= maxN; ++i) {
		minPrimeFactor[i] = i;
	}

	for (int i = 2; i * i <= maxN; ++i) {
		if (minPrimeFactor[i] == i) {
			for (int j = i * i; j <= maxN; j += i) {
				// multiples of i which are not already marked by other smaller prime numbers
				if (minPrimeFactor[j] == j) minPrimeFactor[j] = i;
			}
		}
	}
}



int main() {

	sieve();
	int q;
	cin >> q;
	while (q--) {
		int k;
		cin >> k;

		while (k != 1) {
			cout << minPrimeFactor[k] << " ";
			k = k / minPrimeFactor[k];
		}
	}

	return 0;
}


