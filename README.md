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

### [ProgressBar](ProgressBar/)

Visualize progress using a **progress bar** within the print-outs/shell.

![Progress Bar example](ProgressBar/resources/ProgressBar.gif)

#### Usage

```cpp
// initialize colors (if wanted)
Color::Modifier green(Color::FG_GREEN);
Color::Modifier default(Color::FG_DEFAULT);
    
// initialize progress bar
int width = 80;
ProgressBar progressBar(width);

for (int i = 0; i < 1500; i++) {

	// calculate something
	
	//change color to green
	std::cout << green;
	//calculate progress
	float progress i/1500.0;
	// visualize progress using the progress bar
	progressBar.show_progress(progress);
	// change color back to default
	std::cout << default;
}
```





