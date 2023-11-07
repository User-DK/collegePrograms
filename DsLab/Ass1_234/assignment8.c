#include <stdio.h>

int main(){
    FILE *file1=fopen("text.txt","r");
    FILE* file2=fopen("text1.txt","a");
    
    if(file1==NULL || file2==NULL){
        printf("File counld not be read");
        return 1;
    }char ch;

    while((ch=fgetc(file1))!=EOF){
        fputc(ch,file2);
    }
    fclose(file1);
    fclose(file2);
    return 0;

}