FROM gradescope/autograder-base:latest

ARG c0_binaries=https://c0.cs.cmu.edu/downloads/aux/cc0-latest.tgz
ARG c0_version=v20210822

## Common packages
RUN apt-get -y update && \
    apt-get -y install \
      build-essential \
      libpng-dev \
      libncurses5 \
      valgrind \
      wget


## Getting cc0
RUN wget ${c0_binaries}
RUN tar -xvzf cc0-latest.tgz
RUN mv cc0.${c0_version} /usr/local/share/cc0
RUN rm cc0-latest.tgz

ENV PATH="/usr/local/share/cc0/bin:${PATH}"

ADD run_autograder /autograder/run_autograder

RUN dos2unix /autograder/run_autograder
RUN chmod +x /autograder/run_autograder

RUN apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

CMD bash
