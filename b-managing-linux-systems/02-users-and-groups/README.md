
# Users and Groups

Try to solve the challenges without using google. Better to use the man-pages to find the information you need.

Mark challenges using a ✅ once they are finished.

## ❌ System user accounts

*Try to login to the `daemon` system user account. Use `sudo su daemon`. What does it display as a message ? What application is outputting this message ? Run that application and prove it.*

## ❌ Creating group with id

*Create a group called `hackers` with the specific group id `1337`. Now create two users (students from the class) and add them both the group.*

## ❌ Difference false and nologin

*Some user entries are showing `/bin/false` as the shell command. Do some research and explain what the difference is with `/usr/sbin/nologin`.*

## ❌ The auth.log file 

*What does the file `/log/var/auth.log` track? Provide an example of a command that shows entries being added to the log after you executed the command. Include the entry here that was added to the file.*

## ❌ Locking out Steve

*Create a new user steve and set a password for the user. Login to the `steve` account using `su` to make sure it works.*

*Now lock the user account and make sure there is no way anyone can login as `steve`, not even `root`*

## ❌ Zsh Shell

*Install the zsh shell on your system. Now change your own shell to `zsh`. Make sure to do this in such a way that a new session will also use `zsh`.*

## ❌ Semester Account

*Create a new account for an exchange student called `maggie`. Make sure the account can only be used until 31st of January of the next year. Basically only for this semester*.
