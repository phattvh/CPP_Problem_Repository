//Author: Phat Tran
//All my info: https://phattvh.is-not-a.dev


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int cp;

        for(int i = 0; i < nums.size(); i++){
            cp = target - nums[i];
        
            if (mp.find(cp) != mp.end()) return {mp[cp], i};
                else mp[nums[i]] = i;  
        
        }
        
        return{};

    }
};

//su dung mang bam (unordered_map) luu cac so di qua

//cac buoc:
//1. khoi tao map (mp) (gia tri:index)
//2. for 1 -> n, tai moi nums[i]:
//   - tim gtri con thieu de khi +i = target: cp = target - nums[i]
//   - check trong mp, neu thay tra ve {mp[cp], i}, neu khong thi luu mp[nums[i]] = i
