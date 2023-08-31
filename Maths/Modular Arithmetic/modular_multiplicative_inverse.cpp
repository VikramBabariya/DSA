(A * B) % M = 1 then B is a MMI of A. ; where A and M must be coprime( gcd(A, M) = 1)

// Brute TC : O(M)
int modMulInv(int a, int m){
  for(int i = 1; i < m; i++){
    if((a * i) % m == 1) return i;
  }
}


Fermat's Thm : a^(m-1) cong 1 (mod m) ; m is prime and a is not a multiple of m
a^(m-2) cong a^-1 (mod m) ; 

// TC : O(logM)
int modMulInv(int a, int m){
  return binary_expo(a, m-2, m);
}
