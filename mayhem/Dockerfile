FROM --platform=linux/amd64 ubuntu:20.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y automake pkg-config libtool build-essential clang

COPY . /repo
WORKDIR /repo
RUN autoreconf -if
RUN ./configure --prefix=/install
RUN make -j8
RUN make install
RUN clang++ /repo/mayhem/fuzz_fromUtf8.cpp -fsanitize=fuzzer,address -I /repo/src/intern/ /install/lib/libdxfrw.a -o /fuzz

FROM ubuntu:20.04 as package
COPY --from=builder /install /install
COPY --from=builder /fuzz /fuzz_fromUtf8
