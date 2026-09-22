class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0)
         return true;
        int size =  flowerbed.size();

        for(int i=0; i<size;  i++)
        {
            if(flowerbed[i]==0)
            { 
                 //check  left and right should me zero  
                bool leftEmpty =  (i==0 || flowerbed [i-1]==0);
                bool  rightEmpty =  (i==size-1 || flowerbed[i+1]==0);

                if(leftEmpty && rightEmpty) // if dono  zero h or current bhi zero h to place kr  do
                {
                    flowerbed [i]=1; 
                    n--;
                    if(n==0) //required flowers sare lg gye
                      return true;
                }

            }
        }
        return false;// if flower is left
        
    }
};