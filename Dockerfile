FROM gcc:latest

WORKDIR /app

COPY . .

RUN g++ src/main.cpp src/calculator.cpp -o calculator

CMD ["./calculator"]