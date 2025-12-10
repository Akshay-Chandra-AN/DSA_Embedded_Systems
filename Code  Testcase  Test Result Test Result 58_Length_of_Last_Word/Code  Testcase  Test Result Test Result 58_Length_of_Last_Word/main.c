#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, const char * argv[])
{
    char s[]="Hello my name is akshay";
    char *word=NULL;
    word = (char *)malloc(1000 * sizeof(char));
    int j=0;
    for(int i=0;s[i] != '\0';i++)
    {
        if(isalnum(s[i]))
        {
        word[j++]=s[i];
        }
        else if (j > 0)
        {
            word[j]='\0';
            //printf("%s\n",word);
            j=0;
        }
    }
    
    if(j > 0)
    {
        word[j] = '\0';
        //printf("Extracted word: %s\n", word);
    }
    
    printf("%d",(int)strlen(word));
    return 0;
}
