#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int copy_file(int src_fd, int dest_fd)
{
    // Escribir esta función que:
    // Lea carácter a carácter del fichero de origen y lo guarde en el fichero de destino
    //
    // Si todo va bien, tiene que retornar el número de bytes que se han copiado
    // Si hay un error al leer del fichero de origen, tiene que retornar -3
    // Si hay un error al escribir en el fichero de destino, tiene que retornar -4

    size_t  bytes_read;
    char    *buffer;

    buffer = 0;
    bytes_read = read (src_fd, buffer, 1 );
    if ((int)bytes_read == -1)
        close (src_fd);
        return (-3);
    while (bytes_read < 0)
{
        bytes_read = write(dest_fd, buffer, 1);
        if (bytes_read == -1)
            return (-4);
        bytes_read = read (dest_fd, buffer, 1);
}
    close (src_fd);
    close (dest_fd);
return (bytes_read);
}    


int main(int argc, char **argv)
{
    int fd_to_read;
    int fd_to_write;
    int bytes_copied;

    if (argc < 3)
    {
        printf("usage %s: <source_file> <destination_file>\n", argv[0]);
        return (-1);
    }
    fd_to_read = 0;
    fd_to_write = 0;
    bytes_copied = copy_file (fd_to_read, fd_to_write);
    if (bytes_copied >= 0)
    {
        printf("%d bytes %s successfully copied to %s\n", bytes_copied, argv[1], argv[2]);
        return (0);
    }
        fd_to_read = open ("texto_prueba1.c", O_RDONLY);
        if (fd_to_read == -1)
    {   
        printf( "There has been an error reading the source file %s\n", argv[1]);
        return (-1);
    }
        fd_to_write = open(" new_one_text", O_WRONLY | O_CREAT | O_TRUNC);
    {
        printf("There has been an arror reading the destiny file %s\n", argv [2]);
        return (-1);
    }
    return (0);
}  
    
// Abrir el fichero de origen (argv[1])
    // Si falla, mostrar un mensaje de error y retornar -1

    // Abrir el fichero de destino (argv[2])
    // Si falla, mostrar un mensaje de error y retornar -1
