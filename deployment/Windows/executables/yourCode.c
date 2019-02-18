#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
char morse[1000][100], cpy[1000], str[1000][100], mes[1000][200], str_mor[1000][200];
void sct(char* a, char* b){
    strcat(a, b);
}

int gaps(char* a, char* b, int c){
    int i;
    for (i = 0; i < c; i++) {
        if (*(a + i) != *(b + i)) {
            return i;
        }
    }
    return i;
}


int main() {
    int i, j, k;
    memset(morse, '\0', sizeof(morse));
    memset(cpy, '\0', sizeof(cpy));
    memset(str, '\0', sizeof(str));
    memset(mes, '\0', sizeof(mes));
    scanf("%[ \n\0]", cpy);
    for (i = 0; ; i++){
        scanf("%c", &morse[i][0]);
        if (morse[i][0] == '*') break;
        scanf("%[^-.]%s", cpy, cpy);
        getchar();
        sct(morse[i], cpy);
        scanf("%[ \n\0]", cpy);
    }
    scanf("%[ \n\0]", cpy);
    for (i = 0; ; i++){
        scanf("%s", str[i]);
        if (str[i][0] == '*') break;
    }
    scanf("%[ \n\0]", cpy);
    for (i = 0; ; i++){
        scanf("%[^ \n\0]", mes[i]);
        if (mes[i][0] == '*') break;
        scanf("%[^-.*]", mes[i + 1]);
    }
    for (i = 0; str[i][0] != '*'; i++) {
        for (j = 0; j < strlen(str[i]); j++) {
            for (k = 0; morse[k][0] != '*'; k++) {
                if (str[i][j] == morse[k][0]) {
                    sct(str_mor[i], morse[k] + 1);
                    break;
                }
            }
        }
    }
            
    for (i = 0; mes[i][0] != '*'; i++) {
        int gap = 10000, g, ans = 0, q = 0;
        for (j = 0; str[j][0] != '*'; j++) {
            if (strlen(mes[i]) < strlen(str_mor[j]))
                g = strlen(str_mor[j]) - gaps(mes[i], str_mor[j], strlen(str_mor[j]));
            else g = strlen(mes[i]) - gaps(str_mor[j], mes[i], strlen(mes[i]));
            if (g < gap) {
                q = 0;
                ans = j;
                gap = g;
            }
            else if (g == gap)
                q = 1;
           
        }
        printf("%s", str[ans]);
        if (q && gap == 0) printf("!");
        else if (gap) printf("?");
        printf("\n");
    }
    
    
    return 0;
}
