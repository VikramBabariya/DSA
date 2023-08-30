// TC: O(maxN) // 1e8
// SC: O(maxN) // 1e8

int maxN = (int)1e8;
vector<bool> isPrime(maxN+1, true);

void sieve(){
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i <= maxN; i++){
        if(isPrime[i] == true){
            for(int j = i * i; j <= maxN; j += i){
                isPrime[j] = false;
            }
        }
    }
}
