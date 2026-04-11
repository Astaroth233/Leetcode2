class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        int seat = 1;
        unordered_map<char, int> free;
        priority_queue<pair<int, char>> pq;

        for(int i=0;i<tasks.size();i++)
        {
            freq[tasks[i]] ++;
            free[tasks[i]] = 1;
        }

        for(auto i : freq)
        {
            pq.push({i.second, i.first});
        }

        while(!pq.empty())
        {
            vector<pair<int, char>> pulled;
            while(!pq.empty())
            {
                pair<int, char> curr = pq.top();
                pq.pop();
                int f = curr.first;
                int l = curr.second;
                if(free[l] <= seat)
                {
                    if(f > 1)
                    {
                        pq.push({f - 1, l});
                        free[l] = seat + n + 1;  
                    }
                    break;
                }
                else
                {
                    pulled.push_back(curr);
                }
            }
            for(int i=0;i<pulled.size();i++)
            {
                pq.push(pulled[i]);
            }
            seat ++;
        }
        return seat - 1;
    }
};