#include <stdint.h>
#include <stdbool.h>

#ifndef CCL_H_INCLUDED
#define CCL_H_INCLUDED

#include "../system/utils/compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
  @Summary
    Initializes the CCL.

  @Description
    This routine initializes the CCL.
    This routine should only be called once during system initialization.

  @Preconditions
    None

  @Param
    None
    
   @Example
    <code>
    CCL_Initialize();
    </code>
*/
int8_t CCL_Initialize(void);

#ifdef __cplusplus
}
#endif

#endif /* CCL_H_INCLUDED */
