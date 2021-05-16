/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *        *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *         *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *          * };
 *           */
class Solution {
    public:
        int ans = 0;
        int cal_grand_child(TreeNode *node, int level)
        {
            int sum = 0;
            if (node == NULL)
                return sum;
            if (level == 0)
            {
                sum = node->val;
            }
            else
            {
                sum += cal_grand_child(node->left, 0);
                sum += cal_grand_child(node->right, 0);
            }
            return sum;
        }
        void cal(TreeNode *node)
        {
            int sum = 0;
            if (node == NULL)
            {
                return;
            }
            if (node->val % 2 == 0)
            {

                sum += cal_grand_child(node->left, 1);
                sum += cal_grand_child(node->right, 1);
            }
            ans += sum;
            cal(node->left);
            cal(node->right);
        }
        int sumEvenGrandparent(TreeNode* root) {

            cal(root);
            return ans;
        }
};
