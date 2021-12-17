/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 15:46:04 by cbilbo            #+#    #+#             */
/*   Updated: 2021/07/23 17:22:42 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libasm.h"
#include <errno.h>

int	main(void)
{
	/////////////////////////////////////////////////////////////////
	printf("\n==========ft_strdup===========\n");
	char	*empty;
	empty = ft_strdup("");
	printf("\nEMPTY : \"%s\"", empty);
	free(empty);
	char	*str;
	str = ft_strdup("test");
	printf("\nTEST: \"%s\"", str);
	free(str);
	char	*lstr;	
	lstr = ft_strdup("\n\"To be, or not to be, that is the question:\nWhether 'tis nobler in the mind to suffer\nThe slings and arrows of outrageous fortune,\nOr to take arms against a sea of troubles\nAnd by opposing end them. To die—to sleep,\nNo more; and by a sleep to say we end\nThe heart-ache and the thousand natural shocks\nThat flesh is heir to: 'tis a consummation\nDevoutly to be wish'd. To die, to sleep;\nTo sleep, perchance to dream—ay, there's the rub:\nFor in that sleep of death what dreams may come,\nWhen we have shuffled off this mortal coil,\nMust give us pause—there's the respect\nThat makes calamity of so long life.\nFor who would bear the whips and scorns of time,\nTh'oppressor's wrong, the proud man's contumely,\nThe pangs of dispriz'd love, the law's delay,\nThe insolence of office, and the spurns\nThat patient merit of th'unworthy takes,\nWhen he himself might his quietus make\nWith a bare bodkin? Who would fardels bear,\nTo grunt and sweat under a weary life,\nBut that the dread of something after death,\nThe undiscovere'd country, from whose bourn\nNo traveller returns, puzzles the will,\nAnd makes us rather bear those ills we have\nThan fly to others that we know not of?\nThus conscience doth make cowards of us all,\nAnd thus the native hue of resolution\nIs sicklied o'er with the pale cast of thought,\nAnd enterprises of great pith and moment\nWith this regard their currents turn awry\nAnd lose the name of action. \"\n");
	printf("\nLONG: \"%s\"\n", lstr);
	printf("\n==========ft_strlen===========\n");
	printf("\nEMPTY: original = %lu, my = %zu, errno = %d\n", strlen(""), ft_strlen(""), errno);
	printf("\n\"test\": original = %lu, my = %zu, errno = %d\n", strlen("test"), ft_strlen("test"), errno);
	printf("\"%s\":\n  original = %lu, my = %zu, errno = %d\n", lstr, strlen(lstr), ft_strlen(lstr), errno);
	printf("\n==========ft_strcpy===========\n");
	char	*a;
	char	*b;
	a = calloc(10, 1);
	b = calloc(10, 1);
	memset(a, 0, 10);
	memset(b, 0, 10);
	printf("dst = \"%s\", src = \"%s\"\n\nALL ARGS EMPTY:\n  dst = \"%s\", src = \"%s\"\n-------------", a, b, ft_strcpy(a, b), b);
	printf("\ndst = \"\", src = \"hello\":\n dst = \"%s\", src = \"%s\"\n-----------------", ft_strcpy(a, "hello"), "hello");
	printf("\ndst = \"hello\", src = \"\":\n dst = \"%s\", src = \"%s\"\n-----------------", ft_strcpy(a, b), b);
	printf("\nORIGINAL : dst = \"hello\", src = \"ves\":\n dst = \"%s\", src = \"%s\"\n--------------", strcpy(a, "ves"), "ves");
	a = strcpy(a, "hello");
	char *s;
	s = (char *)malloc(1500);
	printf("\nMY = dst = \"hello\", src = \"ves\":\n dst = \"%s\", src = \"%s\"\n--------------", ft_strcpy(a, "ves"), "ves");
	printf("\ndst = \"\", src = \"To be or not ....\":\n\n dst = %s src = %s strcmp = %d\n", ft_strcpy(s, lstr), lstr, strcmp(s, lstr));
	printf("\n==========ft_strcmp===========\n");
	memset(a, 0, 10);
	memset(b, 0, 10);
	printf("\nNULL:\n  original = %d, my = %d, errno = %d\n--------------", strcmp(a, b), ft_strcmp(a, b), errno);
	printf("\ns1 = \"%s\", s2 = \"%s\":\n  original = %d, my = %d, errno = %d\n--------------", "", "1", strcmp("", "1"), ft_strcmp("", "1"), errno);
	printf("\ns1 = \"%s\", s2 = \"%s\":\n  original = %d, my = %d, errno = %d\n--------------", "1", "", strcmp("1", ""), ft_strcmp("1", ""), errno);
	printf("\ns1 = \"%s\", s2 = \"%s\":\n  original = %d, my = %d, errno = %d\n--------------", "hello", "world", strcmp("hello", "world"), ft_strcmp("hello", "world"), errno);
	printf("\ns1 = \"%s\", s2 = \"%s\":\n  original = %d, my = %d, errno = %d\n--------------", s, lstr, strcmp(s, lstr), ft_strcmp(s, lstr), errno);
	s[30] = '3';
	printf("\ns1 = \"%s\", s2 = \"%s\":\n  original = %d, my = %d, errno = %d\n--------------\n", s, lstr, strcmp(s, lstr), ft_strcmp(s, lstr), errno);	
	printf("\n==========ft_write===========\n");
	int fd = open("./test.txt", O_RDWR);
	printf("  original = %zd, my = %zd, errno = %d\n", write(1, "Hello world!\n", 14), ft_write(1, "Hello world!\n", 14), errno);
	printf("  original = %zd, my = %zd, errno = %d\n", write(fd, "Hello world!\n------------", 13), ft_write(fd, "Hello world!\n", 13), errno);
	printf("Wrong FD:\n");
	printf("  original = %zd, errno = %d, srterror = %s\n", write(-1, "Hello world!\n", 13), errno, strerror(errno));
	errno = 0;
	printf("  my = %zd, errno = %d, srterror = %s\n", ft_write(-1, "Hello world!\n", 13), errno, strerror(errno));
	fd = close(fd);
	errno = 0;
	printf("\n==========ft_read===========\n");
	fd = open("./test.txt", O_RDWR);
	char buf[10000];
	memset(buf, 0, 10000);
	printf(" original = %zd, buf = %s, ", read(0, buf, 10000), buf);
	memset(buf, 0, 10000);
	printf(" my = %zd, buf = %s\n", ft_read(0, buf, 10000), buf);
	memset(buf, 0, 10000);
	int r = read(fd, buf, 6);
	printf("original = count (%d)= %s|", r, buf);
	r = read(fd, buf, 6);
	printf("%s (%d)", buf, r);
	memset(buf, 0, 10000);
	r = ft_read(fd, buf, 6);
	printf("my = count (%d)= %s|", r, buf);
	r = ft_read(fd, buf, 6);
	printf("%s (%d)\n", buf, r);	
	printf("Wrong FD:\n");
	printf("  original = %zd, errno = %d, srterror = %s\n", read(-1, buf, 13), errno, strerror(errno));
	errno = 0;
	printf("  my = %zd, errno = %d, srterror = %s\n", ft_read(-1, buf, 13), errno, strerror(errno));
	memset(buf, 0, 10000);
	close(fd);
	free(a);
	free(b);
	free(lstr);
	free(s);
	return (0);

}