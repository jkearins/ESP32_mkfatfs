### Example of using **FAT** with ESP32

---

#### Features

* prepare of **FAT** image
* flash **FAT** image to ESP32
* example of **FAT** functions

---

#### How to build

Configure your esp32 build environment as for other **esp-idf examples**

Clone the repository

`git clone https://github.com/jkearins/ESP32_mkfatfs.git`

Execute menuconfig and configure your Serial flash config and other settings. Included *sdkconfig.defaults* sets some defaults to be used.

`make menuconfig`

Make and flash the example.

`make all && make flash && make flashfatfs`

---

#### Prepare **FAT** image

FAT **image** can be prepared on host and flashed to ESP32.

Tested and works under **Windows**.
It is not tested under **Linux** and **Mac OS** yet but should work.

Copy the files to be included on FAT into **components/fatfs_image/image/** directory. Subdirectories can also be added.

Execute:

`make makefatfs`

to create **FAT image** in build directory **without flashing** to ESP32

Execute:

`make flashfatfs`

to create **FAT image** in *build* directory and **flash** it to ESP32

Execute:

`make copyfatfs`

to **flash** previously prepared in *build* directory **FAT image** to ESP32

---

#### Example functions

* register FAT as VFS file system; if the fs is not mounted the system will halt
* list files in root directory


**Example output:**

```
I (399) cpu_start: Pro cpu up.
I (399) cpu_start: Starting app cpu, entry point is 0x40080e98
I (0) cpu_start: App cpu up.
I (402) heap_init: Initializing. RAM available for dynamic allocation:
I (417) heap_init: At 3FFAE2A0 len 00001D60 (7 KiB): DRAM
I (433) heap_init: At 3FFB3E60 len 0002C1A0 (176 KiB): DRAM
I (449) heap_init: At 3FFE0440 len 00003BC0 (14 KiB): D/IRAM
I (466) heap_init: At 3FFE4350 len 0001BCB0 (111 KiB): D/IRAM
I (483) heap_init: At 40087D04 len 000182FC (96 KiB): IRAM
I (499) cpu_start: Pro cpu start user code
I (582) cpu_start: Starting scheduler on PRO CPU.
I (192) cpu_start: Starting scheduler on APP CPU.
I (192) FATFS: Mounting FAT partition...
I (195) FATFS: Done.
I (196) FATFS: ============= Begin of root contents
I (199) FATFS: 	ESP32Explorer.html              	   8332 bytes
I (202) FATFS: 	ESP32Explorer.js                	  11434 bytes
I (208) FATFS: 	<images>
I (210) FATFS: 	<jquery>
I (212) FATFS: 	<jQuery-File-Upload-9.18.0>
I (216) FATFS: 	<jqueryui>
I (218) FATFS: 	<jstree>
I (220) FATFS: ============= End of root contents

```

---

#### Donation
If this project help you reduce time to develop, you can give me a cup of coffee :) 

[![paypal](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_donations&business=KRVFZP9KNCRSG&lc=GB&item_name=ESP32_mkfatfs&item_number=1&no_note=1&no_shipping=1&currency_code=USD&bn=PP%2dDonationsBF%3abtn_donateCC_LG%2egif%3aNonHosted)
