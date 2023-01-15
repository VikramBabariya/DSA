class Solution {

    bool isPos(vector<int> &st, double d, int k){
        int n = st.size();
        for(int i = 0; i < n-1; i++){
            if(st[i+1] - st[i] <= d) continue; // no need to create station
            double t1 = st[i], t2 = st[i+1], st, exit = 0;
            while(exit != 1){
                if(t2 - (t1 + d) > d) t1 = t1 + d;
                else exit = 1;
                if(!k) return false; // not inough resources
                k--;
            }
        }
        return true;
    }

public:
    double minmaxGasDist(vector<int> &st, int k) {
        double l = 0, r = 0, n = st.size();
        for(int i = 0; i < n-1; i++){
            double d = st[i+1] - st[i];
            if(d > r) r = d;
        }

        while((r-l) > 1e-6){
            cout<<l<<" "<<r<<endl;
            double mid = (l + r)/2;
            if(isPos(st, mid, k)) r = mid;
            else l = mid;
        }
        
        return l;
    }
};
