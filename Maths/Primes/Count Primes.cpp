// TC: O(maxN) // 1e8
// SC: O(maxN) // 1e8

int maxN = 5000000;
vector<bool> isPrime(maxN+1, true);
vector<int> v{0};

void sieve(){
    cout<<"deb";
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i <= maxN; i++){
        if(isPrime[i] == true){
            for(int j = i * i; j <= maxN; j += i){
                isPrime[j] = false;
            }
        }
    }

    for(int i = 1; i <= maxN; i++){
        if(isPrime[i]) v.push_back(v[i-1] + 1);
        else v.push_back(v[i-1]);
    }
}


class Solution {
public:
    int countPrimes(int n) {
        if(n == 0) return 0;
        if(v.size() == 1) sieve();
        return v[n-1];
    }
};
