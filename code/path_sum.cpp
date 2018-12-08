#include "base.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<int> path;
        vector<vector<int> > result;
        if (root == NULL) return result;
        traverse(root, sum, path, result);
        return result;
    }
    
    void traverse(TreeNode *root, int sum, vector<int> &path, vector<vector<int> > &result){
        if (root->val == sum && root->left == NULL && root->right == NULL){
            path.push_back(root->val);
            result.push_back(path);
            path.pop_back();
        }else {
            path.push_back(root->val);
            sum -= root->val;
            if (root->left) traverse(root->left, sum, path, result);
            if (root->right) traverse(root->right, sum, path, result);
            path.pop_back();
        }
    }
};

int main()
{
	return 0;
}
