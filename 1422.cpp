class Solution {
public:
    int maxScore(string s) {
        unordered_map<int, vector<int>> map;
        if(s.length() == 0){
            return 0;
        }
        vector<int> zeros;
        vector<int> ones;
        map[0] = zeros;
        map[1] = ones;
        for( int i=0; i < s.length() ; i++){
            if(s[i] == '0')
                map[0].push_back(i);
            if(s[i] == '1')
                map[1].push_back(i);
        }
        for(int i = 0; i < map[0].size(); i++){
            cout << map[0].at(i) << " ";
        }
        cout << endl;
        for(int i = 0; i < map[1].size(); i++){
            cout << map[1].at(i) << " ";
        }
        return 1;
    }
};
