int read_char(int fd, char *pch)
{
    // Escribe esta función:
    // Tiene que leer un byte (char) del file descriptor "fd" y guardarlo dentro
    // del puntero "pch" ("pch" es la abreviatura de "pointer to char")
    // * Si puede leer el carácter, tiene que retornar 1 (y guardarlo dentro de "pch")
    // * Si no hay nada más que leer (se ha llegado al final del fichero), tiene que retornar
    //   cero Y NO GUARDAR NADA EN "pch"
    // * Si hay un error al leer, tiene que retornar -1
}

int copy_file(int src_fd, int dest_fd)
{
    int     read_result;
    int     write_result;
    char    byte;
    size_t  num_bytes;

    num_bytes = 0;
    read_result = read_char(src_fd, &byte);
    while(read_result > 0)
    {
        write_result = write(dest_fd, &byte, 1);
        if (write_result <= 0)
        {
            // Fallo al escribir, así es que la documentación dice que retornemos -4
            return (-4);
        }
        // Si llegamos hasta aquí, significa que la escritura ha ido bien
        // En este bucle, el "incremento" es leer el siguiente carácter y asignar el
        // resultado a "read_result" que es lo que va a chequear la condición del "while"
        read_result = read_char(src_fd, &byte);
        num_bytes++;
    }

    // Si hemos llegado aquí, significa que todo se ha escrito bien y se ha salido del bucle
    // porque, al leer, ha fallado (<0) o ha llegado al final (==0)
    // Tenemos que distinguir los dos casos
    if (read_result < 0)
    {
        // Fallo al leer, así es que la documentación dice que retornemos -3
        return (-3);
    }
    return (numBytes);
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
