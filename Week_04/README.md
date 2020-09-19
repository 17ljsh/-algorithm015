学习笔记
//C/C++
//dfs递归写法：
//对于没有环的数据结构，visited是没必要的
map<int, int> visited;

void dfs(Node* root) {
  // terminator
  if (!root) return ;

  if (visited.count(root->val)) {
    // already visited
    return ;
  }

  visited[root->val] = 1;

  // process current node here. 
  // ...
  //依次遍历所有孩子
  for (int i = 0; i < root->children.size(); ++i) {
    dfs(root->children[i]);
  }
  return ;
}

//C/C++
//dfs非递归写法：
void dfs(Node* root) {
  map<int, int> visited;
  if(!root) return ;

  stack<Node*> stackNode;
  stackNode.push(root);

  while (!stackNode.empty()) {
    Node* node = stackNode.top();
    stackNode.pop();
    if (visited.count(node->val)) continue;
    visited[node->val] = 1;

    //注意这里的放入输入是从右结点开始入栈
    for (int i = node->children.size() - 1; i >= 0; --i) {
        stackNode.push(node->children[i]);
    }
  }

  return ;
}

// C/C++
//bfs遍历
void bfs(Node* root) {
  map<int, int> visited;
  if(!root) return ;

  queue<Node*> queueNode;
  queueNode.push(root);

  while (!queueNode.empty()) {
    Node* node = queueNode.top();
    queueNode.pop();
    if (visited.count(node->val)) continue;
    visited[node->val] = 1;
	//队列是先进先出，所以依次放入孩子即可
    for (int i = 0; i < node->children.size(); ++i) {
        queueNode.push(node->children[i]);
    }
  }

  return ;
}

//C/C++
//二分查找
int binarySearch(const vector<int>& nums, int target) {
	//找出边界
	int left = 0, right = (int)nums.size()-1;
	
	//循环查找
	while (left <= right) {
		int mid = left + (right - left)/ 2;
		//判断是否找到目标
		if (nums[mid] == target) return mid;
		//考虑如何截枝
		else if (nums[mid] < target) left = mid + 1;
		else right = mid - 1;
	}
	
	return -1;
}

使用二分查找，寻找一个半有序数组 [4, 5, 6, 7, 0, 1, 2] 中间无序的地方
这个和找最小值是一样的。
若中间从i开始无序，那么nums[i]<nums[i-1]成立（i=0）除外。
所以，可以从1到size()-1查找，判定找到的条件就是nums[i]<nums[i-1]
截枝条件：
	1.nums[i]<nums[0],那么现在i在较小的部分，目标值在其左边，应往前搜索
	2.nums[i]>nums[0],
代码：
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low(1),high(nums.size() - 1);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            //目标值比它前一个要小（nums[0]另外处理）
            if (nums[mid] < nums[mid - 1]) {
                return nums[mid];
            }
            //mid在较小的右部，应往前搜索
            if (nums[mid] < nums[0]) {
                high = mid -1;
            }
            else {
                low = mid + 1;
            }
        }
        //没找着，即第一个就是最小的
        return nums[0];
    }
};