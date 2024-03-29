
# The Filesystem

Try to solve the challenges without using google. Better to use the man-pages to find the information you need.

Mark challenges using a ✅ once they are finished.

## ✅ touch
//*What does `touch` actually do? Demonstrate using an example.*

touch is used to create a new file in the filesystem.

### the touch command
```sh
[user@linux][~]$ touch {filename}
```

## ✅ Authentication Log
//*There is a file on the system that logs authentication changes and failures. Can you guess where it can be found? Provide the path to the file.*

this does **not** work on Windows subsystem for linux because WSL doesn't run any services by default, including `rsyslog` witch would have created the `/log/var/auth.log`.

## ✅ Apt Source List
//*The apt tool uses a configuration file which specifies in which repositories it should look for packages. Its called the apt `sources.list` file. Can you guess where it can be found? Provide the path to the file.*

this file can be found at this path `/etc/apt/sources.list`

## ✅ Tmp Filesystem
//*Create a file called `hello` in `/tmp`. Restart your linux distro using `reboot`. Where is the file? What happened?*

the `hello` file was created but when you restart your linux distro the `tmp`
directory gets cleared.

## ✅ Timestamps
//*Create a file called `first-of-many` in your home directory. Use `nano` to add some content to the file. Now list the details of the file such as the size and when it was last modified.*

### the commands
```sh
[user@linux][~]$ touch first-of-many
[user@linux][~]$ nano first-of-many
[user@linux][~]$ ls -al first-of-many
```
### the output
```
-rw-r--r-- 1 user user 57 Oct 28 10:18 first-of-many
```

## ✅ No space for spaces
//*Try to create a file called `second try` (with the space included) using the command `touch second try` in your home directory. What happened? Why did this happen? How can you actually achieve creating a file with a space in its name?*

the `touch second try` command will create two files one named second and one named try.

## ✅ The root
//*Try to create a directory `/backups` (under the root of the filesystem). Why is it failing?*

you don't have permission to create a directory under root as non root user

//*Now use `sudo` to create the directory. Try creating a file called `README.md` within this `/backups` directory. Can you do it? Why / Why not?*

no you can't create the file because you don't have root permissions  

## ✅ Bash RC
//*In your home directory you will find a file called `.bashrc`. Create a backup of that file called `.bashrc.bak`.*

### the following command will create a backup of the bashrc file
```bash
[user@linux][~]$ cp .bashrc .bashrc.bak
```

## ✅ Sym Linking
//*What does the tool `ln` allow you to do? Use it to create such a link in your home directory called `secrets` to the file `/etc/passwd`. Now use the `cat` tool to open the file `secrets`. What do you see? What happened?*

### the commands 
```bash
[user@linux][~]$ touch secrets
[user@linux][~]$ ln secrets /etc/passwd
```
### output
```bash
ln: failed to create hard link '/etc/passwd': File exists
[user@linux][~]$ cat secrets

```
The `ln` command will try to create a symbolic link between two files.
If you don't have permissions to read one of the files the the `ln` command will return an `failed to create`.

## ✅ SD Card
//*Plugin an SD Card or a USB stick into you computer. Where can we find the actual block device? Where is the filesystem mounted? What is the difference between these two?*

you will find the SD card under `/mnt/sd-card` and the usb stick under `/media/usb-drive`.

## ✅ My Own Local Domain Name
1. //*Make a backup of the file `/etc/hosts` to the directory `~/backups` directory. Create the directory as needed.*
```sh
[user@linux][~]$ mkdir -p backups && cp /etc/hosts backups
```

2. //*Search the man pages for the use of `/etc/hosts`. Explain in your own words.*
I would discribe the `/etc/hosts` file as the file that associates ip addresses with a hostname. 
In other words your device's local dns.

3. //*Edit the file `/etc/hosts` so we can ping the hostname `hellokitty.dev`. Test it by using the `ping` command. Output the result here and the content of `/etc/hosts`. Make sure to leave the `localhost` entry as is!*
I added this line in the `/etc/hosts` file after the localhost line:
```sh
127.0.1.2   hellokitty.dev 
```
### ping 
```sh 
[user@linux][~]$ ping hellokitty.dev
```
### output
```sh
64 bytes from hellokitty.dev (127.0.1.2): icmp_seq=1 ttl=64 time=0.916 ms
64 bytes from hellokitty.dev (127.0.1.2): icmp_seq=2 ttl=64 time=0.025 ms
64 bytes from hellokitty.dev (127.0.1.2): icmp_seq=3 ttl=64 time=0.050 ms
64 bytes from hellokitty.dev (127.0.1.2): icmp_seq=4 ttl=64 time=0.019 ms
^C
--- hellokitty.dev ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3071ms
rtt min/avg/max/mdev = 0.019/0.252/0.916/0.383 ms
```

## ✅ Chuck
1. //*Make a git clone of `https://github.com/BioBoost/chuck_norris_facts.git` inside of the directory `~/projects`.*
```sh
[user@linux][~]$ mkdir -p ./projects && cd ./projects
[user@linux][~/projects]$ git clone https://github.com/BioBoost/chuck_norris_facts.git 
```

2. //*Rename the directory to `facts_about_chuck_norris`.*
By using the mv command the directory will be effectively renamed.
```sh
[user@linux][~]$ mv ./chuck_norris_facts ./facts_about_chuck_norris
```

3. //*All we need from this repo is the actual facts from the file `README.md`. Delete all other files and directories. Don't forget to remove the hidden `.git` directory.*
```sh
[user@linux][~]$ rm -rf ^*.md
[user@linux][~]$ rm -rf .gitignore && rm -rf .git
```
first command is to delete all files and directories that are not hidden and are not a .md file.
second command is to delete the hidden git files

## ✅ Oh My API
1. //*Go back to your `projects` directory and create a directory `oh_my_api`.*
```sh
[user@linux][~/projects]$ mkdir -p ./oh_my_api && cd ./oh_my_api 
```

2. //*Create a file called `index.js` inside of the directory `oh_my_api/src`.*
```sh
[user@linux][~/projects/oh_my_api]$ touch ./index.js
```

3. //*Execute the command `npm init` inside the `oh_my_api` directory and follow its instructions.*
```sh
[user@linux][~/projects/oh_my_api]$ npm init
```

4. //*Next install the `express` module by executing the command `npm install express` inside of the directory `oh_my_api`.*
```sh
[user@linux][~/projects/oh_my_api]$ npm install express
```

5. //*Now edit the file `index.js` using nano and place the following content in it:*
```js
const express = require('express')
const app = express()
const port = 3000

app.get('/', (req, res) => res.send('Welcome to Oh My API'))
app.listen(port, () => console.log(`App is listening on port ${port}!`))
```

6. //*Test your API using a browser or a tool such as insomnia from Windows or another machine. If you are using WSL you will need to do some research on how to connect to your Ubuntu from Windows.*
![image of windows browser](../images-c/browser.png)