/* 
 * File:   constants.h
 * Author: marcr
 *
 * Created on 27 May 2026, 11:18
 */

#ifndef CONSTANTS_H
#define	CONSTANTS_H

#include "dsp.h"
#include <stdint.h>

#define Q_SHIFT 15
#define SCALE (1UL << Q_SHIFT)

#define ALPHA 0.01
#define STEP 0.9

const uint16_t q_num_1 = (uint16_t)(0.5 * SCALE);
const uint16_t q_num_2 = (uint16_t)(0.5 * SCALE);

const uint16_t step_q = (uint16_t) (STEP * SCALE);
const uint16_t alpha_q = (uint16_t) (ALPHA * SCALE);
const uint16_t alpha_complement = 0b0111111111111111; // closest q15 value to 1



#endif	/* CONSTANTS_H */

