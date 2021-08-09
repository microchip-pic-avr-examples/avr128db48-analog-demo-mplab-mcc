#ifndef ADCPRINT_H
#define	ADCPRINT_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdbool.h>

    /*
     * These function set/get/clear flags from the ISR to the main function.
     */
    
    void setResultFlag(void);
    void clearResultFlag(void);
    bool getResultFlag(void);
    
    void setGainFlag(void);
    void clearGainFlag(void);
    bool getGainFlag(void);

#ifdef	__cplusplus
}
#endif

#endif	/* ADCPRINT_H */

