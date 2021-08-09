#include "ADCPrint.h"

#include <xc.h>
#include <stdbool.h>

static volatile bool resultFlag = false;
static volatile bool gainFlag = false;

void setResultFlag(void)
{
    resultFlag = true;
}

void clearResultFlag(void)
{
    resultFlag = false;
}

bool getResultFlag(void)
{
    return resultFlag;
}

void setGainFlag(void)
{
    gainFlag = true;    
}

void clearGainFlag(void)
{
    gainFlag = false;
}

bool getGainFlag(void)
{
    return gainFlag;
}
