/*
This file is part of foxstd
Copyright (C) 2022 Ján Gajdoš

This library is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this library.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <unistd.h>

#include "foxauth.h"

int main(int argc, char **argv) {
    if (getuid()) {
        printf("Please run this test as root\n");
        return 1;
    }

    if (argc == 1) {
        printf("./test_main NAME PASSWORD");
        return 1;
    }

    printf("Does %s's password match? %s\n", argv[1], !FoxAuth_checkPassword(argv[1], argv[2]) ? "Yes" : "No");

    return 0;
}