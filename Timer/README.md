# Timer

Class for timing events.

## Dependencies

* `<chrono>`

## Usage

```cpp
Timer timer;
timer.reset();
// do something
double elapsedTime = timer.elapsed();
std::cout << "Elapsed time: " << elapsedTime << " s" << std::endl;
```

