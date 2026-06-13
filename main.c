/* Требуется написать программу solution, выполняющую разбор опций командной строки и выводящую в стандартный поток вывода символ '+', если набор корректен, или '-' в противном случае.
Описание возможных опций:
-q | --query (опциональный, но обязательно требует аргумента)
-i | --longinformationrequest (опциональный)
-v | --version (опциональный)
Пример вызова
./solution -q 9 --version
+
Программа выводит символ корректности опций командной строки */

#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

int main(int argc, char **argv)
{
  // отключение вывода потока ошибок
	extern int opterr;
	opterr = 0;
	int is_correct = 1;
	int opchar = 0;
	int opindex = 0;
	struct option opts[] = {
    // опция с обязательным аргументом
		{"query", required_argument, 0, 'q'},
    // опции без аргументов
		{"longinformationrequest", no_argument, 0, 'i'},
		{"version", no_argument, 0, 'v'},
		{0,0,0,0}
	};
  // перебор аргументов командной строки
	while (-1 != (opchar = getopt_long(argc, argv, "q:iv", opts, &opindex))) {
    // обработка конкретного аргумента
		switch (opchar) {
		case 'q':
      // если опция q передана без аргумента
			if (optarg == NULL || optarg[0] == '\0')
				is_correct = 0;
			break;
		case 'i':
			break;
		case 'v':
			break;
		case '?':
      // если указана несуществующая опция
			is_correct = 0;
			break;
		default:
			is_correct = 0;
		}
	}
	printf("%c", is_correct ? '+' : '-');
	return 0;
}
