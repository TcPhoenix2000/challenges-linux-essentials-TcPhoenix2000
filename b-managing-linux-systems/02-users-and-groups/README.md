
# Users and Groups

Try to solve the challenges without using google. Better to use the man-pages to find the information you need.

maggie challenges using a ✅ once they are finished.

## ✅ System user accounts
//*Try to login to the `daemon` system user account. Use `sudo su daemon`. What does it display as a message ? What application is outputting this message ? Run that application and prove it.*

the `daemon` account is a Service account and these typically locked.
```bash
[user@linux][~]$ sudo su daemon
```
### Output
```sh
This account is currently not available.
```
## ✅ Creating group with id
//*Create a group called `hackers` with the specific group id `1337`. Now create two users (students from the class) and add them both the group.*
 ```bash
[user@linux][~]$ sudo addgroup -gid 1337 hackers
```
### Output
```sh
Adding group `hackers' (GID 1337) ...
Done.
```
### adding 2 students users to group
```
[user@linux][~]$ sudo adduser student_1 hackers && sudo adduser student_2 hackers
```
### Output
```
Adding user `student_1' to group `hackers' ...
Adding user student_1 to group hackers
Done.
Adding user `student_2' to group `hackers' ...
Adding user student_2 to group hackers
Done.
```
## ✅ Difference false and nologin
//*Some user entries are showing `/bin/false` as the shell command. Do some research and explain what the difference is with `/usr/sbin/nologin`.*

#### note the following answer was found on the web and i did not now how to word it any better.
> Originally, `/bin/false` has been created for a general command as it always returns non-zero. Then, seems it is used as `nologin` user's shell before creating `/usr/sbin/nologin`. On the other hand, `/usr/sbin/nologin` has been created for nologin user's shell, it has a feature to give a message in `/etc/nologin`.

## ✅ The auth.log file 
//*What does the file `/log/var/auth.log` track? Provide an example of a command that shows entries being added to the log after you executed the command. Include the entry here that was added to the file.*

this does **not** work on Windows subsystem for linux because WSL doesn't run any services by default, including `rsyslog` witch would have created the `/log/var/auth.log`.

it would have shown the login attempts log.

## ✅ Locking out Steve
//*Create a new user steve and set a password for the user. Login to the `steve` account using `su` to make sure it works.*

//*Now lock the user account and make sure there is no way anyone can login as `steve`, not even `root`*

### locking out all users and root 
```
[user@linux][~]$ passwd -l steve && usermod --expiredate 1 steve
```

## ✅ Zsh Shell
//*Install the zsh shell on your system. Now change your own shell to `zsh`. Make sure to do this in such a way that a new session will also use `zsh`.*

### making linux my Own
![image of zsh terminal](../images-b/zch.png)

## ✅ Semester Account
//*Create a new account for an exchange student called `maggie`. Make sure the account can only be used until 31st of January of the next year. Basically only for this semester*.

### locking out all users and root 
```sh
[user@linux][~]$ sudo adduser maggie && sudo usermod --expiredate 2023-1-31 maggie
```
### output
```
Adding user `maggie' ...
Adding new group `maggie' (1001) ...
Adding new user `maggie' (1001) with group `maggie' ...
Creating home directory `/home/maggie' ...
Copying files from `/etc/skel' ...
Enter new UNIX password:
Retype new UNIX password:
passwd: password updated successfully
Changing the user information for maggie
Enter the new value, or press ENTER for the default
	Full Name []:
	Room Number []:
	Work Phone []:
	Home Phone []:
	Other []:
Is the information correct? [Y/n] y
```