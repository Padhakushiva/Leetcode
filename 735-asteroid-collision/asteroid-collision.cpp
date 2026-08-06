class Solution {
public:
    
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;
        for(int i=0; i<asteroids.size(); i++){
            if(asteroids[i]>0 || st.empty()){
                st.push(asteroids[i]);
            }

            else{
                while((!st.empty()&& st.top()>0 && abs(asteroids[i])>st.top() )){
                    st.pop();
                }

                if (st.empty() || st.top() < 0) {
                    st.push(asteroids[i]);
                }
                 else if (st.top() == abs(asteroids[i])) {

                    st.pop();

                }                
            }
        }

        while(!st.empty()){
                    ans.push_back(st.top());
                    st.pop();

                }
                reverse(ans.begin(), ans.end());
        return ans;
    }
};