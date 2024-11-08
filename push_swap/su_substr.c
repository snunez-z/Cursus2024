************************************************************************* */


#include <stdlib.h>
#include <stddef.h>

char	*ft_substr(const char	*s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	s_len;

	s_len = (unsigned int) ft_strlen(s);
	if (start > s_len)
	{
		sub = (char *)malloc (1);
		if (sub)
			sub [0] = '\0';
		return (sub);
	}
	if ((start + len) > s_len)
	{
		sub = (char *)malloc (((s_len - start) + 1) * sizeof(char));
		if (sub)
			ft_strlcpy (sub, (s + start), ((s_len - start) + 1));
		return (sub);
	}
	sub = (char *)malloc ((len +1) * sizeof(char));
	if (sub)
		ft_strlcpy (sub, (s + start), (len + 1));
	return (sub);
}
