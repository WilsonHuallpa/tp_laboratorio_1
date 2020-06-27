

/** \brief function of validating an option
 *
 * \param mensaje[] char  resive un texto
 * \return int returns an integer and the valid option
 *
 */
int validate_option(char mensaje[]);

/** \brief validate an integer, use of isdigit function
 *
 * \param numero[] char
 * \return int returns a valid integer
 *
 */
int validate_number(char numero[]);

/** \brief
 *
 * \param palabra[] char
 * \return int
 *
 */
int validate_Word(char palabra[]);

/** \brief This function ask the user to enter something (string) like Name, Last Name, etc... and make of the function Validate_String.
 *
 * \param char[] Receives the message to show.
 * \param char[] Receives data that user enters.
 * \param int Receives the length of the "string".
 * \return void Return nothing
 *
 */
void GetString(char[],char[]);

/** \brief Ask the user to enter an Id for later validate it using function Validate_IntId.
 *
 * \param char[] Receives the message to show.
 * \param int Receive length of the "string".
 * \return int Return validated number.
 *
 */

int GetInt(char[]);


/** \brief Ask the user to enter the salary.
 *
 * \param char[] Receives the message to show.
 * \return float Return the number loaded.
 *
 */
float GetFloat(char[]);


/** \brief Ask the user to enter a character 'S' or 'N' to make a decision
 *
 * \param message[] char Receives the message to show.
 * \return char Return character validated.
 *
 */
char GetChar(char message[]);


/** \brief function that automatically calculates the id
 *
 * \param id int
 * \param cont int
 * \return int returns incremented id
 *
 */
int GenerarId(int id,int cont);

int generarMaximoid(int num);

