int rob(int* nums, int numsSize) {
   int rob_first;
   int not_rob_first;
   
   if (numsSize <= 0) {
       return 0;
   }
   
   if (numsSize == 1) {
       return nums[0];
   } 
   
   rob_first  = nums[0] + rob(&nums[2], numsSize - 2);
   not_rob_first = rob(&nums[1], numsSize - 1);
   if (rob_first > not_rob_first) {
       return rob_first;
   } else {
       return not_rob_first;
   }
}
