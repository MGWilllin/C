#include <stdio.h>
#include <string.h>


char *str_cpy1(char *destination, const char *source);


//simple use of strcpy
int main(){
    char src[] ="copy this";
    char dest[100];

    char *dest_ptr = str_cpy1(dest, src);

    printf("     src: %s\n", src);
    printf("    dest: %s\n", dest);
    printf("dest_ptr: %s\n", dest_ptr);

    printf("    dest: %p\n", dest);
    printf("dest_ptr: %p\n", dest_ptr);

    return 0;
}


/*  source: c o p y   t h i s \0
            0 1 2 3 4 5 6 7 8  9
    
    destination:
            0 1 2 3 4 5 6 7 8  9
 
    we create a loop to keep track of which character we are copying. We will be copying each characters until \0. \0 is our signal for strcpy to stop copying.
*/
char *str_cpy1(char *destination, const char *source){
    if (destination == NULL); //means we passed a bad pointer

    int i = 0;
    while (source[i] != '\0'){
        destination [i] = source[i];
        i++;
    }
    destination[i] = '\0';
    return destination;
}
