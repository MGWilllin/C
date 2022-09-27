#include <stdio.h>
#include <string.h>

//simple use of strcpy
int main(){
    char src[] ="copy this";
    char dest[100];

    char *dest_ptr = strcpy(dest, src);

    printf("     src: %s\n", src);
    printf("    dest: %s\n", dest);
    printf("dest_ptr: %s\n", dest_ptr);

    printf("    dest: %p\n", dest);
    printf("dest_ptr: %p\n", dest_ptr);

    return 0;
}