/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 typedef struct{
    int num;
    int count;
 } Element;
int compare(const void* a, const void* b) {
    return ((Element*)b)->count - ((Element*)a)->count;  // Sort by frequency descending
}
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int *num=(int*)malloc(20001*sizeof(int));
    for(int i=0;i<numsSize;i++){
        num[nums[i]+10000]++;
    }
    Element* elements = (Element*)malloc(20001 * sizeof(Element));
    int count=0;
    for(int i=0;i<20000;i++){
        if(num[i]){
            elements[count].num=i-10000;
            elements[count].count=num[i];
            count++;
        }
    }

    qsort(elements, count, sizeof(Element), compare);
    int* ans = (int*)malloc(k * sizeof(int));
    *returnSize = k;
    for(int i=0;i<k;i++){
        ans[i]=elements[i].num;
    }return ans; 
}