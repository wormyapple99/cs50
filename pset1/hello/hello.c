#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string ans = get_string("What's your name?\n");
    printf("hello, %s\n", ans);
}

//clang hello.c -- this compiles the code
//./a.out --executes
//clang -o hello hello.c lcs50 --compiles into file hello, link with the library cs50
//make hello -- compiles code in hello.c into hello, while linking stuff neede
