class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
        sum_value = 0
        for i in range(0, len(nums)):
            for j in range(i+1, len(nums)):
                sum_value = nums[i] + nums[j]
                if sum_value == target:
                    return [i, j]

