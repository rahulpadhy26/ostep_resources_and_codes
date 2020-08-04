#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
#include "common.h"

/* 
 * Here, argv, argc -> how command line arguments are passed to main() in C.
 * argc is the number of strings pointed to by argv.
 * In practice, argc = 1 + the number of arguments, as virtually all implementationswill prepend the name of the program to the array.
 * The above names are due to convention, any valid identifier can be given...
 * int main(int num_args, char** arg_strings) -> example of a valid main function signature
*/
int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        /*
	 * stderr -> an output stream typically used by programs to output error messages or diagnostics to the console.
	 * fprintf(stderr, "") -> prints whatever is provided within the quotes, to the console.
	*/
        fprintf(stderr, "usage: 2_1 <string>\n");
        exit(1);
    }
    //printf("%s\n", argv[0]); -> this just shows the manner in which the program is executed, e.g., ./2_1
    char *str = argv[1];
    while(1)
    {
        Spin(1);
        printf("%s\n", str);
    }
    return 0;
}

