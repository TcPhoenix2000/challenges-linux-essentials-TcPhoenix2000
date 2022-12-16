# Backups

Solve the challenges by creating small bash scripts. Place the bash scripts here for every challenge. Make sure to add some comments and explain how they work.

Mark challenges using a ✅ once they are finished.

## ✅ Backups
//*Choose a directory on your system (best to choose one in your home-dir). Create a script that archives this directory in a `.tar.gz` tarball file. Add a timestamp in the name of the output file.*

use ./maketar to run the script.
```sh
#!/bin/sh
#Specify user
USER="User"

#Add timestamp
TimeStamp=$(date +"%F")

#Specify how the tar archive will be named
BKPNAME="HomeDir-$TimeStamp"

#TarBall it
tar -zcvf "Backups/$BKPNAME.tar.gz" "/home/$USER"
```

## ✅ Backup Home
//*Create a cron-job that will backup your user directory to a `tar.gz` archive file every day at a specific time. Choose the time yourself.*

use the `crontab -e` command to create a cron job
```sh
[user@linux][~]$ crontab -e
```
add the following line at the bottom of the crontab configuration file
```sh
@daily /home/user/maketar
```
this will run the maketar script every day at 
