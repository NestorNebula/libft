#include "config.h"

Test(ft_putstr_fd, writes_string_in_file_descriptor)
{
	int	fd;
	char	buf[STR_SIZE];

	fd = open(FILENAME, O_CREAT | O_RDWR, S_IRWXU);
	ft_putstr_fd(STR, fd);
	lseek(fd, 0, SEEK_SET);
	read(fd, buf, STR_SIZE - 1);
	buf[STR_SIZE - 1] = '\0';
	cr_expect(zero(int, strcmp(buf, STR)),
		"ft_putstr_fd: expected string to be copied in given file descriptor");
	close(fd);
	remove(FILENAME);
}
