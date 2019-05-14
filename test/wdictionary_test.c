#include "../src/string.h"
#include "../src/wdictionary.h"
#include "../thirdparty/ctest.h"

//string.c
CTEST(string, fun_slen) //Длина строки
{
	char str[30] = "animal;животное;2";
	char str_1[1] = "\0";

	int real = slen(str);
	int real1 = slen(str_1);

	const int expected = 25;
	const int expected1 = 0;

	ASSERT_EQUAL(expected, real);
	ASSERT_EQUAL(expected1, real1);
}

CTEST(string, fun_s_tok) //Разбиение строки
{
	char str[] = "animal;животное;2";
 	char delim = ';';
 	char delim_1 = '.';
 	char *ptr[3];

	int real = s_tok(str, delim, ptr);
	int real1 = s_tok(str, delim_1, ptr);

	const int expected = 3;
	const int expected1 = 1;
	
	ASSERT_EQUAL(expected, real);
	ASSERT_EQUAL(expected1, real1);
}

CTEST(string, fun_sthr) //Поиск символа в строке
{
	char str[] = "animal;животное;2";
 	char ch = 'm';
 	char ch1 = 'g';
	
	int real = schr(str, ch);
	int real1 = schr(str, ch1);

	const int expected = 3;
	const int expected1 = -1;

	ASSERT_EQUAL(expected, real);
	ASSERT_EQUAL(expected1, real1);
}

CTEST(string, fun_scopy) //Копирование строки
{
	char str[] = "animal;животное;2";
	char str_1[] = "";
	
	scopy(str_1,str);

	ASSERT_STR(str, str_1);
}

CTEST(string, fun_str_char) //Поиск подстроки в строке
{
	char str[] = "animal;животное;2";
	char ch[2] = ";";
	char ch_1[7] = "animal";

	int real = str_chr(str, ch);
	int real1 = str_chr(str, ch_1);

	const int expected = 6;
	const int expected1 = 0;
	
	ASSERT_EQUAL(expected, real);
	ASSERT_EQUAL(expected1, real1);
}

//wdictionary.c
CTEST(dictinory, fun_getrand)
{
	int min = 0;
	int max = 100;

	int rand = getrand(min,max);

	int res;
    if((rand >= 0) && (rand <= 100)){
    	res = 1;
    } else {
    	res = 0;
    }

    int exp = 1;

    ASSERT_EQUAL(exp,res);
}

CTEST(dictinory, fun_words_count) // считает без 1, но с цифрами строчки
{
	int value = 1;
	FILE *input = fopen("../test/dic_test.txt", "r");

	int real = words_count(input, value);
	
	const int expected = 6;
	
	ASSERT_EQUAL(expected, real);
}

CTEST(dictinory, fun_dictionary_init)
{
	int words = 7;
	dictionary* test = dictionary_init(words);

	ASSERT_NOT_NULL(test);
	free(test);
}

CTEST(dictinory, fun_dictionary_read) //выделяет массив структур
{
	FILE *input = fopen("../test/dic_test.txt", "r");
	int value = 4;
	int words = words_count(input, value);
	dictionary* test = dictionary_init(words);

	test = dictionary_read(test,words,input,value);

	ASSERT_NULL(test);
	free(test);
}

CTEST(dictinory, fun_dictionary_shuf) //тусование русских слов
{
	FILE *input = fopen("../text/dictionary.txt", "r");
	int value = 1;
	int words = words_count(input, value);
	dictionary* test = dictionary_init(words);

	dictionary_read(test,words,input,value);

	dictionary lord = test[0];

	dictionary_shuf(test, words);

    int res = 0;
    if (lord.engword != test[0].engword) {
		res = 1;
	}

	int exp = 1;

	ASSERT_EQUAL(exp, res);
}



