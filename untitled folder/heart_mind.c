#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>

size_t  ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}
void	*ft_calloc(size_t nitems, size_t size)
{
	void	*new;
	size_t	num_bytes;

	num_bytes = nitems * size;
	new = malloc(num_bytes);
	if (!new)
		return (NULL);
	ft_bzero(new, num_bytes);
	return (new);
}

char	*ft_substr_test(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;
	char			*ptr;

	i = start;
	j = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	ptr = (char *) malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (s[i] != '\0' && j < len)
	{
		ptr[j] = s[i];
		i++;
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}


char	*ft_strchr(const char *s1, int ch)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == (char)ch)
			return ((char *)&s1[i]);
		i++;
	}
	if ((char)ch == '\0')
		return ((char *)&s1[i]);
	return (NULL);
}

char *ft_substr(char const *s, unsigned int start, size_t len) {
	
	char    *new;
	size_t  actual_len;
	if (!s)
		return NULL;
	actual_len = ft_strlen(s) - start;
	if (actual_len > len)
		actual_len = len;
	 else if 
	(actual_len < 0) 
		actual_len = 0;
	new = (char *)malloc((actual_len + 1) * sizeof(char));
	if (!new)
		return (NULL); 
	ft_strlcpy(new, s + start, actual_len + 1); 
	return (new);
}
char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t size;
	size_t act_len;
    size = ft_strlen(s);
	char *new;
	act_len = 0;
	if(!s)
		return (NULL);
	if (size <= start)
		return (ft_calloc(1,sizeof(char)));
	act_len = size - start;
	if (act_len < len)
		len = act_len;
	new = (char *)malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new,&s[start], len + 1);
	return (new);
}
char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t size;
	size_t i;
	size = ft_strlen(s);
	char *new;
	i = 0;
	if (size <= start)
		return (calloc(1,sizeof(char)));
	if (len > size)
		len = ft_strlen(s);
	new = (char *)malloc((size + 1) * sizeof(char));
	if (!new)
		return NULL;
	while (i < len && s[start] != '\0')
	{
		new[i] = s[start];
		i++;
		start++;
	}
	new[i] = '\0';
	return (new);
}

int main ()
{
	printf("%s", ft_strtrim("!*42*!",2,3));
}