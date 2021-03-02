# ProgressBar

Visualize progress using a **progress bar** within the print-outs/shell.

![Progress Bar example](resources/ProgressBar.gif)

## Usage

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
	float progress = i/1500.0;
	// visualize progress using the progress bar
	progressBar.show_progress(progress);
	// change color back to default
	std::cout << default;
}
```



