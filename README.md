# 07-120 - Intro to Software Construction

## Installation of the C0 Language

*C0* is a safe subset of C augmented with contracts. This language has been
specifically designed to support the learning objectives of [15-122][15-122],
titled *Principles of Imperative Computation*. It provides

* garbage collection
* fixed range modular integer arithmetic
* an unambiguous language definition
* contracts

This [Wiki doc][c0-install] provides instructions for installing C0 on different
operating systems, including those running on MacOS ARM machines. We've modified
this doc and will provide feedback on any issues.

### Ubuntu and other Debian-based Linux distributions

Download the package and install it:

```sh
wget https://c0.cs.cmu.edu/downloads/cc0-debian.deb
sudo apt install ./cc0-debian.deb
```

To uninstall, run:

```sh
sudo apt remove cc0
```

### MacOS

#### Apple Silicon/ARM Macs

Follow these steps:

  * Install a Universal version of `libgmp` using [MacPorts][macports], though
    this may work with [Homebrew][homebrew-gmp] now as well.

    First, install `macPorts`, following [this guide][macports].

    Then,

    ```sh
    sudo port install gmp +universal
    ```

  * Download two versions ofthe latest MLTon:
    * [Darwin amd64 with statically-linked gmp][mlton-dawrin-gmp-static]
    * [Source code][mlton-src]

    You can find more release packages [here][mlton-releases]. For downloads on
    MacOS, [you may need to override security settings][mac-app-security].

  * Compile the MLTon source code you downloaded, using the amd64
    statically-linked version of mlton from mlton.org in your `$PATH`:

    ```sh
    cd <where-you-placed-mlton-source-code>
    env PATH=<where-you-placed-mlton-amd64-static>/bin:$PATH LIBRARY_PATH=/opt/local/lib/ C_INCLUDE_PATH=/opt/local/include/ make WITH_GMP_DIR=/opt/local
    ```
Note: you might need to disable gatekeeper as described here: https://osxdaily.com/2015/05/04/disable-gatekeeper-command-line-mac-osx/


  * Install the CC0 dependencies using [Homebrew][homebrew] or [MacPorts][macports] (brew example shown here):

    First, install `homebrew`:

    ```sh
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    ```

    Then, install these items:

    ```sh
    brew install autoconf automake libpng pkg-config gnu-getopt libtool
    ```

  * Finally, download and compile the C0/CC0 source:

    ```sh
    git clone --recurse-submodules https://github.com/CMU-07-120/intro-to-software-construction
    cd intro-to-software-construction
    cd c0/cc0
    ./configure
    env PATH=<where-you-built-mlton-in-the-previous-step/mlton>/build/bin:$PATH LIBRARY_PATH=/opt/local/lib/ C_INCLUDE_PATH=/opt/local/include/  make -j
    ```

  * Then `bin/cc0` and `bin/coin` (`coin` is the C0 interpreter, `cc0` is the compiler)
    in can be used normally. You can create links to these files from some
    directory on your `$PATH`.

*Note*: while all of these steps look somewhat daunting, I (Zeeshan Lakhani) was
personally able to compile everything with just the statically-linked MLTon in
my path, the required installs (GMP, Automake, etc) and running just:

``` sh
git clone --recurse-submodules https://github.com/CMU-07-120/intro-to-software-construction
cd intro-to-software-construction
cd c0/cc0
./configure
make -j
```

Nonetheless, I've kept everything here from what the C0 team recommends.

#### Intel/x86 Macs

* The first and easiest step is use to [Homebrew][homebrew], and run

  ```sh
  brew tap cmu/cc0 https://bitbucket.org/c0-lang/downloads.git
  brew install cc0
  ```
* To test the installation, run:

  ```sh
  brew test cc0
  ```

* To uninstall, run:

  ```sh
  brew uninstall cc0
  ```

Sadly, this **may not work!** cause life.

So, let's re-brew:

  ```sh
    brew install autoconf automake libpng pkg-config gnu-getopt libtool
  ```

Then, let's install from source:

