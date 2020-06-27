



/** \brief Parse data of Employee type structures from file (text mode)
           and adds them to an array of type LinkedList.
 *
 * \param pFile FILE* Pointer to text file.

 * \param pArrayListEmployee LinkedList* LinkedList type array.
 * \return int Number of Employee type structures parsed from text file.
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
/** \brief Parse the data of type Employee structures from the file (binary mode)
           and adds them to an array of type LinkedList.
 *
 * \param pFile FILE* Pointer to binary file.
 * \param pArrayListEmployee LinkedList* LinkedList type array.
 * \return int Number of Employee type structures parsed from binary file.
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
