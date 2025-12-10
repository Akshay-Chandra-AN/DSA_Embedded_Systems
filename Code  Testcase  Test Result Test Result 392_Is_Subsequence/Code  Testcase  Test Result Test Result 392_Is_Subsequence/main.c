#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isSubsequence(char* s, char* t) {
    int j=0;
    int lenT = strlen(t);
    int lenS = strlen(s);
    for(int i=0;i<lenT;i++)
    {
       if(s[j]==t[i])
       {
           //printf("%c",s[j]);
           j++;
       }
       
       if (j == lenS) {
            return true;
        }
    }
    return false;


}

int main() {
   char s[]="abc";
    char t[]= "aebewdffdc";

    printf("%d",isSubsequence(s,t));

    return 0;
}
