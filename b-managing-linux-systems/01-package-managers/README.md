# Package Managers

Find all the info you need in the man-pages. Make sure to comment the commands you used to find this information. Try to solve the challenges without making use of the Internet.

Mark challenges using a ✅ once they are finished.

## ✅ Cowsay
//*Download the `.deb` package for `cowsay` and install it using `dpkg`. You can find the package at [https://packages.debian.org/sid/all/cowsay/download](https://packages.debian.org/sid/all/cowsay/download).*

//*Run it once it's installed. What does it do ?*

it shows you a cow saying what ever arguments are passed to the command `cowsay`.

```sh
[user@linux][~]$ cowsay "i hope this works"
```
### output
```
 ___________________
< i hope this works >
 -------------------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
```

## ✅ Nmap
//*Install the `nmap` package using `apt`.*

//*Port scan the server `fenix.devbit.be`. Make sure you are connected to the lab network. What services are running on this machine?*

The `nmap -A` command will scan the server argument for any available open ports and tell them to you.

```sh
[user@linux][~]$ nmap -A fenix.devbit.be
```
### output
```
Starting Nmap 7.80 ( https://nmap.org ) at 2022-10-10 16:03 CEST
Stats: 0:00:22 elapsed; 0 hosts completed (1 up), 1 undergoing Service Scan
Service scan Timing: About 50.00% done; ETC: 16:04 (0:00:12 remaining)
Nmap scan report for fenix.devbit.be (193.190.135.171)
Host is up (0.0068s latency).
Not shown: 737 closed ports, 261 filtered ports
PORT    STATE SERVICE  VERSION
80/tcp  open  http     Golang net/http server (Go-IPFS json-rpc or InfluxDB API)
|_http-title: Did not follow redirect to https://fenix.devbit.be/
443/tcp open  ssl/http Golang net/http server (Go-IPFS json-rpc or InfluxDB API)
|_http-title: Site doesn't have a title (text/plain; charset=utf-8).
| ssl-cert: Subject: commonName=TRAEFIK DEFAULT CERT
| Subject Alternative Name: DNS:688cf70ed3bb5f91c5036492b7ef7f50.93b7f7d04c8b5b07effe0e70f7f9c1b5.traefik.default
| Not valid before: 2022-10-09T13:07:51
|_Not valid after:  2023-10-09T13:07:51
|_ssl-date: TLS randomness does not represent time
| tls-alpn:
|   h2
|_  http/1.1

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 23.38 seconds
```   

## ✅ NodeJS

//*Install Node.js v18.x using the instructions found at [https://github.com/nodesource/distributions](https://github.com/nodesource/distributions).*

//*Check if the installation completed successfully by issuing the command `node --version`. It should return `18.8.0` or a similar `18.xx` version.*

I personally have VERSION  18.9.0 currently running

//*Now launch node and tryout the following little code snippet:*

```js
console.log("Hello World from JavaScript");
```
In this output you can see the following after activating the node environment. I was able to run the little code snippet.
### node activating
```ps
node
```
### Output
```js
Welcome to Node.js v18.9.0.
Type ".help" for more information.      
> console.log("Hello World from JavaScript");
Hello World from JavaScript
undefined
```

## ❌ Dhcpdump

//*Install the `dhcpdump` and try to capture some DHCP traffic in the network. Work together with another student and try to capture the DHCP request of his/her laptop. Find out what the MAC Address is and check it using the `ip` tool.*

## ❌ MQTT

//*Find a command line tool that allows you to publish messages to an MQTT broker. Use it to send your name to the topic `linux/students`. Use the broker `mqtt.devbit.be`.*

## ❌ tree command

//*What does the `tree` command do? How do you list all subdirs too? How can you only include directories?*
