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

//  problems--  https://leetcode.com/problems/fruit-into-baskets/solutions/170740/java-c-python-sliding-window-for-k-elements/?orderBy=most_votes

// generel substring sw -- https://leetcode.com/problems/minimum-window-substring/solutions/26808/here-is-a-10-line-template-that-can-solve-most-substring-problems/?orderBy=most_votes

