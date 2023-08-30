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
