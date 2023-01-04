## Uncomplicated Firewall

Try to solve the challenges without using google. Better to use the man-pages to find the information you need.

Mark challenges using a ✅ once they are finished.

## ✅ Enable Firewall
//*Install and enable the ufw service on your Raspberry Pi.*
```sh
[pi@raspberrypi][~]$ sudo apt install ufw
```

//*Enable incoming traffic for ssh from any host.*
```sh
[pi@raspberrypi][~]$ sudo ufw enable
[pi@raspberrypi][~]$ sudo ufw allow ssh
```

//*Set the default rule to allow outgoing and deny incoming connections.*
```sh
[pi@raspberrypi][~]$ sudo ufw default allow outgoing deny incoming
```

## ✅ Setup Apache
//*Install and enable the apache webserver. Make sure to enable http connections to your device. Test it out by surfing to your device using a webbrowser.*
```sh
[pi@raspberrypi][~]$ sudo apt install apache2
[pi@raspberrypi][~]$ sudo systemctl enable apache2
[pi@raspberrypi][~]$ sudo systemctl start apache2
```
To test the apache webserver, you can use a web browser to visit the URL of your Raspberry Pi.
For example, if the IP address of your Raspberry Pi is `192.168.1.100`, you can visit the URL `http://192.168.1.100` in a web browser to access the default apache web page.