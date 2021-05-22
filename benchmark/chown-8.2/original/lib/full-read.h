/* An interface to read() that reads all it is asked to read.

   Copyright (C) 2002 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, read to the Free Software Foundation,
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#include <stddef.h>

/* Read COUNT bytes at BUF to descriptor FD, retrying if interrupted
   or if partial reads occur.  Return the number of bytes successfully
   read, setting errno if that is less than COUNT.  errno = 0 means EOF.  */
extern size_t full_read (int fd, void *buf, size_t count);