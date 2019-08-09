# Hardware Software Platforms : Altera Quartus EDA and DE1-SoC-Accelerometer_Sensor (driver and application)

This project repository is made in the frame of M. Valderrama (FPMS-UMONS, Belgium) course entitled Hardware Software Platform. The objective of this course is to develop and create a tutorial explaining how to use a development tool (Altera Quartus EDA in my case), platform and peripheral, to develop tests to evaluate the device, its driver and its human interface using simulation or a test bench.

To do so we should create or use an existing driver, create an application (human interaction interface) and test it on the board.

The FPGA board that was used in this project was Altera DE1-SoC rev. D. The accelerometer sensor peripheric model is LIS3LV02DL. All the information provided in the tutorial comes from personal knowledge, experiment and from the .PDF documentation that can be found in the "documentation" folder.

In this project i learn how to drive an accelerometer sensor mentionned above through I2C serial bus interface with an Altera Cyclone V SoC using Quartus II starting from a simple code C that did the same job on a PIC card (accelorometer.c).

The video demonstrating how my application works can be found on youtube : https://youtu.be/tSfjQ94cZB0

The .qar file is the archived project under Quartus. The .sof file is the binary used to flash the FPGA board with the code of the driver and the application.

# Project Presented by

Kasongo Kabasele Dieudonné : dieudonne.kasongokabasele@student.umons.ac.be
