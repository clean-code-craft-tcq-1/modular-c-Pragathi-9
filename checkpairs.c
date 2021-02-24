#include <stdio.h>
#include <assert.h>
#include "colorcode.h"

//This function extracts the color-pairs from the requested pair number
ColorPair GetColorFromPairNumber(int RequestedPairNumber)
{	
   if ((RequestedPairNumber > MAX_COLORPAIR_NAME_CHARS) || (RequestedPairNumber < MIN_COLORPAIR_NAME_CHARS))
	{
	  printf("Invalid Pair number : number outside the range of color-pair number"); 
	}
   else
	{
	  ColorPair ColorfromPairNumber;
	  int zeroBasedPairNumber = RequestedPairNumber - 1;
	  ColorfromPairNumber.majorColor = (enum MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
	  ColorfromPairNumber.minorColor = (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
	  return ColorfromPairNumber;
	}
}

//This function copies the color pairs into a buffer
void ColorPairToString(const ColorPair* ExtractColorPair, char* buffer) 
{
   sprintf(buffer, "%s %s", MajorColorNames[ExtractColorPair->majorColor], MinorColorNames[ExtractColorPair->minorColor]);
}

void testNumberToPair(int RequestedPairNumber, enum MajorColor expectedMajor, enum MinorColor expectedMinor)
{
    ColorPair ExtractColorPair = GetColorFromPairNumber(RequestedPairNumber);
    char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
    ColorPairToString(&ExtractColorPair, colorPairNames);
    if ((assert(ExtractColorPair.majorColor == expectedMajor)) && (assert(ExtractColorPair.minorColor == expectedMinor)))
    {
       printf("Got pair %s\n", colorPairNames);
    }
}

//This function extracts the Pair number from the requested color-pairs
int GetPairNumberFromColor(const ColorPair* PairNumberfromColor) 
{
    return (PairNumberfromColor->majorColor * numberOfMinorColors + PairNumberfromColor->minorColor + 1);
}

void testPairToNumber(enum MajorColor RequestedMajor, enum MinorColor RequestedMinor, int expectedPairNumber)
{
    ColorPair ExtractPairNumber;
    ExtractPairNumber.majorColor = RequestedMajor;
    ExtractPairNumber.minorColor = RequestedMinor;
    int ExtractedPairNumber = GetPairNumberFromColor(&ExtractPairNumber);
    if (assert(ExtractedPairNumber == expectedPairNumber))
    {
       printf("Got pair number %d\n", ExtractedPairNumber);
    }
}
