#include <stdio.h>
#include <string.h>

char s[1000005];
int a[1000005];

int main(int argc, char const *argv[])
{    
    int k;
    scanf("%d ", &k);
    int cnt_words = 0;
    int len_word = 0;
    int n = 0;
    char c;
    scanf("%c", &c);
    while(c != '\n'){
        s[n++] = c;
        if(c == ' '){
            a[cnt_words++] = len_word;
            len_word = 0;
        }
        else{
            len_word++;
        }
        scanf("%c", &c);
    }
    a[cnt_words++] = len_word;
    int it = 0;
    int cur_pos = 0;
    while(cur_pos < n){
        int sum_len = 0;
        int used_word = 0;
        while(it < cnt_words && sum_len + (used_word != 0) + a[it] <= k){
            sum_len += (used_word != 0) + a[it];
            used_word++;
            it++;
        }
        if(used_word == 1){
            for(int i = 0; i < sum_len; ++i){
                printf("%c", s[cur_pos++]);
            }
            for(int i = 0; i < k - sum_len; ++i){
                printf(" ");
            }
        }
        else{
            int addAll = (k - sum_len) / (used_word - 1);
            int addFirst = (k - sum_len) % (used_word - 1);
            for(int i = 0; i < sum_len; ++i, ++cur_pos){
                printf("%c", s[cur_pos]);
                if(s[cur_pos] == ' '){
                    int count_spaes = addAll + (addFirst-- > 0);
                    for(int j = 0; j < count_spaes; ++j){
                        printf(" ");
                    }
                }
            }
        }
        cur_pos++;
        if(cur_pos < n){
            printf("\n");
        }
    }
    return 0;
}
