class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
        {
            return false;
        }
        
        // ex: key: 'b' value: 3
        // value being the number of times it appears
        unordered_map<char, int> letterCount;

        for(char letter : s)
        {
            letterCount[letter]++;
            // updates the # of times letter appears.
        }

        // Decrement counts for string t
        for (char ch : t) {
            letterCount[ch]--;
            if (letterCount[ch] < 0) {
                return false;
            }
        }

        return true;

    }
};
