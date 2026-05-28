/* 
 * File:   constants.h
 * Author: marcr
 *
 * Created on 27 May 2026, 11:18
 */

#ifndef CONSTANTS_H
#define	CONSTANTS_H

#include <stdint.h>

#define Q_SHIFT 15
#define SCALE (1UL << Q_SHIFT)

const uint16_t q_num_1 = (uint16_t)(0.5 * SCALE);
const uint16_t q_num_2 = (uint16_t)(0.5 * SCALE);


#endif	/* CONSTANTS_H */

