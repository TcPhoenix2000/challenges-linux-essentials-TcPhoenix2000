# Locating Things

Document all the commands and their output on your system. If the output is too long take a couple of lines and add `...` at the end.

Mark challenges using a ✅ once they are finished.

## ✅ Locate
//*Install the `locate` command and update the index database.*
```sh
[user@linux][~]$ sudo apt-get install locate
```
//*Locate the following files on your system:*
* //`sudoers.dist`
* //the configuration file `ssh_config`
* //`auth.log`
```sh
[user@linux][~]$ locate sudoers.dist
[user@linux][~]$ locate ssh_config
[user@linux][~]$ locate auth.log
```

## ✅ Python man-pages
//*Use the `whereis` tool to determine the location of the man-pages of `python`.*
```sh
[user@linux][~]$ whereis python
```
output
```sh
python: /usr/bin/python3.8 /usr/lib/python3.8 /usr/lib/python3.9 /usr/lib/python2.7 /etc/python3.8 /usr/local/lib/python3.8 
```
The man pages for python are typically stored in the /usr/share/man directory

## ✅ Binary of find
//*Use the `whereis` tool to determine the location of the `find` binary.*
```sh
[user@linux][~]$ whereis find
```
output
```sh
/usr/bin/find /usr/share/man/man1/find.1.gz /usr/share/info/find.info-1.gz /usr/share/info/find.info-2.gz /usr/share/info/find.info.gz
```
The binary's are typically stored in the /usr/bin/ directory

## ✅ Which
//*What is the location of the following commands for the current user:*
* //`passwd`
* //`locate`
* //`fdisk`
```sh
[user@linux][~]$ which passwd
[user@linux][~]$ which locate
[user@linux][~]$ which fdisk
```
output
```sh
/usr/bin/passwd
/usr/bin/locate
/sbin/fdisk
```

//*Why are the location of `passwd` and `fdisk` different? What is `fdisk` used for?*
In many cases, the `passwd` and `fdisk` commands are stored in different directories because they are used for different purposes.
The `passwd` command is used to change the password for a user account, while the `fdisk` command is used to manage disk partitions.

The `fdisk` command is typically used to create, delete, and resize disk partitions on a hard drive.
It is often used to prepare a hard drive for use with a new operating system, or to create multiple partitions on a single hard drive for different purposes.

## Use find for the following challenges
//Make sure to redirect the `permission denied` errors to `/dev/null` for all searches unless specified otherwise.
by adding The `2>/dev/null` part will the command redirects the permission denied errors that find might encounter when it tries to search certain directories to /dev/null, so that they are not displayed on the screen.

### ✅ kernel.log
//*Find the file `kernel.log`.*
```sh
[user@linux][~]$ find / -name kernel.log 2>/dev/null
```
output:
```sh
/var/log/kernel.log
```

### ✅ .bashrc
//*Find the files `.bashrc`.*
```sh
[user@linux][~]$ find / -name .bashrc 2>/dev/null
```
output:
```sh
/root/.bashrc
/home/user/.bashrc
```

### ✅ System Configuration Files
//*Search for files that end with the extension `.conf` and contain a filename with the keyword `system` in the `/etc` directory.*
```sh
[user@linux][~]$ find /etc -name "*system*.conf" 2>/dev/null
```
output:
```sh
/etc/systemd/system.conf
/etc/systemd/user.conf
```

### ✅ User Readable Files
//*What option can we use on `find` to make sure the current user can read the file? Don't use the `-perm` option. There is a better option. Give a nice example.*
```sh
[user@linux][~]$ find /etc -readable 2>/dev/null
```
output:
```sh
/etc/passwd
/etc/group
/etc/bash.bashrc
```

### ✅ Altered Log Files
//*Find all log files in `/var/log` that were modified in the last 24 hours. Make sure to only include files and not directories. Now extend the command to perform a long listing human readable `ls` for each file.*
```sh
[user@linux][~]$ find /var/log -mtime -1 -type f -ls 2>/dev/null
```
output:
```sh
223960 -rw-r--r--  1 root root   319072 Jan  3 23:35 /var/log/cron
223959 -rw-r--r--  1 root root    79994 Jan  3 23:35 /var/log/dmesg
223958 -rw-r--r--  1 root root   101575 Jan  3 23:35 /var/log/lastlog
```

### ✅ Steal All Logs
//*Create a directory `logs` in `/tmp` and copy all `*.log` files you can find on the system to that location.*
```sh
[user@linux][~]$ mkdir /tmp/logs
[user@linux][~]$ find / -name "*.log" -exec cp {} /tmp/logs/ \; 2>/dev/null && ls /tmp/logs/
```
output:
```sh
/var/log/cron
/var/log/dmesg
/var/log/lastlog
```

### ✅ Markdown README files
//*Find all `README.md` files on your system. Can you make it so the case of the filename does not matter? In other words, you should also be able to find `readme.md`, `Readme.md`, `readme.MD`, ...*
```sh
[user@linux][~]$ find / -iname "readme.md" 2>/dev/null
```
example output:
```sh
/home/user/projects/project1/README.md
/home/user/projects/project2/readme.md
/home/user/projects/project3/Readme.md
```