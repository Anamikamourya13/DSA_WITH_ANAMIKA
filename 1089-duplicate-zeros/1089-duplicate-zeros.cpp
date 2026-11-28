class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int count =0;

        //count total zeros 
        for(int i=0; i<n;  i++){
            if(arr[i] == 0){
                count++;
            }
        }
        //initialize pointers from right
        int i=n-1;
        int j = n+ count -1;

        //travrse from right to left
        while(i>=0){

            // Copy element if index is valid
            if(j < n) {
                arr[j] = arr[i];
            }
            // Duplicate zero
            if(arr[i] == 0) {
                j--;

                if(j < n) {
                    arr[j] = 0;
                }
            }
            i--;
            j--;

        }
    }
};