#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("current directory\n");
    system("pwd");

    printf("\nfiles\n");
    system("is-1");

    printf("\ncreating directory\n");
    system("mkdir demo");

    printf("\nlisting files again\n");
    system("is");

    printf("\nremoving directory\n");
    system("rmdir demo");

    return 0;
}