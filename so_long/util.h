#ifndef UTIL_H
 #define UTIL_H

void util_write(const char *str);
void util_write_line(const char *str);
void util_write_position(size_t x, size_t y, char ch);
void	*util_calloc(size_t size);

#endif