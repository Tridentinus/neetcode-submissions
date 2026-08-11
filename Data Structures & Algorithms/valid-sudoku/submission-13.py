class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row, col, sqr = defaultdict(set), defaultdict(set), defaultdict(set)
        
        for i in range(9):

            for j in range(9):
                if board[i][j] == ".":
                    continue
                n = int(board[i][j])
                r = int((i)/3)
                c = int((j)/3)
                s = 3*r + c
                if n in row[i] or n in col[j] or n in sqr[s]:
                    
                    return False
                row[i].add(n)
                col[j].add(n)
                sqr[s].add(n)

        return True
