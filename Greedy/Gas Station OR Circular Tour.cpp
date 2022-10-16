class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tankFuel = 0, need = 0, start = 0;
        
        for(int i = 0; i < n; i++){
            tankFuel += gas[i];
            if(tankFuel >= cost[i]){
                tankFuel = tankFuel - cost[i];
            }else{
                need += cost[i] - tankFuel;
                tankFuel = 0;
                start = i+1;
            }
        }
        if(tankFuel >= need) return start;
        else return -1;
    }
};
