学习笔记
树的遍历有广度遍历和深度遍历，深度遍历包括前序，中序，后序三种。
遍历的主要实现方法有递归和迭代两种。用递归实现深度遍历比较简单，主要注意顺序就好。但用递归实现层次遍历也就是广度遍历有点难
我现在主要是讨论下用迭代的方法来实现，是否存在一套通用的模板。
vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        deque<TreeNode*> dq;
        TreeNode* rt = root;
        while (rt || !dq.empty()) {
            while (rt) {
                //（1）...
            }
            //（2）...
        }
        return res;
    }      
1.先序遍历
输出顺序是 根->左结点->右结点
这里有个方法 首先需要输出的就直接push到res中（当然时机要选好），不需入栈，而剩下的两个，由于rt是不断深入的条件，不需要入栈，所以只有右结点需要入栈
//（1）
while (rt || !dq.empty()) {
	while (rt) {
		res.push_back(rt->val);//从上面的根开始输出
		dq.push_front(rt);
		rt  = rt -> left;
}
//当找不到左孩子时，我们就要处理右孩子。需要优先处理的右孩子在栈顶
//（2）
rt = dq.front();
dq.pop_front();
rt = rt ->right;

2.中序遍历
输出顺序 左结点->根->右结点
和先序遍历类似，左结点不需要push
while (rt || dq.size()) {
	while (rt) {
		dq.push_front(rt);
		rt = rt->left;
	}
	rt = dq.front();
	dq.pop_front();
	res.push_back(rt->val);
	rt = rt ->right;
}
return res;
可以发现先序和中序就只有res.push_back(rt->val);的位置不同

3.后序遍历
输出顺序 左结点->右结点->根
//如果根是放在最后处理的话有点麻烦，但换一下思路，后序遍历的反向是 根->右结点->左结点，所以可以灵活地应用前序遍历的方法，最后再将输出顺序反转
代码：
while (rt || dq.size()) {
	while (rt) {
		dq.push_front(rt);
		res.push_back(rt->val);
		//rt = rt->left;
		rt = rt->right;
	}
	rt = dq.front();
	dq.pop_front();
	//rt = rt ->right;
	rt = rt ->left;
}
reverse(res.begin(),res.end());
return res;

核心语句不变，那么可以整合成以下代码
int flag = 2;//{0,1,2},0代表先序，1代表中序，2代表后续
vector<int> res;
deque<TreeNode*> dq;
TreeNode* rt = root;
while (rt || dq.size()) {
	while (rt) {
		dq.push_front(rt);
		if (flag != 1) { //这里只考虑0，1，2三种情况，没做容错处理
		res.push_back(rt->val);
		}		
		rt = flag == 2? rt->right: rt->left;
	}
	rt = dq.front();
	dq.pop_front();
	if (flag == 1) {
		res.push_back(rt->val);
		}
	rt = flag == 2? rt->left: rt->right;
}
if (flag == 2) {
	reverse(res.begin(),res.end());
}
return res;
经检测，在不同的遍历下，只需要改动flag就可以了，所有提交都是ac。
可能这个东西也没多大实际意义。因为递归的代码几行就可以写完了，我也是有兴趣就写一下而已。
另外，层次遍历因为输出格式不同，所以代码不同之处肯定更多，我就不写了。