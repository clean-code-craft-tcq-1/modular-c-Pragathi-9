//header file

//Define the Major and Minor colors used in the transmission lines
enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};

typedef struct {
    enum MajorColor majorColor;
    enum MinorColor minorColor;
} ColorPair; 


inline const char* MajorColorNames[] = {
    "White", "Red", "Black", "Yellow", "Violet"
};

//Calculate number of Major colors
inline int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);


inline const char* MinorColorNames[] = 
{
   "Blue", "Orange", "Green", "Brown", "Slate"
};

//Calculate number of minor colors
inline int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

inline const int MAX_COLORPAIR_NAME_CHARS = 25;
inline const int MIN_COLORPAIR_NAME_CHARS = 1;

//function declaration

ColorPair GetColorFromPairNumber(int);
void ColorPairToString(const ColorPair* ExtractColorPair, char* buffer);
void testNumberToPair(int, enum MajorColor expectedMajor, enum MinorColor expectedMinor);
int GetPairNumberFromColor(const ColorPair* PairNumberfromColor );
void testPairToNumber(enum MajorColor RequestedMajor, enum MinorColor RequestedMinor, int);
void reference_manual();
