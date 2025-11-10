#include "config.h"

Test(ft_putendl_fd, writes_string_and_newline_to_file_descriptor)
{
	char	buf[STR_SIZE + 1];
	int		fd;

	fd = open(FILENAME, O_CREAT | O_RDWR, S_IRWXU);
	ft_putendl_fd(STR, fd);
	lseek(fd, 0, SEEK_SET);
	read(fd, buf, STR_SIZE);
	buf[STR_SIZE] = '\0';
	cr_expect(zero(int, strncmp(buf, STR, STR_SIZE - 1)),
		"ft_putendl_fd: expected string to be written to given file descriptor");
	cr_expect(eq(int, buf[STR_SIZE - 1], '\n'),
		"ft_putendl_fd: expected new line to be written to given file descriptor");
	close(fd);
	remove(FILENAME);
}
