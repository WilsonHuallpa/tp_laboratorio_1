/** \brief function that control the linkedlist and the file if it is null or not.
 *
 * \param path char* File address to read
 * \param pArrayListEmployee LinkedList* employee list
 * \return int 0 if the files and the linkedlist are null or returns the quantity of the item in my employee list.
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief function that control the linkedlist and the file if it is null or not.
 *
 * \param path char* File address to read
 * \param pArrayListEmployee LinkedList* employee list
 * \return int 0 if the files and the linkedlist are null or returns the quantity of the item in my employee list.
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief function adds an employee to the employee list
 *
 * \param pArrayListEmployee LinkedList* employee list
 * \return int 0 if the employee list is null. 1 if you were able to add an employee to the list.
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief function to edit an item in the employee list
 *
 * \param pArrayListEmployee LinkedList*

 * \return int 0 if the list of employees is null. 1 if you were able to edit an employee from the list.
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Remove an element from the pArrayListEmploy, Verifying that the pointer pArrayListEmployee
            be other than NULL.

 * \param pArrayListEmployee LinkedList*

 * \return int If verification function fails returns (0) and if successful (1).

 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Prints the list of employees available in the pArrayListEmployee. verifying that the pointer pArrayListEmployee
            be other than NULL.
 *
 * \param pArrayListEmployee LinkedList*

 * \return int If verification function fails returns (0) and if successful (1).
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief verifying that the pointer pArrayListEmployee
            be other than NULL. orders employee
 *
 * \param pArrayListEmployee LinkedList*

 * \return int If verification function fails returns (0) and if successful (1).
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Save the data of the structures in the file (text mode).
 *
 * \param path char* location of the text file.
 * \param pArrayListEmployee LinkedList*

 * \return int If verification function fails returns (0) and if successful (1).
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Save the structure data in the file (binary mode).
 *
 * \param path char* location of the text file.
 * \param pArrayListEmployee LinkedList*
 * \return int If verification function fails returns (0) and if successful (1).
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief function searches for an element that is equal to the id entered by parameter.
 *
 * \param list_Employee LinkedList*
 * \param index int

 * \return int If the search function id fails, it returns (-1) and if it succeeds (it returns the position of the element).
 *
 */
int controller_findEmployeeById(LinkedList* list_Employee, int index);




