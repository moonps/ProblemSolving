#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main(void)
{
    int n;
    char sstr[35],cmp[2];

    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        sstr[0]='\0';
        scanf("%s", sstr);
        int len=strlen(sstr);
        
        cmp[0]=sstr[len-2];
        cmp[1]=sstr[len-1];  
        
        switch(cmp[1]) {
            case 'a': strcat(sstr,"s"); break;
            case 'i': strcat(sstr,"os"); break;
            case 'y': sstr[len-1]=NULL; strcat(sstr,"ios"); break;
            case 'l': strcat(sstr,"es"); break;
            case 'n': sstr[len-1]=NULL; strcat(sstr,"anes"); break;
            case 'e':
                if(cmp[0]=='n') {
                    sstr[len-2]=NULL;
                    strcat(sstr,"anes"); break;
                }
                strcat(sstr , "us");
                break;
            case 'o': strcat(sstr,"s"); break;
            case 'r': strcat(sstr, "es"); break;
            case 't': strcat(sstr, "as"); break;
            case 'u': strcat(sstr, "s"); break;
            case 'v': strcat(sstr, "es"); break;
            case 'w': strcat(sstr, "as"); break;
            default: strcat(sstr, "us");
        }
        printf("%s\n", sstr);
    }
    return 0;
}