class Solution {
public:

    bool isvowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
            return true;
        }
        else{
            return false;
        }
    }
    string sortVowels(string s) {
        vector<char>vowels;
        for(char c:s){
            if(isvowel(c)){
                vowels.push_back(c);
            }
        }
        sort(vowels.begin(), vowels.end());
        int j=0;
        for(int i=0; i<s.size(); i++){
            if(isvowel(s[i])){
                s[i]=vowels[j++];
            }
        }
        return s;
    }
};