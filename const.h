#ifndef _CONST_H_

#define _CONST_H

#define ASCII_CONV 48

#ifdef DEBUG_MODE
#define dprintf printf
#else
#define dprintf(...) ;
#define print_stack(...) ;
#endif

#endif

