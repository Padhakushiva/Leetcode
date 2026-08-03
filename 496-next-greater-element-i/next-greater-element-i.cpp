class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans;

        for(int i : nums1){

            // Find index of i in nums2
            int idx = -1;

            for(int j = 0; j < nums2.size(); j++){
                if(nums2[j] == i){
                    idx = j;
                    break;
                }
            }

            // Find next greater element
            int greater = -1;

            for(int j = idx + 1; j < nums2.size(); j++){
                if(nums2[j] > i){
                    greater = nums2[j];
                    break;
                }
            }

            ans.push_back(greater);
        }

        return ans;
    }
};