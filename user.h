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

#ifndef FINALPROJECT_USER_H
#define FINALPROJECT_USER_H

#include "account.h"

class User
{
private:
    Account* mAccounts;
    int mAccountInUsed;

public:
    User();
    User(const User& obj);
    ~User();

    Account getAccount(int index);
    int getAccountInUsed();
    string getID(int index);
    string getPassword(int index);

    void setAccount(int index, Account obj);
    void setId(int index, string id);
    void setPassword(int index, string password);

    bool isUserExist(Account obj);
    void loadData(string dataFile);
    void storeData(string dataFile);
    bool validateLogin(Account obj);

};


#endif //FINALPROJECT_USER_H
