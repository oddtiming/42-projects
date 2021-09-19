#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t len);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dest, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

//To test function pointers//
char	ft_touppcase(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - i);
	else
		return (c);
}

void	ft_touppcase_iter(unsigned int i, char *s)
{
	if (*(s + i) >= 'a' && *(s + i) <= 'z')
		*(s + i) -= 32;
}
//End of test functions//

int	main(void)
{
	//Test for ft_isalpha
	printf("###Tests for ft_isdigit###\n");
	printf("Is '%c' alpha? : %d\n", 101, ft_isalpha(101));
	printf("Is '%c' alpha? : %d\n", 3, ft_isalpha(3));
	printf("Is '%c' alpha? : %d\n\n", 70, ft_isalpha(70));
	
	//Test for ft_isdigit
	printf("###Tests for ft_isdigit###\n");
	printf("Is '%c' digit? : %d\n", 101, ft_isdigit(101));
	printf("Is '%c' digit? : %d\n", 54, ft_isdigit(54));
	printf("Is '%c' digit? : %d\n\n", -4, ft_isdigit(-4));

	//Test for ft_isalnum
	printf("###Tests for ft_isalnum###\n");
	printf("Is '%c' alnum? : %d\n", 101, ft_isalnum(101));
	printf("Is '%c' alnum? : %d\n", 54, ft_isalnum(54));
	printf("Is '%c' alnum? : %d\n", -4, ft_isalnum(-4));
	printf("Is '%c' alnum? : %d\n\n", 32, ft_isalnum(32));

	//Test for ft_isascii
	printf("###Tests for ft_isascii###\n");
	printf("Is '%c' ascii? : %d\n", 101, ft_isascii(101));
	printf("Is '%c' ascii? : %d\n", 54, ft_isascii(54));
	printf("Is '%c' ascii? : %d\n", -4, ft_isascii(-4));
	printf("Is '%c' ascii? : %d\n\n", 32, ft_isascii(32));

	//Test for ft_isprint
	printf("###Tests for ft_isprint###\n");
	printf("Is '%c' printable? : %d\n", 101, ft_isprint(101));
	printf("Is '%c' printable? : %d\n", 4, ft_isprint(4));
	printf("Is '%c' printable? : %d\n", -4, ft_isprint(-4));
	printf("Is '%c' printable? : %d\n\n", 32, ft_isprint(32));

	//Tests for ft_strlen
	printf("###Tests for ft_strlen###\n");
	char	*str1 = "This is a sentence.";
	char	*str2 = "";
	printf("For the sentence '%s', the strlen fct gives: %lu\nft_strlen gives: %lu\n\n", str1, strlen(str1), ft_strlen(str1));
	if (strlen(str1) != ft_strlen(str1))
		printf("Error : the fct does not behave as the original\n\n");
	printf("For the sentence '%s', the strlen fct gives: %lu\nft_strlen gives: %lu\n\n", str2, strlen(str2), ft_strlen(str2));
	if (strlen(str2) != ft_strlen(str2))
		printf("Error : the fct does not behave as the original\n\n");

	//Tests for ft_memset
	printf("###Tests for ft_memset###\n");
	char	str3[50];
	
	strcpy(str3, "The initial sentence");
	puts(str3);
	memset(str3 + 2, '*', 5);
	printf("After memset(str + 2, '*', 5): '%s'\n\n", str3);

	strcpy(str3, "The initial sentence");
	puts(str3);
	ft_memset(str3 + 2, '*', 5);
	printf("After ft_memset(str + 2, '*', 5): '%s'\n\n", str3);

	//Tests for ft_bzero
	printf("--------------------\n###Tests for ft_bzero###\n-------------------\n");
	strcpy(str3, "The initial sentence");
	puts(str3);
	bzero(str3 + 5, 3);
	printf("After bzero(str + 5, 3):\n");
	for (unsigned int i = 0; i < sizeof(str3); i++)
	   printf("%c, ", str3[i]);

	printf("\n\n");	
	strcpy(str3, "The initial sentence");
	puts(str3);
	ft_bzero(str3 + 5, 3);
	printf("After ft_bzero(str + 5, 3):\n");
	for (unsigned int i = 0; i < sizeof(str3); i++)
	   printf("%c, ", str3[i]);
	printf("\n\n");	
	
	//Tests for ft_memcpy
	printf("--------------------\n###Tests for ft_memcpy###\n-------------------\n");
	char origin[50];
	char dest[50];
	strcpy(origin, "This is the string to be copied!");
	puts(origin);
	//to clear the dest string btw tests:
	strcpy(dest, "");
	//32 is the total len of the str
	memcpy(dest, origin, 32);
	puts(dest);

	strcpy(origin, "This is the string to be copied by ft_memcpy!");
	puts(origin);
	strcpy(dest, "");
	ft_memcpy(dest, origin, 47);
	printf("%s\n\n", dest);

	//Tests for ft_memmove
	printf("--------------------\n###Tests for ft_memmove###\n-------------------\n");
	strcpy(origin, "This is the string to be copied!");
	puts(origin);
	//to clear the dest string btw tests:
	strcpy(dest, "");
	//32 is the total len of the src, add 1 for null termination
	memmove(dest, origin, 33);
	puts(dest);
	printf("Now to see what gives if dest = src + 5;\n");
	memmove(origin + 5, origin, 33);
	puts(origin);
	printf("What if we use memcpy instead?\n");
	strcpy(origin, "This is the string to be copied!");
	memcpy(origin + 5, origin, 33);
	puts(origin);

	strcpy(origin, "a shiny white sphere");
	printf("\n\nBefore ft_memmove, the string is '%s'\n", origin);
	ft_memmove(origin + 8, origin + 2, 5);
	//expected result "a shiny shiny sphere"
	printf("After ft_memmove the string becomes '%s'\n\n", origin);

	//Tests for ft_strlcpy
	printf("--------------------\n###Tests for ft_strlcpy###\n-------------------\n");
	char	src[50];

	strcpy(src, "this is the test string");
	printf("This is the src string : '%s'\n", src);
	int i = strlcpy(dest, src, 50);
	printf("This is the strlcpy(dest) string for dstsize = 50: '%s'\n", dest);
	printf("return value = %d\n\n", i);

	//reset the dest
	strcpy(dest, "");
	i = ft_strlcpy(dest, src, 50);
	printf("This is the ft_strlcpy(dest) string for dstsize = 50: '%s'\n", dest);
	printf("return value = %d\n\n", i);
	
	//Tests for ft_strlcat
	printf("--------------------\n###Tests for ft_strlcat###\n-------------------\n");
	strcpy(src, "*this is to be added*");
	strcpy(dest, "*incomplete sentence*");
	printf("This is the src string : '%s'\n", src);
	printf("This is the dest string : '%s'\n", dest);
	i = strlcat(dest, src, 50);
	printf("This is the strlcatted dest string : '%s'\n", dest);
	printf("return value = %d\n\n", i);

	//reset the dest
	strcpy(dest, "*incomplete sentence*");
	printf("reset dest : '%s'\n", dest);
	i = ft_strlcat(dest, src, 50);
	printf("This is the strlcatted dest string : '%s'\n", dest);
	printf("return value = %d\n\n", i);

	//Tests for ft_toupper
	printf("-------------------------\n###Tests for ft_toupper###\n-------------------------\n");
	strcpy(origin, "thIs iS A senTence");
	printf("The original string: '%s'\n", origin);
	for (i = 0; i < (int)ft_strlen(origin); i++)
		origin[i] = ft_toupper(origin[i]);
	printf("The string after ft_toupper: '%s'\n\n", origin);
	
	//Tests for ft_tolower
	printf("-------------------------\n###Tests for ft_tolower###\n-------------------------\n");
	strcpy(origin, "thIs iS A senTence");
	printf("The original string: '%s'\n", origin);
	for (i = 0; i < (int)ft_strlen(origin); i++)
		origin[i] = ft_tolower(origin[i]);
	printf("The string after ft_tolower: '%s'\n\n", origin);

	//Tests for ft_strchr
	printf("-------------------------\n###Tests for ft_strchr###\n-------------------------\n");
	strcpy(origin, "haystack");
	i = 'a';
	printf("haystack = '%s'\nneedle = '%c'\n\n", origin, (char)i);
	printf("address returned by strchr fct = '%p'\n", strchr(origin, i));
	printf("address returned by ft_strchr = '%p'\n\n", ft_strchr(origin, i));
	
	strcpy(origin, "haystack");
	i = 0;
	printf("haystack = '%s'\nneedle = '%c'\n\n", origin, (char)i);
	printf("address returned by strchr fct = '%p'\n", strchr(origin, i));
	printf("address returned by ft_strchr = '%p'\n\n", ft_strchr(origin, i));

	strcpy(origin, "haystack");
	i = 'z';
	printf("haystack = '%s'\nneedle = '%c'\n\n", origin, (char)i);
	printf("address returned by strchr fct = '%p'\n", strchr(origin, i));
	printf("address returned by ft_strchr = '%p'\n\n", ft_strchr(origin, i));

	//Tests for ft_strrchr
	printf("-------------------------\n###Tests for ft_strrchr###\n-------------------------\n");
	strcpy(origin, "haystack");
	i = 'a';
	printf("haystack = '%s'\nneedle = '%c'\n\n", origin, (char)i);
	printf("address returned by strrchr fct = '%p'\n", strrchr(origin, i));
	printf("address returned by ft_strrchr = '%p'\n\n", ft_strrchr(origin, i));
	
	strcpy(origin, "haystack");
	i = 0;
	printf("haystack = '%s'\nneedle = '%c'\n\n", origin, (char)i);
	printf("address returned by strrchr fct = '%p'\n", strrchr(origin, i));
	printf("address returned by ft_strrchr = '%p'\n\n", ft_strrchr(origin, i));

	strcpy(origin, "haystack");
	i = 'z';
	printf("haystack = '%s'\nneedle = '%c'\n\n", origin, (char)i);
	printf("address returned by strrchr fct = '%p'\n", strrchr(origin, i));
	printf("address returned by ft_strrchr = '%p'\n\n", ft_strrchr(origin, i));

	//Tests for ft_strncmp
	printf("-------------------------\n###Tests for ft_strncmp###\n-------------------------\n");
	strcpy(origin, "test1");
	strcpy(dest, "test2");
	i = 5;
	printf("s1 = '%s'\ns2 = '%s'\nn = %d\n\n", origin, dest, i);
	printf("strncmp : %d\nft_strncmp : %d\n\n", strncmp(origin, dest, i), ft_strncmp(origin, dest, i));
	
	strcpy(origin, "");
	strcpy(dest, "test2");
	i = 4;
	printf("s1 = '%s'\ns2 = '%s'\nn = %d\n\n", origin, dest, i);
	printf("strncmp : %d\nft_strncmp : %d\n\n", strncmp(origin, dest, i), ft_strncmp(origin, dest, i));

	//Tests for ft_memchr
	printf("-------------------------\n###Tests for ft_memchr###\n-------------------------\n");
	strcpy(origin, "haystack");
	i = 'a';
	int n = 8;
	printf("haystack = '%s'\nneedle = '%c'\nn = %d\n\n", origin, (char)i, n);
	printf("address returned by memchr fct = '%p'\n", memchr(origin, i, n));
	printf("address returned by ft_memchr = '%p'\n\n", ft_memchr(origin, i, n));
	
	strcpy(origin, "haystack");
	i = 0;
	n = 9;
	printf("haystack = '%s'\nneedle = '%c'\nn = %d\n\n", origin, (char)i, n);
	printf("address returned by memchr fct = '%p'\n", memchr(origin, i, n));
	printf("address returned by ft_memchr = '%p'\n\n", ft_memchr(origin, i, n));

	strcpy(origin, "haystack");
	i = 't';
	n = 4;
	printf("haystack = '%s'\nneedle = '%c'\nn = %d\n\n", origin, (char)i, n);
	printf("address returned by memchr fct = '%p'\n", memchr(origin, i, n));
	printf("address returned by ft_memchr = '%p'\n\n", ft_memchr(origin, i, n));

	//Tests for ft_memcmp
	printf("-------------------------\n###Tests for ft_memcmp###\n-------------------------\n");
	const char string1[] = "field\0\0\0\0"; 
	const char string2[] = "field\0abc";
	n = 6;
	printf("s1 = \"field\\0\\0\\0\\0\"\ns2 = \"field\\0abc\"\nn = %d\n\n", n);
	printf("memcmp = %d\nft_memcmp = %d\n\n", memcmp(string1, string2, n), ft_memcmp(string1, string2, n));
	n = 8;
	printf("s1 = \"field\\0\\0\\0\\0\"\ns2 = \"field\\0abc\"\nn = %d\n\n", n);
	printf("memcmp = %d\nft_memcmp = %d\n\n", memcmp(string1, string2, n), ft_memcmp(string1, string2, n));

	//Tests for ft_strnstr
	printf("-------------------------\n###Tests for ft_strnstr###\n-------------------------\n");
	char	needle[] = "bao";
	char	test1[] = "see_the_bao";
	char	test2[] = "see_bao_bao";
	char	test3[] = "baao_the_sea";

	printf("needle = '%s'\ns1 = '%s'\ns2 = '%s'\ns3 = '%s'\n\n", needle, test1, test2, test3);
	printf("strnstr(s1, needle, 11) = %s\nft_strnstr(s1, needle, 11) = %s\n\n", strnstr(test1, needle, 11), ft_strnstr(test1, needle, 11));
	printf("strnstr(s1, needle, 10) = %s\nft_strnstr(s1, needle, 10) = %s\n\n", strnstr(test1, needle, 10), ft_strnstr(test1, needle, 10));
	printf("strnstr(s2, needle, 11) = %s\nft_strnstr(s2, needle, 11) = %s\n\n", strnstr(test2, needle, 11), ft_strnstr(test2, needle, 11));


	//Tests for ft_atoi
	printf("-------------------------\n###Tests for ft_atoi###\n-------------------------\n");
	strcpy(origin, "   ++32");
	printf("string = '%s'\natoi = %d\nft_atoi = %d\n\n", origin, atoi(origin), ft_atoi(origin));

	//Tests for ft_calloc
	printf("-------------------------\n###Tests for ft_calloc###\n-------------------------\n");
	size_t count = 3;
	size_t size = sizeof(int);
	char *test_mem = (char *)ft_calloc(count, size);

	printf("Test for ft_calloc(3, sizeof(int));\n");
	for (size_t calloc_count = 0; calloc_count < size * count; calloc_count++)
	{
		printf("%c, ", test_mem[calloc_count]);
	}
	count = 0;
	printf("\n\nfor count == 0, what is the address of the void ptr returned?\n");
	free(test_mem);
	test_mem = ft_calloc(count, size);
	printf("Adress : %p\n\n", test_mem);
	
	//Tests for ft_strdup
	printf("-------------------------\n###Tests for ft_strdup###\n-------------------------\n");
	strcpy(origin, "ft_strdup test");
	printf("The original string = '%s'\nstrdup = '%s'\nft_strdup = '%s'\n\n", origin, strdup(origin), ft_strdup(origin));
	strcpy(origin, "");
	printf("The original string = '%s'\nstrdup = '%s'\nft_strdup = '%s'\n\n", origin, strdup(origin), ft_strdup(origin));

	//Tests for ft_substr
	printf("-------------------------\n###Tests for ft_substr###\n-------------------------\n");
	strcpy(origin, "This is a long test for substr");
	unsigned int start = 5;
	size_t	len = 30;
	printf("Original string = '%s'\nstart = %u\nlen = %lu\n", origin, start, len);
	char *substr = ft_substr(origin, start, len);
	printf("ft_substr = '%s'\n\n", substr);
	free (substr);
	start = 5;
	len = 30;
	printf("Original string = '%s'\nstart = %u\nlen = %lu\n", origin, start, len);
	substr = ft_substr(origin, start, len);
	printf("ft_substr = '%s'\n\n", substr);
	free (substr);

	//Tests for ft_strjoin
	printf("-------------------------\n###Tests for ft_strjoin###\n-------------------------\n");
	strcpy(origin, "*First string*");
	strcpy(dest, "*Second string*");
	char	*strjoin = ft_strjoin(origin, dest);
	printf("s1 = '%s'\ns2 = '%s'\nstrjoin = '%s'\n\n", origin, dest, strjoin);

	strcpy(origin, "*First string*");
	strcpy(dest, "");
	strjoin = ft_strjoin(origin, dest);
	printf("s1 = '%s'\ns2 = '%s'\nstrjoin = '%s'\n\n", origin, dest, strjoin);

	//Tests for ft_split
	printf("-------------------------\n###Tests for ft_split###\n-------------------------\n");
	char	c;
	char	**s_split;
	int		j;
	char	s1[50];

	j = 0;
	strcpy(s1, ".This.....is..a.test");
	c = '.';
	printf("string = '%s'\nc = '%c'\n", s1, c);
	s_split = ft_split(s1, c);
	while (s_split[j])
	{
		printf("s_split[%d] = '%s'\n", j, s_split[j]);
		j++;
	}
	printf("s_split[%d] (should be null) : %p\n\n", j, s_split[j]);

	j = 0;
	strcpy(s1, "");
	printf("string = '%s'\nc = '%c'\n", s1, c);
	s_split = ft_split(s1, c);
	while (s_split[j])
	{
		printf("s_split[%d] = '%s'\n", j, s_split[j]);
		j++;
	}
	printf("s_split[%d] (should be null) : %p\n\n", j, s_split[j]);

	j = 0;
	strcpy(s1, "test");
	printf("string = '%s'\nc = '%c'\n", s1, c);
	s_split = ft_split(s1, c);
	while (s_split[j])
	{
		printf("s_split[%d] = '%s'\n", j, s_split[j]);
		j++;
	}
	printf("s_split[%d] (should be null) : %p\n\n", j, s_split[j]);

	j = 0;
	strcpy(s1, "......this...is......another.test");
	printf("string = '%s'\nc = '%c'\n", s1, c);
	s_split = ft_split(s1, c);
	while (s_split[j])
	{
		printf("s_split[%d] = '%s'\n", j, s_split[j]);
		j++;
	}
	printf("s_split[%d] (should be null) : %p\n\n", j, s_split[j]);

	j = 0;
	strcpy(s1, "test..");
	printf("string = '%s'\nc = '%c'\n", s1, c);
	s_split = ft_split(s1, c);
	while (s_split[j])
	{
		printf("s_split[%d] = '%s'\n", j, s_split[j]);
		j++;
	}
	printf("s_split[%d] (should be null) : %p\n\n", j, s_split[j]);

	j = 0;
	strcpy(s1, "With 0");
	c = 0;
	printf("string = '%s'\nc = '%c'\n", s1, c);
	s_split = ft_split(s1, c);
	while (s_split[j])
	{
		printf("s_split[%d] = '%s'\n", j, s_split[j]);
		j++;
	}
	printf("s_split[%d] (should be null) : %p\n\n", j, s_split[j]);
	
	//Tests for ft_itoa
	printf("-------------------------\n###Tests for ft_itoa###\n-------------------------\n");
	n = 3;
	printf("For n = %d\nString = '%s'\n\n", n, ft_itoa(n));
	
	n = INT_MIN;
	printf("For n = %d\nString = '%s'\n\n", n, ft_itoa(n));
	
	n = INT_MAX;
	printf("For n = %d\nString = '%s'\n\n", n, ft_itoa(n));
	
	n = -12345;
	printf("For n = %d\nString = '%s'\n\n", n, ft_itoa(n));
	
	n = 0;
	printf("For n = %d\nString = '%s'\n\n", n, ft_itoa(n));

	//Tests for ft_strmapi
	printf("-------------------------\n###Tests for ft_strmapi###\n-------------------------\n");
	char	(*itoc)(unsigned int, char);
	
	itoc = &ft_touppcase;
	strcpy(s1, "thIS Is a tEst");
	printf("original string = %s\nModified string = %s\n\n", s1, ft_strmapi(s1, itoc));

	//Tests for ft_striteri
	printf("-------------------------\n###Tests for ft_striteri###\n-------------------------\n");
	void	(*itos)(unsigned int, char *);
	itos = &ft_touppcase_iter;
	printf("Original string = %s\n", s1);
	ft_striteri(s1, itos);
	printf("Modified string = %s\n\n", s1);

	//Tests for ft_putchar_fd
	printf("-------------------------\n###Tests for ft_putchar_fd###\n-------------------------\n");
	int		fd = 1;
	
	c = 'z';
	printf("For fd = %d && c = %c\nResult of ft_putchar_fd: \n", fd, c);
	ft_putchar_fd(c, fd);
	printf("\n");

	//Tests for ft_putstr_fd
	printf("-------------------------\n###Tests for ft_putstr_fd###\n-------------------------\n");
	strcpy(s1, "This is a test string");
	printf("For fd = %d && string = '%s'\nResult of ft_putstr_fd: \n", fd, s1);
	ft_putstr_fd(s1, fd);
	printf("\n\n");

	//Tests for ft_putendl_fd
	printf("-------------------------\n###Tests for ft_putendl_fd###\n-------------------------\n");
	printf("For fd = %d && string = '%s'\nResult of ft_putstr_fd: \n", fd, s1);
	ft_putendl_fd(s1, fd);
	printf("\n");

}
