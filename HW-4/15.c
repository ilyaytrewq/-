//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void readString(char* s) {
    for (int i = 0; i < 1005; ++i) {
        s[i] = '\0';
    }
    /*int it = 0;
    char c;
    scanf("%c", &c);
    while (c != '\n') {
        s[it++] = c;
        scanf("%c", &c);
    }*/
    fgets(s, 1005, stdin);
}

void printString(const char* s) {
    printf("%s", s);
}

void getSubStr(const char* s, int l, int r, char* dest) {
    if (r - l + 1 > 20) {
        exit(1);
    }
    int it = 0;
    for (int i = l; i < r; ++i) {
        dest[it++] = s[i];
    }
}

int Digit(char c) {
    return c - '0';
}

int getTime(const char* s) {
    int add = (s[0] == '-');
    return (Digit(s[0 + add]) * (60 * 60 * 100) + (Digit(s[2 + add]) * 10 + Digit(s[3 + add])) * (60 * 100) +
        (Digit(s[5 + add]) * 10 + Digit(s[6 + add])) * 100 + (Digit(s[8 + add]) * 10 + Digit(s[9 + add]))) * (add == 1 ? -1 : 1);
}

void formatTime(int t, char* s) {
    int add = 0;
    if(t < 0){
        add = 1;
        s[0] = '-';
    }
    int hs = t % 100;
    t /= 100;
    int ss = t % 60;
    t /= 60;
    int m = t % 60;
    t /= 60;
    int h = t;
    s[1 + add] = ':';
    s[4 + add] = ':';
    s[7 + add] = '.';
    s[0 + add] = h + '0';
    s[2 + add] = m / 10 + '0';
    s[3 + add] = m % 10 + '0';
    s[5 + add] = ss / 10 + '0';
    s[6 + add] = ss % 10 + '0';
    s[8 + add] = hs / 10 + '0';
    s[9 + add] = hs % 10 + '0';
}

void readInfo(int* shift, double* accel) {
    *shift = 0;
    *accel = 1;
    char s[1005] = { '\0' };
    readString(s);
    printString(s);
    readString(s);
    while (s[0] == ';') {
        printString(s);
        readString(s);
    }
    for (int i = 0; i < 3; ++i) {
        int n = strlen(s);
        if (s[0] == 'T') {
            char buff[20];
            getSubStr(s, strchr(s, ' ') - s + 1, n, buff);
            *accel = 100 / atof(buff);
            printf("Timer: 100.00\n");
        }
        else if (s[0] == 'D') {
            char buff[20];
            getSubStr(s, strchr(s, ' ') - s + 1, n, buff);
            *shift = getTime(buff);
        }
        else {
            printString(s);
            return;
        }
        readString(s);
    }
}

int posOfNxtChr(const char* s, int start, char c) {
    for (int i = start + 1; i < strlen(s); ++i) {
        if (s[i] == c) {
            return i;
        }
    }
    return -1;
}

void readDialogues(int shift, double accel) {
    char s[1005] = { '\0' };
    readString(s);
    int Start = 0, End = 0, countComma = 0;
    for (int i = 0; i < strlen(s) - 4; ++i) {
        if (s[i] == ',') {
            countComma++;
        }
        if (s[i] == 'S' && s[i + 1] == 't' && s[i + 2] == 'a' && s[i + 3] == 'r') {
            Start = countComma;
        }
        if (s[i] == 'E' && s[i + 1] == 'n' && s[i + 2] == 'd') {
            End = countComma;
        }
    }
    printString(s);
    readString(s);
    while (s[0] != 'E') {
        int n = strlen(s);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            printf("%c", s[i]);
            if (s[i] == ',') {
                cnt++;
            }
            if (cnt == Start || cnt == End) {
                char buff[20] = { '\0' };
                int to = posOfNxtChr(s, i + 1, ',');
                getSubStr(s, i + 1, to, buff);
                int t = getTime(buff);
                t *= accel;
                t += shift;
                formatTime(t, buff);
                printf("%s", buff);
                i = to - 1;
            }
        }
        //printf("\n");
        readString(s);
    }
    printString(s);
}
//WA ON TEST2
int main(int argc, char const* argv[])
{
    int shift;
    double accel;
    readInfo(&shift, &accel);
    readDialogues(shift, accel);
    return 0;
}
