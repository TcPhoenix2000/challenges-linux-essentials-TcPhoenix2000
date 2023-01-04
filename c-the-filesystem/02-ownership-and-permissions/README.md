# Ownership and Permissions

Make sure to document all your commands here.

Unless specified otherwise, all commands should be executed in a terminal session logged in with your own user account.

Mark challenges using a ✅ once they are finished.

## ✅ Sudo
//Open a terminal session with your current user. Execute the `id` command. Explain the output. To what groups does your user belong?

this will result are the user id's group id's and groups where the current user belongs too

//Next execute the `id` command prefixed with `sudo`. What is the difference between both commands. What is happening here?

this will just show the user id ,group id and group that have sudo permissions

## ✅ New User Davy
1. //*Create a user account for `davy`.*
   ```sh
   [user@linux][~]$ sudo adduser davy
   ```

2. //*Now open a terminal and switch to the user account using the command `su davy`.*
   ```sh
   [user@linux][~]$ su davy
   ```

3. //*Create a file called `i_am_legend` inside of the home dir of `davy` using the `davy` session using the command `sudo touch ~/i_am_legend`. Why is this not working?*
   ```sh
   [davy@linux][~]$ sudo touch ~/i_am_legend
   ```
   it doen't work because davy does not have sudo permissions

4. //*`exit` the current shell of `davy`.*
   ```sh
   [davy@linux][~]$ exit
   ```

5. //*Add the user account `davy` to the group `sudo`. Now repeat the process. Is it working now?*
   ```sh
   [user@linux][~]$ usermod -aG sudo davy
   ```
   yes i was able to create the i_am_legend file

6. //*`exit` the current shell of `davy`.*
   ```sh
   [davy@linux][~]$ exit
   ```

7. //*Now switch to the superuser using `sudo su`.*
   ```sh
   [user@linux][~]$ sudo su
   ```

8. //*Now execute the `su davy` command from the superuser session. Why do we not need to provide the password of `davy`?*
   because we were root with sudo permissions we do not need to provide the password od davy

## ✅ Auth.log
//*What does the file `/log/var/auth.log` track? Provide an example that shows entries being added to the log after you executed the commands.*

this file does not exists on wsl. 

## ✅ Editable Text Configuration
//*Who is the owner of the `/etc` directory on the system? What are the permissions on this directory? Why can you list the content of this directory?*

the `/etc` directory is owned by the root user and the root group. The permissions on this directory are usually set to `rwxr-xr-x`.
you can list the contents of a directory if you have execute permission on that directory. Execute permission allows you to access the directory.


## ✅ Davy's Secrets
1. //*Create a file called `davys_secrets.txt` inside of the `tmp` directory. Add some content to the file using nano.*
   ```sh
   [user@linux][~]$ cd /tmp
   [user@linux][~]$ nano davys_secrets.txt
   ```

2. //*What are the current permissions and who is the owner of the file?*
   ```sh
   [user@linux][/tmp]$ ls -l
   ```
   the current permissions are `-rw-rw-r--`

3. //*Change the owner to `davy`. Can you still read / change the content of the file?*
   ```sh
   [user@linux][/tmp]$ chown davy davys_secrets.txt
   ```

4. //*What command would you need to lock everyone except davy out of the file? Make sure to test it.*
   ```sh
   [user@linux][/tmp]$ chmod go-rw davys_secrets.txt
   ```

## ✅ Sudo created files
1. //*Create a file called `my_root.txt` inside of the `/tmp` directory using the command `sudo touch /tmp/my_root.txt`.*
   ```sh
   [user@linux][/tmp]$ sudo touch /tmp/my_root.txt
   ```

2. //*Who can access the file and what permissions does it have. Who is the owner of the file?*
   ```sh
   -rw-rw-r-- 1 root root 0 Jan 1 00:00 my_root.txt
   ```
   In this case, the permissions are interpreted as follows:

   - rw-: The owner (root) has read and write permissions.
   - rw-: Members of the group (root)  has read and write permissions.
   - r--: All other users have read permissions.

3. //*Change the permissions of the file to `640`. What has changed? Do you still have access to the file?*
   ```sh
   [user@linux][/tmp]$ sudo chmod 640 /tmp/my_root.txt
   ```
   This will update the permissions on the file to `-rw-r-----`, which means that the owner (`root`) has read and write permissions, members of the group (`root`) have read permissions, and all other users have no permissions.


