#define ll long long
class Solution {

    bool canCreate(vector<int>& bday, ll thsd, int m, int k){
        ll buck = 0, temp = 0;
        for(auto &bd: bday){
            if(bd > thsd) temp = 0;
            else temp++;
            
            if(temp == k){
                buck++;
                temp = 0;
            }
        }
        return buck >= m;
    }

public:
    int minDays(vector<int>& bday, int m, int k) {
        if((ll)m*k > bday.size()) return -1;

        ll l = 1, r = *max_element(begin(bday), end(bday));
        while(l <= r){
            ll mid = (l+r)/2;
            if(canCreate(bday, mid, m, k)){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
};
