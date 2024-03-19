int copy_file(const char *src_file_name, const char *dest_file_name)
{
    // Escribir esta función que:
    // Abra "src_file_name" para lectura
    // Abra "dest_file_name" para escritura
    // Lea carácter a carácter del fichero de origen y lo guarde en el fichero de destino
    //
    // Si todo va bien, tiene que retornar cero
    // Si hay un error al abrir el fichero de origen, tiene que retornar -1
    // Si hay un error al abrir el fichero de destino, tiene que retornar -2
    // Si hay un error al leer del fichero de origen, tiene que retornar -3
    // Si hay un error al escribir en el fichero de destino, tiene que retornar -4
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
    if (copy_result == 0)
    {
        printf("%s successfully copied to %s\n", argv[1], argv[2]);
        return (0);
    }

    // Mostrar un mensaje de error (usando printf) adecuado al error que se haya producido
    return (-1);
}
