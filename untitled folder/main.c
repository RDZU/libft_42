/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razamora <razamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:16:42 by razamora          #+#    #+#             */
/*   Updated: 2024/03/17 17:16:12 by razamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
SRCS = function.c file.c main.c
OBJS = ${SRCS:.c=.o}
CFLAG = cc -Wall -Wextra -Werror
NAME = rush-02

.c.o:
	${CFLAG} -c $< -o ${<:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

fclean:
	rm -f ${NAME} ${OBJS}

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
    else if ((c >= '0' && c <= '9'))
        return (1);
	else
		return (0);
}

int	ft_isdigit(int c)
{
    if ((c >= '0' && c <= '9'))
        return (1);
	else
		return (0);
}

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}


int ft_tolower (int c)
{
    if(c >= 65 && c <= 90)
        return (c + 32);
    else
        return (c);
}

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (c);
}

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

char	*ft_strdup(const char *src)
{
	size_t		i;
	char		*new;

	i = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!new)
		return (0);
	while (src[i] != '\0')
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int	ft_strncmp(const char *s1,const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' && s2[i] != '\0') && s1[i] == s2[i] && i < n)
		i++;
	if (i < n)
		return (s1[i] - s2[i]);
	else
		return (0);
}
					// dest				src
void *ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char 		*dest;
	const unsigned char	*src;
	size_t				i;

	dest = s1;
	src = s2;
	i = 0;

	if(!src)
		return (NULL);
	while (src && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*new;
	size_t			i;

	new = b;
	i = 0;
	while(new && i < len)
	{
		new[i] = c;
		i++;
	}
	return (new);
}

void ft_bzero(void *s, size_t n)
{
	ft_memset(s,'\0',n);
}

char	*ft_strchr (const char *s1, int ch)
{
	size_t i;

	i = 0;
	if(ch == '\0')
		return (char *)s1;
		
	while (s1[i] != '\0')
	{
		if (s1[i] == ch)
			return (char*) &s1[i];
		i++;
	}
	return (NULL);
}

char    *ft_strrchr (const char *s, int ch)
{
    size_t i;
    size_t size_str;
    size_str = strlen(s);
    
    i = 0;
    while (size_str-- > 0)
    {
        if (s[size_str] == ch)
            return (char*) &s[size_str];
    }
    return (NULL);
}

// de prueba repo kmoro/libft

size_t	ft_strlcpy_test(char *dest, const char *src, size_t size)
{
	size_t	count;

	count = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[count] != '\0' && count < (size - 1))
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (ft_strlen(src));
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
					 // dst		 src   len
// 

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	const unsigned char *str1;
	const unsigned char *str2;
	
	str1 = s1;
	str2 = s2;

	i = 0;
	while ((str1[i] != '\0' && str2[i] != '\0') && str1[i] == str2[i] && i < n)
		i++;
	if (i < n)
		return (str1[i] - str2[i]);
	else
		return (0);
}
// size_t i;

// 	i = 0;
// 	while (s1[i] != '\0')
// 	{
// 		if (s1[i] == ch)
// 			return (char*) &s1[i];
// 		i++;
// 	}
// 	return (NULL);
void *ft_memchr(const void *s, int c, size_t n)
{
    size_t i;
    const unsigned char *str;

	str = s;
    i = 0;
    while (str && i < n)
    {
        if (str[i] == c)
            return (char*) &str[i];
		i++;
    }
    return (NULL);
}

void *ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*s1;
	const unsigned char	*s2;

	s2 = src;
	s1 = dst;
	if (s1 < s2)
		return ft_memcpy(s1, s2, n);
	else
	{
		while (n--)
			s1[n] = s2[n];
	}
	return (s1);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int		i;
	char	c;
	int		len_src;
	int		len_to_find;

	i = 0;
	len_src = ft_strlen(str);
	len_to_find = ft_strlen(to_find);
	c = to_find[0];
	if (len_to_find > len_src)
		return (0);
	else if (len_to_find == 0)
		return ((char *)str);
	while (str[i] != '\0' && (len_to_find + i) <= len)
	{
		if (str[i] == c)
		{
			if ((ft_strncmp(&str[i], to_find,len_to_find) == 0))
				return ((char *)&str[i]);
		}
		i++;
	}
	return (0);
}

void *ft_calloc(size_t nitems, size_t size)
{
	void 	*new;
	size_t	num_bytes;
	
	num_bytes = nitems * size;
	new = malloc(num_bytes);
	if(!new)
		return(NULL);
	ft_bzero(new, num_bytes);
	return (new);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;
	int	i;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57 && str[i] != '\0')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}


size_t	ft_strlcat(char *dest,const char *src,size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;

	i = ft_strlen(src);
	j = ft_strlen(dest);
	if (size == 0 || size < j)
		return (size + i);
	l = 0;
	k = j;
	while (src[l] != '\0' && l < size - 1)
	{
		if (j + l < size - 1)
		{
			dest[l + j] = src[l];
			k++;
		}
		l++;
	}
	dest[k] = '\0';
	return (i + j);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	while(*s)
		write(fd, s++, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	while(*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	size_t	i;
	size_t	j;
	char	*new;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	i = 0;
	j = 0;
	new = (char *)malloc((size_s1 + size_s2) * sizeof(char) + 1);
	if (!new)
		return (NULL);
	while (s1[j] != '\0')
		new[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}

static int	count_digit(int num)
{
	int	count;

	count = 0;
	while(num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

static int is_negative(int num)
{
	if (num < 0)
		return (1);
	else
		return (0);
}
char	*ft_itoa(int n)
{
	int		size;
	int		negative;
	char	*new;
	size = count_digit(n);
	negative = is_negative(n);
	if(n == -2147483648)
		return (ft_strdup("-2147483648"));
	new = (char *) malloc((size + negative + 1) * sizeof(char));
	if (!new)
		return (NULL);
	if (negative == 1)
	{
		n *= -1;
		new[0] = '-';
	}
	size += negative;
	new[size] = '\0';
	while (size -- != negative)
	{
		new[size] = (n % 10) + 48;
		n /= 10;
	}
	return (new);
}

int main ()
{

	const char str[] = "Uhpttps://www.tutorialspoint.com";
   const char ch = '\0';
   char *ret;
   ret = strchr(str, ch);
   printf("String after |%c| is -> |%s|\n", ch, ret);
	//printf("%s", ft_itoa(-2147483648));
	// const char c[] = "casa";
	// const char x[] = "case";
	// printf("%d",ft_strncmp(c,x,4));

   //printf("%s",c2);
	//  strdup
	/*char *src = "hello";
	char *mine = NULL;
	char *theirs = NULL;
	mine = ft_strdup(src);
	theirs = strdup(src);
	printf("%s %s", mine, theirs);*/
	/**************************/
	//char src[50] = "";
   //char dest[50];
   	//strcpy(dest,"Heloooo!!");
  	// printf("Before memcpy dest = %s\n", dest);
   	//ft_memcpy(dest, src, 10)
	
	//memset(src,'7',10);
	
	//printf("memset = %s\n", dest);
	///printf("memset = %s\n", src);
