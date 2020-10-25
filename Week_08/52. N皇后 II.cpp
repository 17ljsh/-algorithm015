class Solution {
private:
    int count = 0;
    void hleper(int n, int row, int cols, int pie, int na) {
        //满足条件
        if (row >= n) {
            count++;
            return;
        }
                  //列，撇，捺对应的列都不能放 
        int bits = (~(cols | pie | na)) & ((1 << n) - 1);//((1 << n) - 1)作用是清除n前面的位，n不得大于32
        while (bits > 0) {
            int p = bits & (-bits); //取得最低位的1
            //cols,pie,na都有变化
            hleper(n, row + 1, cols | p, (pie | p) << 1, (na | p) >> 1);
            //去掉最低位的1
            bits -= p;
        }
    }
public:
    int totalNQueens(int n) {
        hleper(n,0,0,0,0);
        return count;
    }
};