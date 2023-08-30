// recursive

int modPow(int x, int y, int m){
    if (y == 0)
        return 1;
    long long p = modPow(x, y / 2, m);
    p = (p * p) % m;
    
    if(y % 2 == 0) return p;
    return (p * x) % m;
}

// iterative
int modPow(int x, int y, int m){
    int ans = 1;
    for(int b = 0; b < 32; b++){
        if(y & (1<<b)) ans = (1ll * ans * x) % m;
        x = (1ll * x * x) % m;
    }
    return ans;
}

