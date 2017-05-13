/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 02:51:56 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/13 18:22:13 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <limits.h>
# include <termios.h>
# include <term.h>
# include <dirent.h>

# define BUFF_SIZE 86
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define ABS(x) (((x) < 0) ? -(x) : (x))

typedef struct		s_push
{
	int				value;
	int				rotate_top;
	int				rotate_bottom;
	struct s_push	*next;
}					t_push;

void				push_back(t_push **list, int data);
void				clear_list(t_push **list);
void				print_list(t_push *list);
int					lenght_list(t_push *list);
t_push				*creat_new_list(int data);
void				push_front(t_push **list, int data);
void				if_remove_list(t_push **list, int data);
int					search_elem(t_push *list, int data);

void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strcpy (char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, char const *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *big, const char *little, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
long long			ft_atoi(const char *nptr);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size, size_t ssize);
char				*ft_strnew(size_t size);
void				ft_striter(char *s, void(*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *s));
char				*ft_strtrim(char const *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_itoa(long long int n);
void				ft_putstr(char const *s, unsigned int size);
char				*ft_strrev(char *s);
int					ft_issspace(char c);
int					get_next_line(int const fd, char **line);
char				**ft_strsplit(char *s1, char character);
int					ft_putchar(int c);
void				ft_putnbr(long long nbr);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
char				*ft_strndup(char *str, int size);
DIR					*ft_opendir(const char *str);
int					if_a_character(const char *str, char character);
int					count_n_character(const char *str, int character);
int					clear_tab(char **board);
char				*ft_strndup_x(char *line_command, char character);
void				push_char(char *buff, char character, int *ite);
char				**strsplit(char *s1, char character);
void				ft_putendl(char *str);
int					returns_small_value_array(int *board, int size);
int					returns_big_value_array(int *board, int size);
int					returns_pos_array(int *board, int size, int data);
int					returns_last_array(int *board, int size);
int					*transforms_list_to_array(void *list);
int					is_sorted_array(int *board, int size);
void				print_array(int *board, int size);
int					is_sorted_ascending_array(int *board, int size);
int					is_sorted_descending_array(int *board, int size);
int					getintsize(long long data);
int					ft_strlen_matrice(char **board);
int					is_digit(const char *s1);
int					ft_strlen_n(const char *str, char character);
#endif
