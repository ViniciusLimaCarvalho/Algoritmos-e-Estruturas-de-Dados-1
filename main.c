#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main(){
    char ch, CPF[12];
    int j = 0;

    while(j < 11){
        ch = getch();
        CPF[j] = ch;
        j++;
        printf("%c",ch);
    }


    return 0;

}