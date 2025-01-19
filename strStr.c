#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int strStr(char* haystack, char* needle) {
    int resultIndex = -2;
    int haystackLen = strlen(haystack);
    int needleLen = strlen(needle);
    int tempIndex = -2;
    
    int matchLen = 0;

    for (int i = 0; i < haystackLen; i++)
    {

        for (int z = 0; z < needleLen; z++)
        {
            if(haystack[i + z] == needle[z])
            {
                matchLen++;

                if(matchLen == 1)
                {
                    tempIndex = i + z;
                }

                if((matchLen == needleLen) && (tempIndex != -2))
                {
                    resultIndex = tempIndex;
                    return resultIndex;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                matchLen = 0;
                break;
            }
        }
    }

    if(-2 == resultIndex)
    {
        resultIndex = -1;
    }
    
    return resultIndex;
}