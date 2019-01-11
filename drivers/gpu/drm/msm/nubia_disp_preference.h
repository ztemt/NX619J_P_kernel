#ifndef _NUBIA_DISP_PREFERENCE_
#define _NUBIA_DISP_PREFERENCE_

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/list.h>
#include <linux/spinlock.h>
#include <linux/device.h>
#include <linux/timer.h>
#include <linux/err.h>
#include <linux/ctype.h>
#include "sde_kms.h"
#include "dsi_panel.h"
#include "dsi_display.h"

/* ------------------------- General Macro Definition ------------------------*/
#define NUBIA_DISP_COLORTMP_DEBUG        0

enum {
	SATURATION_OFF = 23,
	SATURATION_SOFT,
	SATURATION_STD,
	SATURATION_GLOW
};

enum {
	COLORTMP_OFF = 23,
	COLORTMP_WARM,
	COLORTMP_NORMAL,
	COLORTMP_COOL
};

enum {
	CABC_OFF = 23,
	CABC_LEVER1 ,
	CABC_LEVER2 ,
	CABC_LEVER3
};
#define NUBIA_DISP_LOG_TAG "ZtemtDisp"
#define NUBIA_DISP_LOG_ON

#ifdef  NUBIA_DISP_LOG_ON
#define NUBIA_DISP_ERROR(fmt, args...) printk(KERN_ERR "[%s] [%s: %d] "  fmt, \
	NUBIA_DISP_LOG_TAG, __FUNCTION__, __LINE__, ##args)
#define NUBIA_DISP_INFO(fmt, args...) printk(KERN_ERR "[%s] [%s: %d] "  fmt, \
	NUBIA_DISP_LOG_TAG, __FUNCTION__, __LINE__, ##args)

    #ifdef  NUBIA_DISP_DEBUG_ON
#define  NUBIA_DISP_DEBUG(fmt, args...) printk(KERN_DEBUG "[%s] [%s: %d] "  fmt, \
	NUBIA_DISP_LOG_TAG, __FUNCTION__, __LINE__, ##args)
    #else
#define NUBIA_DISP_DEBUG(fmt, args...)
    #endif
#else
#define NUBIA_DISP_ERROR(fmt, args...)
#define NUBIA_DISP_INFO(fmt, args...)
#define NUBIA_DISP_DEBUG(fmt, args...)
#endif

/* ----------------------------- Structure ----------------------------------*/
struct nubia_disp_type{
  int en_cabc;
  int en_saturation;
  int en_colortmp;
  unsigned int cabc;
  unsigned int saturation;
  unsigned int colortmp;
};

/* ------------------------- Function Declaration ---------------------------*/
void nubia_disp_preference(void);
void nubia_set_dsi_ctrl(struct dsi_display *display);
#endif
