class Solution {
private:
    //�Ҹ�
    int findParent(vector<int>& p,int i) {
        while (p[i] != i){
            //�ҵ�ͬʱѹ��
            p[i] = p[p[i]];
            i = p[i];
        }
        return i;
    }
    //�ϲ�
    void unionSet(vector<int>& p,int i, int j) {
        int l = findParent(p, i);
        int r = findParent(p, j);
        p[r] = l;
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
        int size = M.size();
        vector<int> parent(size);
        //��ʼ��
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < size; i++) {
            for (int j = i +1; j < size; j++) {
                //�ϲ����ѹ�ϵ
                if (M[i][j])
                    unionSet(parent,i,j);
            }
        }
        int count = 0;
        //ͬһ�����Ѽ�����ֻ��һ���Ǳ����±�i�͸�parent[i]��һ�µ�
        for (int i = 0; i < size; i++) {
            if (parent[i] == i) {
                count++;
            }
        }
        return count;
    }
};