class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans;

        for (int x : nums1) {

            int index = -1;
            for (int i = 0; i < nums2.size(); i++) {
                if (nums2[i] == x) {
                    index = i;
                    break;
                }
            }

            int nextGreater = -1;


            for (int i = index + 1; i < nums2.size(); i++) {
                if (nums2[i] > x) {
                    nextGreater = nums2[i];
                    break;
                }
            }

            ans.push_back(nextGreater);
        }

        return ans;
    }
};