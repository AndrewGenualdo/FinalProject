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
#include "user.h"

/*
    Pre: None
   Post: mAccounts will be set to nullptr, mAccountsInUsed set to 0
Purpose: Default constructor
 Author: Drew Genualdo
*********************************************************************************/
User::User()
{
    mAccounts = nullptr;
    mAccountInUsed = 0;
}

/*
    Pre: None
   Post: mAccounts and mAccountInUsed will be set to obj's mAccounts and mAccountsInUsed
Purpose: Copy constructor
 Author: Drew Genualdo
*********************************************************************************/
User::User(const User &obj)
{
    if(mAccounts != nullptr) {
        delete [] mAccounts;
    }
    mAccounts = new Account[obj.mAccountInUsed];
    for(int i=0;i<obj.mAccountInUsed;i++) {
        mAccounts[i] = obj.mAccounts[i];
    }
    mAccountInUsed = obj.mAccountInUsed;
}

/*
    Pre: None
   Post: this object will be destroyed
Purpose: Default destructor
 Author: Drew Genualdo
*********************************************************************************/
User::~User()
{
    delete [] mAccounts;
    mAccountInUsed = 0; //not sure why this is necessary, it's getting deleted...
}

/*
    Pre: Initialized
   Post: None
Purpose: Return the account at the given index
 Author: Drew Genualdo
*********************************************************************************/
Account User::getAccount(int index)
{
    return mAccounts[index];
}

/*
    Pre: Initialized
   Post: None
Purpose: Get how many accounts are loaded
 Author: Drew Genualdo
*********************************************************************************/
int User::getAccountInUsed()
{
    return mAccountInUsed;
}

/*
    Pre: Initialized
   Post: None
Purpose: Return the account's ID at the given index
 Author: Drew Genualdo
*********************************************************************************/
string User::getID(int index)
{
    return mAccounts[index].mId;
}

/*
    Pre: Initialized
   Post: None
Purpose: Return the account's password at the given index
 Author: Drew Genualdo
*********************************************************************************/
string User::getPassword(int index)
{
    return mAccounts[index].mPassword;
}

/*
    Pre: Initialized
   Post: The account at the given index will be set to obj
Purpose: Set an account at an index
 Author: Drew Genualdo
*********************************************************************************/
void User::setAccount(int index, Account obj)
{
    mAccounts[index] = obj;
}

/*
    Pre: Initialized
   Post: The mId of the account at the given index will be set to id
Purpose: Set an id of an account at an index
 Author: Drew Genualdo
*********************************************************************************/
void User::setId(int index, string id)
{
    mAccounts[index].mId = id;
}

/*
    Pre: Initialized
   Post: The mPassword of the account at the given index will be set to password
Purpose: Set a password of an account at an index
 Author: Drew Genualdo
*********************************************************************************/
void User::setPassword(int index, string password)
{
    mAccounts[index].mPassword = password;
}

/*
    Pre: Initialized
   Post: None
Purpose: Check if an account with the same mId and mPassword exist
 Author: Drew Genualdo
*********************************************************************************/
bool User::isUserExist(Account obj)
{
    for(int i=0;i<mAccountInUsed;i++) {
        if(obj == mAccounts[i]) {
            return true;
        }
    }
    return false;
}

/*
    Pre: Initialized
   Post: mAccounts will be populated with data from dataFile and mAccountInUsed will store how many Accounts are in mAccounts
Purpose: Load account data from a file
 Author: Drew Genualdo
*********************************************************************************/
void User::loadData(string dataFile)
{
    ifstream input(dataFile);
    if(input.is_open() && input.good()) {
        input >> mAccountInUsed;
        mAccounts = new Account[mAccountInUsed];
        int i = 0;
        while(!input.eof() && i < mAccountInUsed) {
            input >> mAccounts[i];
            i++;
        }
    }
    input.close();

}

/*
    Pre: Initialized
   Post: None
Purpose: Store account data to a file
 Author: Drew Genualdo
*********************************************************************************/
void User::storeData(string dataFile)
{
    ofstream output(dataFile);
    if(output.is_open() && output.good()) {
        output << mAccountInUsed << endl;
        for(int i=0;i<mAccountInUsed;i++) {
            output << mAccounts[i];
        }
    }
    output.close();
}

/*
    Pre: Initialized
   Post: None
Purpose: Check whether a user exists with the attempted id and password
 Author: Drew Genualdo
*********************************************************************************/
bool User::validateLogin(Account obj)
{
    return isUserExist(obj);
}
