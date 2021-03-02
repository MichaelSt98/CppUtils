# CppUtils

**Utilities (e.g. Parser, Logger, ...) for C++**

## Content

### [Logger](Logger/)

Class for logging in dependece of `typelog`:

* `DEBUG`
* `INFO`
* `WARN`
* `ERROR`

with coloring of printouts.

#### Usage

```cpp
structlog LOGCFG = {};

LOGCFG.headers = true;
LOGCFG.level = DEBUG;

Logger(DEBUG) << "Debug message";
Logger(INFO)  << "Info message";
Logger(WARN)  << "Warning message";
Logger(ERROR) << "Error message";

// printing variables
int a = 0;
Logger(INFO) << "a = " << a;
```

### [Timer](Timer/)

Class for timing events.

#### Dependencies

* `<chrono>`

#### Usage

```cpp
Timer timer;
timer.reset();
// do something
double elapsedTime = timer.elapsed();
std::cout << "Elapsed time: " << elapsedTime << " s" << std::endl;
```




