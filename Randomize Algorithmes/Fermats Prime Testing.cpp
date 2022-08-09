long long modPower(int a, int n, int m){
    a = a % m;
    long long res = 1;

    while(n > 0){
        if(n & 1 != 0) res = (res * a) % m;
        a = ((long long)a * a) % m;
        n = n>>1;
    }        
    return res;
}

int isPrime(int N){
    if(N <= 1) return false;
    if(N <= 3) return true;
    if(N % 2 == 0) return false;

    int k = 1000;
    srand(time(NULL));
    while(k--){
        int a = 2 + rand() % (N - 3);
        if(modPower(a, N-1, N) != 1) return false;
    }
    return true;
}
