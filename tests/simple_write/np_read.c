/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * np_read.c
 * Copyright (C) 2024 Vladimir Roncevic <elektron.ronca@gmail.com>
 *
 * simple_write is free software: you can redistribute it and/or modify it
 * under terms of GNU General Public License as published by
 * Free Software Foundation, either version 3 of License, or
 * (at your option) any later version.
 *
 * simple_write is distributed in hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See GNU General Public License for more details.
 *
 * You should have received a copy of GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "np.h"

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
 *                       number is set to indicate error.
 *
 *     On success, number of bytes read is returned (zero indicates
 *     end of file), and file position is advanced by this number.
 *     It is not an error if this number is smaller than number of
 *     bytes requested; this may happen for example because fewer bytes
 *     are actually available right now (maybe because we were close to
 *     end-of-file, or because we are reading from a pipe, or from a
 *     terminal), or because read() was interrupted by a signal.  See
 *     also NOTES.
 *     EAGAIN (file descriptor refers to a file other than a socket and has
 *             been marked nonblocking (O_NONBLOCK), and read would block)
 *     EAGAIN or EWOULDBLOCK (file descriptor refers to a socket and has been
 *                            marked nonblocking (O_NONBLOCK), and read would
 *                            block)
 *     EBADF (not a valid file descriptor or is not open for reading)
 *     EFAULT (buffer is outside your accessible address space)
 *     EINTR (call was interrupted by a signal before any data was read)
 *     EINVAL (file_descriptor is attached to an object which is unsuitable
 *            for reading; or file was opened with O_DIRECT flag, and either
 *            address specified in buf, value specified in count, or file
 *            offset is not suitably aligned)
 *     EINVAL (file_descriptor was created via a call to timerfd_create(2)
 *             and wrong size buffer was given to read())
 *     EIO (I/O error, this will happen for example when process is in a
 *          background process group, tries to read from its controlling
 *          terminal, and either it is ignoring or blocking SIGTTIN or
 *          its process group is orphaned. It may also occur when there is
 *          a low-level I/O error while reading from a disk or tape.
 *          A further possible cause of EIO on networked filesystems is
 *          when an advisory lock had been taken out on file descriptor
 *          and this lock has been lost)
 *     EISDIR (file_descriptor refers to a directory)
 *     Other errors may occur, depending on object connected to descriptor)
 *
 * Standards:
 *     POSIX.1-2001, POSIX.1-2008
 */
ssize_t np_read(int file_descriptor, void * buffer, size_t count)
{
    ssize_t number_of_bytes;

    if (file_descriptor >= 0)
    {
        number_of_bytes = read(file_descriptor, buffer, count);
    }
    else
    {
        number_of_bytes = NP_ERROR;
    }

    return number_of_bytes;
}

