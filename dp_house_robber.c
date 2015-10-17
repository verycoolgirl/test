int max(int a, int b) {
    if (a >= b) return a; 
    return b;
}

int rob(int* nums, int numsSize) {
int i;
if (numsSize <= 0) return 0;
if (numsSize == 1) return nums[0];
if (numsSize >= 3) nums[2] += nums[0];
for (i = 3; i < numsSize; i++) {
    nums[i] += max(nums[i-2], nums[i-3]);
}

return max(nums[numsSize-1], nums[numsSize-2]);
}
