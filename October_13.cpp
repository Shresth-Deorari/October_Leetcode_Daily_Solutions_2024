class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>sizes(k);
        vector<int>indices(k);
        int mini = INT_MAX,maxi = INT_MIN;
        for(int i = 0;i<k;i++){
            sizes[i] = nums[i].size();
            pq.push({nums[i][0],i});
            mini = min(mini,nums[i][0]);
            maxi = max(maxi,nums[i][0]);
        }
        vector<int>ans(2,0);
        ans[0] = mini;
        ans[1] = maxi;
        while(1){
            int remove = pq.top().second;
            pq.pop();
            indices[remove]++;
            if(indices[remove]==sizes[remove])break;
            int next = nums[remove][indices[remove]];
            pq.push({next,remove});
            mini = pq.top().first;
            maxi = max(maxi,next);
            if(maxi-mini < ans[1]-ans[0]){
                ans[0] = mini;
                ans[1] = maxi;
            }
        }
        return ans;
    }
};