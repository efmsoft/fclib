#include <proto.h>

static DWORD dwSoftRndGen = 0x87654321L;    // Software Random generator
                                            // storage, initialized by
                                            // abstract value

#define  MULTIPLIER      0x015A4E35L        // Random generator Magic Value
#define  INCREMENT       1                  // Random generator Default
                                            // increment
#define MAX_RND_WORD            0x7FFF      // Max. value returned from RandWord

void InitSoftRandGenerator(DWORD dwStartValue)
{
  dwSoftRndGen = dwStartValue;            // Initialization generator

  RandWord();                                 // Run one generator step
}

WORD RandWord(void)
{
  // Note: rand uses a multiplicative congruential random number
  //       generator with period 2^32 to return successive pseudo-
  //       random numbers in the range from 0 to 2^15 - 1 (0x7FFF).
  //       The generator is reinitialized by calling srand with an
  //       argument value of 1. It can be set to a new starting point by
  //       calling srand with a given seed number.

  dwSoftRndGen = MULTIPLIER * dwSoftRndGen + INCREMENT;

  return (WORD)((WORD)(dwSoftRndGen >> 16) & MAX_RND_WORD);
}

DWORD RandDWord(void)
{
  return (DWORD)((DWORD)(RandWord() << 16) + RandWord());
}

