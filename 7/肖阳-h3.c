int cmp(const void *a, const void *b) {
    int arg1 = *(int *)a;
    int arg2 = *(int *)b;
    
    if (arg1 > arg2) return -1;
    if (arg1 < arg2) return 1;
    return 0;
}
int majorityElement(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),cmp);
    int count=1,max=1,p;
    for(int i=1;i<numsSize;i++){
        if(nums[i]==nums[i-1]){
            count++;
            if(count>max){
                max=count;
                p=i;
            }
        }else count=1;
    }return nums[p];
}