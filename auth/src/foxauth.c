#include <stdio.h>
#include <string.h>
#include <pwd.h>
#include <shadow.h>
#include <sys/types.h>
#include <crypt.h>

#include "foxauth.h"

short FoxAuth_checkPassword(char *name, char *password) {
    struct passwd* pwd = getpwnam(name);

    if (!pwd)
        return 1;

    if (strcmp(pwd->pw_passwd, "x") != 0)
        return strcmp(pwd->pw_passwd, crypt(password, pwd->pw_passwd));

    struct spwd* shpwd = getspnam(name);
    if (!shpwd)
        return 2;

    return strcmp(shpwd->sp_pwdp, crypt(password, shpwd->sp_pwdp));
}