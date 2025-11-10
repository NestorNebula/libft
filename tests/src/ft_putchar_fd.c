#include "config.h"

#define PUTCHAR_FD_CHAR 'c'

Test(ft_putchar_fd, writes_char_to_expected_file)
{
	int		fd;
	char	c;

	fd = open(FILENAME, O_CREAT | O_RDWR, S_IRWXU);
	ft_putchar_fd(PUTCHAR_FD_CHAR, fd);
	lseek(fd, 0, SEEK_SET);
	read(fd, &c, 1);
	cr_expect(eq(c, PUTCHAR_FD_CHAR),
		"ft_putchar_fd: expected character to be copied in given file descriptor");
	close(fd);
	remove(FILENAME);
}
