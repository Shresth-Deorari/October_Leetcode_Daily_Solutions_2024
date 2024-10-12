class Solution {
    static bool comp(vector<int>& a, vector<int>& b){
        return a[0]<b[0];
    }
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),comp);
        int ans = 0, i = 0;
        priority_queue<int,vector<int>,greater<int>>pq;
        while(i<n){
            while(!pq.empty() && pq.top() < intervals[i][0])pq.pop();
            pq.push(intervals[i++][1]);
            ans = max(ans,(int)pq.size());
        }
        return ans;
    }
};