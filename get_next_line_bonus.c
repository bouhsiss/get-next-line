#include"get_next_line_bonus.h"

int find_n(char *save)
{
	int i;

	i = 0;
	if (!save)
		return(1);
	while (save[i])
	{
		if (save[i] == '\n')
			return (0);
		i++;
	}
	return(1);
}

char *new_line(char *save)
{
	int i;

	i = 0;
	if (!save[0])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	return(ft_substr(save, 0, i+1));
}

char *rest(char *save)
{
	int i;
	char *rest;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i])
	{
		if (save[i] == '\n')
		{
			rest = ft_substr(save, i+1, (ft_strlen(save)));
			free (save);
			return (rest);
		}
		i++;
	}
	free (save);
	return (NULL);	
}

char *get_next_line(int fd )
{
    static char *save[1024];
    int i;
	char *buff;
	char *ret;

	i = 1;
	if (fd < 0 || BUFFER_SIZE < 0)
		return(NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (find_n(save[fd]) && i)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			return(0);
		}
		buff[i] = '\0';
		save[fd] = ft_strjoin(save[fd], buff);
	}
	free(buff);
	ret = new_line(save[fd]);
	save[fd] = rest(save[fd]);
	return (ret);
}