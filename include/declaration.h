#include <stdio.h>

#define SIXTY_FOUR_BITS 64
#define THIRTY_TWO_BITS 32
#define TWENTY_EIGHT_BITS 28

static void permutationForKey(int *, int *, int, int);
static void permutationForText(int *, int *, int, int);
static void getBits(int *, const char *); 
void firstTextPermutation(const char *, int *, int, int);
void firstKeyPermutation(const char *, int *, int, int);