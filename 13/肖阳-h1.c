/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
 void help(struct TreeNode *root,int ans[],int*count){
    if(root==NULL) return;
    else{
        help(root->left,ans,count);
    ans[*count]=root->val;
    (*count)++;
    help(root->right,ans,count);

    }
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int countNodes = 0;
    struct TreeNode* node;
    struct TreeNode** stack = NULL;
    int stackSize = 0;
    node = root;
    while (node!= NULL || stackSize > 0) {
        while (node!= NULL) {
            stack = (struct TreeNode**)realloc(stack, (stackSize + 1) * sizeof(struct TreeNode*));
            stack[stackSize++] = node;
            node = node->left;
        }
        node = stack[--stackSize];
        countNodes++;
        node = node->right;
    }//向左走到头，将叶节点入栈，然后向右走到头，出栈，直到栈空，返回结果
    int *ans=(int*)malloc(sizeof(int)* countNodes);
    int count=0;
    help(root,ans,&count);
    *returnSize=countNodes;
    return ans;
}
