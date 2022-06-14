  double multiply(double num, int n){
    double ans = num;
    for(int i = 1; i < n; ++i){
      ans *= num;
    } 
    return ans;
  }

  double bs(int val, int n){
          double l = 0, r = val;
          double eps = 1e-6;

          while((r - l) > eps){
              double mid = (l + r)/2;
              if(multiply(mid, n) > val) r = mid;
              else l = mid;
          }
          return r;
  }
