class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<pair<int, int>> events;
        for (int i = 0; i < n; i++) {
            events.push_back({times[i][0], i}); 
        }

        sort(events.begin(), events.end());
        

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leavingQueue;
        

        set<int> availableChairs;
        for (int i = 0; i < n; i++) {
            availableChairs.insert(i);
        }
        

        for (auto& event : events) {
            int arrivalTime = event.first;
            int friendIndex = event.second;

            while (!leavingQueue.empty() && leavingQueue.top().first <= arrivalTime) {
                int freedChair = leavingQueue.top().second;
                leavingQueue.pop();
                availableChairs.insert(freedChair); 
            }
            
            int assignedChair = *availableChairs.begin();
            availableChairs.erase(availableChairs.begin());
            
            leavingQueue.push({times[friendIndex][1], assignedChair});
            
            if (friendIndex == targetFriend) {
                return assignedChair;
            }
        }
        
        return -1;
    }
};
