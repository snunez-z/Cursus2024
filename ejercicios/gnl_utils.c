#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

#define MALLOC_SIZE 10

static void copy_buffer(char *dest, char *source, size_t len) //cuando se agranda o se reduce se la llama para copiar el buffer del antiguo al nuevo. 
{
	size_t index;

	index = 0;
	while(index < len)
	{
		dest[index] = source[index];
		index++;
	}
}

dstr_t	*dstr_create()// reserva memoria para la estructura y para el buffer.
{
	dstr_t  *pdstr;

	pdstr = malloc(1 * sizeof(dstr_t));
	if (pdstr == NULL)
		return (NULL);
	pdstr->buffer = malloc((MALLOC_SIZE + 1) * sizeof(char));
	if (pdstr->buffer == NULL)
	{
		free(pdstr);
		return (NULL);
	}
	pdstr->buffer[0] = '\0';
	pdstr->buffer_size = MALLOC_SIZE;
	pdstr->str_len = 0;// es cero porque es una cadena vacia y el \0 es una marca no es imprimible.
	return (pdstr);
}

char	*dstr_destroy(dstr_t *pdstr) // libero con null para reducir espacio en el get next line.
{
	free(pdstr->buffer);
	free(pdstr);
	return (NULL);
}

char	*dstr_reduce(dstr_t	*pdstr) // para reducir el buffer, se usa al final para ajustar lo reservado a lo leido.
{
	char	*reduced_buffer;
	if (pdstr->str_len == pdstr->buffer_size) // caso especial, si ocupase justo el espacio que se ha reservado
	{
		reduced_buffer = pdstr->buffer;
		free(pdstr); //libero la estructura, el buffer no porque me sirve al ser igual
		return reduced_buffer; // retorno el buffer reducido que coindice con el que se tenia
	}

	reduced_buffer = malloc((pdstr->str_len + 1) * sizeof(char)); // tengo que reducir strlen ( son los realmente usados) + 1 para el \0
	if (reduced_buffer == NULL)
	{
		dstr_destroy(pdstr);// si ha ido la reserva mal libero todo llanado al destroy
		return (NULL);
	}
	
	copy_buffer(reduced_buffer, pdstr->buffer, pdstr->str_len + 1); // si ha ido todo bien copiamos el antiguo y lo metemos en el nuevo buffer con menos memoria
	dstr_destroy(pdstr); //libera la estructura y el buffer antiguo  - todo
	return (reduced_buffer); // retorno el nuevo buffer reducido 
}

dstr_t	*dstr_append_char(dstr_t    *dest_dstr, char ch)
{
	char *new_buffer;

	if (dest_dstr->str_len >= dest_dstr->buffer_size) // si el tamaño de lo leido es mayor o igual que lo reservado para el buffer
	{
		new_buffer = malloc((dest_dstr->buffer_size + MALLOC_SIZE + 1) * sizeof(char)); //Al tamaño de lo que tenia antes le sumo 10 mas + \0.
		if (new_buffer == NULL)
		{
			dstr_destroy(dest_dstr);
			return (NULL);
		}
		copy_buffer(new_buffer, dest_dstr->buffer, dest_dstr->buffer_size + 1);
		free(dest_dstr->buffer);// LIbero el antiguo
		dest_dstr->buffer = new_buffer;// buffer es ahora le nuevo buffer agrandado.
		dest_dstr->buffer_size = dest_dstr->buffer_size + MALLOC_SIZE;// ahora su tamaño esta agrandado 
	}

	dest_dstr->buffer[dest_dstr->str_len] = ch; // Meto el carcater y le meto el \0 
	dest_dstr->buffer[dest_dstr->str_len + 1] = '\0';
	dest_dstr->str_len++; // crece en funcion de los carcateres que voy metiendo en el buffer

	return (dest_dstr);
}
