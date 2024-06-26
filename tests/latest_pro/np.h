/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * np.h
 * Copyright (C) 2024 Vladimir Roncevic <elektron.ronca@gmail.com>
 *
 * latest_pro is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * latest_pro is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef NP_H_
#define NP_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define NP_ERROR -1

/**
 * Description:
 *     Make a FIFO special file (a named pipe).
 *
 * Arguments:
 *     path_name - FIFO special file path name
 *     mode - specifies the FIFO's permissions
 *
 * Return value:
 *     status - on success return 0 | NP_ERROR and error number is set to
 *              indicate the error:
 *                  EACCES, EDQUOT, EEXIST, ENAMETOOLONG, ENOENT, ENOSPC
 *                  ENOTDIR, EROFS, EBADF
 *
 * Standards:
 *     POSIX.1-2001, POSIX.1-2008
 */
int np_make(const char * path_name, mode_t mode) __attribute__((nonnull (1)));

/**
 * Description:
 *     Open and possibly create a file.
 *
 * Arguments:
 *     path_name - FIFO special file path name
 *     flags - flags for opening named pipe
 *
 * Return value:
 *     file_descriptor - on success return new file descriptor
 *                       (a nonnegative integer) | NP_ERROR and error number
 *                       is set to indicate error:
 *                          EACCES, EBUSY, EDQUOT, EEXIST, EFAULT, EFBIG
 *                          EINTR, EINVAL, EISDIR, ELOOP, EMFILE, ENAMETOOLONG
 *                          ENFILE, ENODEV, ENOENT, ENOMEM, ENOSPC, ENOTDIR
 *                          ENXIO, EOPNOTSUPP, EOVERFLOW, EPERM. EROFS, ETXTBSY
 *                          EWOULDBLOCK, EBADF, ENOTDIR
 *
 * Standards:
 *     POSIX.1-2001, POSIX.1-2008
 */
int np_open(const char * path_name, int flags) __attribute__((nonnull (1)));

/**
 * Description:
 *     Read from a file descriptor.
 *
 * Arguments:
 *     file_descriptor - file descriptor
 *     buffer - socket address structure
 *     count - size of peer address
 *
 * Return value:
 *     number_of_bytes - on success, number of bytes read is returned
 *                       (zero indicates end of file), and file position
 *                       is advanced by this number | NP_ERROR and error
 *                       number is set to indicate error:
 *     EAGAIN, EWOULDBLOCK, EBADF, EFAULT, EINTR, EINVAL, EINVAL, EIO, EISDIR
 *
 * Standards:
 *     POSIX.1-2001, POSIX.1-2008
 */
ssize_t np_read(int file_descriptor, void * buffer, size_t count);

/**
 * Description:
 *     Write to a file descriptor.
 *
 * Arguments:
 *     file_descriptor - file descriptor
 *     buffer - socket address structure
 *     count - size of peer address
 *
 * Return value:
 *     number_of_bytes - on success, number of bytes written is returned |
 *                       NP_ERROR and error number is set to indicate error.
 *
 *     Note that a successful write() may transfer fewer than count
 *     bytes.  Such partial writes can occur for various reasons; for
 *     example, because there was insufficient space on disk device
 *     to write all of requested bytes, or because a blocked write()
 *     to a socket, pipe, or similar was interrupted by a signal handler
 *     after it had transferred some, but before it had transferred all
 *     of requested bytes.  In event of a partial write, the
 *     caller can make another write() call to transfer remaining
 *     bytes.  subsequent call will either transfer further bytes or
 *     may result in an error (e.g., if disk is now full).
 *     If count is zero and descriptor refers to a regular file, then write()
 *     may return a failure status if one of errors below is
 *     detected.  If no errors are detected, or error detection is not
 *     performed, 0 is returned without causing any other effect.  If
 *     count is zero and descriptor refers to a file other than a regular
 *     file, results are not specified.
 *
 *     EAGAIN, EWOULDBLOCK, EBADF, EDESTADDRREQ, EDQUOT, EFAULT, EFBIG, EINTR
 *     EINVAL, EIO, ENOSPC, EPERM, EPIPE
 *     Other errors may occur, depending on object connected to descriptor.
 *
 * Standards:
 *     POSIX.1-2001, POSIX.1-2008
 */
ssize_t np_write(
    int file_descriptor, const void * buffer, size_t count
) __attribute__((nonnull (2)));

/**
 * Description:
 *     Close a file descriptor.
 *
 * Arguments:
 *     file_descriptor - file descriptor
 *
 * Return value:
 *     status  - returns zero on success | NP_ERROR and error number is set to
 *               indicate the error:
 *                   EBADF, EINTR, EIO, ENOSPC, EDQUOT
 *
 * Standards:
 *     POSIX.1-2001, POSIX.1-2008
 */
int np_close(int file_descriptor);

#ifdef __cplusplus
}
#endif

#endif
