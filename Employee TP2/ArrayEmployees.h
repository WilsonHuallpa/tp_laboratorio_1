#define UPP 1
#define DOWN 0
#include "Validacio.h"

 /*******************************************
 * \brief The Employee structure that allows working
 *        with the stored data which represents the data
 *        of an employee of the company.
 *
 * \param id int          ID number
 * \param name[] char     Name of the employee
 * \param lastName[] char Employee's last name
 * \param salary float    Employee salary
 * \param sector int      Sector de trabajo del empleado(numero)
 * \param isEmpty int     Employee array status, if free it will be FREE and otherwise occupied it will be OCCUPIED
.*
 ********************************************/
typedef struct {
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

 /*******************************************
 * \brief  Indicates empty array positions
 *
 * \param  List[]      Employee Array
 * \param  len int     Array size
 * \return return int If it is free it returns FREE, otherwise it will return -1
 *
 ********************************************/
int initEmployees(Employee List[], int len);

 /*******************************************
 * \brief  Seek that the state is empty
 *
 * \param  List[] Employee
 * \param  len int     Array size
 * \return returno int    Returns -1 if no free place is found
 *
 ********************************************/
int searchFreeEmployee(Employee List[], int len);

 /*******************************************
 * \brief Create consecutive id for the employee
 *
 * \param  list[] Employee
 * \param  len int
 * \return id int
 *
 ********************************************/
int selectId(Employee List[], int len);

 /*******************************************
 * \brief Employee registration
 *
 * \param  List[] Employee
 * \param  len int
 * \return index int
 *
 ********************************************/
int addEmployee(Employee List[], int len, int cont);

 /*******************************************
 * \brief Search id like
 *
 * \param  List[] Employee
 * \param  len int
 * \param  id int
 * \return return int
 *
 ********************************************/
int findEmployeeById(Employee List[], int len, int id);

 /*******************************************
 * \brief Shows an employee
 *
 * \param  TheEmployee Employee
 * \return printf void  evolve the message with employee data
 *
 ********************************************/
void printEmployee(Employee TheEmployee);

 /*******************************************
 * \brief Show all charged employees
 *
 * \param  List[] Employee
 * \param  length int
 * \return return int
 *
 ********************************************/
int printEmployees(Employee List[], int length);

 /*******************************************
 * \brief Low logic of an employee
 *
 * \param  List[] Employee
 * \param  id int
 * \return return int
 *
 ********************************************/
int removeEmployee(Employee List[], int len, int id);

 /*******************************************
 * \brief Sort alphabetically and by sector
 *
 * \param  List[] Employee
 * \param  len int
 * \param  order int
 * \return returno int Returns 0 or -1
 *
 ********************************************/
int sortEmployees(Employee List[], int len, int order);

 /*******************************************
 * \brief Make salary calculations
 *
 * \param  List[] Employee
 * \param  len int
 * \param  Promedy float*
 * \param  Suma float*
 * \return returno int
 *
 ********************************************/
int totalSalary(Employee List[], int len, float Promedy, float Suma);

