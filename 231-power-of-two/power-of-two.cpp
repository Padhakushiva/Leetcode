class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) {
            return false;
        }

        int count = 0;

        while(n >= 1) {
            if((n & 1) != 0) {
                count++;
            }

            n = n >> 1;
        }

        return count == 1;
    }
};