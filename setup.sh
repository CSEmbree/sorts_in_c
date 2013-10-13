 #!/bin/bash          

#DEBUG ON
#gcc -std=c99 -g sortcmp.c quick.c merge.c insert.c -o sortcmp


#DEBUG OFF
gcc -std=c99 -g -DDEBUG=1 sortcmp.c quick.c merge.c insert.c -o sortcmp