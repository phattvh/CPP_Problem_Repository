//Author: Phat Tran
//All my info: https://phattvh.is-not-a.dev


class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int c = 0, idx1, idx2;

        while(true){
            if (is_sorted(nums.begin(), nums.end())) return c;

            int minn = 99999;

            for(int i = 0; i < nums.size() - 1; i += 1) if (nums[i] + nums[i + 1] < minn){
                idx1 = i;
                idx2 = i + 1;
                minn = nums[i] + nums[i + 1];
            }

            nums[idx1] = minn;
            nums.erase(nums.begin() + idx2);

            c += 1;
        }
    }
};

//y tuong
// 1. Kiem tra is_sorted, neu sorted return count
// 2. quet cac cap canh nhau, neu a[i] + a[i + 1] < minn luu i1, i2 & min
// 3. gop^ mang (i1 = min, erase i2)
