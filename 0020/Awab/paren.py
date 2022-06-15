class Solution:

    def parenRev(char):
        match char:
            case ')':
                return '('
            case ']':
                return '['
            case '}':
                return '{'

    def isValid(self, s: str) -> bool:

        stack = []

        for char in s:

            if char == "(" or char == "[" or char == "{":
                stack.append(char)
            else:
                if len(stack) > 0:
                    check = stack.pop()
                    if Solution.parenRev(char) != check:
                        return False
                else:
                    return False
                

        if len(stack) > 0:
            return False
            
        return True
            
 

example = "()"
print(Solution.isValid)