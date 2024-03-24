/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razamora <razamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:16:42 by razamora          #+#    #+#             */
/*   Updated: 2024/03/23 19:14:24 by razamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	size_t	size;
	len = ft_strlen(s1);
	i = 0;
	if (!s1)
		return (NULL);
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	while (ft_strchr(set,s1[len]) && len)
		len--;
	size = len - i + 1;
	return (ft_substr(s1, i, size));
}


static int	ft_count_word(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}


static int	ft_count_lenght_split(char const *s, char c)
{
	int	end_pos;

	end_pos = 0;
	while (*s != '\0' && *s != c)
	{
		s++;
		end_pos++;
	}
	return (end_pos);
}


// int	size_word(char const s, char c)


char **ft_split(char const *s, char c)
{
	char	**new;
	int		count_word;
	int		pos;
	int		size_string;
	int		i;
	int 	num_matrix;
	
	if (!s)
		return (NULL);
	size_string = ft_strlen(s);
	count_word = ft_count_word(s, c);
	i = 0;
	num_matrix = 0;
	new = (char **)malloc((count_word + 1) * sizeof (char *));
	if (!new)
		return (NULL);
	while (i < size_string && s[i] != '\0')
	{
		pos = ft_count_lenght_split(&s[i], c);
		if (pos > 0)
			new[num_matrix++] = ft_substr(s, i, pos);
		i += pos + 1;
	}
	new[num_matrix] = 0;
	return (new);
}

size_t	ft_lenword(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		++i;
	}
	return (ft_strlen(s));
}
int main ()
{
	/*
	void	(*f)(unsigned int, char *);
	char str [] = "Hello, world!";
	f = ft_capitalize2;
  	ft_striteri(str, f);
	return(0);
	*/


	//printf("%zu",ft_lenword(s,' '));
	//printf("%d",ft_count_lenght_split(s,' '));
//int fd = open("test.txt",1);
 	char const *s = "Bienvenidos a 42 madrid";
	char **result = ft_split(s, ' ');
	int i = 0;
	while ( i <= 3)
	{
		printf("Palabra %d: %s\n", i + 1, result[i]);
		i++;
	}
//system("leaks -q a.out");
 return (0);

}


// int	main(void)
// {
// 	char const *s = "Bienvenidos a 42 madrid";
// 	char **result = ft_split(s, ' ');

// 	if (result == NULL)
// 	{
// 		printf("Fallo en asignacion de memoria.\n");
// 		return (1);
// 	}
// 		int	i;

// 		i = 0;
// 		while (result[i] != NULL)
// 		{
// 			printf("Palabra %d: %s\n", i + 1, result[i]);
// 			free(result[i]);
// 			result[i] = NULL;
// 			i++;
// 		}
// 		free_str(result);
// 		return (0);
// }*/
