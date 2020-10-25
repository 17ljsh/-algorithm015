class Solution {
public:
    int mergeSort(vector<int>& nums, vector<int>& temp, int left, int right) {
        //�ݹ���ֹ����
        if (left >= right) return 0;

        //����
        int mid = left + (right - left) / 2;
        // �ȼ�������������Ľ��
        int res = mergeSort(nums, temp, left, mid) + mergeSort(nums, temp, mid + 1, right);

        // Ȼ���¼����������֮��Ľ��
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

        // ���й鲢
        int index = 0;
        l = left;
        r = mid + 1;
        while (l <= mid && r <= right) {
            temp[index++] = nums[l] > nums[r]? nums[r++]: nums[l++];
        }
        //��ʣ���׷����β��
        while (l <= mid) temp[index++] = nums[l++];
        while (r <= right) temp[index++] = nums[r++];
        
        // ����ʱ���鸴�Ƶ���������
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
