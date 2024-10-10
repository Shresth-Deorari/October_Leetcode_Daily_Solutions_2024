class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int maxWidth = 0;
        stack<int>stackMin;
        for(int i = 0;i<nums.size();i++){
            if(stackMin.empty() || nums[stackMin.top()]>nums[i]){
                stackMin.push(i);
            }
        }

        for(int i = nums.size()-1;i>=0;i--){
            while(!stackMin.empty() && nums[stackMin.top()] <= nums[i]){
                maxWidth = max(maxWidth,i-stackMin.top());
                stackMin.pop();
            }
        }
        return maxWidth;
    }
};