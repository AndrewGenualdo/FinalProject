/*
 * Author: Drew Genualdo
 * Class: CSI-240-04
 * Assignment: Final Project Part 1
 * Date Assigned: Unknown
 * Due Date: Apr 9, 2024 @ 1pm
 *
 * Description:
 * A system to store accounts and system to manage those accounts
 *
 * Certification of Authenticity:
 * I certify that this is entirely my own work, except where I have given
 * fully-documented references to the work of others. I understand the definition and
 * consequences of plagiarism and acknowledge that the assessor of this assignment
 * may, for the purpose of the assessing this assignment:
 * - Reproduce this assignment and provide a copy to another member of academic staff;
 * and/or
 * - Communicate a copy of this assignment to a plagiarism checking service (which may
 * then retain a copy of this assignment on its database for the purpose of future plagiarism checking)
 */

#include <iostream>
#include "account.h"

/*
    Pre: None
   Post: mId and mPassword will be set to empty strings
Purpose: Default constructor
 Author: Drew Genualdo
*********************************************************************************/
Account::Account()
{
    mId = "";
    mPassword = "";
}

/*
    Pre: None
   Post: mId and mPassword will be set to id and password
Purpose: Custom constructor
 Author: Drew Genualdo
*********************************************************************************/
Account::Account(string id, string password)
{
    mId = id;
    mPassword = password;
}

/*
    Pre: None
   Post: mId and mPassword will be set to obj's mId and mPassword
Purpose: Copy constructor
 Author: Drew Genualdo
*********************************************************************************/
Account::Account(const Account &obj)
{
    mId = obj.mId;
    mPassword = obj.mPassword;
}

/*
    Pre: Initialized
   Post: None
Purpose: check if two Accounts are equal
 Author: Drew Genualdo
*********************************************************************************/
bool Account::operator==(Account rhs)
{
    return mId == rhs.mId && mPassword == rhs.mPassword;
}

/*
    Pre: Initialized
   Post: None
Purpose: check if two Accounts are NOT equal
 Author: Drew Genualdo
*********************************************************************************/
bool Account::operator!=(Account rhs)
{
    return !(*this == rhs);
}

/*
    Pre: Initialized
   Post: obj.mId and obj.mPassword will be loaded from the istream
Purpose: Load values into obj from istream
 Author: Drew Genualdo
*********************************************************************************/
istream &operator>>(istream &input, Account &obj)
{
    input >> obj.mId;
    string tmp;
    getline(input, tmp);
    obj.mPassword = tmp.substr(1); //gets the space after the id as part of the password without this
    return input;
}

/*
    Pre: Initialized
   Post: None
Purpose: Output values from obj to ostream
 Author: Drew Genualdo
*********************************************************************************/
ostream &operator<<(ostream &output, Account obj)
{
    output << obj.mId << " " << obj.mPassword << endl;
    return output;
}
