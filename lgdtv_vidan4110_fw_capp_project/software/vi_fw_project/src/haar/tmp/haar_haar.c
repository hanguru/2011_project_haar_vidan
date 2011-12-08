//
// 
// (c) 2011 Brian Fransioli, Hansoo Seong, CAPP Lab

#include "haar_define.h"

int 
haar_compute_feature(Haar_Image *integral_image, Haar_FeatureRect *f, Haar_Window *win)
{
    int TL_x, TL_y;
    int TR_x, TR_y;
    int BL_x, BL_y;
    int BR_x, BR_y;

    // HAAR feature calculation rectangles
    // If our feature looks like...
    // [ A B ]
    // [ C D ]
    // 
    // then we can find the integral sum value by:
    // 
    // value = D - B - C - A
    unsigned int A, B, C, D;

    unsigned int *data;

    int width, height;

    // Setup the topleft, topright, botleft, botright coords
    // For the feature inside the given window
    TL_x = win->x + f->x;
    TL_y = win->y + f->y;

    TR_x = TL_x + f->width;
    TR_y = TL_y;

    BL_x = TL_x;
    BL_y = TL_y + f->height;

    BR_x = TR_x;
    BR_y = BL_y;

    width = integral_image->width;
    height = integral_image->height;

    data = (unsigned int *)integral_image->data;

    //D = data[ BR_y * width + BR_x ];
    D = *((unsigned int*)my_c2_addr_gen((int)(data + BR_y * width + BR_x )));

    // Boundary check - if we want the entire column from the top
    // then we have nothing to subtract (no part B)
    if ( (TR_y - 1) < 0 )
        B = 0;
    else
        //B = data[ (TR_y-1) * width + BR_x ];
        B = *((unsigned int*)my_c2_addr_gen((int)(data + (TR_y-1) * width + BR_x )));

    // Boundary check - if we want the entire row from the left
    // then we have nothing to subtract (no part C)
    if ( (BL_x - 1) < 0 )
        C = 0;
    else
        //C = data[ BL_y * width + (BL_x - 1) ];
        C = *((unsigned int*)my_c2_addr_gen((int)(data + BL_y * width + (BL_x - 1) )));

    // Boundary check - if there is no diagonally adjacent point
    // to the top left then we have nothing to add (no part A)
    if ( ((TL_y - 1) < 0 ) || ((TL_x - 1) < 0 ) )
        A = 0;
    else
        //A = data[ (TL_y-1)*width + (TL_x - 1) ];
        A = *((unsigned int*)my_c2_addr_gen((int)(data + (TL_y-1)*width + (TL_x - 1) )));

    return( D - B - C + A );
}
