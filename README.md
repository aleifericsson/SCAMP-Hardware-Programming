# SCAMP-Hardware-Programming

# Introduction
This repository is part of a Final Year EEE Project to add colour acquisition to a monochrome camera known as the [SCAMP Vision Sensor](https://personalpages.manchester.ac.uk/staff/p.dudek/scamp/). This repository contains firmware to be uploaded to the ESP32 modules of each of the three hardware approaches to colourise the SCAMP. When the hardware approaches are running, the code from the [SCAMP Image Acquisition repository](https://github.com/aleifericsson/SCAMP-Image-Acquisition) to function will also be run simultaneously to synchronise the two and systems and record the output.

# Installation
1. Install [Arduino IDE](https://www.arduino.cc/en/software)
2. Open the folders as projects and set the board and port to NodeMCU-32S and the port that it is connected to.
3. For the Filter-LCD method, download and install the [TFT_eSPI](https://github.com/Bodmer/TFT_espi) library first. For the Filter-Wheel method, optionally install the [AccelStepper](https://github.com/swissbyte/AccelStepper) library first.
4. Compile and upload the code at a flash frequency of 80 MHz and upload speed of 256000 for best effect.
5. Connect the wires of the ESP32 to the selected hardware apparatus and the SCAMP before running

# Future Improvements
- Filter-LCD: After finding a better LCD module (requirements detailed in the report) find the optimal draw method to maximise the luminous intensity of light entering into the SCAMP without affecting the resulting image.


