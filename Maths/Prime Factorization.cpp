// Bruteforce -- TC : O(N)

vector<int> prime_fact(int n){
	vector<int> pfact;
	for(int i = 2; i <= n; i++){
		while(n%i == 0){
			pfact.push_back(i);
			n /= i;
		}
	}
	return pfact;
}

// Optimization TC : O(sqrt(N))
// Fact : Every composite number has atleast one prime divisor which is less then sqrt(N)
vector<int> prime_fact(int n){
	vector<int> pfact;
	for(int i = 2; i * i <= n; i++){
		while(n%i == 0){
			pfact.push_back(i);
			n /= i;
		}
	}
	if(i > 1) pfact.push_back(i);
	return pfact;
}





// TC: O(Q * logn)
// SC: O(n)

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

// facorization of n
while (n != 1) {
	cout << minPrimeFactor[n] << " ";
	n = n / minPrimeFactor[n];
}


//approach 2 : hard code 

int p[65] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
    101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
    211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313};
int smallestValue(int n) {
    for (int i = 0; i < 65 && n != 1; ++i){
        while (n % p[i] == 0) {
		cout<<p[i]<<" ";
            	n /= p[i];
        }
    }
    if(n != 1) cout<<n<<" "; // large prime
}


