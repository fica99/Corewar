/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:42:59 by aashara-          #+#    #+#             */
/*   Updated: 2020/06/25 20:48:04 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define FT_LLONG_MAX 9223372036854775807
# define FT_ULLONG_MAX 18446744073709551615ULL

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			*ft_realloc(void *buf, size_t old, size_t new_size);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
void			*ft_memset(void *b, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			*ft_memchr(const void *arr, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strcpy(char *destination, const char *source);
char			*ft_strncpy(char *destination, const char *source, size_t n);
char			*ft_strcat(char *destination, const char *arr);
char			*ft_strchr(const char *str, int ch);
char			*ft_strrchr(const char *str, int ch);
char			*ft_strstr(const char *string1, const char *string2);
char			*ft_strnstr(const char *s1, const char *s2, size_t len);
int				ft_strncmp(const char *string1, const char *string2, size_t n);
int				ft_atoi(const char *str);
int				ft_isdigit(int character);
int				ft_isalpha(int ch);
int				ft_isalnum(int ch);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char*));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putendl(char *s);
void			ft_putnbr_fd(int n, int fd);
char			*ft_itoa(int n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strncat(char *destination, const char *append, size_t n);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int				ft_isspace(int c);
int				ft_isupper(char c);
void			ft_swap(int *start, int *end);
int				ft_min(int a, int b);
int				ft_max(int a, int b);
int				ft_pathcmp(char *p1, char *p2);
char			*ft_pathjoin(char *s1, char *s2);
#endif
