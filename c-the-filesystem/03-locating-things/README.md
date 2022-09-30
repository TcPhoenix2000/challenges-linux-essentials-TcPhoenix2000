# Locating Things

Document all the commands and their output on your system. If the output is too long take a couple of lines and add `...` at the end.

Mark challenges using a ✅ once they are finished.

## ❌ Locate

*Install the `locate` command and update the index database.*

*Locate the following files on your system:*

* `sudoers.dist`
* the configuration file `ssh_config`
* `auth.log`

## ❌ Python man-pages

*Use the `whereis` tool to determine the location of the man-pages of `python`.*

## ❌ Binary of find

*Use the `whereis` tool to determine the location of the `find` binary.*

## ❌ Which

*What is the location of the following commands for the current user:*

* `passwd`
* `locate`
* `fdisk`

*Why are the location of `passwd` and `fdisk` different? What is `fdisk` used for?*

## Use find for the following challenges

Make sure to redirect the `permission denied` errors to `/dev/null` for all searches unless specified otherwise.

### ❌ kernel.log

*Find the file `kernel.log`.*

### ❌ .bashrc

*Find the files `.bashrc`.*

### ❌ System Configuration Files

*Search for files that end with the extension `.conf` and contain a filename with the keyword `system` in the `/etc` directory.*

### ❌ User Readable Files

*What option can we use on `find` to make sure the current user can read the file? Don't use the `-perm` option. There is a better option. Give a nice example.*

### ❌ Altered Log Files

*Find all log files in `/var/log` that were modified in the last 24 hours. Make sure to only include files and not directories. Now extend the command to perform a long listing human readable `ls` for each file.*

### ❌ Steal All Logs

*Create a directory `logs` in `/tmp` and copy all `*.log` files you can find on the system to that location.*

### ❌ Markdown README files

*Find all `README.md` files on your system. Can you make it so the case of the filename does not matter? In other words, you should also be able to find `readme.md`, `Readme.md`, `readme.MD`, ...*
