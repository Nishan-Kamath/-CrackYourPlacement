class Solution
{
  public:
    
   string smallestWindow(string s, string p) {
     int n = s.length();
     int m = p.length();

     if (n < m) {
        return "-1";
     }

    
     vector<int> p_freq(128, 0);
     for (char ch : p) {
        p_freq[ch]++;
     }

     int start = 0, min_len = INT_MAX, count = 0, min_start = -1;
     vector<int> s_freq(128, 0);

     for (int end = 0; end < n; end++) {
        char end_char = s[end];
        s_freq[end_char]++;

        if (p_freq[end_char] != 0 && s_freq[end_char] <= p_freq[end_char]) {
            count++;
        }

        // When we have a valid window
        while (count == m) {
            if (end - start + 1 < min_len) {
                min_len = end - start + 1;
                min_start = start;
            }

            // Try to shrink the window from the left
            char start_char = s[start];
            s_freq[start_char]--;
            if (p_freq[start_char] != 0 && s_freq[start_char] < p_freq[start_char]) {
                count--;
            }
            start++;
        }
     }

     if (min_start == -1) {
        return "-1";
     }

     return s.substr(min_start, min_len);
  }

};