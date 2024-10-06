bool isValid(char* s) {
    int n = strlen(s);
    if(n==1)
       return false;
    char *stack = (char *)malloc(n *sizeof(char));
    int top = -1;
    for(int i=0; i<n; i++){
        char c = s[i];
        if(top == -1)
            stack[++top]=c;
        else{
            if(c == ')'){
                if(stack[top] == '(')
                   top--;
                else{
                    free(stack);
                    return false;
                }
            }
            else if(c == '}'){
                if(stack[top] == '{')
                   top--;
                else{
                    free(stack);
                    return false;
                }
            }
            else if(c == ']'){
                if(stack[top] == '[')
                   top--;
                else{
                    free(stack);
                    return false;
                }
            }
            else  
               stack[++top]=c;
        } 
    }
    bool result = (top == -1);
    free(stack);
    return result;
}