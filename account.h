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

#ifndef FINALPROJECT_ACCOUNT_H
#define FINALPROJECT_ACCOUNT_H

#include <string>
#include <fstream>

using namespace std;

struct Account
{

    string mId, mPassword;

    Account();
    Account(string id, string password);
    Account(const Account& obj);

    bool operator==(Account rhs);
    bool operator!=(Account rhs);
    friend istream& operator>>(istream& input, Account& obj);
    friend ostream& operator<<(ostream& output, Account obj);
};


#endif //FINALPROJECT_ACCOUNT_H