// PENDIENTE PROBAR
/*
   const char str[] = "Uhpttps://www.tutorialspoint.com";
   const char ch = 'U';
   char *ret;
   ret = ft_strrchr(str, ch);
   printf("String after |%c| is -> |%s|\n", ch, ret);

   */
//   char	input[50] = "sad";
//   char	to[] = "Hello World!rewrw";
//    printf("ft_strlcpy: %zu\n", ft_strlcpy(input, to, 10));
//    printf("dest: %s\n", input);
/*
	char dest[] = "oldstring";
   const char src[]  = "newstring";
   printf("Before memmove dest = %s, src = %s\n", dest, src);
   ft_memmove(dest, src, 9);
   printf("After memmove dest = %s, src = %s\n", dest, src);
   
   */

  // MEMCMP
  /*
   char str1[] = "caso";
   const char str2[]  = "casa";
   printf("result: %d\n", ft_memcmp(str1, str2, 0));
  */

 // STRNSTR
 /*
 	char haystack[20] = "PointTutorial";
   	char needle[10] = "Point";
   	char *ret;
   	ret = ft_strnstr(haystack, needle,4);
	printf("The substring is: %s\n", ret);
*/
	// MEMCHR
	/*
   const char str[] = "https://www.tutorialspoint.com";
   const char ch = 'm';
   char *ret;
   ret = memchr(str, ch, ft_strlen(str));
	*/
	//MMEMOVE
	
	// char src[] = "mora";
	// const char dst[] = "12345";
	// printf("%s",ft_memmove(src,dst,5));

	/*
	char dest[] = "mora";
   const char src[]  = "123456";

   printf("Before memmove dest = %s, src = %s\n", dest, src);
   memmove(dest, src, 5);
   printf("After memmove dest = %s, src = %s\n", dest, src);
   */

  //int a[4] = {7,8,6,4,8};
  /*int *a;
  int i;
  a = (int*)ft_calloc(4, sizeof(int));
  
   printf("The numbers entered are: ");
   for(i = 0 ; i < 4 ; i++ )
   {
      printf("%d ",a[i]);
   }
   free(a);
   */
/*
  char	src[] = "car";
  char	dst[50] = "casa";
	//printf("CONCATENADA: %zu\n", strlcat(dst, src, sizeof(dst)));
	printf("CONCATENADA: %zu\n",strlcat(dst, src, 4));
	printf("string:  %s\n", dst);
*/
//2147483647  -2147483648
// printf("%d",ft_atoi("756465"));

// FILE
/*
	ft_putchar_fd(a, fd);
	ft_putchar_fd('\n', fd);
*/
/*
char a = '9';
char *cadena = "TeaTro";
int fd = open("test.txt",1);
*/

//ft_putchar_fd(a,fd);
//ft_putstr_fd(cadena,fd);
//ft_putendl_fd(cadena,fd);
//ft_putchar_fd(a,fd);
///printf("%s", ft_strjoin("casa", "avion"));

//printf("%d", count_digit(5050505));

return(0); 

}
