class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // key = number from array
        // value = the index where that number was found
        unordered_map<int,int> numMap;

        for(int i = 0; i < nums.size(); i++)
        {
            // calculate the difference
            // the difference is needed to reach the target
            int difference = target - nums[i];
            // the difference is what we need

            // check if difference exist in the map. 
            if(numMap.count(difference))
            {   
                // if the needed number does exist in the map
                // return the 2 indices.
                return{numMap[difference],i};
            }

            // update the hashmap.
            // number wasn't found so store the current number
            // and its index so other numbers later on can match with it. 
            numMap[nums[i]] = i;
        }
        // return nothing when no two numbers can reach target.
        return {};
    }
};
