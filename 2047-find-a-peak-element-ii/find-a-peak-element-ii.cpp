class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        int low = 0;
        int high = n - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            // mid column me maximum element ki row find karo
            int maxRow = 0;

            for (int i = 1; i < m; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }

            // current element
            int current = mat[maxRow][mid];

            // same row me left neighbor
            int left = -1;
            if (mid - 1 >= 0) {
                left = mat[maxRow][mid - 1];
            }

            // same row me right neighbor
            int right = -1;
            if (mid + 1 < n) {
                right = mat[maxRow][mid + 1];
            }

            // agar current left aur right dono se bada hai
            if (current > left && current > right) {
                return {maxRow, mid};
            }

            // agar left bada hai, left side me peak hoga
            else if (left > current) {
                high = mid - 1;
            }

            // agar right bada hai, right side me peak hoga
            else {
                low = mid + 1;
            }
        }

        return {-1, -1};
    }
};