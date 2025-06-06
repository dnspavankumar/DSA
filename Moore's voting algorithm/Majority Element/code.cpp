class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int votes = 0;
        int participant = arr[0];
        for(int num:arr){
            if(participant==num){
                votes++;
            }
            else{
                votes--;
            }
            if(votes<0){
                votes=0;
                participant=num;
            }
        }
        return participant;
    }
};
