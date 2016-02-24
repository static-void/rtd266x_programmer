# rtd266x_programmer
Programmer for RTD266X using linux and i2c-dev

This allows you to program these devices just using a VGA cable plugged in to your graphics card (it uses the I2C bus on the DDC pins). No need to buy a programmer!

This is based on the code [here](https://github.com/ghent360/RTD-2660-Programmer) (but that code uses an external USB I2C interface and MS windows).

Using it
--------

Make sure to `modprobe i2c-dev`

Then run `i2cdetect -l`. I get the following output:

i2c-0	i2c       	i915 gmbus ssc                  	I2C adapter  
i2c-1	i2c       	i915 gmbus vga                  	I2C adapter  
i2c-2	i2c       	i915 gmbus panel                	I2C adapter  
i2c-3	i2c       	i915 gmbus dpc                  	I2C adapter  
i2c-4	i2c       	i915 gmbus dpb                  	I2C adapter  
i2c-5	i2c       	i915 gmbus dpd                  	I2C adapter  
i2c-6	i2c       	DPDDC-B                         	I2C adapter  
i2c-7	i2c       	DPDDC-C                         	I2C adapter  
i2c-8	i2c       	DPDDC-D                         	I2C adapter  

Clearly `i2c-1` is the i2c bus connected to the VGA DDC pins. Now I can plug a VGA cable between my laptop and the RTD2660 board and run `rtd_prog -d 1 -b backup.bin` to backup my firmware.

Usage: rtd_prog -d <device #> [-option[s]]  
Options:  
  -d \<device #\> : Specify the i2c bus to use, e.g. -d 1 means /dev/i2c-1  
  -b \<file\>     : Backup the current firmware on the RTD266X to a file  
  -f \<file\>     : Flash a file to the RTD266X  

Building
--------
No special requirements except `i2c-dev.h`, and you probably want `i2cdetect` from `i2c-tools` as well. On ubuntu you just need to do `sudo apt-get install i2c-tools libi2c-dev` and that's it. Then just run `make`.
