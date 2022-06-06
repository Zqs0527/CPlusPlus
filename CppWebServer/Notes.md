### Introduction
C++ compiles down to the machine code. It makes it fast when starting up and excuting. On the web, it means your users will wait less time for your site to render.

Docker will help to cure the pain for different environments, builds. It creates images which contains all of the tools which are needed.
- `apt-get -qq` means install the packages quietly and assume yes to all installation . `-qq` can be replaced with `-y` to see details
- `tcmalloc` helps handle allocating and freeing memory
- docker build ends with `.` `docker build -t cppbox .`. `-t` meneans tag. The image will be tagged as `cppbox`
- Creating a volume, this allows to modify the docker containers on the host machine and build on the container
    - `docker run -v <host>:<container> -it <image> bash`
        - `-v` creates a volume option
        - `<host>` the directory on the host machine, absolute path
        - `<container>` the directory on teh docker container, absolute path
        - `<image>` the name of the image to run
    - `docker run -v <host>:<container> <host port>:<container port> -e PORT=8081 <image> bash`
        - Each docker container is isolated. None of its ports are open. In order to access our server, we need to open a port and tell the server which port to use
        - `-p` option opens a port. The number to the left of the colon is the host machine's port number; the number to the right is the container's port number
        - `-e` option creates an environment variable
