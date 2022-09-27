#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    fork(); //duplica lo que viene después
    fork();
    printf("Mi PID es: %d y mi padre es: %d \n", getpid(), getppid());

    return 0;
}

// argumento 0 siempre es el llamamiento ej: ./ejer.exe
//compilar: gcc prog.c -o prog.exe