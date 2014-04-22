/*
 * Copyright © 2014 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sub license, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
 * IN NO EVENT SHALL PRECISION INSIGHT AND/OR ITS SUPPLIERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "i965_drv_video.h"

extern struct hw_context *i965_proc_context_init(VADriverContextP, struct object_config *);
extern struct hw_context *g4x_dec_hw_context_init(VADriverContextP, struct object_config *);
static const struct hw_codec_info g4x_hw_codec_info = {
    .dec_hw_context_init = g4x_dec_hw_context_init,
    .enc_hw_context_init = NULL,
    .proc_hw_context_init = NULL,
    .max_width = 2048,
    .max_height = 2048,

    .has_mpeg2_decoding = 1,

    .num_filters = 0,
};

extern struct hw_context *ironlake_dec_hw_context_init(VADriverContextP, struct object_config *);
static const struct hw_codec_info ilk_hw_codec_info = {
    .dec_hw_context_init = ironlake_dec_hw_context_init,
    .enc_hw_context_init = NULL,
    .proc_hw_context_init = i965_proc_context_init,
    .max_width = 2048,
    .max_height = 2048,

    .has_mpeg2_decoding = 1,
    .has_h264_decoding = 1,
    .has_vpp = 1,
    .has_accelerated_putimage = 1,

    .num_filters = 0,
};

extern struct hw_context *gen6_dec_hw_context_init(VADriverContextP, struct object_config *);
extern struct hw_context *gen6_enc_hw_context_init(VADriverContextP, struct object_config *);
static const struct hw_codec_info snb_hw_codec_info = {
    .dec_hw_context_init = gen6_dec_hw_context_init,
    .enc_hw_context_init = gen6_enc_hw_context_init,
    .proc_hw_context_init = i965_proc_context_init,
    .max_width = 2048,
    .max_height = 2048,

    .has_mpeg2_decoding = 1,
    .has_mpeg2_encoding = 1,
    .has_h264_decoding = 1,
    .has_h264_encoding = 1,
    .has_vc1_decoding = 1,
    .has_vpp = 1,
    .has_accelerated_getimage = 1,
    .has_accelerated_putimage = 1,
    .has_tiled_surface = 1,

    .num_filters = 2,
    .filters = {
        { VAProcFilterNoiseReduction, I965_RING_NULL },
        { VAProcFilterDeinterlacing, I965_RING_NULL },
    },
};

extern struct hw_context *gen7_dec_hw_context_init(VADriverContextP, struct object_config *);
extern struct hw_context *gen7_enc_hw_context_init(VADriverContextP, struct object_config *);
static const struct hw_codec_info ivb_hw_codec_info = {
    .dec_hw_context_init = gen7_dec_hw_context_init,
    .enc_hw_context_init = gen7_enc_hw_context_init,
    .proc_hw_context_init = i965_proc_context_init,
    .max_width = 4096,
    .max_height = 4096,

    .has_mpeg2_decoding = 1,
    .has_mpeg2_encoding = 1,
    .has_h264_decoding = 1,
    .has_h264_encoding = 1,
    .has_vc1_decoding = 1,
    .has_jpeg_decoding = 1,
    .has_vpp = 1,
    .has_accelerated_getimage = 1,
    .has_accelerated_putimage = 1,
    .has_tiled_surface = 1,
    .has_di_motion_adptive = 1,
    .has_blending = 1,

    .num_filters = 2,
    .filters = {
        { VAProcFilterNoiseReduction, I965_RING_NULL },
        { VAProcFilterDeinterlacing, I965_RING_NULL },
    },
};

extern struct hw_context *gen75_dec_hw_context_init(VADriverContextP, struct object_config *);
extern struct hw_context *gen75_enc_hw_context_init(VADriverContextP, struct object_config *);
extern struct hw_context *gen75_proc_context_init(VADriverContextP, struct object_config *);
static const struct hw_codec_info hsw_hw_codec_info = {
    .dec_hw_context_init = gen75_dec_hw_context_init,
    .enc_hw_context_init = gen75_enc_hw_context_init,
    .proc_hw_context_init = gen75_proc_context_init,
    .max_width = 4096,
    .max_height = 4096,

    .has_mpeg2_decoding = 1,
    .has_mpeg2_encoding = 1,
    .has_h264_decoding = 1,
    .has_h264_encoding = 1,
    .has_vc1_decoding = 1,
    .has_jpeg_decoding = 1,
    .has_vpp = 1,
    .has_accelerated_getimage = 1,
    .has_accelerated_putimage = 1,
    .has_tiled_surface = 1,
    .has_di_motion_adptive = 1,
    .has_di_motion_compensated = 1,
    .has_blending = 1,
    .has_h264_mvc_decoding = 1,
    .has_h264_mvc_encoding = 1,

    .num_filters = 5,
    .filters = {
        { VAProcFilterNoiseReduction, I965_RING_VEBOX },
        { VAProcFilterDeinterlacing, I965_RING_VEBOX },
        { VAProcFilterSharpening, I965_RING_NULL },
        { VAProcFilterColorBalance, I965_RING_VEBOX},
        { VAProcFilterSkinToneEnhancement, I965_RING_VEBOX},
    },
};

extern struct hw_context *gen8_dec_hw_context_init(VADriverContextP, struct object_config *);
extern struct hw_context *gen8_enc_hw_context_init(VADriverContextP, struct object_config *);
static const struct hw_codec_info bdw_hw_codec_info = {
    .dec_hw_context_init = gen8_dec_hw_context_init,
    .enc_hw_context_init = gen8_enc_hw_context_init,
    .proc_hw_context_init = gen75_proc_context_init,
    .max_width = 4096,
    .max_height = 4096,

    .has_mpeg2_decoding = 1,
    .has_mpeg2_encoding = 1,
    .has_h264_decoding = 1,
    .has_h264_encoding = 1,
    .has_vc1_decoding = 1,
    .has_jpeg_decoding = 1,
    .has_vpp = 1,
    .has_accelerated_getimage = 1,
    .has_accelerated_putimage = 1,
    .has_tiled_surface = 1,
    .has_di_motion_adptive = 1,
    .has_di_motion_compensated = 1,
    .has_vp8_decoding = 1,
    .has_blending = 1,
    .has_h264_mvc_decoding = 1,
    .has_h264_mvc_encoding = 1,

    .num_filters = 5,
    .filters = {
        { VAProcFilterNoiseReduction, I965_RING_VEBOX },
        { VAProcFilterDeinterlacing, I965_RING_VEBOX },
        { VAProcFilterSharpening, I965_RING_NULL }, /* need to rebuild the shader for BDW */
        { VAProcFilterColorBalance, I965_RING_VEBOX},
        { VAProcFilterSkinToneEnhancement, I965_RING_VEBOX},
    },
};

const struct hw_codec_info *
i965_get_codec_info(int devid)
{
    switch (devid) {
#undef CHIPSET
#define CHIPSET(id, family, dev, str) case id: return &family##_hw_codec_info;
#include "i965_pciids.h"
    default:
        return NULL;
    }
}
