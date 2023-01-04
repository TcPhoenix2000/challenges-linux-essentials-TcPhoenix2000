## Docker for Linux

Try to solve the challenges without using google. Better to use the man-pages to find the information you need.

Mark challenges using a ✅ once they are finished.

### ✅ Docker on the Pi
//*Install docker and your raspberry pi and make sure the hello-world runs*.
download and run the official Docker setup script by running the following command.
```sh
[pi@raspberrypi][~]$ curl -sSL https://get.docker.com | sh
```
Setting up the Pi user for Docker
```sh
[pi@raspberrypi][~]$ sudo usermod -aG docker pi
```
This command will tell Docker to download, setup and run a docker container called “hello-world.
```sh
[pi@raspberrypi][~]$ docker run hello-world
```
output:
```sh
Hello from Docker!
This message shows that your installation appears to be working correctly.
```

### ✅ Hello API from RPi
//*Setup the hello-node-api on the Raspberry Pi as a docker container. Make sure it runs on port 8000.*
//*You can find the repository at [https://github.com/BioBoost/linux-essentials-docker-hello-node-api](https://github.com/BioBoost/linux-essentials-docker-hello-node-api)*.
1. Clone the repository using the `git` command.
2. Change to the directory of the repository.
3. Build the Docker image using the `docker build` command.
4. Run the Docker container using the `docker run` command and expose port 8000.
```sh
[pi@raspberrypi][~]$ git clone https://github.com/BioBoost/linux-essentials-docker-hello-node-api.git
[pi@raspberrypi][~]$ cd linux-essentials-docker-hello-node-api
[pi@raspberrypi][~]$ docker build -t hello-node-api .
[pi@raspberrypi][~]$ docker run -p 8000:8000 hello-node-api
```
The hello-node-api should now be running on port 8000 of your Raspberry Pi. You can test it by opening a web browser and visiting http://localhost:8000/ or http://<ip-of-your-raspberry-pi>:8000/.

You should see a message similar to "Hello World from Node Express API".

### ✅ Node-RED on RPi
//*Setup a node-red service on your Raspberry Pi using docker. At what port is it available?*
//*Use the image [https://hub.docker.com/r/nodered/node-red](https://hub.docker.com/r/nodered/node-red)*.

1. Pull the Node-RED Docker image using the docker pull command:
    ```sh
    [pi@raspberrypi][~]$ docker pull nodered/node-red
    ```
2. Run the Node-RED Docker container using the docker run command and expose port 1880:
    ```sh
    [pi@raspberrypi][~]$ docker run -d -p 1880:1880 --name node-red nodered/node-red
    ```
The Node-RED service should now be running on port 1880 of your Raspberry Pi.
You can access the Node-RED editor by opening a web browser and visiting http://localhost:1880/ or http://<ip-of-your-raspberry-pi>:1880/.

If you want to stop the Node-RED service, you can use the docker stop command:
```sh
[pi@raspberrypi][~]$ docker stop node-red
```
You can start the Node-RED service again using the docker start command:
```sh
[pi@raspberrypi][~]$ docker start node-red
```