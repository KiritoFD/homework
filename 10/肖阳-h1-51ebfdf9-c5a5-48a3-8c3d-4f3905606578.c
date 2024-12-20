/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 int count;
 void dfs(int *nums,int numsSize,int depth,int *current,bool *used,int **res){
    if(depth==numsSize){
        res[count]=(int*)malloc(sizeof(int)*numsSize);
        memcpy(res[count++],current,numsSize*sizeof(int));
        return;
    }
    for(int i=0;i<numsSize;i++){
        if(used[i]) continue;
        current[depth]=nums[i];
        used[i]=true;
        dfs(nums,numsSize,depth+1,current,used,res);
        used[i]=false;
    }
 }
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int s=1;
    for(int i=1;i<=numsSize;i++) s*=i;
    int **res=(int**)malloc(s*sizeof(int*));
    bool *used=(bool*)malloc(numsSize*sizeof(bool));
    memset(used,0,numsSize*sizeof(bool));
    int *current=(int*)malloc(numsSize*sizeof(int));
    count=0;
    dfs(nums,numsSize,0,current,used,res);
    *returnSize=s;
    *returnColumnSizes=(int*)malloc(s*sizeof(int));
    for(int i=0;i<s;i++) (*returnColumnSizes)[i]=numsSize;
    return res;
}
