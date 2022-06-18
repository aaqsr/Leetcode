def checkDuplicates(arr):
    elements = set()
    for elem in arr:
        if elem != ".":
            
            if elem in elements:
                return False
            
            elements.add(elem)
    return True

class Solution:
    def isValidSudoku(self, board) -> bool:
        
    # checks rows first
        for row in board:
            if checkDuplicates(row) == False:
                return False

        # then checks columns
        for i in range(9):
            column = []
            for j in range(9):
                column.append(board[j][i])
            if checkDuplicates(column) == False:
                return False

        # then checks the 3x3 MiniGrids
        for i in range(0, 9, 3):
            for j in range(0, 9, 3):
                miniGrid = []
                for k in range(j, j+3):
                    miniGrid.extend(board[k][i:i+3])
                if checkDuplicates(miniGrid) == False:
                    return False

        # If all are valid then true
        return True
    


if __name__ == "__main__":
    sol = Solution()

    board = [["5","3",".",".","7",".",".",".","."]
            ,["6",".",".","1","9","5",".",".","."]
            ,[".","9","8",".",".",".",".","6","."]
            ,["8",".",".",".","6",".",".",".","3"]
            ,["4",".",".","8",".","3",".",".","1"]
            ,["7",".",".",".","2",".",".",".","6"]
            ,[".","6",".",".",".",".","2","8","."]
            ,[".",".",".","4","1","9",".",".","5"]
            ,[".",".",".",".","8",".",".","7","9"]]

    print(sol.isValidSudoku(board))

    board = [["8","3",".",".","7",".",".",".","."]
            ,["6",".",".","1","9","5",".",".","."]
            ,[".","9","8",".",".",".",".","6","."]
            ,["8",".",".",".","6",".",".",".","3"]
            ,["4",".",".","8",".","3",".",".","1"]
            ,["7",".",".",".","2",".",".",".","6"]
            ,[".","6",".",".",".",".","2","8","."]
            ,[".",".",".","4","1","9",".",".","5"]
            ,[".",".",".",".","8",".",".","7","9"]]
    
    print(sol.isValidSudoku(board))

    # print(checkDuplicates(['3','0','6', '3']))
    # print(checkDuplicates(['3','0','6',]))