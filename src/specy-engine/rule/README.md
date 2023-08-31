# Rule Check Module

## Build

This module use CMake to generate build system.

```bash
# Generate an empty directory for build system
mkdir build
cd build

# Default to SGX SIM mode and enable Debug flags
cmake ..
make

# Generated two artifacts:
# (1) rule_checker executable;
# (2) libenclave.so shared library.

# Run rule checker internal test App
./rule_checker
```

## TODO

- [ ] Add thread-safe support for `RequestHandler` and `RuleProcessor`

- [ ] Fix bugs leading to illegal instruction and segment fault
