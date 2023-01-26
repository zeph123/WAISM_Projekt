
# 4. Przykładowy dłuższy program

## emojicode-web-server

### Run as a Docker container
```terminal
docker build -t emoji-fib-webserver .
docker run -p 8080:8888 emoji-fib-webserver
```

Next go to [https://localhost:8080/fib/`<value>`](https://localhost:8080/fib/3)


***

### Setting Up
1. Build/Install dependencies
```console
➜ cd emojicode-web-server
➜ ./configure
```

### Running Project using Make
1. To run the program
```console
➜ make
```
2. To clean compiled files (main, .o, compiled)
```console
➜ make clean
```

### Running Project using Docker
```console
➜ make docker
```

### Configurations
- Listening Port: `8888`
- Web Root: `/var/www/emoji/html`
- Default Page: `index.html`
- No. of Workers: `512`

### Limitations
- Can only serve GET requests..for now
- Supports HTTP/1.1 & below
- Pages not cached to RAM unlike Apache, nginx
- No config file