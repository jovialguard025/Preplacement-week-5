#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_LEN 1000000
#define MAX_OPS 1000000

char* history[MAX_OPS];
int history_top = -1;

void push(char* s) {
    history[++history_top] = strdup(s);
}

char* pop() {
    if (history_top < 0) return "";
    return history[history_top--];
}

int main() {
    int Q;
    scanf("%d", &Q);

    char S[MAX_LEN] = "";
    for (int i = 0; i < Q; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            char W[MAX_LEN];
            scanf("%s", W);
            push(S);  
            strcat(S, W);
        } else if (type == 2) {
            int k;
            scanf("%d", &k);
            push(S); 
            int len = strlen(S);
            S[len - k] = '\0';
        } else if (type == 3) {
            int k;
            scanf("%d", &k);
            printf("%c\n", S[k - 1]);
        } else if (type == 4) {
            strcpy(S, pop());  
        }
    }

    // Free memory
    for (int i = 0; i <= history_top; i++) {
        free(history[i]);
    }

    return 0;
}
