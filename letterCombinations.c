#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char **result = NULL;
char **temp = NULL;
char *path = NULL;

int pathlen;
int temp_returnSize;

const char Map[8][5] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

// k:有多少个数字
void backtracking(int k,int startindex)
{
    int start_index = startindex;
    // 终止条件
    if(pathlen == k)
    {
        char *tem = malloc(sizeof(char *) * (k + 1));
        for (int i = 0; i < k; i++)
        {
            tem[i] = path[i];
        }
        tem[k] = '\0';

        result[temp_returnSize++] = tem;
        
        return;   
    }

    for (int i = 0; i < strlen(temp[start_index]); i++)
    {
        path[pathlen++] = temp[start_index][i];
        backtracking(k, start_index + 1);
        pathlen--;
    }
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    
    if (digits[0] == '\0')
    {
        result = (char **)malloc(sizeof(char *) * 1);
        *result = (char *)malloc(sizeof(char *) * 1);
        (*result)[0] = '\0';
        *returnSize = 0;
        return result;
    }

    int digitslen = strlen(digits);

    temp = (char **)malloc(sizeof(char *) * digitslen);
    pathlen = temp_returnSize = 0;
    path = (char *)malloc(sizeof(char *) * 5);

    for (int i = 0; i < digitslen; i++)
    {
        switch (digits[i])
        {
            case '2':
                // temp[i] = (char *)malloc(sizeof(char) * 4);
                // temp[i] = "abc"; 典型的内存泄露
                temp[i] = (char *)malloc(sizeof(char) * 4);
                strcpy(temp[i],"abc");
                
                break;
            case '3':
                // temp[i] = (char *)malloc(sizeof(char) * 4);
                // temp[i] = "def";
                temp[i] = (char *)malloc(sizeof(char) * 4);
                strcpy(temp[i],"def");
                break;
            case '4':
                // temp[i] = (char *)malloc(sizeof(char) * 4);
                // temp[i] = "ghi";
                temp[i] = (char *)malloc(sizeof(char) * 4);
                strcpy(temp[i],"ghi");
                break;
            case '5':
                // temp[i] = (char *)malloc(sizeof(char) * 4);
                // temp[i] = "jkl";
                temp[i] = (char *)malloc(sizeof(char) * 4);
                strcpy(temp[i],"jkl");
                break;
            case '6':
                // temp[i] = (char *)malloc(sizeof(char) * 4);
                // temp[i] = "mno";
                temp[i] = (char *)malloc(sizeof(char) * 4);
                strcpy(temp[i],"mno");
                break;
            case '7':
                // temp[i] = (char *)malloc(sizeof(char) * 5);
                // temp[i] = "pqrs";
                temp[i] = (char *)malloc(sizeof(char) * 5);
                strcpy(temp[i],"pqrs");
                break;
            case '8':
                // temp[i] = (char *)malloc(sizeof(char) * 4);
                // temp[i] = "tuv";
                temp[i] = (char *)malloc(sizeof(char) * 4);
                strcpy(temp[i],"tuv");
                break;        
            case '9':
                // temp[i] = (char *)malloc(sizeof(char) * 5);
                // temp[i] = "wxyz";
                temp[i] = (char *)malloc(sizeof(char) * 5);
                strcpy(temp[i],"wxyz");
                break;
            default:
                break;
        }
    }
    
    result = (char **)malloc(sizeof(char *) * 20000);


    backtracking(digitslen, 0);

    *returnSize = temp_returnSize;

    return result;
}

int main()
{
    char *digits = "";
    int returnSize = 0;
    char **Result = NULL;

    Result = letterCombinations(digits, &returnSize);

    printf("returnSize = %d\r\n", returnSize);

    return 0;
}