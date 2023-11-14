# Video processing using opencv

This repository is intended to demonstrate video processing using opencv. 

The following functions are implemented:
1. simple frame by frame video processing 
2. possibility to create a bounding box which follows the target
3. segmentation to stand out from the background
4. a video output for each sub-step
5. text output of the last frame in yaml format

## How to build

* please check out the Git submodules located in the "ext" directory
* build the external libraries using the customised CMakelists.txt and install it
* set the opencv install folder as OpenCV_DIR cmake argument for this project
* add opencv to the system path
* build and install the project

## How to run

* the launcher.exe can be startet via terminal (e.g. mingw64) like:
```
./launcher.exe <path/to/video.avi>
```

* if no file path is specified, the default camera is used

## Example Data

* an example video file can be found here:
```
./data/example/video.avi
```
* some example outputs can be found here: 
```
./data/output/
```