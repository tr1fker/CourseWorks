#ifndef USERFUNCTION_H
#define USERFUNCTION_H

#include "../include/struct.h"

void resetPassword(struct User currentUser);
void registerUser();
void deleteUser(int currentId);
void blockUser(int currentId);

#endif USERFUNCTION_H