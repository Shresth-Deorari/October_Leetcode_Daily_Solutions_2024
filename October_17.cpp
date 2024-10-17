class Solution {
public:
    int maximumSwap(int num) {
        string start = to_string(num);
        map<char,int>mp;
        for(int i = 0;i<start.size();i++){
            mp[start[i]] = i;
        }
        bool stop = false;
        char swap_char = '0';
        int swap_ind = 0;
        int swap_with = 0;
        for(int i= 0;i<start.size();i++){
            char ch = start[i];
            for(auto it : mp){
                if(it.first>ch && it.second>i && it.first>swap_char){
                    stop = true;
                    swap_ind = i;
                    swap_char = it.first;
                    swap_with = it.second;
                }
            }
            if(stop){
                swap(start[swap_ind],start[swap_with]);
                break;
            }
        }
        return stoi(start);
    }
};