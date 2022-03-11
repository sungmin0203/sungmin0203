#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int cus_strlen(char* string) {
    int cnt = 0;
    while (string[cnt] != '\0') {
        ++cnt;
    }
    return cnt;
}

int main() {
    char sentence[1000], tokens[10][100];
    char* ps = sentence, temp[100];
    gets(sentence);
    int sen_len = cus_strlen(sentence), i = 0;
    int start = 0, end = 0, word_idx = 0, t, k;


   
    for (ps = sentence, i = 0; ps <= sentence + sen_len; i++, ps++) {
        if (i != -1) {
            if (isspace(*ps) != 0 || *(ps) == NULL) {
                end = i;// 
                if(start == end){
                    start = end + 1;
                } 
                else {
                    for (t = start, k = 0; t < end; k++, t++) {
                        tokens[word_idx][k] = sentence[t];
                    }
                    tokens[word_idx][k] = NULL;
                    word_idx++;
                    start = end + 1;
                }
              
            }
        }
    }
  
    printf("nr_tokens = %d\n", word_idx);
    for (int j = 0; j < word_idx; j++) {
        printf("tokens[%d] = ", j);
        puts(tokens[j]);
    }

    return 0;
}
