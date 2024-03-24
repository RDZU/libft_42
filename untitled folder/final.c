

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>




static int	ft_count_word(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		if (*s != (char)c && (*(s + 1) == (char)c || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}

static int	ft_count_lenght_split(char const *s, char c)
{
	int	end_pos;

	end_pos = 0;
	while (*s != '\0' && *s != (char)c)
	{
		s++;
		end_pos++;
	}
	return (end_pos);
}

static void	*ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i]);
	free(matrix);
	return (NULL);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	act_len;
	char	*new;

	size = ft_strlen(s);
	act_len = 0;
	if (!s)
		return (NULL);
	if (size <= start)
		return (ft_calloc(1, sizeof(char)));
	act_len = size - start;
	if (act_len < len)
		len = act_len;
	new = (char *)malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, &s[start], len + 1);
	return (new);
}
char	**ft_split(char const *s, char c)
{
	char	**new;
	int		pos;
	int		size_string;
	int		i;
	int		num_matrix;

	if (!s)
		return (NULL);
	size_string = ft_strlen(s);
	i = 0;
	num_matrix = 0;
	new = (char **)malloc((ft_count_word(s, c) + 1) * sizeof (char *));
	if (!new)
		return (NULL);
	while (num_matrix < ft_count_word(s, c))
	{
		pos = ft_count_lenght_split(&s[i], c);
		if (pos > 0)
			new[num_matrix++] = ft_substr(s, i, pos);
		if (!new)
			return (ft_free_matrix(new));
		i += pos + 1;
	}
	new[num_matrix] = NULL;
	return (new);
}



int main(void)
{
    char **words;
    int i = 0;

    words = ft_split("^^^1^^2a,^^^^3^^^^--h^^^^",'^');
    while (words[i])
    {
        printf("%s\n", words[i]);
        free(words[i]);
        i++;
    }
    free(words);
    return (0);
}