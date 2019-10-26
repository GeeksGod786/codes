/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> fun(int s,int e)
    {
        vector<TreeNode*> list;
        if(s>e)
        {
            list.push_back(NULL);
            return list;
        }
        
        for(int i=s;i<=e;i++)
        {
            vector<TreeNode*> l_sub=fun(s,i-1);
            vector<TreeNode*> r_sub=fun(i+1,e);
            for(int j=0;j<l_sub.size();j++)
            {
                TreeNode *left=l_sub[j];
                for(int k=0;k<r_sub.size();k++)
                {
                    TreeNode *right=r_sub[k];
                    TreeNode *node=new TreeNode(i);
                    node->left=left;
                    node->right=right;
                    list.push_back(node);
                }
            }
        }
       return list; 
        
    }
    vector<TreeNode*> generateTrees(int n) {
        
        vector<TreeNode*>ans;
        if(n==0)
            return ans;
        
        return fun(1,n);
    }
};