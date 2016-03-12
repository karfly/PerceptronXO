#include "bmp_to_array.h"

using std::cout;

vector<RGBQuad>  ReadPixelsWithInfo(const char *path, BmpFileHeader *bfile, BmpInfoHeader *binfo) {
	assert(path		!= NULL);
	assert(bfile	!= NULL);
	assert(binfo	!= NULL);

	int i = 0;
	FILE* file = fopen(path, "rb");

	assert(file);

	// Reading BMPFILEHEADER
	bfile->bfType		= Read_u16(file);
	bfile->bfSize		= Read_u32(file);
	bfile->bfReserved1	= Read_u16(file);
	bfile->bfReserved2	= Read_u16(file);
	bfile->bfOffBits	= Read_u32(file);

	// Reading BMPINFOHEADER
	binfo->biSize			= Read_u32(file);
	binfo->biWidth			= Read_u32(file);
	binfo->biHeight			= Read_s32(file);
	binfo->biPlanes			= Read_u16(file);
	binfo->biBitCount		= Read_u16(file);
	binfo->biCompression	= Read_u32(file);
	binfo->biSizeImage		= Read_u32(file);
	binfo->biXPelsPerMeter	= Read_s32(file);
	binfo->biYPelsPerMeter	= Read_s32(file);
	binfo->biClrUsed		= Read_u32(file);
	binfo->biClrImportant	= Read_u32(file);

	// Ignoring palette
/*	for (i = 0; i < bfile->bfOffBits - 54; i++) {		// 54 - number of bytes, which have been already read
		getc(file);
	}
*/
	fseek(file, bfile->bfOffBits - NUMB_OF_BYTES_IN_BFH_AND_BIH, SEEK_CUR);

	int size_of_pic = binfo->biWidth * binfo->biHeight;
	vector<RGBQuad> pixels(size_of_pic);
	
	// Reading pixels
	for (i = 0; i < size_of_pic; i++) {
		pixels[i].rgbBlue			= getc(file);
		pixels[i].rgbGreen			= getc(file);
		pixels[i].rgbRed			= getc(file);
		pixels[i].rgbReserved		= getc(file);
	}

	fclose(file);

	return pixels;
}


vector<RGBQuad>  ReadPixels(const char *path) {
	assert(path != NULL);
	int i = 0;
	FILE* file = fopen(path, "rb");
	unsigned int bfOffBits = 0, biWidth = 0, biHeight = 0;

	// Reading BMPFILEHEADER
				Read_u16(file);					// bfile->bfType
				Read_u32(file);					// bfile->bfSize
				Read_u16(file);					// bfile->bfReserved1
				Read_u16(file);					// bfile->bfReserved2
	bfOffBits =	Read_u32(file);					// bfile->bfOffBits

	// Reading BMPINFOHEADER
				Read_u32(file);					// binfo->biSize
	biWidth =	Read_u32(file);					// binfo->biWidth
	biHeight =	Read_s32(file);					// binfo->biHeight 
				Read_u16(file);					// binfo->biPlanes
				Read_u16(file);					// binfo->biBitCount
				Read_u32(file);					// binfo->biCompression
				Read_u32(file);					// binfo->biSizeImage
				Read_s32(file);					// binfo->biXPelsPerMeter
				Read_s32(file);					// binfo->biYPelsPerMeter
				Read_u32(file);					// binfo->biClrUsed
				Read_u32(file);					// binfo->biClrImportant

	// Ignoring palette
	fseek(file, bfOffBits - NUMB_OF_BYTES_IN_BFH_AND_BIH, SEEK_CUR);

	int size_of_pic = biWidth * biHeight;
	vector<RGBQuad> pixels(size_of_pic);
	
	// Reading pixels
	for (i = 0; i < size_of_pic; i++) {
		pixels[i].rgbBlue			= getc(file);
		pixels[i].rgbGreen		= getc(file);
		pixels[i].rgbRed			= getc(file);
		pixels[i].rgbReserved		= getc(file);
	}

	fclose(file);

	return pixels;

}

WORD Read_u16(FILE *file) {
	assert(file != NULL);

	unsigned char x0 = 0, x1 = 0;

	x0 = getc(file);
	x1 = getc(file);

	return ((x1 << 8) | x0);
}

DWORD Read_u32(FILE *file){
	assert(file != NULL);

	unsigned char x0 = 0, x1 = 0, x2 = 0, x3 = 0;

	x0 = getc(file);
	x1 = getc(file);
	x2 = getc(file);
	x3 = getc(file);

	return ((((((x3 << 8) | x2) << 8) | x1) << 8) | x0);
}



LONG Read_s32(FILE *file){
	assert(file != NULL);

	unsigned char x0 = 0, x1 = 0, x2 = 0, x3 = 0;

	x0 = getc(file);
	x1 = getc(file);
	x2 = getc(file);
	x3 = getc(file);

	return ((((((x3 << 8) | x2) << 8) | x1) << 8) | x0);
}