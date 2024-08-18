
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int copy_file(const char *src_file_name, const char *dest_file_name)
{
    // Escribir esta función que:
    // Abra "src_file_name" para lectura
    // Abra "dest_file_name" para escritura
    // Lea carácter a carácter del fichero de origen y lo guarde en el fichero de destino
    //
    // Si todo va bien, tiene que retornar cero
    // Si hay algún error, tiene que retornar -1

	char buffer[1];
	int	fd_src;
	int	fd_dst;
	ssize_t bytes_read;
	
	fd_src = open (src_file_name, O_RDONLY);

	if (fd_src == -1)
		return (-1);
	fd_dst = open (dest_file_name, O_WRONLY | O_CREAT | O_TRUNC);
	if (fd_dst == -1)
	{
		close (fd_src);
		return (-1);
	}
	bytes_read = read (fd_src, buffer, 1); 
	while (bytes_read > 0)
	{
		bytes_read = write(fd_dst, buffer, bytes_read);
		if (bytes_read == 0)
			return (0);
		if (bytes_read == -1)

			return (-1);
		bytes_read = read (fd_src, buffer, 1);
	}
	close (fd_src);
	close (fd_dst);
return (0);
}

int main(int argc, char **argv)
{
    int copy_result;

    if (argc < 3)
    {
        printf("usage %s: <source_file> <destination_file>\n", argv[0]);
        return (-1);
    }

    copy_result = copy_file(argv[1], argv[2]);
    if (copy_result < 0)
    {
        printf("Error copying %s to %s\n", argv[1], argv[2]);
        return (-1);
    }

    printf("%s successfully copied to %s\n", argv[1], argv[2]);
    return (0);
}
