class Solution {
public:
    int longestPalindrome(string s) {
        int lower[26] = {0};
        int higher[26] = {0};

        for(char ch : s) {
            if(ch >= 'a' && ch <= 'z')
                lower[ch - 'a']++;
            else
                higher[ch - 'A']++;
        }

        int count = 0;
        bool odd = false;

        for(int i = 0; i < 26; i++) {

            if(lower[i] % 2 == 0)
                count += lower[i];
            else {
                count += lower[i] - 1;
                odd = true;
            }

            if(higher[i] % 2 == 0)
                count += higher[i];
            else {
                count += higher[i] - 1;
                odd = true;
            }
        }

        if(odd) count++;

        return count;
    }
};