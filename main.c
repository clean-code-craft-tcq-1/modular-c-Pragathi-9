#include <stdio.h>
#include <assert.h>
//enumerate major and minor colors
enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};

//struct to fetch minor and major colors
typedef struct {
    enum MajorColor majorColor;
    enum MinorColor minorColor;
} ColorPair; 

//characters for print
const char* MajorColorNames[] = {
    "White", "Red", "Black", "Yellow", "Violet"
};

//Calculate number of major colors
int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);

//you cannot change the minor color value
const char* MinorColorNames[] = 
{
   "Blue", "Orange", "Green", "Brown", "Slate"
};

//should the max be 25?
const int MAX_COLORPAIR_NAME_CHARS = 25;
const int MIN_COLORPAIR_NAME_CHARS = 1;


//no. of minor colors
int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

//find the sprintf function, is this printing the reference document
//int sprintf (char *string, const char *form, … );

void ColorPairToString(const ColorPair* colorPair, char* buffer) 
{
   sprintf(buffer, "%s %s", MajorColorNames[colorPair->majorColor], MinorColorNames[colorPair->minorColor]);
}

ColorPair GetColorFromPairNumber(int pairNumber)
{	if (pairNumber>MAX_COLORPAIR_NAME_CHARS || pairNumber<MIN_COLORPAIR_NAME_CHARS)
	{
		printf("Come back when sober"); //hidden req
	}
	else
	{
    ColorPair colorPair;
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColor = (enum MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    colorPair.minorColor = (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorPair;
	}
}

int GetPairNumberFromColor(const ColorPair* colorPair) 
{
    return (colorPair->majorColor * numberOfMinorColors + colorPair->minorColor + 1);
}

void testNumberToPair(int pairNumber, enum MajorColor expectedMajor, enum MinorColor expectedMinor)
{
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
    ColorPairToString(&colorPair, colorPairNames);
    printf("Got pair %s\n", colorPairNames);
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}

void testPairToNumber(enum MajorColor major, enum MinorColor minor, int expectedPairNumber)
{
    ColorPair colorPair;
    colorPair.majorColor = major;
    colorPair.minorColor = minor;
    int pairNumber = GetPairNumberFromColor(&colorPair);
    printf("Got pair number %d\n", pairNumber);
    assert(pairNumber == expectedPairNumber);
}

void reference_manual()
{
	ColorPair Pair;
	int numberpair = 1;
	char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
	printf(" PAIRNUMBER \t\t\t\t\t MAJORCOLOR-MINORCOLOR ");
	while (numberpair <= MAX_COLORPAIR_NAME_CHARS)
	{
		ColorPair Pair = GetColorFromPairNumber(numberpair);
    		ColorPairToString(&Pair, colorPairNames);
		printf(" %d \t\t\t\t\t %s\n ",numberpair,colorPairNames);
		numberpair++;
		
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

