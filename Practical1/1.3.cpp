#include<stdio.h>
#include<string.h>
int main()
{
    char sentence[100],word[100],longest[100];
    int i=0,j=0;
    int currlen=0,maxlen=0;
    printf("Enter a sentence: ");
    fgets(sentence,sizeof(sentence),stdin);
    for(i=0;sentence[i]!='\0';i++)
    {
        if(sentence[i]!=' ' && sentence[i]!='\n' && sentence[i]!='\t')
        {
            word[j]=sentence[i];
            j++;
        }
        else
        {
            if(j>0)
            {
                word[j]='\0';
                currlen=strlen(word);
                if(currlen>maxlen)
                {
                    maxlen=currlen;
                    strcpy(longest,word);
                }
                j=0;
            }
        }
    }
    if(maxlen>0)
    {
        printf("The longest word is: %s\n",longest);
        printf("Length of the longest word is: %d\n",maxlen);
    }
    else
    {
        printf("No words found in the sentence.\n");
    }
    return 0;
}