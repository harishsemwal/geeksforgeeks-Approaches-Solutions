class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word, ans = "";
        while(ss >> word){
            ans = word + " " + ans;
        }
        ans.pop_back();
        return ans;
    }
};
