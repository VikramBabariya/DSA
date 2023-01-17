/*

Here Window Size is not fixed.(we need to minimize or maximaize it)
Here some condition(sum) is geven.
*/

// general format

int i = 0, j = 0;

while(j < n){
  //calculation
  if(cond < k) j++;
  else if(cond == k){
    //ans from calculation
    j++;
  }
  else if(cond > k){
    while(cond  > k){
      //remove calculation for i
      i++;
    }
    j++;
  }
  return ans;
}

