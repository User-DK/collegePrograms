#include <stdio.h>

int main(){
    FILE *file=fopen("text.txt","r");
    if(file==NULL){
        printf("File not present");
        return 1;
    }
    int linecount=0;
    char c;
    while((c=fgetc(file))!=EOF){
        if(c==10||c==13){
            linecount++;
        }
    }
    if (c != '\n' && linecount > 0) {
        linecount++;
    }
    printf("The number of lines in the text file is: %d",linecount);
    fclose(file);
    return 0;
}

