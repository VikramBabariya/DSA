Some basic constraints and the safe time complexity :
---
| N | Big Oh |
|-----|------|
|For N <= 11  | O(N!) |
|For N <= 20 | O(2^N)(Recursion) |
|For N <= 100 | O(N^4) |
|For N <= 500 | O(N^3) |
|For N <= 10^4 | O(N^2) |
|For N <= 10^6 | O(N*Log(N))(sorting) |
|For N <= 10^8 | O(N) |
|For N >= 10^9 | O(Log(N)(Binary Search)) |
---

## Debug Your Code

1. Custom Input + Logic Checking from Dry Run
2. Print stmt for every logical segment
3. Stub the functions(segments)
4. Commenting and Uncommenting to handle Segmentaion Fault
