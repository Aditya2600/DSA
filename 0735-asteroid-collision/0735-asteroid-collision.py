class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        st = []
        n = len(asteroids)

        for i in range(n):
            while st and st[-1] > 0 and asteroids[i] < 0:
                sum = st[-1] + asteroids[i]
                if sum < 0 :
                    st.pop()
                elif sum > 0 :
                    asteroids[i] = 0
                
                else:
                    st.pop()
                    asteroids[i] = 0
            
            if asteroids[i]:
                st.append(asteroids[i])
        return st
            