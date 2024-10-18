class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0,ans=0;
        for(auto i : nums) maxi = maxi|i;
        int n = nums.size();
        for(int i = 0;i<pow(2,n);i++){
            int aur = 0;
            for(int j=0;j<n;j++){
                if((i>>j)&1){
                    aur = aur | nums[j];
                }
            }
            if(aur==maxi)ans++;
        }
        return ans;
    }
};