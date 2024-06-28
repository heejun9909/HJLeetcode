class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        row_num = len(matrix)
        col_num = len(matrix[0])
        row_sel = -1
        rstart, rend = 0, row_num - 1

        while rend >= rstart:
            rmid = (rend - rstart) // 2 + rstart

            if matrix[rmid][0] == target:
                return True
            elif matrix[rmid][0] > target:
                rend = rmid - 1
                continue
            else:
                rstart = rmid + 1
                continue
        row_sel = rend

        cstart, cend = 0, col_num - 1

        while cend >= cstart:
            cmid = (cend - cstart) // 2 + cstart

            if matrix[row_sel][cmid] == target:
                return True
            elif matrix[row_sel][cmid] > target:
                cend = cmid - 1
                continue
            else:
                cstart = cmid + 1
                continue
        return False
        