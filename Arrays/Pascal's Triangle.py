# var 1 TC : O(n^2)

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans = []
        ans.append([1]*1)
        
        for i in range(1, numRows):
            temp = []
            temp.append(1)
            for j in range(1, len(ans[i-1])):
                temp.append(ans[i-1][j] + ans[i-1][j-1])
            temp.append(1)
            ans.append(temp)
            
        return ans
      
   # var 2 --- given row number and col number, return number on that potition.
  # soln --- r-1 C c-1 (combination) TC : O(1)
      
   # var 3 --- given row number, return that row only
  #soln --- combination in loop. TC : O(n)
