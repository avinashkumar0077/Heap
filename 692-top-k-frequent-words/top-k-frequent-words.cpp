class Solution {
public:
    
    struct compare {
        bool operator()(pair<string,int>& a, pair<string,int>& b) {

            if (a.second == b.second) {
                return a.first > b.first;
            }

            return a.second < b.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int> freq;

        for (string word : words) {
            freq[word]++;
        }

        priority_queue<pair<string,int>,
                       vector<pair<string,int>>,
                       compare> pq;

        for (auto it : freq) {
            pq.push({it.first, it.second});
        }

        vector<string> ans;

        while (k--) {
            ans.push_back(pq.top().first);
            pq.pop();
        }

        return ans;
    }
};