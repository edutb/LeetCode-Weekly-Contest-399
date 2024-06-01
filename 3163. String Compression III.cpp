class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int len = 0;
        for(int i = 0; i < word.size(); i+=len){
            len = 1;
            for( ; i + len < word.size() && word[i+len] == word[i] && len + 1 <=9; len++);
            ans+=(to_string(len)+word[i]);
        }
        
        return ans;
    }
};