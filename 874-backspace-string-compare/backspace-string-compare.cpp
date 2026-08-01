class Solution {
public:
    string build(string s){
        string newstring;
        for(char ch: s){
            if(ch != '#'){
                newstring.push_back(ch);
            }
            else if(!newstring.empty()){
                newstring.pop_back();
            }
        }
        return newstring;
    }
    bool backspaceCompare(string s, string t) {
        return build(s)==build(t);
    }
};