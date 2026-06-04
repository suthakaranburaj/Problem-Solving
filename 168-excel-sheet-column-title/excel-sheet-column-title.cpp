class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber){
            columnNumber--;
            ans= char((columnNumber%26)+'A')+ans;
            columnNumber= columnNumber/26;
        }
        return ans;
    }
};