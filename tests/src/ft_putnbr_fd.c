#include "config.h"

Test(ft_putnbr_fd, writes_positive_number_to_file_descriptor)
{
	char	buf[POSLEN];
	int		fd;

	fd = open(FILENAME, O_CREAT | O_RDWR, S_IRWXU);
	ft_putnbr_fd(POSNBR, fd);
	lseek(fd, 0, SEEK_SET);
	read(fd, buf, POSLEN);
	cr_expect(zero(int, strncmp(buf, POSSTR, POSLEN)),
		"ft_putnbr_fd: expected positive number to be written \
		to given file descriptor");
	close(fd);
	remove(FILENAME);
}

Test(ft_putnbr_fd, writes_negative_number_to_file_descriptor)
{
	char	buf[NEGLEN];
	int		fd;

	fd = open(FILENAME, O_CREAT | O_RDWR, S_IRWXU);
	ft_putnbr_fd(NEGNBR, fd);
	lseek(fd, 0, SEEK_SET);
	read(fd, buf, NEGLEN);
	cr_expect(zero(int, strncmp(buf, NEGSTR, NEGLEN)),
		"ft_putnbr_fd: expected negative number to be written \
		to given file descriptor");
	close(fd);
	remove(FILENAME);
}
