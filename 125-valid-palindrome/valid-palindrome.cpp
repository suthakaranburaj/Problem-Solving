class Solution {
public:
    string convert(string &s){
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                s[i] = s[i] - 'A' + 'a';
            }
        }
        return s;
    }
    bool isPalindrome(string s) {
        s = convert(s);
        int i=0;
        int j = s.size()-1;
        while(i<j){
            if(s[i] == ' '){
                i++;
            }
            else if( s[j] == ' '){
                j--;
            }
            else if(!isalnum(s[i])){
                i++;
            }
            else if(!isalnum(s[j])){
                j--;
            }
            else if(s[i] != s[j]){
                return false;
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
};