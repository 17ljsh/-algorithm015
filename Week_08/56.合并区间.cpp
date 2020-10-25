class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if (!size) {
            return {};
        }
        vector<vector<int>> res;
        //�ܴ��������������������ܺϲ���һ������
        sort(intervals.begin(),intervals.end());
        //˼·
        //��[a,b] [c,d] [e,f]���������ݣ���[a,b] [c,d]�ɺϲ���������b>=c,�ϲ���Ϊ[a,max(b,d)].

        //��ʼ���ʼ������
        int left = intervals[0][0], right = intervals[0][1];
        for (int i = 0; i < size; i++) {
            //[a,b] [c,d],��b >= c��ʱ��ִ��
            if (right >= intervals[i][0]) {
                right = max(right, intervals[i][1]);
            }
            else {
                //[a,b] [c,d],b < c,���ɷ������ս��
                res.push_back({left,right});
                //���µ�ǰ����
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        //ע�����ﻹ�����һ��������Ҫ�Ž�ȥ��
        res.push_back({left,right});
        return res;
    }
};