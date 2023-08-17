class Solution {
public:
    int candy(vector<int>& ratings) {

        vector <int> ltor;
        vector <int> rtol;

        for(int i = 0; i< ratings.size(); i++){
            ltor.push_back(1);
            rtol.push_back(1);
        }

        for(int i = 1; i< ratings.size(); i++){
            if(ratings[i] > ratings[i-1]){
                ltor[i] = ltor[i-1] + 1;
            }
        }

        for(int i = ratings.size()-2; i>= 0 ; i--){
            if(ratings[i] > ratings[i+1]){
                rtol[i] = rtol[i+1] + 1;
            }
        }

        for(int i = 0; i< ratings.size(); i++){
            ltor[i] = max(ltor[i], rtol[i]);
        }

        int count = 0;
        for(int i = 0; i< ratings.size(); i++){
            count += ltor[i];
        }
        

        return count;
        
    }
};
