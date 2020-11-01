class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int index = 0;
        int flag = 1;
        //消除前面空格
        while (index < n){
            if (s[index] != ' ')
                break;
            index++;
        }
        //提前结束
        if (index == n) {
            return 0;
        }
        //确认符号
        if (s[index] == '+'){
            index++;
        }
        else if(s[index] == '-'){
            index++;
            flag = -1;
        }
        int res = 0;
        while (index < n && '0' <= s[index] && s[index] <= '9') {
            //不能超出最大最小值
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && (s[index] - '0') > INT_MAX % 10)) {
                return INT_MAX;
            }
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && (s[index] - '0') > -(INT_MIN % 10))) {
                return INT_MIN;
            }
            res = res * 10 + flag * (s[index] - '0');
            index++;
        }
        return res;
    }
};
