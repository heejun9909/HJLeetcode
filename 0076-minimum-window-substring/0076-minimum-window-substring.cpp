class Solution {
public:
    string minWindow(string s, string t) {
        if (t == "")
            return "";
        unordered_map<char, int> t_map;
        unordered_map<char, int> s_map;
        for (char c : t) {
            t_map[c]++;
        }

        int start = 0, end = 0, have = 0, need = t_map.size(), minDis = INT_MAX,
            left = 0, right = 0;
        while (end < s.size()) {

            if (t_map.find(s[end]) != t_map.end()) {
                s_map[s[end]]++;
                if (s_map[s[end]] == t_map[s[end]]) {
                    have++;
                }
            }

            while (need == have) {
                if (t_map.find(s[start]) != t_map.end()) {
                    s_map[s[start]]--;
                    if (s_map[s[start]] < t_map[s[start]]) {
                        have--;
                    }
                }
                if (end - start + 1 < minDis) {
                    minDis = end - start + 1;
                    left = start;
                }
                start++;
            }
            end++;
        }

        if (minDis == INT_MAX) {
            return "";
        }

        return s.substr(left, minDis);
    }

};