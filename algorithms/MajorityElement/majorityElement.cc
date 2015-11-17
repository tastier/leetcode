class Solution {
public:
    int majorityElement(vector<int>& nums) {
/*
        unordered_map<int, unsigned int> m;
        for(int i = 0; i != nums.size(); ++i){
            ++m[nums[i]];
        }
        unordered_map<int, unsigned int>::iterator it, maj;
        for(it = m.begin(), maj = m.begin(); it != m.end(); ++it){
            maj = it->second > maj->second ? it : maj;
        }
        return maj->first;
*/
        int majority;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(cnt == 0){
                majority = nums[i];
                ++cnt;
            }
            else{
                majority == nums[i] ? ++cnt : --cnt;
                if(cnt > nums.size()/2) 
                    return majority;
            }
        }
        return majority;
    }
};
