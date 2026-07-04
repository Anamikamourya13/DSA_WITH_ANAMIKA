class Solution {
public:
int findSquareSum(int n ){
    int sum = 0;
    while(n>0)
    {
      int digit = n% 10;
      sum += digit * digit;
      n/=10;
    }
      return sum;
}
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do
        {
            slow = findSquareSum(slow);
            fast = findSquareSum(findSquareSum(fast));
        }while(slow != fast);

        return slow == 1;
    }
};