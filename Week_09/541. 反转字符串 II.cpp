class Solution {
public:
    string reverseStr(string s, int k) {
        int length = s.size();
        int start = 0;
        while (length > 0) {
            //大于2k和大于k可以合并操作
            if (length >= k ) {
                //反转起点开始的k个字符
                reverse(s.begin() + start, s.begin() + start + k);
                //更新长度和起点
                length -= 2*k;
                start += 2*k;
            }
            else if (length < k) {
                //反转剩下的
                reverse(s.begin() + start,s.end());
                length = 0;
            }
        }
        return s;
    }
};