//
// 
// (c) 2011 Brian Fransioli, Hansoo Seong, CAPP Lab

#include "haar_define.h"

void 
haar_draw_rect (int *src_frame_addr, int src_frame_width, int x, int y, int width, int height, int color, int fill)
{
    //int frame_width = (ORC_CAM_SIZE & 0xffff);
    //int frame_y_base = VIM_Y_BASE;
    int frame_width = (int)src_frame_width;
    int frame_y_base = (int)src_frame_addr;

    int x_start = (x>>2)<<2;
    int x_end   = ((x+width-1)>>2)<<2;
    int y_start = y;
    int y_end   = y+height-1;

    int i,j;


    if ( fill )
    { 
        // top & bottom line
        for (j=x_start; j<= x_end ; j=j+4)
        {
            // fill
            for (i=y_start; i<= y_end ; i=i+1)
            *( (int*)my_c2_addr_gen(frame_y_base + i*frame_width + j) ) = ((color)<<24) + ((color)<<16) + ((color)<<8) + ((color)<<0) ;
        }
    }
    else 
    {

        // top & bottom line
        for (j=x_start; j<= x_end ; j=j+4)
        {
            // top
            i = y_start;
            *( (int*)my_c2_addr_gen(frame_y_base + i*frame_width + j) ) = ((color)<<24) + ((color)<<16) + ((color)<<8) + ((color)<<0) ;

            // bottom
            i = y_end;
            *( (int*)my_c2_addr_gen(frame_y_base + i*frame_width + j) ) = ((color)<<24) + ((color)<<16) + ((color)<<8) + ((color)<<0) ;
        }

        // left & right line
        for (i=y_start; i<= y_end; i= i+1)
        {
            // left
            // the reason why adding 3 is the endian of ViDan is big.
            // (3, 2, 1, 0), (3, 2, 1, 0) ...
            j= x_start+3;
            *( (char*)my_c2_addr_gen(frame_y_base + i*frame_width + j ) ) = color;

            // right
            j= x_end;
            *( (char*)my_c2_addr_gen(frame_y_base + i*frame_width + j) ) = color;
        }
    }
}

int matched_flag_debug = 0;

