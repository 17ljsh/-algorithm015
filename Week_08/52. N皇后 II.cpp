class Solution {
private:
    int count = 0;
    void hleper(int n, int row, int cols, int pie, int na) {
        //��������
        if (row >= n) {
            count++;
            return;
        }
                  //�У�Ʋ�����Ӧ���ж����ܷ� 
        int bits = (~(cols | pie | na)) & ((1 << n) - 1);//((1 << n) - 1)���������nǰ���λ��n���ô���32
        while (bits > 0) {
            int p = bits & (-bits); //ȡ�����λ��1
            //cols,pie,na���б仯
            hleper(n, row + 1, cols | p, (pie | p) << 1, (na | p) >> 1);
            //ȥ�����λ��1
            bits -= p;
        }
    }
public:
    int totalNQueens(int n) {
        hleper(n,0,0,0,0);
        return count;
    }
};