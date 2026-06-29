class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // first check if total gas available at all the stations is more than total cost
        int totalCost = 0;
        int totalGas = 0;
        for(int i = 0; i < gas.size(); i++) {
            totalCost += cost[i];
            totalGas += gas[i];
        }
        if (totalCost > totalGas) return -1;
        int total = 0;
        int res = 0;
        for(int i = 0; i < gas.size(); i++) {
            total += (gas[i] - cost[i]);
            if (total < 0) {
                total = 0;
                res = i+1;
            }
        }
        return res;
    }
};
