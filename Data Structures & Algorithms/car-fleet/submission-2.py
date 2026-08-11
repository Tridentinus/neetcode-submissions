class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        
        def posSort(e):
            return e[0]

        stack = []
        cars = [[position[i],speed[i]] for i in range(len(speed))]
        cars.sort(reverse=True,key=posSort)
        
        for [p,s] in cars:
            if len(stack) == 0:
                stack.append([p,s])
                continue

            
            carAhead = stack[-1]
            
            delta_p = carAhead[0] - p
            delta_t = (target - carAhead[0]) / carAhead[1]
            delta_s = s - carAhead[1]

            print(delta_p,delta_t,delta_s)

            if delta_p/delta_t > delta_s:
                stack.append([p,s])

        return len(stack)
