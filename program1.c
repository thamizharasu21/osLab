#include <stdio.h>
#include <stdlib.h>
int main(){
printf("creating directory...\n");
system("mkdir demodir");
printf("\ndirectoy tree:\n");
system("tree");
printf("\nReomoving Directory...\n");
system("rmdir demodir");
return 0;
}
