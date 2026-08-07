class Solution {
public:

     vector<int> nextSmaller(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nse;
    }

    vector<int> previousSmaller(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return pse;
    }
    int largestRectangleArea(vector<int> & heights){
        int n = heights.size();

        vector<int> nse = nextSmaller(heights);
        vector<int> pse = previousSmaller(heights);

        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        vector<int> v(matrix[0].size(),0);
        int maxarea=0;

        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){

                if((matrix[i][j]) == '0' ){
                    v[j] = 0;
                }
                else
                    v[j]++;
                
            }
            maxarea=max(maxarea,largestRectangleArea(v));
        }
        return maxarea;
    }
};