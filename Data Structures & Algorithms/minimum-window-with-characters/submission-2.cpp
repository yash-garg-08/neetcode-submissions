class Solution {
   public:
    string minWindow(string s, string t) {
        int n = s.length();

        if (n < t.length()) return "";
        unordered_map<char, int> mp;

        // creating the map with the required elements
        for (char& ch : t) {
            mp[ch]++;
        }
        int required_count = t.length();
        int i = 0, j = 0;

        int minimum_window_size = INT_MAX;
        int start_i = i;

        while (j < n) {
            // storing current jth character
            char ch = s[j];

            if (mp[ch] > 0) {
                required_count--;
            }

            mp[ch]--;

            // if all the required characters are present in the current window
            // then start shrinking the window
            while (required_count == 0) {
                int current_window_size = j - i + 1;
                // if the current window size is smaller then store it
                // and also string the starting index of minimum window
                if (current_window_size < minimum_window_size) {
                    minimum_window_size = current_window_size;
                    start_i = i;
                }
                
                // decreasing the frequency of ith element
                mp[s[i]]++;

                // checking if the removed element is the required element
                // if present then increasing the size of required_count
                if (mp[s[i]] > 0) {
                    required_count++;
                }
                i++;
            }
            j++;
        }

        return minimum_window_size == INT_MAX ? "" : s.substr(start_i, minimum_window_size);
    }
};
