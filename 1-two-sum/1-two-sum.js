/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const mp = new Map() 
    const n = nums.length
    for(let i=0 ; i<n ; ++i){
        const toFind = target - nums[i] 
        const matchingValue = mp.get(toFind)
        if(matchingValue!==undefined){
            return [matchingValue,i]
        }
        mp.set(nums[i],i)
    }
};