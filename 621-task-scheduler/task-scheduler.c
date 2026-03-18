#include <stdio.h>

int leastInterval(char tasks[], int size, int n) {

    int freq[26] = {0};

    // Count frequency
    for(int i = 0; i < size; i++) {
        freq[tasks[i] - 'A']++;
    }

    // Find max frequency
    int maxFreq = 0;
    for(int i = 0; i < 26; i++) {
        if(freq[i] > maxFreq)
            maxFreq = freq[i];
    }

    // Count how many have max frequency
    int countMax = 0;
    for(int i = 0; i < 26; i++) {
        if(freq[i] == maxFreq)
            countMax++;
    }

    int result = (maxFreq - 1) * (n + 1) + countMax;

    // Return max of total tasks and result
    return (result > size) ? result : size;
}