#include <stdio.h>     //PRINTF
#include <unistd.h>    //FORK, SLEEP, wait
#include <sys/types.h> //PID_T
#include <sys/wait.h>  //WAIT

int main(int argc, char const *argv[])
{
    pid_t numpid;
    int num = 12;

    numpid = fork();

    if (numpid == 0)
    { // processo hijo devolverá cierto y entrará en el if
        printf("Soy el hijo, mi pid es: %d\n", getpid());
        num = num + 3;
        sleep(1);
    }
    else
    {
        printf("Soy el padre, mi pid es %d\n", getpid());
        int estado; // declaro un entero donde el wait guardaré información sobre el retorno
        // pid_t pidfinalizado = wait(NULL); //espera al hijo y devuelve su pid
        pid_t pidfinalizado = wait(&estado); // Envia tanto el pid del hijo y rellena el entero. & es para enviar la dirección de memoria y no el 25 en sí.
        printf("El hijo con PID: %d finalizó con estado %d\n",
               pidfinalizado, WEXITSTATUS(estado));
        // el 'valor' de estado no tiene ningún sentido practico ya que todos los bits de ese entero se codifican
        // de diferentes datos que nos dan informacion sobre la finalizacion de ese proceso.
        // más info en 'man wait'
        sleep(1);
    }
    printf("Lorem ipsum, num es %d\n", num);

    return 23;
}