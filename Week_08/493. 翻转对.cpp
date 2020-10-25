class Solution {
public:
    int mergeSort(vector<int>& nums, vector<int>& temp, int left, int right) {
        //递归终止条件
        if (left >= right) return 0;

        //分治
        int mid = left + (right - left) / 2;
        // 先加上左右子数组的结果
        int res = mergeSort(nums, temp, left, mid) + mergeSort(nums, temp, mid + 1, right);

        // 然后记录左右子数组之间的结果
        int count = 0;
        int l = left, r = mid + 1;
        while (l <= mid) {
            if (r > right || (long)nums[l] <= 2 * (long)nums[r]) {
                res += count;
                l++;
            }
            else {
                r++;
                count++;
            }
        } 

        // 进行归并
        int index = 0;
        l = left;
        r = mid + 1;
        while (l <= mid && r <= right) {
            temp[index++] = nums[l] > nums[r]? nums[r++]: nums[l++];
        }
        //将剩余的追加在尾部
        while (l <= mid) temp[index++] = nums[l++];
        while (r <= right) temp[index++] = nums[r++];
        
        // 从临时数组复制到排序数组
        for (int i = left; i <= right; ++i) {
            nums[i] = temp[i - left];
        }
        return res;
    }
    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums.size(), 0);
        return mergeSort(nums, temp, 0, nums.size() - 1);
    }
};
