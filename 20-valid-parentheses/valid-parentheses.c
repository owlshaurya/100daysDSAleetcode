#include <stdbool.h>
#include <string.h>

bool isValid(char * s) {
    char stack[10000];
    int top = -1;

    for(int i = 0; s[i] != '\0'; i++) {

        // If opening bracket, push
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        }
        else {
            // If stack empty → invalid
            if(top == -1)
                return false;

            char topChar = stack[top--];

            // Check matching
            if((s[i] == ')' && topChar != '(') ||
               (s[i] == '}' && topChar != '{') ||
               (s[i] == ']' && topChar != '[')) {
                return false;
            }
        }
    }

    // If stack empty → valid
    return (top == -1);
}