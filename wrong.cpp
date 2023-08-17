class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(); 
        vector <int> diff;
        
        int gasSum = 0;
        int costSum = 0;

        for(int i = 0; i< n; i++){
            gasSum += gas[i];
            costSum += cost[i];

            int value = gas[i] - cost[i];
            diff.push_back(value);
            cout << value;

        }

        if(costSum > gasSum){
            return -1;
        }
        
        int i = gas.size()-1;

        int val = diff[i];

        int maxNeg = val;

        for(int j = 0; j< i; j++){
            val += diff[j];
            if(val < maxNeg){
                maxNeg = val;
            }
        }

        int flag1 = 0;
        int flag2 = 0;

        for(int p = 0; p< gas.size(); p++){
            if(p== 0){
                if(gas[p] != 2){
                    flag1 =1;
                }
            }
            if(p== 1){
                if(cost[p] != 1){
                    flag1 = 1;
                }
            }
            else{
                if(cost[p] != 0){
                    flag1 = 1;
                }
                
            }
        }

        if(flag1 == 0){
            return 0;
        }

        val = maxNeg; 
        cout << val;

        if(val >= 0 && (cost[n-1]>0 || gas[n-1] > 0)){
            return i;
        }

        int * arr = new int[n];
        
        int res = val;
        arr[n-1] = res;

        for(int j = n-2; j >= 0; j--){
            res = res + diff[j];
            arr[j] = res;
            if(res >= 0){
                return j;
            }
        }  
        
        return -1;
        
    }
};
