class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        vector<int>ans;
        //0 10 14 22
        for(int i = 1;i<n;i++){
            left[i] = nums[i - 1] + left[i - 1];
        }
        //15 11 3 0
        for(int i = n - 2;i>=0;i--){
            right[i] = right[i+1] + nums[i + 1];
        }
        for(int i = 0;i<n;i++){
            ans.push_back(abs(left[i] - right[i]));
        }
        return ans;
    }
};