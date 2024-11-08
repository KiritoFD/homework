int cmp(const void *a, const void *b) {
    int arg1 = *(int *)a;
    int arg2 = *(int *)b;
    
    if (arg1 > arg2) return -1;
    if (arg1 < arg2) return 1;
    return 0;
}

int thirdMax(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),cmp);
    int count=1,q;
    for(int i=1;i<=numsSize-1;i++)
    {
        if(nums[i]!=nums[i-1]){
            count++;
        }
        if(count==3) {
            q=i;
            break;
        }
    }if(count<3) return nums[0];
    return nums[q];
}