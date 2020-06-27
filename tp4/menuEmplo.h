#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validacio.h"

/** \brief Function that prints the edition menu
           for an Employee in a LinkedList arrangement.
 *
 * \param option int* Option chosen from the menu.
 * \return int [-1] If there was an error. [1] if you had
            function successful
 *
 */
int menu_edit(int* option);

/** \brief Function that prints the array ordering menu.
 *
 * \param option int* Option chosen from the menu.
 * \return int [-1] If there was an error. [1] if you had
            function successful
 *
 */
int menu_sort(int* option);

/** \brief  Function that prints the main menu of the program.
 *
 * \param void
 * \return int Returns the option chosen in the menu.
 *
 */
int menu_main(void);


#endif // MENU_H_INCLUDED
