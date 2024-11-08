int removeDuplicates(int* nums, int numsSize) {
    int count=0;
    for(int i=1;i<numsSize;i++){
        if(nums[i]!=nums[i-1]){
            count++;
            nums[count]=nums[i];
        }
    }return count+1;
}