void
//main(int argc, char **argv)
Haar_ViDan(int src_img_width, int src_img_height, int src_frame_addr, int src_frame_width, int integral_base_addr)
{
    
    //MSG(HAAR_START);

    //int *haar_src_base;
    int haar_src_base;

    haar_src_base = src_frame_addr;
    haar_integral_base = (int)integral_base_addr;

    Haar_Image haar_image; 
    Haar_Image haar_integral_image;

    int i;//, n;
    float win_ratio = 1;//0.25;
    //int x, y;
    //int step;
    //unsigned char *data;

    int fresult, fresult2, fresult3, thresh;

    //int frames;
    int win_width, win_height, search_step;

    float scale;
    int scale_int;

    Haar_Window win;
    
    Haar_Feature *f;//, *f1, *f2, *f3;

    // source image setting
    //SET_MEMORY(haar_image, Haar_Image, SOURCE_IMAGE_MEMORY_OFFSET);
    haar_image.height = src_img_height;
    haar_image.width = src_frame_width;
    SET_MEMORY(haar_image.data, unsigned char, (int *)haar_src_base);

    // integral image setting
    //SET_MEMORY(haar_integral_image, Haar_Image, INTEGRAL_IMAGE_MEMORY_OFFSET);
    haar_integral_image.width = src_img_width;
    haar_integral_image.height = src_img_height;
    //haar_integral_image.width = 350;    // for test only
    //haar_integral_image.height = 200;   // for test only

    SET_MEMORY(haar_integral_image.data, void, INTEGRAL_IMAGE_DATA_MEMORY_OFFSET);

    //n = 0;
    //frames = 0;

//start:
//    while(1) {

        // assume grayscale frame is ready in "image" variable


        //frames++;

        // for Debugging
        //MSG(DEFINE_CHECK);
        // *((int*)INTEGRAL_IMAGE_DATA_MEMORY_OFFSET) = (int)INTEGRAL_IMAGE_MEMORY_OFFSET;
        // *((int*)INTEGRAL_IMAGE_DATA_MEMORY_OFFSET) = (int)FEATURE_WORKING_MEMORY_OFFSET;
        // *((int*)INTEGRAL_IMAGE_DATA_MEMORY_OFFSET) = (int)FEATURE_COUNT_OFFSET;
        // *((int*)INTEGRAL_IMAGE_DATA_MEMORY_OFFSET) = (int)FEATURE_START_MEMORY_OFFSET;
        //MSG(DEFINE_CHECK_DONE);
        //MSG(FEATURE_TEST_START);
        //f = features_set_current(1, 1, win_ratio);
        //MSG(FEATURE_TEST_END);

        //MSG(INTEGRAL_START);
        // make the integral image from the source frame
        //haar_integral_image = integral_image_new(&haar_image);
        integral_image_new(&haar_image, &haar_integral_image );
        //MSG(INTEGRAL_END);

        // Default window size of 100,100
        // we will scale down and up around this base size
        win.x = 0;
        win.y = 0;

        //MSG(ONE);

        win_width = 100*win_ratio;
        win_height = 100*win_ratio;
        //win_width = 25;
        //win_height = 25;
        //search_step = 10;
        search_step = 5;
        //search_step = 2;
    
        // Scan the image from lowest to largest scale
        //for (scale = 1.0; scale <= 1.4; scale = scale+0.1) {
        //for (scale = 0.3; scale <= 0.31; scale = scale+0.01) {
        //for (scale = 0.8; scale <= 1.2; scale = scale+0.05) {

        // float for_loop works strange.. so, scale_int for_loop is used 
        //for (scale_int = 10; scale_int < 11; scale_int = scale_int+1) {
        for (scale_int = 6; scale_int < 15; scale_int = scale_int+2) {
        //for (scale_int = 3; scale_int < 4; scale_int = scale_int+1) {

            scale = scale_int * 0.1;

            //MSG(TWO);
            win.width  = (int)(win_width *scale);

            //MSG(THREE);
            win.height = (int)(win_height*scale);

            //MSG(FOUR);

            //if (scale == (float)0.3)      MSG(SCALE_DOT_THREE);
            //else if (scale == (float)0.4) MSG(SCALE_DOT_FOUR);
            //else if (scale == (float)0.5) MSG(SCALE_DOT_FIVE);
            //else if (scale == (float)0.6) MSG(SCALE_DOT_SIX);
            //else if (scale == (float)0.7) MSG(SCALE_DOT_SEVEN);
            //else if (scale == (float)0.8) MSG(SCALE_DOT_EIGHT);
            //else if (scale == (float)0.9) MSG(SCALE_DOT_NINE);
            //else if (scale == (float)1.0) MSG(SCALE_ONE_DOT_ZERO);
            //else if (scale == (float)1.1) MSG(SCALE_ONE_DOT_ONE);
            //else if (scale == (float)1.2) MSG(SCALE_ONE_DOT_TWO);
            //else if (scale == (float)1.3) MSG(SCALE_ONE_DOT_THREE);
            //else if (scale == (float)1.4) MSG(SCALE_ONE_DOT_FOUR);

            //MSG(SCALE_ONE);

            // Scan the window across the entire line (column span)
            // then go to the next line
            for (win.y = 0; win.y < (haar_integral_image.height - win.height - 1); win.y += search_step) {
                for (win.x = 0; win.x < (haar_integral_image.width - win.width - 1); win.x += search_step) {

            // for simple test
            //for (win.y = 9; win.y < 12; win.y += search_step) {
            //    for (win.x = 64; win.x < 67; win.x += search_step) {

                    // Evaluate the HAAR features we have (up to 3)
                    for (i = 1; i <= 3; i++) {

                        // Put the requested feature at the appropriate scale
                        // into the temp feature working space
                        f = features_set_current(i, scale, win_ratio);

                        // Compute up to three rectangles for each feature
                        fresult = haar_compute_feature(&haar_integral_image, f->r1, &win);
                        fresult = fresult * f->r1->weight;

                
                        fresult2 = haar_compute_feature(&haar_integral_image, f->r2, &win);
                        fresult2 = fresult2 * f->r2->weight;

                
                        if (f->n == 3) {
                            fresult3 = haar_compute_feature(&haar_integral_image, f->r3, &win);
                            fresult3 = fresult3 * f->r3->weight;

                        } else {
                            fresult3 = 0;
                        }

                        // Threshold for the feature (weights are 1 or -1 from above to indicate black/white)
                        thresh = fresult + fresult2 + fresult3;

                        if (thresh < f->thresh) {

                            //if (i==1) MSG(MATCH_ZERO);
                            //else if (i==2) MSG(MATCH_ONE);
                            //else if (i==3) MSG(MATCH_TWO);

                            break;
                        }
                    }

                    // passed all stages (1,2,3)
                    if (i == 4) {
                
                        // insert code to draw the passed window rectangle on 'image'
                        // draw rectangle when i==3 & passed !!!
                        haar_draw_rect ((int *)haar_src_base, src_frame_width, win.x, win.y, win.width, win.height, 255, 0);
                        //MSG(MATCHED);
                    }

                }
                //MSG(SEARCH_ONELINE_END);
            }

        }
//    } // while(1)

    //MSG(HAAR_END);

    return;
}


