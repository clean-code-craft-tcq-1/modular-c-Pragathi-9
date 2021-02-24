#include <stdio.h>
#include <assert.h>
#include "colorcode.h"


// This function prints the reference manaul that maps the color-names to the corresponding numbers 
void reference_manual()
{
  ColorPair Display;
  int PairNumber = 1;
  char StoreColorPair[MAX_COLORPAIR_NAME_CHARS];
  printf(" PAIRNUMBER \t\t\t\t MAJORCOLOR-MINORCOLOR\n ");
	
  while (PairNumber <= MAX_COLORPAIR_NAME_CHARS)
   {
     Display = GetColorFromPairNumber(PairNumber);
     ColorPairToString(&Display, StoreColorPair);
     printf(" %d \t\t\t\t\t %s\n ", PairNumber,StoreColorPair);
     PairNumber++;
		
   }	
}


int main() 
{
    testNumberToPair(4, WHITE, BROWN);
    testNumberToPair(5, WHITE, SLATE);

    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);
    
    reference_manual();
	
    return 0;
}
