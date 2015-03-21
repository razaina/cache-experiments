
LOCAL_PATH := $(call my-dir)

#include $(CLEAR_VARS)
#LOCAL_MODULE    := cache-exp-1
#LOCAL_SRC_FILES := cache-exp-1.c
#LOCAL_ARM_MODE := arm
#LOCAL_CFLAGS := -g -O3
#include $(BUILD_EXECUTABLE)

#include $(CLEAR_VARS)
#LOCAL_MODULE    := cache-exp-2
#LOCAL_SRC_FILES := cache-exp-2.c
#LOCAL_ARM_MODE := arm
#LOCAL_CFLAGS := -g -O3
#include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)
LOCAL_MODULE    := rijndael 
LOCAL_SRC_FILES := rijndael-alg-fst.c rijndael-api-fst.c aes.c
LOCAL_ARM_MODE := arm
LOCAL_CFLAGS := -g -ggdb 
include $(BUILD_EXECUTABLE)
