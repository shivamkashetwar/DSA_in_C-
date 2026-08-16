#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // Helper function to compare the two frequency arrays
    bool same(int freq1[], int freq2[]) {
        for(int i = 0; i < 26; i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        // If s1 is longer than s2, a permutation is impossible
        if (s1.length() > s2.length()) {
            return false;
        }

        int freq1[26] = {0};
        int windowFreq[26] = {0};
        int windowSize = s1.length();

        // Populate frequency arrays for s1 and the first window of s2
        for(int i = 0; i < windowSize; i++){
            freq1[s1[i] - 'a']++;
            windowFreq[s2[i] - 'a']++;
        }
        
        // Check if the very first window is a match
        if (same(freq1, windowFreq)) {
            return true;
        }

        // Slide the window across the rest of s2
        for(int i = windowSize; i < s2.length(); i++){
            // Add the new character entering the window
            windowFreq[s2[i] - 'a']++;
            
            // Remove the old character leaving the window
            windowFreq[s2[i - windowSize] - 'a']--;

            // Check if the current window matches s1's frequencies
            if (same(freq1, windowFreq)) {
                return true;
            }
        }

        return false;
    }
};