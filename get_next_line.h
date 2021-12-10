#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<fcntl.h>

char *get_next_line(int fd);
char	*ft_strcat(char	*dest, char	*src);
char	*ft_strcpy(char	*dest, char	*src);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char *s1);

#endif