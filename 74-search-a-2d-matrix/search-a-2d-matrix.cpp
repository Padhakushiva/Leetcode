class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0; i<matrix.size(); i++){
            if(matrix[i][0]<=target &&  target<=matrix[i][matrix[i].size() - 1]){
                int low=0;
                int high=matrix[i].size()-1;
                while(low<=high){
                    int mid=low+(high-low)/2;
                    if(matrix[i][mid]==target){
                        return true;
                    }
                    else if(matrix[i][mid]>target){
                        high=mid-1;
                    }
                    else{
                        low=mid+1;
                    }
                }
            }
        }
        return false;
    }
};