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

using namespace std;

int main()
{
    User user = User();
    user.loadData("data.txt");

    cout << user.getAccountInUsed() << " accounts have been loaded!" << endl;

    user.setAccount(0, Account("b-obama", "obamacare"));
    Account account = user.getAccount(0);
    cout << account.mId << " " << account.mPassword << endl; //should print 'b-obama obamacare'

    user.setId(1, "d-trump");
    user.setPassword(1, "maga");
    cout << user.getID(1) << " " << user.getPassword(1) << endl; //should print 'd-trump maga'

    Account fakeAccount = Account("r-person", "randompasswordthatdoesntexistprobably");
    cout << "This account does" << (user.validateLogin(fakeAccount) ? "" : " not") << " exist!" << endl; //should not exist

    Account realAccount = Account("b-obama", "obamacare");
    cout << "This account does" << (user.validateLogin(realAccount) ? "" : " not") << " exist!" << endl; //should exist

    //should store whatever the input file was but the first account is
    //'b-obama obamacare' and the second account is 'd-trump maga'
    user.storeData("output.txt");
    return 0;
}
