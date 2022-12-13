# Cron Jobs

Try to solve the challenges without using google. Better to use the man-pages to find the information you need.

Mark challenges using a ✅ once they are finished.

## ✅ I am Alive
//*Create a cron-job that will publish a message to the `mqtt.devbit.be` broker on the topic `linux/alive/<yourname>` every 15th minute of the day. You can use the `mosquitto_pub` command for this.*

use the `crontab -e` command to create a cron job
```sh
[user@linux][~]$ crontab -e
```
add the following line at the bottom of the crontab configuration file
```sh
15 * * * * mosquitto_pub -h mqtt.devbit.be -t linux/alive/Tc_Phoenix_ -m "i am still alive $(date)"
```

## ✅ My IP
//*Create a cron-job that will publish your raspberry pi's IP address to the `mqtt.devbit.be` broker on the topic `linux/ip/<yourname>` every minute. You can use the `mosquitto_pub` command for this.*

use the `crontab -e` command to create a cron job
```sh
[user@linux][~]$ crontab -e
```
add the following line at the bottom of the crontab configuration file
```sh
* * * * * ip -4 addr show eth0 | grep -oP '(?<=inet\s)\d+(\.\d+){3}' >> /tmp/cron-ip
* * * * * cat /tmp/cron-ip | mosquitto_pub -h mqtt.devbit.be -t linux/ip/Tc_Phoenix_ -m 
```