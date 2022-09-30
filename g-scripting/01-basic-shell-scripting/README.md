# Basic Shell Scripting

Solve the challenges by creating small bash scripts. Place the bash scripts here for every challenge. Make sure to add some comments and explain how they work.

Mark challenges using a ✅ once they are finished.

## ❌ Log the Date

*Create a script that output the date every 10 seconds. Use the `sleep` command to wait between calls to the `date` command.*

## ❌ Available Memory

*Output the available system memory together with the current date in the following format:*

```
[Thu 14 May 2020 11:12:55 AM CEST] MemAvailable:   28439572 kB
```

*The available memory can be found in the file `/proc/meminfo`. Use the `grep` tool to filter out the line with MemAvailable.*

## ❌ Fetching Github Keys

*Create a script that fetches the public SSH keys of a user on GitHub and displays them in the terminal. This can be accomplished by using the curl tool to access the endpoint `https://github.com/<username>.keys`, where `<username>` is an existing github username.*

*Take in the username via the command line arguments. If none is provided request it from the user using the read command.*

*Example via command line:*

```bash
./githubkeys bioboost
```

*or via the read command:*

```bash
./githubkeys
Please enter GitHub username: BioBoost
Fetching Keys
...
```
