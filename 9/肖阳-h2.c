int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b); // Ascending order
}
void sortColors(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),cmp);
}