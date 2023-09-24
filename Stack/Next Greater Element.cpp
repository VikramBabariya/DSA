/*
TC: O(N)
SC: O(N)
*/

vector<long long> nextLargerElement(vector<long long> arr, int n){
    vector<long long> nge(n);
    stack<long long> st;
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && st.top() <= arr[i]) st.pop();
        if(st.empty()) nge[i] = -1;
        else nge[i] = st.top();
        st.push(arr[i]);
    }
    return nge;
}
