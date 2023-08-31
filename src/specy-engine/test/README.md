# Compliance Engine Test

## Usage

+ ### pre-requisite

install googletest 

```
git clone -b v1.12.x https://github.com/google/googletest.git
cd googletest
mkdir build
cd build
cmake ../
make
sudo make install
```

About the feature of googletest, check [primer](http://google.github.io/googletest/primer.html) and [advanced](http://google.github.io/googletest/advanced.html).

+ ### build

```
mkdir build
cd build
cmake ../
make
```

+ ### execute

Before execution, we should start compliance engine at first. [check](../README.md)

+ #### execute all
    ```
    make test
    ```

+ #### execute seperated
    + test `GetComplianceProof` only
    ```
    ./regulator_client
    ``` 
    + test `GetRegisterInfo` only
    ```
    ./register_client
    ```

## Develope

### Structure
```
├── basic_server
├── register_client.cpp
├── regulator_client.cpp
└── testcases
```

+ #### basic_server

There are implements of mocked firehose server, graph node server and interface of mocked database.

+ #### testcases

There are testcases for regulator_client test.

+ #### regulator_client.cpp and register_client.cpp

Implements of test client for `GetComplianceProof` and `GetRegisterInfo`.

### Write your own testcases

+ #### first, write your mocked database implementation

The database interface has been defined in `basic_server/database.h`. 

```
class Database {
public:

    // check whether the target subgraph has been mocked by database
    virtual bool matchDatabase (std::string& target) {
        return false;
    }
    // handle query and reply the mocked and formated data 
    virtual std::string handleQuery(std::string& query, std::string& target) {
        return "";
    }
};
```

Your database implementation should inherit from this `database` class. There is a example case in `testcases` directory.

+ #### second, write your testcase

    + you can add a test case in `regulator_client.cpp` follow the origin cases' format:
        ```
        TEST_F(RegulatorClientTest, RegulatorFail1) {

        // registe your own database
        // YourDatabase* database_ = new YourDatabase();
        // InitYourDatabase(*database_);
        testdatabase = database_;

        // generate test request and send

        // receive response and check

        // clean up
        delete(testdatabase);
        testdatabase = nullptr;
        }
        ```
    
    + or you can write your own `.cpp` file like `regulator_client.cpp`.



 