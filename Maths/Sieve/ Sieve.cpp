

int maxN = (int)1e7;
vector<bool> isPrime(maxN+1, true);

// TC: O(N * loglogN)
void sieve(){
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i<= maxN; i++){
        if(isPrime[i] == true){
            for(int j = 2 * i; j <= maxN; j += i){
                isPrime[j] = false;
            }
        }
    }
}

// Optimization
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



--------------------
Finding Lowest and Highest prime divisor of a numbers

void low_high_prime_fact(int n){
    vector<bool> isPrime(n+1, true);
    vector<int> lp(n+1, 0), hp(n+1, 0); // we can only use isPrime also 

    for(int i = 2; i <= n; i++){
        if(isPrime[i]){
            lp[i] = hp[i] = i;
            for(int j = 2*i; j <= n; j += i){
                isPrime[j] = false;
                hp[j] = i;
                if(lp[j] == 0) lp[j] = i;
            }
        }
    }
}







    








    
