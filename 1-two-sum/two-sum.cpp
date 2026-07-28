class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        int s = v.size();

        for(int i = 0; i <= s - 1; i++) {
            for(int j = i + 1; j < s; j++) {
                if(v[i] + v[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};  
    }
};