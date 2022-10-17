
//snow ball concept
public void moveZeroes(int[] nums) {
    int snowBallSize = 0; 
    for (int i=0;i<nums.length;i++){
      if (nums[i]==0){
            snowBallSize++; 
        }
        else if (snowBallSize > 0) {
          int t = nums[i];
          nums[i]=0;
          nums[i-snowBallSize]=t;
        }
    }
}

//sol2
void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int replace = 0, zeros = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] == 0){
            zeros++;
        }else{
            swap(nums[replace], nums[i]);
            replace++;
        }
    }
    for(int i = n-1; zeros > 0; i--, zeros--){
        nums[i] = 0;
    }
}
