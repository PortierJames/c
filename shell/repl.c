/* todos
lisp functions
1. (quote x)
2. (atom x)
3. (eq x y)
4. (cons x y)
5. (cond (x y) (w z) (t q))
6. (car x)
7. (cdr x)
8. (eval x)

Command Line
basename
cat
cd
chmod
chown
clear
cmp
cp
cron
dir
echo
exit
ls
mkdir
mv
open
printf
rename
rm
rmdir

*/

#include <stdio.h>

#define MAX 1024

// 
void parse_input(char *raw_input)
{
}



int main(int argc, char *argv[])
{
  char input[MAX];
  
  while(1) {
    printf("> ");
    scanf("%s", input);
    printf("%s\n", input);
  }
  return 0;
}
