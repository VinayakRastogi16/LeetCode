/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    let n = nums.length;

    let sum = n*(n+1)/2;
    let sum2 = 0;
    for(const num of nums){
        sum2 += num;
    }

    return sum-sum2;

};