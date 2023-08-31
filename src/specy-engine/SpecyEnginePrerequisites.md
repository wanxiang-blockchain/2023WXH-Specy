### Compliance Module Prerequisites

#### Required Packages

```shell
sudo apt-get update
sudo apt-get install -y cmake swig pkg-config python3-dev python \
     software-properties-common virtualenv curl xxd git unzip dh-autoreconf \
     ocaml ocamlbuild liblmdb-dev protobuf-compiler python3-pip python3-toml \
     python3-requests python3-colorlog python3-twisted
sudo apt-get install -y python3-venv
pip3 install --upgrade setuptools json-rpc py-solc-x web3 colorlog twisted wheel toml
```

#### Intel SGX SDK  in Simulator-mode
```shell
sudo mkdir -p /opt/intel
cd /opt/intel
sudo wget https://download.01.org/intel-sgx/sgx-linux/2.10/distro/ubuntu18.04-server/sgx_linux_x64_sdk_2.10.100.2.bin
echo "yes" | sudo bash ./sgx_linux_x64_sdk_2.10.100.2.bin
source /opt/intel/sgxsdk/environment
echo "source /opt/intel/sgxsdk/environment" >>~/.bashrc
```

#### OpenSSL

```shell
mkdir -p ~/openssl/install
cd ~/openssl
wget https://www.openssl.org/source/openssl-1.1.1g.tar.gz
tar -xzf openssl-1.1.1g.tar.gz
cd openssl-1.1.1g/
./Configure --prefix=$PWD/../install
./config --prefix=$PWD/../install
make
make test
make install
cd ../..
export PKG_CONFIG_PATH="$PWD/install/lib/pkgconfig${PKG_CONFIG_PATH:+:$PKG_CONFIG_PATH}"
```

#### Intel SGX OpenSSL

```shell
source /opt/intel/sgxsdk/environment
mkdir ~/sgxssl
cd ~/sgxssl
wget https://download.01.org/intel-sgx/sgx-linux/2.10/as.ld.objdump.gold.r2.tar.gz
tar -xvf as.ld.objdump.gold.r2.tar.gz
sudo cp external/toolset/ubuntu18.04/* /usr/local/bin/
git clone -b lin_2.10_1.1.1g 'https://github.com/intel/intel-sgx-ssl.git'
git checkout master
cd intel-sgx-ssl/openssl_source
wget 'https://www.openssl.org/source/openssl-1.1.1g.tar.gz'
cd ..
cd Linux
export SGX_MODE=${SGX_MODE:-SIM}
make DESTDIR=/opt/intel/sgxssl all test
sudo make install
cd ../../..
export SGX_SSL=/opt/intel/sgxssl
echo "export SGX_SSL=/opt/intel/sgxssl" >>~/.bashrc
```

#### cmake 3.14 installation

```shell
wget https://cmake.org/files/v3.14/cmake-3.14.5.tar.gz
tar -xzvf cmake-3.14.5.tar.gz
cd cmake-3.14.5/
./bootstrap
make
sudo make install
cmake --version
```

#### Protocol Buffers

```shell
# sudo apt-get install protobuf-compiler python-protobuf libprotobuf-dev
sudo apt-get install autoconf automake libtool curl make g++ unzip
git clone -b v3.15.2 https://github.com/protocolbuffers/protobuf.git
cd protobuf
git submodule update --init --recursive
./autogen.sh
./configure
make
make check
sudo make install
sudo ldconfig # refresh shared library cache.
protoc --version
```

#### gRPC

```shell
export MY_INSTALL_DIR=$HOME/.local
mkdir -p $MY_INSTALL_DIR
export PATH="$MY_INSTALL_DIR/bin:$PATH"
sudo apt install -y build-essential autoconf libtool pkg-config
git clone --recurse-submodules -b v1.37.1 https://github.com/grpc/grpc
cd grpc
mkdir -p cmake/build
pushd cmake/build
cmake -DgRPC_INSTALL=ON \
      -DgRPC_BUILD_TESTS=OFF \
      -DCMAKE_INSTALL_PREFIX=$MY_INSTALL_DIR \
      ../..
make
make install
popd
mkdir -p third_party/abseil-cpp/cmake/build
pushd third_party/abseil-cpp/cmake/build
cmake -DCMAKE_INSTALL_PREFIX=$MY_INSTALL_DIR \
      -DCMAKE_POSITION_INDEPENDENT_CODE=TRUE \
      ../..
make
make install
popd
```

#### Boost 
```shell
cd ~/
wget https://boostorg.jfrog.io/artifactory/main/release/1.81.0/source/boost_1_81_0.tar.gz
tar -zvxf boost_1_81_0.tar.gz
cd boost_1_81_0
# make sure that we have essential tools
sudo apt-get update
sudo apt-get install build-essential g++ python-dev autotools-dev libicu-dev libbz2-dev libboost-all-dev
./bootstrap.sh
./b2
sudo ./b2 install
```


