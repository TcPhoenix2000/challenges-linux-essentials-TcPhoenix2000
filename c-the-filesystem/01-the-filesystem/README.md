
# The Filesystem

Try to solve the challenges without using google. Better to use the man-pages to find the information you need.

Mark challenges using a ✅ once they are finished.

## ❌ touch

*What does `touch` actually do? Demonstrate using an example.*

## ❌ Authentication Log

*There is a file on the system that logs authentication changes and failures. Can you guess where it can be found? Provide the path to the file.*

## ❌ Apt Source List

*The apt tool uses a configuration file which specifies in which repositories it should look for packages. Its called the apt `sources.list` file. Can you guess where it can be found? Provide the path to the file.*

## ❌ Tmp Filesystem

*Create a file called `hello` in `/tmp`. Restart your linux distro using `reboot`. Where is the file? What happened?*

## ❌ Timestamps

*Create a file called `first-of-many` in your home directory. Use `nano` to add some content to the file. Now list the details of the file such as the size and when it was last modified.*

## ❌ No space for spaces

*Try to create a file called `second try` (with the space included) using the command `touch second try` in your home directory. What happened? Why did this happen? How can you actually achieve creating a file with a space in its name?*

## ❌ The root

*Try to create a directory `/backups` (under the root of the filesystem). Why is it failing?*

*Now use `sudo` to create the directory. Try creating a file called `README.md` within this `/backups` directory. Can you do it? Why / Why not?*

## ❌ Bash RC

*In your home directory you will find a file called `.bashrc`. Create a backup of that file called `.bashrc.bak`.*

## ❌ Sym Linking

*What does the tool `ln` allow you to do? Use it to create such a link in your home directory called `secrets` to the file `/etc/passwd`. Now use the `cat` tool to open the file `secrets`. What do you see? What happened?*

## ❌ SD Card

*Plugin an SD Card or a USB stick into you computer. Where can we find the actual block device? Where is the filesystem mounted? What is the difference between these two?*

## ❌ My Own Local Domain Name

1. *Make a backup of the file `/etc/hosts` to the directory `~/backups` directory. Create the directory as needed.*

2. *Search the man pages for the use of `/etc/hosts`. Explain in your own words.*

3. *Edit the file `/etc/hosts` so we can ping the hostname `hellokitty.dev`. Test it by using the `ping` command. Output the result here and the content of `/etc/hosts`. Make sure to leave the `localhost` entry as is!*

## ❌ Chuck

1. *Make a git clone of `https://github.com/BioBoost/chuck_norris_facts.git` inside of the directory `~/projects`.*

2. *Rename the directory to `facts_about_chuck_norris`.*

3. *All we need from this repo is the actual facts from the file `README.md`. Delete all other files and directories. Don't forget to remove the hidden `.git` directory.*


## ❌ Oh My API

*1. Go back to your `projects` directory and create a directory `oh_my_api`.*

*2. Create a file called `index.js` inside of the directory `oh_my_api/src`.*

*3. Execute the command `npm init` inside the `oh_my_api` directory and follow its instructions.*

*4. Next install the `express` module by executing the command `npm install express` inside of the directory `oh_my_api`.*

*5. Now edit the file `index.js` using nano and place the following content in it:*

```js
const express = require('express')
const app = express()
const port = 3000

app.get('/', (req, res) => res.send('Welcome to Oh My API'))
app.listen(port, () => console.log(`App is listening on port ${port}!`))
```

*6. Test your API using a browser or a tool such as insomnia from Windows or another machine. If you are using WSL you will need to do some research on how to connect to your Ubuntu from Windows.*
