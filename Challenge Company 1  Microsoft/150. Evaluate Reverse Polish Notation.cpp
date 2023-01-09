class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<long long> st;
        for(auto i:tokens){
            if(i=="+"||i=="-"||i=="*"||i=="/"){
                long long a = st.top(); st.pop();
                long long b = st.top(); st.pop();
                if(i=="+") b+=a;
                else if(i=="-") b-=a;
                else if(i=="*") b*=a;
                else b/=a;
                st.push(b);
            }else{
                long long temp = (long long)stoi(i);
                st.push(temp);
            }
        }
        return st.top();
    }
};
