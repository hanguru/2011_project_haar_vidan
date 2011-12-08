//
// 
// (c) 2011 Brian Fransioli, Hansoo Seong, CAPP Lab

#include "haar_define.h"

Haar_Feature *f, *f1, *f2, *f3;

int Haar_init = 0;
int Haar_total = -1;

static void
features_init(float win_ratio)
{
    int *n;
    long offset;

    offset = FEATURE_START_MEMORY_OFFSET;

    // Features

    SET_MEMORY_C2(f1, Haar_Feature, FEATURE_START_MEMORY_OFFSET);
    SET_MEMORY_C2(f1->r1, Haar_FeatureRect, FEATURE_START_MEMORY_OFFSET + sizeof(Haar_Feature));
    SET_MEMORY_C2(f1->r2, Haar_FeatureRect, FEATURE_START_MEMORY_OFFSET + sizeof(Haar_Feature) + sizeof(Haar_FeatureRect));
    SET_MEMORY_C2(f1->r3, Haar_FeatureRect, FEATURE_START_MEMORY_OFFSET + sizeof(Haar_Feature) + sizeof(Haar_FeatureRect) * 2);

    offset += sizeof(Haar_Feature) + sizeof(Haar_FeatureRect)*3;

    SET_MEMORY_C2(f2, Haar_Feature, offset);
    SET_MEMORY_C2(f2->r1, Haar_FeatureRect, offset + sizeof(Haar_Feature));
    SET_MEMORY_C2(f2->r2, Haar_FeatureRect, offset + sizeof(Haar_Feature) + sizeof(Haar_FeatureRect));
    SET_MEMORY_C2(f2->r3, Haar_FeatureRect, offset + sizeof(Haar_Feature) + sizeof(Haar_FeatureRect) * 2);

    offset += sizeof(Haar_Feature) + sizeof(Haar_FeatureRect)*3;

    SET_MEMORY_C2(f3, Haar_Feature, offset);
    SET_MEMORY_C2(f3->r1, Haar_FeatureRect, offset + sizeof(Haar_Feature));
    SET_MEMORY_C2(f3->r2, Haar_FeatureRect, offset + sizeof(Haar_Feature) + sizeof(Haar_FeatureRect));
    SET_MEMORY_C2(f3->r3, Haar_FeatureRect, offset + sizeof(Haar_Feature) + sizeof(Haar_FeatureRect) * 2);
    

    // Top Feature (f1)
    f1->r1->x = 0*win_ratio;
    f1->r1->y = 0*win_ratio;
    f1->r1->width = 50*win_ratio;
    f1->r1->height = 30*win_ratio;
    
    f1->r1->weight = 1;

    f1->r2->x = 50*win_ratio;
    f1->r2->y = 0*win_ratio;
    f1->r2->width = 50*win_ratio;
    f1->r2->height = 30*win_ratio;
    
    f1->r2->weight = -1;

    f1->n = 2;
    f1->thresh = 145000*win_ratio*win_ratio;
    //f1->thresh = 100000*win_ratio*win_ratio;

    
    // Middle Feature (f2)
    f2->r1->x = 0*win_ratio;
    f2->r1->y = 30*win_ratio;
    f2->r1->width = 30*win_ratio;
    f2->r1->height = 40*win_ratio;
    
    f2->r1->weight = -1;
    
    f2->r2->x = 30*win_ratio;
    f2->r2->y = 30*win_ratio;
    f2->r2->width = 40*win_ratio;
    f2->r2->height = 40*win_ratio;

    f2->r2->weight = 1;

    f2->r3->x = 70*win_ratio;
    f2->r3->y = 30*win_ratio;
    f2->r3->width = 30*win_ratio;
    f2->r3->height = 40*win_ratio;

    f2->r3->weight = -1;

    f2->n = 3;
    //f2->thresh = 110000;
    f2->thresh = 35000*win_ratio*win_ratio;
    //f2->thresh = 20000*win_ratio*win_ratio;
    
    // Bottom Feature (f3)
    f3->r1->x = 0*win_ratio;
    f3->r1->y = 70*win_ratio;
    f3->r1->width = 50*win_ratio;
    f3->r1->height = 30*win_ratio;

    f3->r1->weight = -1;

    f3->r2->x = 50*win_ratio;
    f3->r2->y = 70*win_ratio;
    f3->r2->width = 50*win_ratio;
    f3->r2->height = 30*win_ratio;

    f3->r2->weight = 1;

    f3->n = 2;
    f3->thresh = 110000*win_ratio*win_ratio;
    //f3->thresh = 100000*win_ratio*win_ratio;
    

    // EOFeatures ;)

    SET_MEMORY_C2(n, int, FEATURE_COUNT_OFFSET);
    *n = 3;

    Haar_init = 1;
}

int
features_get_total()
{
    int *t;

    SET_MEMORY_C2(t, int, FEATURE_COUNT_OFFSET);

    if (Haar_total == -1)
        Haar_total = *t = 3;

    return( *t );
}

static void
features_scale_rect(Haar_FeatureRect *src, Haar_FeatureRect *dst, float scale)
{
    dst->height = src->height * scale;

    dst->width = src->width * scale;

    dst->x = src->x * scale;

    dst->y = src->y * scale;

    dst->weight = src->weight;

    return;
}

Haar_Feature *
features_set_current(int i, float scale, float win_ratio)
{    

    if (!Haar_init) {
        //MSG(F_ONE);
        SET_MEMORY_C2(f, Haar_Feature, FEATURE_WORKING_MEMORY_OFFSET);
        //MSG(F_TWO);
    
        SET_MEMORY_C2(f->r1, Haar_FeatureRect, FEATURE_WORKING_MEMORY_OFFSET + sizeof(Haar_Feature));
        SET_MEMORY_C2(f->r2, Haar_FeatureRect, FEATURE_WORKING_MEMORY_OFFSET + sizeof(Haar_Feature) + sizeof(Haar_FeatureRect));
        SET_MEMORY_C2(f->r3, Haar_FeatureRect, FEATURE_WORKING_MEMORY_OFFSET + sizeof(Haar_Feature) + sizeof(Haar_FeatureRect) * 2);

        //MSG(F_THREE);
        features_init(win_ratio);
        //MSG(F_FOUR);
    }

    switch(i) {
    case 1:
        f->n = f1->n;
        
        //MSG(F_FIVE);
        features_scale_rect(f1->r1, f->r1, scale);
        //MSG(F_SIX);
        features_scale_rect(f1->r2, f->r2, scale);
        //features_scale_rect(f1->r3, f->r3, scale);

        f->thresh = f1->thresh * scale * scale;

        break;

    case 2:
        
        f->n = f2->n;
        
        features_scale_rect(f2->r1, f->r1, scale);
        features_scale_rect(f2->r2, f->r2, scale);
        features_scale_rect(f2->r3, f->r3, scale);

        f->thresh = f2->thresh * scale* scale;
        break;

    case 3:
    default:
        
        f->n = f3->n;
        
        features_scale_rect(f3->r1, f->r1, scale);
        features_scale_rect(f3->r2, f->r2, scale);
        //features_scale_rect(f3->r3, f->r3, scale);

        f->thresh = f3->thresh * scale* scale;
        break;
    }
    //MSG(F_SEVEN);
    return(f);
}

Haar_Feature *
features_get_by_num(int i)
{
    if (!Haar_init)
        features_init(1);

    switch(i) {
    case 1:
        return(f1);

    case 2:
        return(f2);

    case 3:
    default:
        return(f3);
    }

}
