class Solution {
public:
    int find_ans(vector<int>&a_s_t, vector<int>&a_d, vector<int>&b_s_t, vector<int>&b_d){
        int mini = INT_MAX;
        for(int i = 0;i<a_s_t.size();i++){
            mini = min(mini,a_s_t[i] + a_d[i]);
        }

        int ans = INT_MAX;
        for(int i = 0;i<b_s_t.size();i++){
            ans = min(ans,max(mini, b_s_t[i]) + b_d[i]);
        }

        return ans;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
            return min(
                find_ans(landStartTime,landDuration,waterStartTime,waterDuration),
                find_ans(waterStartTime,waterDuration,landStartTime,landDuration)
                );
    }
};