int calculate(char* s) {
    long length = strlen(s);
    if (length == 0) return 0;

    long currentNumber = 0;
    long lastNumber = 0;
    long totalSum = 0;
    char lastOperator = '+';

    for (int i = 0; i < length; i++) {
        char currentChar = s[i];

        if (isdigit(currentChar)) {
            currentNumber = (currentNumber * 10) + (currentChar - '0');
        }

        // If character is an operator or we reached the end of the string
        if ((!isdigit(currentChar) && !isspace(currentChar)) || i == length - 1) {
            if (lastOperator == '+') {
                totalSum += lastNumber;
                lastNumber = currentNumber;
            } 
            else if (lastOperator == '-') {
                totalSum += lastNumber;
                lastNumber = -currentNumber;
            } 
            else if (lastOperator == '*') {
                lastNumber = lastNumber * currentNumber;
            } 
            else if (lastOperator == '/') {
                lastNumber = lastNumber / currentNumber;
            }

            lastOperator = currentChar;
            currentNumber = 0;
        }
    }

    totalSum += lastNumber;
    return (int)totalSum;
}