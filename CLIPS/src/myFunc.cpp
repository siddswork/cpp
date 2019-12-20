/*
 * myFunc.c
 *
 *  Created on: Aug 29, 2017
 *      Author: sidd
 */
extern "C" {
#include "clips.h"
#include "myFunc.h"
}

double rta(void *environment)
{
	double base, height;
	/*==================================*/
	/* Check for exactly two arguments. */
	/*==================================*/
	if (EnvArgCountCheck(environment,"rta",EXACTLY,2) == -1) return(-1.0);
	/*===============================================*/
	/* Get the values for the 1st and 2nd arguments. */
	/*===============================================*/
	base = EnvRtnDouble(environment,1); height = EnvRtnDouble(environment,2);
	/*==================================*/
	/* Return the area of the triangle. */
	/*==================================*/
	return(0.5 * base * height);
}

void TripleNumber(void *theEnv, DATA_OBJECT_PTR returnValuePtr)
{
	void *value;
	long long longValue; double doubleValue;
	/*===============================================*/
	/* If illegal arguments are passed, return zero. */
	/*===============================================*/

	if (EnvArgCountCheck(theEnv,"triple",EXACTLY,1) == -1)
	{
		SetpType(returnValuePtr,INTEGER); SetpValue(returnValuePtr,EnvAddLong(theEnv,0LL)); return;
	}
	if (! EnvArgTypeCheck(theEnv,"triple",1,INTEGER_OR_FLOAT,returnValuePtr))
	{
		SetpType(returnValuePtr,INTEGER);
		SetpValue(returnValuePtr,EnvAddLong(theEnv,0LL));
		return;
	}
	/*====================*/
	/* Triple the number. */
	/*====================*/
	if (GetpType(returnValuePtr) == INTEGER) {
		value = GetpValue(returnValuePtr);
		longValue = 3 * ValueToLong(value);
		SetpValue(returnValuePtr,EnvAddLong(theEnv,longValue));
	}
	else /* the type must be FLOAT */
	{
		value = GetpValue(returnValuePtr);
		doubleValue = 3.0 * ValueToDouble(value);
		SetpValue(returnValuePtr,EnvAddDouble(theEnv,doubleValue));
	}
	return;
}
