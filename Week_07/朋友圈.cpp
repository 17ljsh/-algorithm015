class Solution {
private:
    //找根
    int findParent(vector<int>& p,int i) {
        while (p[i] != i){
            //找的同时压缩
            p[i] = p[p[i]];
            i = p[i];
        }
        return i;
    }
    //合并
    void unionSet(vector<int>& p,int i, int j) {
        int l = findParent(p, i);
        int r = findParent(p, j);
        p[r] = l;
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
        int size = M.size();
        vector<int> parent(size);
        //初始化
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < size; i++) {
            for (int j = i +1; j < size; j++) {
                //合并朋友关系
                if (M[i][j])
                    unionSet(parent,i,j);
            }
        }
        int count = 0;
        //同一个朋友集合总只有一个是本身下标i和根parent[i]是一致的
        for (int i = 0; i < size; i++) {
            if (parent[i] == i) {
                count++;
            }
        }
        return count;
    }
};