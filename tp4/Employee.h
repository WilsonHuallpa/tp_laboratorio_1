#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Constructor getting memory space required
           for a new Employee structure.
 *
 * \return Employee* [NULL] If memory space could not be reserved.Dynamic memory address obtained with an Employee with default values.
 *
 */
Employee* employee_new();

/** \brief New Employee structure by entering values
 *         of your fields by parameters.
 *
 * \param idStr int*  Memory address of the ID to load.
 * \param nombreStr char*  Memory address of the Name to load.
 * \param horasTrabajadasStr int*  Memory address of hours worked to load.
 * \param sueldoStr int* Memory address of the Salary to load.
 * \return Employee* [NULL] If memory space could not be reserved.
 *                   Dynamic memory address obtained
 *                   with an Employee with values ​​per parameter.
 *
 */
Employee* employee_newParametros(int* idStr,char* nombreStr,int* horasTrabajadasStr,int* sueldoStr);

/** \brief Release of memory assigned to an Employee.
 *
 * \param this Employee*  Memory address of an Employee.
 * \return void It does not return values.
 *
 */
void employee_delete(Employee* this);

/** \brief Set the ID to an Employee structure.
 *
 * \param this Employee* Memory address of an Employee.
 * \param id int Memory address of the ID to set.
 * \return int [0] If you could not set the ID. [1] If you could set the ID.
 *
 */
int employee_setId(Employee* this,int id);

/** \brief Get the ID of an Employee structure.
 *
 * \param this Employee* Memory address of an Employee.
 * \param id int* Memory address of the ID to load.

 * \return int [0] If you were unable to obtain the ID. [1] If you could load the ID.
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief Set the Name to an Employee structure.
 *
 * \param this Employee* Memory address of an Employee.
 * \param name char* Memory address of the Name to be established.
 * \return int [0] If you could not set the Name.
 *             [1] If you could establish the Name.
 *
 */
int employee_setName(Employee* this,char* name);

/** \brief Gets the Name of an Employee structure.
 *
 * \param this Employee* Memory address of an Employee.
 * \param name char* Memory address of the Name to load.
 * \return int [0] If you were unable to obtain the Name.
 *             [1] If you could load the Name.
 *
 */
int employee_getName(Employee* this,char* name);

/** \brief Set the Hours Worked to an Employee structure.
 *
 * \param this Employee* Memory address of an Employee.
 * \param workHours int  Memory address of the hours worked to establish.
 * \return int [0] If you could not set the Hours Worked.
 *             [1] If you could establish the Hours Worked.
 *
 */
int employee_setHorasTrabajadas(Employee* this,int workHours);

/** \brief  Gets the hours worked for an Employee structure.
 *
 * \param this Employee* Memory address of an Employee.
 * \param horasTrabajadas int* Memory address of hours worked to load.
 * \return int[0] If you were unable to obtain Hours Worked.
 *            [1] If you could load the Hours Worked.
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* workHours);

/** \brief Set the salary to an Employee structure.
 *
 * \param this Employee* Memory address of an Employee.
 * \param salary int Memory address of the Salary to be established.
 * \return int [0] If you could not establish the Salary.
 *             [1] If you could establish the Salary.
 *
 */
int employee_setSueldo(Employee* this,int salary);


/** \brief Get the Salary of an Employee structure.
 *
 * \param this Employee* Memory address of an Employee.
 * \param salary int* Memory address of the Salary to load.
 * \return int [0] If you could not get the Salary.
 *             [1] If you could load the Salary.
 *
 */
int employee_getSueldo(Employee* this,int* salary);

/** \brief Function that compares two elements cast to Employees by name.
 *
 * \param e1 void* Pointer to generic element.
 * \param e2 void* Pointer to generic element.
 * \return int [0] If they have the same name.
 *         <0 If the first name is first in the dictionary.
 *         > 0 If the second name is first in the dictionary.
 *
 */
int employee_CompareByName(void* e1, void* e2);

/** \brief Function that compares two items cast to Employees by ID.
 *
 * \param e1 void* Pointer to generic element.
 * \param e2 void* Pointer to generic element.
 * \return int  [0] If they have the same ID. <0 If the first ID is greater than the second.
 *         > 0 If the second ID is greater than the first.
 *
 */
int employee_CompareById(void* e1, void* e2);

/** \brief  Function that prints an Employee on screen
 *
 * \param this Employee* Memory address of an Employee.
 * \return int [-1] If the Employee could not print out of the value range.
 *              [1] If the Employee could print and free the memory.
 *
 */
int employee_print(Employee* this);


#endif // employee_H_INCLUDED
