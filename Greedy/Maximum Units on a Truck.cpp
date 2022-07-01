// approach 1 - using comprision sorting

static bool comp(vector<int> &v1, vector<int> &v2){
    return v1[1] > v2[1];
}

int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    int n = boxTypes.size();
    sort(boxTypes.begin(), boxTypes.end(), comp);

    int ans = 0;
    for(auto box : boxTypes){
        int minBox = min(box[0], truckSize);
        int unit = minBox * box[1];
        truckSize -= minBox;
        ans += unit;

        if(truckSize == 0) break;
    }
    return ans;
}

// approach 2 -- using count sort

int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    int freq[1001]{0}, maxUnits = 0;   // freq[i] = number of boxes that can hold i units
    for(auto& box : boxTypes) freq[box[1]] += box[0];
    // greedily choose starting from max units till either truckSize runs out or you choose all boxes
    for(int units = 1000; truckSize > 0 && units >= 0; --units) { 
        maxUnits += min(truckSize, freq[units]) * units;
        truckSize -= freq[units];
    }
    return maxUnits;
}
