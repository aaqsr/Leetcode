from math import ceil, floor

class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        
        stringNum = str(x)

        numLength = len(stringNum)
        beforeHalf = floor(numLength / 2)
        afterHalf = ceil(numLength / 2)

        stack = []

        for i in range(beforeHalf):
            stack.append(stringNum[i])
        
        for i in range(afterHalf, numLength):
            currentNum = stack.pop()
            if currentNum != stringNum[i]:
                return False

        return True

if __name__ == "__main__":
    usrIn = int(input())
    sol = Solution()
    print(sol.isPalindrome(x=usrIn))