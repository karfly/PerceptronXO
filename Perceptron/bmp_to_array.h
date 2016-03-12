#ifndef BMP_TO_ARRAY_H
#define BMP_TO_ARRAY_H

#include <iostream>
#include <vector>
#include <assert.h>
#include <malloc.h>

using std::vector;

typedef _int16 WORD;
typedef _int32 DWORD;
typedef int	   LONG;

#define NUMB_OF_BYTES_IN_BFH_AND_BIH 54

typedef struct {
	WORD	bfType;				// Type of file. For BMP it is "BM"
	DWORD	bfSize;				// Size of the file in bytes
	WORD	bfReserved1;		// Reserved space #1 (must be 0)
	WORD	bfReserved2;		// Reserved space #2 (must be 0)
	DWORD	bfOffBits;			// Bits offset. Shows, where the bit array itself starts
} BmpFileHeader;

typedef struct {
	DWORD	biSize;				// Size of the structure itself (must be sizeof(BmpInfoHeader))
	DWORD	biWidth;			// The width of the picture in pixels
	LONG	biHeight;			// The height of the picture in pixels
	WORD	biPlanes;			// Number of planes (must be 1)
	WORD	biBitCount;			// Number of bits for 1 pixel
	DWORD	biCompression;		// Type of compression (must be BI_RGB)
	DWORD	biSizeImage;		// Size of the picture (if it is not compressed, it is 0)
	LONG	biXPelsPerMeter;	// X axis resolution (in Pixels per Meter)
	LONG	biYPelsPerMeter;	// Y axis resolution (in Pixels per Meter)
	DWORD	biClrUsed;			// Number of the colours, which are used in the picture (if it's 0, max number of colours, which are allowed by biBitCount, are used)
	DWORD	biClrImportant;		// Number of important colours (if it's 0, all the colours are important)
} BmpInfoHeader;

typedef struct {
	LONG	rgbBlue;			// Space for BLUE
	LONG	rgbGreen;			// Space for GREEN
	LONG	rgbRed;				// Space for RED
	LONG	rgbReserved;		// Reserved space
} RGBQuad;


	/**
	 * ReadPixelsWithInfo
	 * @brief	Reads info from bmp-file. Works for 32bpp BGR bmps
	 *
	 * @param	path	Path to the file
	 *			bfile	Pointer to your BmpFileHeader, which will be filed with information about bmp-file
	 *			binfo	Pointer to your BmpInfoHeader, which will be filed with information about bmp-file
	 * @return			Array of RGBQuad structures, which is consisted of info about pixel's colours and transparency
	 */
vector<RGBQuad> ReadPixelsWithInfo(const char *path, BmpFileHeader *bfile, BmpInfoHeader *binfo);

	/**
	 * ReadPixels
	 * @brief	Reads only pixels from bmp-file, skipping info. Works for 32bpp BGR bmps
	 *
	 * @param	path	Path to the file
	 * @return			Array of RGBQuad structures, which is consisted of information about pixels' coloures and transparency
	 */
int ReadPixels(const char *path, vector<RGBQuad> & pixels);


WORD	Read_u16	(FILE *file);
DWORD	Read_u32	(FILE *file);
LONG	Read_s32	(FILE *file);

#endif