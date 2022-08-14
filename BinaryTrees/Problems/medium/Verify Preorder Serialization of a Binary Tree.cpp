bool isValidSerialization(string pre) {
    stack<char> st;
    stringstream ss(pre);
    string s;
    while(getline(ss, s, ',')){
        st.push(s[0]);

        while(st.size() >= 3 && st.top() == '#'){
            st.pop(); 
            if(st.top() == '#'){
                st.pop();
                if(st.top() == '#') return false;
                st.pop(); st.push('#');
            }else{
                st.push('#'); break;
            }
        } 
    }
    return st.size() == 1 && st.top() == '#';
}
