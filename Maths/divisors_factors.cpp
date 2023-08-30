// O(sqrt(N))

void divisors(int n){
  int lim = sqrt(n);
  for(int i = 1; i <= lim; i++){
    if(n%i == 0){
      cout<<i<<endl;
      if(i != n/i) cout<<n/i<<endl;
    }
  }
}

// using prime factorization 

let x = p1^n1 * p2^n2 * p3^n3 ...

# of divisors of n = (n1+1) * (n2+1) * (n3+1) ...  // combination

sum of divisors = (1 + p1 + p1^2 + ... + p1^n) * (1 + p2 + p2^2 + ... + p2^n) * (1 + p3 + p3^2 + ... + p3^n)
                = use G.P formula

