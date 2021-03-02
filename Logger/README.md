# Logger

Class for logging in dependece of `typelog`:

* `DEBUG`
* `INFO`
* `WARN`
* `ERROR`

with coloring of printouts.

## Usage

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

