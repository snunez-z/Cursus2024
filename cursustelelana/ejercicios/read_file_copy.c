#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFER_SIZE 1000

int main()
{
    int fd_entry;
    int fd_exit;
    ssize_t read_bytes;
    char buffer [BUFFER_SIZE];

    fd_entry = open ("read_chars.c", O_RDONLY);
    if (fd_entry == -1)
    {
        perror ("Error in readable file");
        return 1;
    }
    fd_exit = open ("fd_exit", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd_exit == -1)
    {
        perror (" Error in fd_exit file");
        close (fd_entry);
        return (-1);
    }
    read_bytes = read (fd_entry, buffer, BUFFER_SIZE);
    while (read_bytes > 0)
    {
        if (write (fd_exit, buffer, read_bytes) != read_bytes)
        {
            perror(" Error into exit file)");
            close(fd_entry);
            close(fd_exit);
            return (1);
        }
    read_bytes = read( fd_entry, buffer, BUFFER_SIZE);
    }
    close(fd_entry);
    close(fd_exit);
    
    printf ("The input file has been sucessfully copied to the output file");
    return (0);
}
