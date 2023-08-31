(A * B) % M = 1 then B is a MMI of A. ; where A and M must be coprime( gcd(A, M) = 1)

// Brute TC : O(M)
int modMulInv(int a, int m){
  for(int i = 1; i < m; i++){
    if((a * i) % m == 1) return i;
  }
}


// Fermat's Thm : a^(m-1) cong 1 (mod m) ; m is prime and a is not a multiple of m
// a^(m-2) cong a^-1 (mod m) ; 

// TC : O(logM) ; works if m is prime
int modMulInv(int a, int m){
  return modPow(a, m-2, m);
}

int modPow(int x, int y, int m){
    int ans = 1;
    for(int b = 0; b < 32; b++){
        if(y & (1<<b)) ans = (1ll * ans * x) % m;
        x = (1ll * x * x) % m;
    }
    return ans;
}
