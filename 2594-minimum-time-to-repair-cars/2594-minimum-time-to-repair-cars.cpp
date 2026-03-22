class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1, high = 1LL * ranks[0] * cars * cars;
        long long res = -1;
        long long guess;
        while(low <= high)
        {
            guess = low + (high - low) / 2;
            if(numcars(ranks, guess) >= cars)
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

    long long numcars(vector<int>& v, long long g)
    {
        long long cars = 0;
        for(int i=0;i<v.size();i++)
        {
            // Sqrt of (g / v[i])
            cars += (long long)sqrt((double)g / v[i]);
        }
        return cars;
    }
};