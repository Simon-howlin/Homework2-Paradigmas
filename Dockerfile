FROM gcc:13

WORKDIR /app
COPY . .

RUN mkdir -p bin
RUN make

CMD ["ls", "bin"]


