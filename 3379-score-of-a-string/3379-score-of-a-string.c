int scoreOfString(char* s) {
    int sum = 0;
    for (int i = 0; s[i+1] !='\0'; i++) {
        sum += abs((int)s[i] - (int)s[i+1]);
    }
    return sum;
}