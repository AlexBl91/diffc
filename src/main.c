#include "../include/declaration.h"

static void permutationForKey(int key[], int bits[], int start_bit, int iteration = 0)
{
	if(iteration == TWENTY_EIGHT_BITS)
		return;

	for(int i = 0; i < 8; i++, iteration++)
	{
		if(iteration == TWENTY_EIGHT_BITS)
			break;
		if((start_bit -= 8) < 0)
			start_bit = SIXTY_FOUR_BITS - 8 - 1;
		bits[iteration] = key[start_bit];
	}

	permutationForKey(key, bits, start_bit, iteration);
}

void firstKeyPermutation(const char *key, int bits_in_key[], int c[], int d[])
{
	int start_bit = 56;
	
	getBits(bits_in_key, key);
	printf("Key binary representation:  ");
	for(int i = 0; i < SIXTY_FOUR_BITS; i++)
		printf("%d", bits_in_key[i]);
	printf("\n");

	permutationForKey(bits_in_key, c, start_bit);
	permutationForKey(bits_in_key, d, start_bit + 6);

	printf("C array: ");
	for(int i = 0; i < TWENTY_EIGHT_BITS; i++)
		printf("%d", c[i]);
	printf("\n");

	printf("D array: ");
	for(int i = 0; i < TWENTY_EIGHT_BITS; i++)
		printf("%d", d[i]);
	printf("\n");
}

static void permutationForText(int text[], int bits[], int start_bit, int iteration = 0)
{
	if(iteration == THIRTY_TWO_BITS)
		return;

	int current_bit = start_bit;
	for(int i = 0; i < 8; i++, iteration++, current_bit -= 8)
		bits[iteration] = text[current_bit];

	permutationForText(text, bits, start_bit + 2, iteration);
}

static void getBits(int bits_in_text[], const char *text)
{
	int j = 0;
	while(*text != '\0')
	{
		for(int i = 7; i >= 0; i--, j++)
			bits_in_text[j] = (*text >> i) & 0x01;

		text++;
	}
}

void firstTextPermutation(const char *text, int bits_in_text[], int r[], int l[])
{
	int start_bit = 57;
	
	getBits(bits_in_text, text);
	printf("Text binary representation: ");
	for(int i = 0; i < SIXTY_FOUR_BITS; i++)
		printf("%d", bits_in_text[i]);
	printf("\n");

	permutationForText(bits_in_text, r, start_bit);
	permutationForText(bits_in_text, l, start_bit - 1);

	printf("R array: ");
	for(int i = 0; i < THIRTY_TWO_BITS; i++)
		printf("%d", r[i]);
	printf("\n");

	printf("L array: ");
	for(int i = 0; i < THIRTY_TWO_BITS; i++)
		printf("%d", l[i]);
	printf("\n");
}

int main()
{
	const char *open_text = "abcdefgh";
	const char *key = "12345678";

	int r[THIRTY_TWO_BITS];
	int l[THIRTY_TWO_BITS];
	int c[TWENTY_EIGHT_BITS];
	int d[TWENTY_EIGHT_BITS];

	int bits_in_text[SIXTY_FOUR_BITS];
	int bits_in_key[SIXTY_FOUR_BITS];

	firstTextPermutation(open_text, bits_in_text, r, l);
	firstKeyPermutation(key, bits_in_key, c, d);

	return 0;
}