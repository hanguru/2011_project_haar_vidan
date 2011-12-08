void Configure_via_SW();
void InitFPGA();
void InitFPGA1();
void WaitSrcFrame();
void WaitStreamWriting();
//void SetupForDoubleBuffer(int frame_sel, int width_offset, int height_offset);
//void SetupForDoubleBuffer(int frame_sel, int double_buffer_en, int width_offset, int height_offset, int src_ref_frame_diff);
void Config_DVPn_via_HIF(); // jarre 2008.05.08 DVP HIF +++

extern int img_sel;
