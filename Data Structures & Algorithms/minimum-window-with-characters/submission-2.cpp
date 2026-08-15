class Solution {
public:
    string minWindow(string s, string t) {
        array<int, 128> freq{};
        for (char c : t) freq[c]++;

        int required = t.size();
        int bestLen = INT_MAX, bestStart = 0;
        int l = 0;

        for (int r = 0; r < (int)s.size(); r++) {
            if (freq[s[r]] > 0) required--;
            freq[s[r]]--;

            while (required == 0) {
                if (r - l + 1 < bestLen) {
                    bestLen = r - l + 1;
                    bestStart = l;
                }
                freq[s[l]]++;
                if (freq[s[l]] > 0) required++;
                l++;
            }
        }

        return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
    }
};