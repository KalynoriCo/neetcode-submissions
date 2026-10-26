class TimeMap {
private:
string _key = "", _value = "";
int _timestamp = 0;
unordered_map<string, vector<pair<int, string>>>mp;
public:
    TimeMap(){}
    
    void set(string key, string value, int timestamp)
    {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) 
    {
        if(!mp.contains(key))
            return "";
        int  l = 0, r = mp[key].size() - 1, answer = -1;
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if(mp[key][mid].first == timestamp) return mp[key][mid].second;
            if(mp[key][mid].first <= timestamp)
            {
                answer = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        if(answer == -1) return "";
        return mp[key][answer].second;
    }
};
