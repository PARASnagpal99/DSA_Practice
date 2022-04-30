/**
 * @param {character[]} letters
 * @param {character} target
 * @return {character}
 */
var nextGreatestLetter = function(letters, target) {
    if (letters[0] > target || target >= letters[letters.length - 1]) return letters[0]
    let left = 0
    let right = letters.length - 1
    while (left < right) {
        let mid = Math.floor((left + right) / 2)
        if (target < letters[mid]) {
            right = mid
        } else {
            left = mid + 1
        }
    }
    return letters[left]
};