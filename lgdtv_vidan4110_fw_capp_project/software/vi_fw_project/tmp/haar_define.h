//
// 
// (c) 2011 Brian Fransioli, CAPP Lab
// 
#ifndef __HAAR_DEFS_H_
#define __HAAR_DEFS_H_

#ifdef _DEBUG
#include <stdio.h>
#endif /* _DEBUG */

typedef struct _Haar_Image {
	
	char type;
	
	int width;
	int height;

	void *data;

} Haar_Image;

typedef struct _Haar_FeatureRect {
	
	int x;
	int y;

	int width;
	int height;

	int weight;

} Haar_FeatureRect;

typedef struct _Haar_Feature {

	int n;

	Haar_FeatureRect *r1;
	Haar_FeatureRect *r2;
	Haar_FeatureRect *r3;

	float thresh;

} Haar_Feature;

typedef struct _Haar_Window {
	int x;
	int y;

	int width;
	int height;

} Haar_Window;

// Set source image size for correct array indexing in memory
#define SOURCE_IMAGE_WIDTH (640)
#define SOURCE_IMAGE_HEIGHT (480)

#ifdef _DEBUG
// Set MEMSIZE to be 4 Mb (only applicable for simulating memory in PC testing)
#define HAAR_MEMSIZE (2 << 22)

// Fake Memory (for testing on PC)
char Haar_memory[HAAR_MEMSIZE];

#endif /* _DEBUG */

// Modify this for chip
//#define HAAR_MEMORY_BASE_ADDR (&Haar_memory[0])
#define HAAR_MEMORY_BASE_ADDR (0)
//#define MEMORY_BASE_ADDR 0xFACEFACE

// Set the memory address based on offset to MEMORY_BASE_ADDR
// Example: Image *integral_image;
// SET_MEMORY(integral_image, Image, INTEGRAL_IMAGE_MEMORY_OFFSET);
// 
#ifdef _DEBUG

#define SET_MEMORY(var, type, offset) \
	do { \
		var = (type *)( my_c2_addr_gen((int)(HAAR_MEMORY_BASE_ADDR + offset)) ); \
		printf("setting %s to %x\n", #var, HAAR_MEMORY_BASE_ADDR+offset); \
	} while(0)

#else

	#define SET_MEMORY(var, type, offset) \
	do { \
		var = (type *)( my_c2_addr_gen((int)(HAAR_MEMORY_BASE_ADDR + offset)) ); \
	} while(0)

#endif /* _DEBUG */

// Bogus memory address to catch errors/work to do
//#define TODO (0xDEADBEEF)

// Quickfix padding to add to some areas when memory alignment may be an issue
#define HAAR_PAD (64)

// OFFSETs are offsets from the base address (MEMORY_BASE_ADDR)
//#define INTEGRAL_IMAGE_MEMORY_ADDR (TODO)
//#define SOURCE_IMAGE_MEMORY_ADDR (TODO)
//#define SOURCE_IMAGE_MEMORY_OFFSET (TODO)
//#define SOURCE_IMAGE_DATA_MEMORY_OFFSET (TODO)
//#define FEATURE_COUNT_ADDR (TODO)
//#define FEATURE_COUNT_OFFSET (1228800)
//#define FEATURE_START_MEMORY_ADDR (TODO)

int haar_integral_base;

#define INTEGRAL_IMAGE_DATA_MEMORY_OFFSET   (haar_integral_base)
#define INTEGRAL_IMAGE_MEMORY_OFFSET        (INTEGRAL_IMAGE_DATA_MEMORY_OFFSET + 4 * SOURCE_IMAGE_WIDTH * SOURCE_IMAGE_HEIGHT + HAAR_PAD)
#define FEATURE_WORKING_MEMORY_OFFSET       (INTEGRAL_IMAGE_MEMORY_OFFSET + HAAR_PAD)
#define FEATURE_COUNT_OFFSET                (FEATURE_WORKING_MEMORY_OFFSET + sizeof(Haar_Feature) + sizeof(Haar_FeatureRect)*3 + HAAR_PAD)
#define FEATURE_START_MEMORY_OFFSET         (FEATURE_COUNT_OFFSET + 2*sizeof(int) + HAAR_PAD)

// integral_image.c
void integral_image_new(Haar_Image *image, Haar_Image *integral_image);

// haar.c
int haar_compute_feature(Haar_Image *integral_image, Haar_FeatureRect *f, Haar_Window *win);

extern int my_c2_addr_gen (int addr);

// features.c
int features_get_total();
Haar_Feature *features_get_by_num(int i);
Haar_Feature *features_set_current(int i, float scale, float win_ratio);

#endif /* __HAAR_DEFS_H_ */
