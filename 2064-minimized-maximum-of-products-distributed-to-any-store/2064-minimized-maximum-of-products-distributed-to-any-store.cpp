class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1, high = 0,res = -1;
        for(int i=0;i<quantities.size();i++)
        {
            high = max(high, quantities[i]);
        }

        while(low <= high)
        {
            int guess = low + (high - low) / 2;
            if(retailnums(quantities, guess) <= n)
            {
                res = guess;
                high = guess - 1;
            }
            else
            {
                low = guess + 1;
            }
        }
        return res;
    }

    int retailnums(vector<int>& v, int g)
    {
        int retailc = 0;
        for(int i : v)
        {
            retailc += (i / g);
            if(i % g != 0)
            {
                retailc ++;
            }
        }
        return retailc;
    }
};