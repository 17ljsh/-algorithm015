学习笔记

单词搜索2的时间复杂度分析
1.使用trie建立前缀树，插入时时间复杂度为
	假设有m个单词，所有单词中最大长度为k。
	时间复杂度T <= O(m*k)
2.对于board的N*N矩阵，每一个字母都需要判断是否是前缀，时间复杂度为O(N*N),
	接着，对每一层的遍历，需要判断选用该字母之后是否仍为前缀，这是O(1)数量级
	在极端情况下，当前字母向四联通扩散时没满足前缀，时间复杂度为O(4)
	再继续极端，每个字母长度都是k，因此总时间复杂度为O(N*N*4^k).
	------------------
	写完之后去看了官方题解，时间复杂度为O(N*N*4*3^(k-1)),第一次时往四周扩散，之后可以减少往上一步的位置扩散。
	------------------

双向bfs模板
void doublebfs(Node* root,Node* base) {
  map<int, int> visited;
  if(!root && !base) return ;

  queue<Node*> rootqueue;
  queue<Node*> basequeue;
  rootqueue.push(root);
  basequeue.push(base);
  
  int rlevel = 0;
  int blevel = 0;
  while (!rootqueue.empty() || !basequeue.empty() {
    //从头部遍历
	int rsize = rootqueue.size();
	rlevel = rsize > 0? rlevel+1: rlevel;
	for (int i = 0; i < rsize; i++) {
		Node* node = rootqueue.top();
		rootqueue.pop();
		
		//visited : 0:未遍历， 1：从root开始遍历的， 2：从base开始遍历的
		if (visited[node->val] == 1) continue;
		if (visited[node->val] == 2) { //相遇
			//process
			//...
			return;
		}
		visited[node->val] = 1;

		for (int i = 0; i < node->children.size(); ++i) {
			rootqueue.push(node->children[i]);
		}
	}
	
	//从底部遍历
	int bsize = basequeue.size();
	blevel = bsize > 0? blevel+1: blevel;
	for (int i = 0; i < bsize; i++) {
		Node* node = basequeue.top();
		basequeue.pop();
		
		//visited : 0:未遍历， 1：从root开始遍历的， 2：从base开始遍历的
		if (visited[node->val] == 2) continue;
		if (visited[node->val] == 1) { //相遇
			//process
			//...
			return;
		}
		visited[node->val] = 2;

		for (int i = 0; i < node->children.size(); ++i) {
			basequeue.push(node->children[i]);
		}
	}
  }
  return ;
}