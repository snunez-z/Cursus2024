
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFER_SIZE 1

int main(void)
{
    int fd;
    char buffer [BUFFER_SIZE];
    ssize_t bytes_read;

    fd = open ("static_var_exercises.c", O_RDONLY);
    if (fd == -1)
    {
        perror ( "Error al abrir el archivo");
        return (1);
    }

    while ((bytes_read = read (fd, buffer, BUFFER_SIZE)) > 0)
        write (1, buffer, bytes_read);
        close (fd);
        return (0);
}
