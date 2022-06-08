FROM bbox:latest
WORKDIR /usr/src/CppWebServer/hello_crow
COPY . .
WORKDIR /usr/src/CppWebServer/hello_crow/build
RUN cmake .
RUN make
CMD ["./hello_crow"]