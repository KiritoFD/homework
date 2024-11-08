void moveZeroes(int* nums, int numsSize) {
    int i=0,count=0;for(i;i<numsSize;i++){
        if(nums[i]!=0) {
            nums[count]=nums[i];
            count++;
        }
    }
    for(i=count;i<numsSize;i++) {
        nums[i]=0;
    }
}