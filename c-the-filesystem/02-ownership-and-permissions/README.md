# Ownership and Permissions

Make sure to document all your commands here.

Unless specified otherwise, all commands should be executed in a terminal session logged in with your own user account.

Mark challenges using a ✅ once they are finished.

## ❌ Sudo

Open a terminal session with your current user. Execute the `id` command. Explain the output. To what groups does your user belong?

Next execute the `id` command prefixed with `sudo`. What is the difference between both commands. What is happening here?

## ❌ New User Davy

1. *Create a user account for `davy`.*

2. *Now open a terminal and switch to the user account using the command `su davy`.*

3. *Create a file called `i_am_legend` inside of the home dir of `davy` using the `davy` session using the command `sudo touch ~/i_am_legend`. Why is this not working?*

4. *`exit` the current shell of `davy`.*

5. *Add the user account `davy` to the group `sudo`. Now repeat the process. Is it working now?*

6. *`exit` the current shell of `davy`.*

7. *Now switch to the superuser using `sudo su`.*

8. *Now execute the `su davy` command from the superuser session. Why do we not need to provide the password of `davy`?*

## ❌ Auth.log

*What does the file `/log/var/auth.log` track? Provide an example that shows entries being added to the log after you executed the commands.*

## ❌ Editable Text Configuration

*Who is the owner of the `/etc` directory on the system? What are the permissions on this directory? Why can you list the content of this directory?*

## ❌ Davy's Secrets

1. *Create a file called `davys_secrets.txt` inside of the `tmp` directory. Add some content to the file using nano.*

2. *What are the current permissions and who is the owner of the file?*

3. *Change the owner to `davy`. Can you still read / change the content of the file?*

4. *What command would you need to lock everyone except davy out of the file? Make sure to test it.*

## ❌ Sudo created files

1. *Create a file called `my_root.txt` inside of the `/tmp` directory using the command `sudo touch /tmp/my_root.txt`.*

2. *Who can access the file and what permissions does it have. Who is the owner of the file?*

3. *Change the permissions of the file to `640`. What has changed? Do you still have access to the file?*

## ❌ Recursive

1. *Create a directory called `/tmp/arts/colors` and add three files to it: `red`, `green` and `blue`.*

2. *Next create a directory `/tmp/arts/musical_notes` and add three files to it: `do`, `re` and `mi`.*

3. *Who is the owner of the files and directories? You can list all of them at once using the `-R` option for `ls`.*

4. *Now change the owner of the directory `/tmp/arts` and all of it included files to `davy` using the recursive option of `chown`.*

5. *Damn we made a small mistake. The goal was actually to make `root` owner of all the files and dirs and set the group to `davy`. Fix the mistake.*

## ❌ Developers group

1. *Create a group `devs` on the system. What is the `GID` of this group?*

2. *Add yourself and `davy` to this group.*

3. *Now add a directory `projects` to the root of the file system, so `/projects`.*

4. *Now set the owner of the directory to `root` and set the group to `devs`. Give both `root` and `devs` permissions to:*

   * *traverse the directory*
   * *create files in it*
   * *read the files in it*

5. *The rest of the world should not be able to access this directory.*

6. *Now add a subdirectory for `davy` and a subdirectory for yourself. Set the owners accordingly. Next change the permissions of the directories so:*

   * *davy has read and traverse permissions on your directory but no write permissions*
   * *you have read and traverse permissions on davy's directory, but no write permissions*

7. *Test everything by using login sessions of each user.*
