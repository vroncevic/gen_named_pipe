/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * np_open.c
 * Copyright (C) 2024 Vladimir Roncevic <elektron.ronca@gmail.com>
 *
 * latest_pro is free software: you can redistribute it and/or modify it
 * under terms of GNU General Public License as published by the
 * Free Software Foundation, either version 3 of License, or
 * (at your option) any later version.
 *
 * latest_pro is distributed in hope that it will be useful, but
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
 *                          EACCES (requested access to file is not
 *                                 allowed, or search permission is denied for
 *                                 one of directories in path prefix of
 *                                 pathname, or file did not exist yet and
 *                                 write access to parent directory is not
 *                                 allowed)
 *                          EACCES (where O_CREAT is specified, the
 *                                  protected_fifos or protected_regular
 *                                  sysctl is enabled, file already exists
 *                                  and is a FIFO or regular file, owner
 *                                  of file is neither current user nor
 *                                  owner of containing directory, and
 *                                  containing directory is both world- or
 *                                  group-writable and sticky)
 *                          EBUSY (O_EXCL was specified in flags and pathname
 *                                 refers to a block device that is in use by
 *                                 system (e.g., it is mounted))
 *                          EDQUOT (where O_CREAT is specified, file does not
 *                                  exist, and user's quota of disk blocks or
 *                                  inodes on filesystem has been exhausted)
 *                          EEXIST (pathname already exists and O_CREAT and
 *                                  O_EXCL were used)
 *                          EFAULT (pathname points outside your accessible
 *                                  address space)
 *                          EFBIG (see EOVERFLOW)
 *                          EINTR (while blocked waiting to complete an open
 *                                 of a slow device (e.g., a FIFO), call was
 *                                 interrupted by a signal handler)
 *                          EINVAL (filesystem does not support O_DIRECT flag)
 *                          EINVAL (invalid value in flags)
 *                          EINVAL (O_TMPFILE was specified in flags, but
 *                                  neither O_WRONLY nor O_RDWR was specified)
 *                          EINVAL (O_CREAT was specified in flags and final
 *                                  component ("basename") of new file's
 *                                  pathname is invalid (e.g., it contains
 *                                  characters not permitted by underlying
 *                                  filesystem))
 *                          EINVAL (final component ("basename") of pathname
 *                                  is invalid (e.g., it contains characters
 *                                  not permitted by underlying filesystem))
 *                          EISDIR (pathname refers to a directory and access
 *                                  requested involved writing (that is,
 *                                  O_WRONLY or O_RDWR is set))
 *                          EISDIR (pathname refers to an existing directory,
 *                                  O_TMPFILE and one of O_WRONLY or O_RDWR
 *                                  were specified in flags, but this kernel
 *                                  version does not provide O_TMPFILE
 *                                  functionality)
 *                          ELOOP (too many symbolic links were encountered in
 *                                 resolving pathname)
 *                          ELOOP (pathname was a symbolic link, and flags
 *                                 specified O_NOFOLLOW but not O_PATH)
 *                          EMFILE (per-process limit on number of open file
 *                                  descriptors has been reached)
 *                          ENAMETOOLONG (pathname was too long)
 *                          ENFILE (system-wide limit on total number of open
 *                                  files has been reached)
 *                          ENODEV (pathname refers to a device special file
 *                                  and no corresponding device exists (this
 *                                  is a Linux kernel bug;in this situation
 *                                  ENXIO must be returned))
 *                          ENOENT (O_CREAT is not set and named file does
 *                                  not exist)
 *                          ENOENT (directory component in pathname does not
 *                                  exist or is a dangling symbolic link)
 *                          ENOENT (pathname refers to a nonexistent directory,
 *                                  O_TMPFILE and one of O_WRONLY or O_RDWR
 *                                  were specified in flags, but this kernel
 *                                  version does not provide O_TMPFILE
 *                                  functionality)
 *                          ENOMEM (named file is a FIFO, but memory for FIFO
 *                                  buffer can't be allocated because per-user
 *                                  hard limit on memory allocation for pipes
 *                                  has been reached and caller is not
 *                                  privileged)
 *                          ENOMEM (insufficient kernel memory was available)
 *                          ENOSPC (pathname was to be created but device
 *                                  containing pathname has no room for new
 *                                  file)
 *                          ENOTDIR (component used as a directory in pathname
 *                                   is not, in fact, a directory, or
 *                                   O_DIRECTORY was specified and pathname
 *                                   was not a directory)
 *                          ENXIO (O_NONBLOCK | O_WRONLY is set, named file is
 *                                 a FIFO, and no process has FIFO open for
 *                                 reading)
 *                          ENXIO (file is a device special file and no
 *                                 corresponding device exists)
 *                          ENXIO (file is a UNIX domain socket)
 *                          EOPNOTSUPP (filesystem containing pathname does
 *                                      not support O_TMPFILE)
 *                          EOVERFLOW (pathname refers to a regular file that
 *                                is too large to be opened, usual scenario
 *                                here is that an application compiled on a
 *                                32-bit platform without:
 *                                -D_FILE_OFFSET_BITS=64 tried to open a file
 *                                whose size exceeds (1<<31)-1 bytes)
 *                          EPERM (O_NOATIME flag was specified, but effective
 *                                 user ID of caller did not match owner of
 *                                 file and caller was not privileged)
 *                          EPERM (operation was prevented by a file seal)
 *                          EROFS (pathname refers to a file on a read-only
 *                                 filesystem and write access was requested)
 *                          ETXTBSY (pathname refers to an executable image
 *                                   which is currently being executed and
 *                                   write access was requested)
 *                          ETXTBSY (pathname refers to a file that is
 *                                   currently in use as a swap file, and
 *                                   O_TRUNC flag was specified)
 *                          ETXTBSY (pathname refers to a file that is
 *                                   currently being read by kernel (e.g.,
 *                                   for module/firmware loading), and write
 *                                   access was requested)
 *                          EWOULDBLOCK (O_NONBLOCK flag was specified, and an
 *                                       incompatible lease was held on file)
 *                          EBADF (dirfd is not a valid file descriptor)
 *                          ENOTDIR (pathname is a relative pathname and
 *                                   dirfd is a file descriptor referring to
 *                                   a file other than a directory)
 *
 * Standards:
 *     POSIX.1-2001, POSIX.1-2008
 */
int np_open(const char * path_name, int flags)
{
    int file_descriptor;

    if (path_name != NULL && flags >= 0)
    {
        file_descriptor = open(path_name, flags);
    }
    else
    {
        file_descriptor = NP_ERROR;
    }

    return file_descriptor;
}

