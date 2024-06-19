#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        
        stack<char> st;
        for (char c : s) {
            st.push(c);
            if (st.size() >= 3) {
                char third = st.top(); st.pop();
                char second = st.top(); st.pop();
                char first = st.top(); st.pop();
                if (first == 'b' && second == 'a' && third == 'b') {
                    st.push('a');
                } else {
                    st.push(first);
                    st.push(second);
                    st.push(third);
                }
            }
        }
        
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        
        cout << result << endl;
    }
    
    return 0;
}
