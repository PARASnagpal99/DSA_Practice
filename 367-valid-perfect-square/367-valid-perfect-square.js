/**
 * @param {number} num
 * @return {boolean}
 */
var isPerfectSquare = function(num) {
    // if(num<1) return false 
    // if(num==1)return true 
    // let left = 1 
    // let right = num 
    // while(left<=right){
    //    let mid = Math.floor(left+(right-left)/2)
    //    if(mid*mid==num) return true 
    //    else if(mid*mid>num)
    //        right = mid-1
    //    else
    //        left = mid+1
    // }
    // return false
    let sum = 1;
     while (num > 0) {
         num -= sum
         sum += 2
     }
     return num == 0
};