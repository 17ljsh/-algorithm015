class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if (!size) {
            return {};
        }
        vector<vector<int>> res;
        //受大佬启发，对数组排序，能合并的一定连续
        sort(intervals.begin(),intervals.end());
        //思路
        //如[a,b] [c,d] [e,f]这样的数据，若[a,b] [c,d]可合并，需满足b>=c,合并后为[a,max(b,d)].

        //初始化最开始的区间
        int left = intervals[0][0], right = intervals[0][1];
        for (int i = 0; i < size; i++) {
            //[a,b] [c,d],当b >= c的时候执行
            if (right >= intervals[i][0]) {
                right = max(right, intervals[i][1]);
            }
            else {
                //[a,b] [c,d],b < c,即可放入最终结果
                res.push_back({left,right});
                //更新当前区间
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        //注意这里还有最后一个区间需要放进去。
        res.push_back({left,right});
        return res;
    }
};