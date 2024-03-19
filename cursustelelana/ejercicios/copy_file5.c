
int copy_file(int src_fd, int dest_fd)
{
    // Escribir esta función que:
    // Lea carácter a carácter del fichero de origen y lo guarde en el fichero de destino
    //
    // Si todo va bien, tiene que retornar el número de bytes que se han copiado
    // Si hay un error al leer del fichero de origen, tiene que retornar -3
    // Si hay un error al escribir en el fichero de destino, tiene que retornar -4
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

    // Abrir el fichero de origen (argv[1])
    // Si falla, mostrar un mensaje de error y retornar -1

    // Abrir el fichero de destino (argv[2])
    // Si falla, mostrar un mensaje de error y retornar -1

    bytes_copied = copy_file(fd_to_read, fd_to_write);
    if (bytes_copied >= 0)
    {
        printf("%d bytes %s successfully copied to %s\n", bytes_copied, argv[1], argv[2]);
        return (0);
    }

    // Mostrar un mensaje de error (usando printf) adecuado al error que se haya producido
    return (-1);
}
