class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        if(n <= 2)
            return 0;

        vector<int> lm(n);
        vector<int> rm(n);

        // -------------------------
        // Left Maximum using Stack
        // -------------------------
        stack<int> st;

        lm[0] = 0;

        for(int i = 0; i < n; i++) {

            if(i == 0) {
                lm[i] = 0;
            }
            else {
                lm[i] = st.top();
            }

            if(st.empty() || height[i] > st.top()) {
                st.push(height[i]);
            }
        }

        // Clear stack
        while(!st.empty()) {
            st.pop();
        }

        // --------------------------
        // Right Maximum using Stack
        // --------------------------
        rm[n - 1] = 0;

        for(int i = n - 1; i >= 0; i--) {

            if(i == n - 1) {
                rm[i] = 0;
            }
            else {
                rm[i] = st.top();
            }

            if(st.empty() || height[i] > st.top()) {
                st.push(height[i]);
            }
        }

        int water = 0;

        for(int i = 0; i < n; i++) {

            int waterHeight = min(lm[i], rm[i]) - height[i];

            if(waterHeight > 0) {
                water += waterHeight;
            }
        }

        return water;
    }
};