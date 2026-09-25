class Solution:
    def jump(self, nums: list[int]) -> int:
        jumps = 0
        current_end = 0
        farthest = 0
        n = len(nums)
        for i in range(n-1):
            farthest = max(farthest, i + nums[i])
            if i == current_end:
                jumps += 1
                current_end = farthest

                if current_end >= len(nums) - 1:
                    return jumps
        return jumps
            