```sh
git clone --recurse-submodules https://github.com/CMU-07-120/intro-to-software-construction
cd intro-to-software-construction
cd c0/cc0
./configure
make -j
make install
```

### Windows

On Windows, we recommend [installing Windows Subsystem for Linux v2][wsl] and
then following the directions for Ubuntu/Debian above.

### Installing from source

C0 depends on `mlton`, `libpng` and `libncurses/ncurses`. If you have those installed
(e.g. via a package manager), you should be able to compile from scratch:

```sh
git clone --recurse-submodules https://github.com/CMU-07-120/intro-to-software-construction
cd intro-to-software-construction
cd c0/cc0
./configure
make -j
make install
```

## Using Docker

If you have [Docker installed][docker], you can install [our container](./Dockerfile)
and run `coin` and `cc0` binaries directly.

First, install our container:

```sh
docker pull ghcr.io/cmu-07-120/intro-to-software-construction:latest
```

Then you can run it with a mounted volume of your `.c0` files for example:

```sh
$ docker run --platform linux/amd64 -it --rm -v <path-to-my-c0-files>:/home/07120 -w /home/07120 ghcr.io/cmu-07-120/intro-to-software-construction:latest
```

Another option is first invoke the container like so:

```sh
$ docker run --platform linux/amd64 --name=c0-docker -it -v <path-to-my-c0-files>:/home/07120 -w /home/07120 ghcr.io/cmu-07-120/intro-to-software-construction:latest
```

and then just start it on subsequent invocations:

``` sh
docker start -i c0-docker
```

You can remove the `c0-docker` container by running:

``` sh
docker container ls -a | grep c0-docker
docker container rm [container_id]
```

where `[container_id]` is the first output of the first command.

You can also run the [container in the background][docker-bg] (in detached mode)
and `docker attach` or `docker exec` into it.

## Visual Studio Code extension

We highly recommend using [Visual Studio Code][vscode] with the [C0 plugin][vscode-c0]
for working with C0. The plugin provide IDE features such as code completion,
parsing/typchecking of errors, go-to-definition, and more.

## VisualC0

[VisualC0][visualc0] is a browser-based C0 playground that may be helpful for
debugging C0 programs.

## Other Resources

We highly recommend these reads from the [15-122][15-122] class to start out:

* [`How to Debug with Print Statements`][how-to-debug-print]
* [`How to Debug with Contracts`][how-to-debug-contracts]
* [`How to Write a Test File`][how-to-write-tests]

[15-122]: https://www.cs.cmu.edu/~15122/home.shtml
[c0-install]: https://bitbucket.org/c0-lang/docs/wiki/Downloads
[docker]: https://www.docker.com/get-started/
[docker-bg]: https://docs.docker.com/language/golang/run-containers/#run-in-detached-mode
[homebrew]: https://brew.sh/
[homebrew-gmp]: https://formulae.brew.sh/formula/gmp
[how-to-debug-contracts]: https://www.cs.cmu.edu/~15122/handouts/gts/contracts.pdf
[how-to-debug-print]: https://www.cs.cmu.edu/~15122/handouts/gts/print.pdf
[how-to-write-tests]: https://www.cs.cmu.edu/~15122/handouts/gts/testing.pdf
[macports]: https://www.macports.org/install.php
[mac-app-security]: https://support.apple.com/guide/mac-help/open-a-mac-app-from-an-unidentified-developer-mh40616/mac
[mlton-dawrin-gmp-static]: https://github.com/MLton/mlton/releases/download/on-20210117-release/mlton-20210117-1.amd64-darwin-19.6.gmp-static.tgz
[mlton-releases]: https://github.com/MLton/mlton/releases
[mlton-src]: https://github.com/MLton/mlton/archive/refs/tags/on-20210117-release.zip
[vscode]: https://code.visualstudio.com/
[vscode-c0]: https://marketplace.visualstudio.com/items?itemName=15122staff.c0-lsp
[visualc0]: https://cs122.andrew.cmu.edu/visualc0/
[wsl]: https://learn.microsoft.com/en-us/windows/wsl/install