## ✅ Recursive
1. //*Create a directory called `/tmp/arts/colors` and add three files to it: `red`, `green` and `blue`.*
   ```sh
   [user@linux][~]$ mkdir -p /tmp/arts/colors
   [user@linux][~]$ touch /tmp/arts/colors/red /tmp/arts/colors/green /tmp/arts/colors/blue
   ```

2. //*Next create a directory `/tmp/arts/musical_notes` and add three files to it: `do`, `re` and `mi`.*
   ```sh
   [user@linux][~]$ mkdir -p /tmp/arts/musical_notes
   [user@linux][~]$ touch /tmp/arts/musical_notes/do /tmp/arts/musical_notes/re /tmp/arts/musical_notes/mi
   ```

3. //*Who is the owner of the files and directories? You can list all of them at once using the `-R` option for `ls`.*
   To view the owner of the files and directories, you can use the `ls -lR` command to recursively list the details of all the files and directories in the `/tmp/arts` directory. 

4. //*Now change the owner of the directory `/tmp/arts` and all of it included files to `davy` using the recursive option of `chown`.*
   ```sh
   [user@linux][~]$ sudo chown -R davy /tmp/arts
   ```

5. //*Damn we made a small mistake. The goal was actually to make `root` owner of all the files and dirs and set the group to `davy`. Fix the mistake.*
   To fix the mistake and make `root` the owner of all the files and directories and set the group to `davy`, you can use the following command:
   ```sh
   [user@linux][~]$ sudo chown -R root:davy /tmp/arts
   ```

## ✅ Developers group
1. //*Create a group `devs` on the system. What is the `GID` of this group?*
   ```sh
   [user@linux][~]$ sudo groupadd devs && id -g devs
   ```
   output:
   ```sh
   id: ‘devs’: no such user
   ```
2. //*Add yourself and `davy` to this group.*
   ```sh
   [user@linux][~]$ sudo usermod -a -G devs user
   [user@linux][~]$ sudo usermod -a -G devs davy
   ```

3. //*Now add a directory `projects` to the root of the file system, so `/projects`.*
   ```sh
   [user@linux][~]$ sudo mkdir /projects
   ```

4. //*Now set the owner of the directory to `root` and set the group to `devs`. Give both `root` and `devs` permissions to:*

   * //*traverse the directory*
   * //*create files in it*
   * //*read the files in it*
   ```sh
   [user@linux][~]$ sudo chown root:devs /projects
   [user@linux][~]$ sudo chmod 775 /projects
   ```

5. //*The rest of the world should not be able to access this directory.*
   To set the permissions of the /projects directory so that the rest of the world does not have access to it, you can use the chmod command to remove read and execute permissions
   ```sh
   [user@linux][~]$ sudo chmod 700 /projects
   ```
6. //*Now add a subdirectory for `davy` and a subdirectory for yourself. Set the owners accordingly. Next change the permissions of the directories so:*
   ```sh
   [user@linux][~]$ sudo mkdir /projects/davy /projects/user
   [user@linux][~]$ sudo chown davy:devs /projects/davy
   [user@linux][~]$ sudo chown your_username:devs /projects/user
   ```
   * //*davy has read and traverse permissions on your directory but no write permissions*
   * //*you have read and traverse permissions on davy's directory, but no write permissions*
   ```sh
   [user@linux][~]$ sudo chmod 755 /projects/user
   [user@linux][~]$ sudo chmod 755 /projects/davy
   ```

7. //*Test everything by using login sessions of each user.*
   ```sh
   [davy@linux][~]$ ls -lR /projects
   drwxr-xr-x 2 root devs 4096 Jan 1 00:00 projects
   drwxr-xr-x 2 davy devs 4096 Jan 1 00:00 projects/davy
   drwxr-xr-x 2 user devs 4096 Jan 1 00:00 projects/user

   [user@linux][~]$ ls -lR /projects
   drwxr-xr-x 2 root devs 4096 Jan 1 00:00 projects
   drwxr-xr-x 2 davy devs 4096 Jan 1 00:00 projects/davy
   drwxr-xr-x 2 user devs 4096 Jan 1 00:00 projects/user
   ```
   it works !!