#include "../src/wdictionary.h"
#include "../thirdparty/ctest.h"

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

CTEST(dictinory, fun_words_count) //-
{
	int value = 1;
	FILE *input = fopen("dic_test.txt", "r");

	int real = words_count(input, value);
	
	const int expected = 0;
	
	ASSERT_EQUAL(expected, real);

}

CTEST(dictinory, fun_dictionary_init)
{
	int words = 7;
	dictionary* test = dictionary_init(words);

	ASSERT_NOT_NULL(test);
	free(test);

}

CTEST(dictinory, fun_dictionary_read)
{
	FILE *input = fopen("dic_test.txt", "r");
	int value = 4;
	int words = words_count(input, value);
	dictionary* test = dictionary_init(words);

	dictionary_read(test,words,input,value);
    
    int res = 0;
	if (test[0].engword == "cook")
	{
		res = 1;
	}

	int exp = 1;
	ASSERT_EQUAL(exp, res);
	
}

CTEST(dictinory, fun_dictionary_shuf)
{
	FILE *input = fopen("dic_test.txt", "r");
	int value = 4;
	int words = words_count(input, value);
	dictionary* test = dictionary_init(words);

	dictionary_read(test,words,input,value);

	dictionary lord = test[0];

	dictionary_shuf(test, words);

	int res = 0;
	if (lord.engword != test[0].engword)
	{
		res = 1;
	}

	int exp = 1;

	ASSERT_EQUAL(exp, res);

}



