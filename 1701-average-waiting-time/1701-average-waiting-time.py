class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        chef = customers[0][0]
        total = 0

        for i in range(len(customers)):
            if chef <= customers[i][0]:
                total += customers[i][1]
                chef = customers[i][0] + customers[i][1]
            else:
                total += (chef + customers[i][1]) - customers[i][0]
                chef += customers[i][1]
            
        return total / len(customers)