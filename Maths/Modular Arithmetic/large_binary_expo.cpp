// case: if x is very large or m is very large --   x, m <= 1e18
// O(logN * logN)
long long  modPow(long long x, int y, long long m){
    x = x % m; // to handle large x
    long long ans = 1;
    for(int b = 0; b < 32; b++){
        if(y & (1<<b)) ans = binary_multiplication(ans, x, m);
        x = binary_multiplication(x, x, m);
    }
    return ans;
}

// to multiply two large numberes (x * y) % m ; x, y, m <= 1e18
// O(logN)
long long binary_multiplication(long long x, long long y, long long m){
    long long ans = 0;
    for(int b = 0; b < 64; b++){
        if(y & (1ll<<b)) ans = (ans + x) % m;
        x = (x + x) % m;
    }
    return ans;
} 

