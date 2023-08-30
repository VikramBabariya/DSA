int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b){
  int g = gcd(a, b);
  long long mul = (long long)a * b;
  return mul/g;
}
