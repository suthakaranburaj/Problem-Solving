class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long small = INT_MAX;
        long long big = INT_MIN;

        for(int i =0; i<nums.size(); i++){
            if(nums[i] > big){
                big = nums[i];
            }
            if(nums[i] < small){
                small = nums[i];
            }
        }
        return (big - small)*k;
    }
};