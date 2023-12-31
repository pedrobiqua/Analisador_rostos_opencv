# Face Recognition System with OpenCV and GTKMM

## Description

This is a C++ based face recognition system that leverages the OpenCV library for image processing and the GTKMM (equivalent to GTK 3.0) library for building graphical user interfaces. The system is designed to capture and process photos for face recognition.

## Features

1. **Face Detection:** Utilizing OpenCV's face detection capabilities, the system identifies and highlights faces in the captured photos.

2. **Graphical User Interface (GUI):** The graphical user interface is built using the GTKMM library, providing a user-friendly experience for photo capture and face recognition.

## Requirements

- **OpenCV:** Ensure that OpenCV is installed for image processing.

- **GTKMM:** GTKMM 3.0 library is required for building the graphical user interface.

## Installation

Make sure to have the dependencies installed before running the system:

```bash
# OpenCV Installation
sudo apt-get install libopencv-dev

# GTKMM Installation
sudo apt-get install libgtkmm-3.0-dev
```

## System Image
![image](https://github.com/pedrobiqua/Analisador_rostos_opencv/assets/65463695/40a9efc7-2af0-4f58-9871-33d640ec1048)


## Execution
To run the system, use Cmake file CMakeLists.txt

## Contribution
Contributions are welcome! Feel free to open issues and propose improvements.

## Developing
We are creating the `.deb` package for this application, available only for Linux (Only those that support .deb), it will be implemented for Windows in 2024.

## License
This project is distributed under the MIT License.
