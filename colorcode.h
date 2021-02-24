//header file

//Define the Major and Minor colors used in the transmission lines
enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};

extern typedef struct {
    enum MajorColor majorColor;
    enum MinorColor minorColor;
} ColorPair; 


extern const char* MajorColorNames[] = {
    "White", "Red", "Black", "Yellow", "Violet"
};

//Calculate number of Major colors
extern int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);


extern const char* MinorColorNames[] = 
{
   "Blue", "Orange", "Green", "Brown", "Slate"
};

//Calculate number of minor colors
extern int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

extern const int MAX_COLORPAIR_NAME_CHARS = 25;
extern const int MIN_COLORPAIR_NAME_CHARS = 1;

//function declaration

extern ColorPair GetColorFromPairNumber(int);
extern void ColorPairToString(const ColorPair* ExtractColorPair, char* buffer);
extern void testNumberToPair(int, enum MajorColor expectedMajor, enum MinorColor expectedMinor);
extern int GetPairNumberFromColor(const ColorPair* PairNumberfromColor );
extern void testPairToNumber(enum MajorColor RequestedMajor, enum MinorColor RequestedMinor, int);
extern void reference_manual();
