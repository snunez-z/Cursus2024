
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int copy_file(const char *src_file_name, const char *dest_file_name)
{
    // Escribir esta función que:
    // Abra "src_file_name" para lectura
    // Abra "dest_file_name" para escritura
    // Lea carácter a carácter del fichero de origen y lo guarde en el fichero de destino
    //
    // Si todo va bien, tiene que retornar el número de bytes que se han copiado
    // Si hay un error al abrir el fichero de origen, tiene que retornar -1
    // Si hay un error al abrir el fichero de destino, tiene que retornar -2
    // Si hay un error al leer del fichero de origen, tiene que retornar -3
    // Si hay un error al escribir en el fichero de destino, tiene que retornar -4
    int fd_src;
    int fd_dst;
    char    *buffer;
    ssize_t bytes_read;

    fd_src = open (src_file_name, O_RDONLY);
    if (fd_src == -1)
        return (-1);
    fd_dst = open (dest_file_name, O_WRONLY | O_CREAT | O_TRUNC);
    if (fd_dst == -1)
        return (-2);
    buffer = 0;
    bytes_read = read( fd_src, buffer, 1);
    if (bytes_read == -1)
        return (-3);
    while (bytes_read < 0)
    {
        bytes_read = write (fd_dst, buffer, 1);
        if (bytes_read == -1)
            return (-4);
        bytes_read = read (fd_dst, buffer, 1);
    }
    close (fd_src);
    close (fd_dst);
return (bytes_read);
}
int main(int argc, char **argv)
{
    int bytes_copied;

    if (argc < 3)
    {
        printf("usage %s: <source_file> <destination_file>\n", argv[0]);
        return (-1);
    }

    bytes_copied = copy_file(argv[1], argv[2]);
    if (bytes_copied >= 0)
    {
        printf("%d bytes %s successfully copied to %s\n", bytes_copied, argv[1], argv[2]);
        return (0);
    }
    else if (bytes_copied == -1)
    {
        printf("No bytes copied. Thre was an error opening the file %s\n", argv[1]);
        return (-1);
    }
    else if (bytes_copied == -2)
    {
        printf("No bytes copied. Thre was an error opening the file %s\n", argv[2]);
        return (-1);
    }
    else if (bytes_copied == -3)
    {
        printf("No bytes copied. Thre was an error reading the file %s\n", argv[1]);
        return (-1);
    }
    else if (bytes_copied == -4)
    {
        printf("No bytes copied. Thre was an error reading the file %s\n", argv[2]);
        return (-1);
    }
    return (0);
}
