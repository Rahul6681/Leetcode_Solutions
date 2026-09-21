class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        long long curr_number = 0;
        long long result = 0;
        int sign = 1;

        for(int i = 0; i < s.length(); ++i){
            char c = s[i];

            if(isdigit(c)){
                curr_number = curr_number * 10 + (c - '0');
            }
            else if(c == '+'){
                result += sign * curr_number;
                curr_number = 0;
                sign = 1; 
            }
            else if(c == '-'){
                result += sign * curr_number;
                curr_number = 0;
                sign = -1;
            }else if(c == '('){
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            }
            else if(c == ')'){
                result += sign * curr_number;
                curr_number = 0;

                int prev_sign = st.top();
                st.pop();

                long long prev_result = st.top();
                st.pop();
                
                result = prev_result + prev_sign * result;
            }
        }
        result += sign * curr_number;
        return result;
    }
};