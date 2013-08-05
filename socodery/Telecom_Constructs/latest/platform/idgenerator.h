/*
ID Generator Module :  header file
*/

#ifndef ID_GENERATOR_H
#define ID_GENERATOR_H

#include <stdio.h>
#include "prototype.h"

typedef int	uIdType;

extern ReturnType allocateid(uIdType * puid);

extern ReturnType freeid(uIdType id);

#endif
