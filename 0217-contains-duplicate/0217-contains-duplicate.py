class Solution:
     def containsDuplicate(self, nums:List(int)) -> bool:
        s = set()
        for x in nums:
            s.add(x)
        return len(nums) != len(s)
