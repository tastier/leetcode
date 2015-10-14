class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
//        map<int,int> m; //20ms
        unordered_map<int,int> m; // hash map
        vector<int> vec;

        for(int i = 0; i != nums.size(); ++i){
//            if(nums[i] > target) continue;
            int tmp = target - nums[i];
            if( m.find( tmp ) != m.end() ) {
                vec.push_back( m[tmp] + 1);
                vec.push_back( i + 1 );
                break;
            }
            m.insert( {nums[i], i} );
        }
        return vec;
    }
};
