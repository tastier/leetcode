class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        
        for(int i = 0; i < nums.size() - 2; ++i){
            if( i > 0 && nums[i] == nums[i-1] )
                continue;
            for(int j = i + 1, k = nums.size() - 1; j < k; ){
                int sum = nums[i] + nums[j] + nums[k];
                closest = abs(closest - target) > abs(sum - target) ? sum : closest;
                if(sum < target){
                    ++j;
                    while(nums[j] == nums[j-1])
                        ++j;
                }
                else if(sum > target){
                    --k;
                    while( nums[k] == nums[k+1] )
                        --k;
                }
                else 
                    return target;
            }
        }
        return closest;
    }
};
