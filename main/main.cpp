
#include <stdio.h>
#include <string>
#include <vector>

#include "sdkconfig.h"
#include <esp_log.h>

#include "FATFS_VFS.h"
#include "Task.h"
#include "FileSystem.h"


static const char* TAG = "FATFS";
const std::string MOUNT_POINT         = "/spiflash";

class FatfsTask: public Task {
	void run(void* data) override {
	        ESP_LOGI(TAG, "Mounting FAT partition...");
		FATFS_VFS* fs = new FATFS_VFS(MOUNT_POINT.c_str(), "storage");
		fs->setMaxFiles(10);
		fs->mount();
	        ESP_LOGI(TAG, "Done.");

	        ESP_LOGI(TAG, "============= Begin of root contents");
		std::vector<File> fileList = FileSystem::getDirectoryContents(MOUNT_POINT);
		for (int i=0; i < fileList.size(); i++) {
			File curFile(MOUNT_POINT + "/" + fileList[i].getName(), DT_UNKNOWN);
			if (curFile.isDirectory()) {
				ESP_LOGI(TAG, "\t<%s>", fileList[i].getName().c_str());
			} else {
				ESP_LOGI(TAG, "\t%-32s\t%7u bytes", fileList[i].getName().c_str(), curFile.length());
			}
		}
	        ESP_LOGI(TAG, "============= End of root contents");


	}
};


void doTask(void* ignore) {
	FatfsTask* fatfsTask = new FatfsTask();
	fatfsTask->setStackSize(8000);
	fatfsTask->start();
	vTaskDelete(NULL);
}

extern "C" {
	int app_main(void);
}

/**
 * @brief Main entry point.
 */
int app_main(void) {
	doTask(nullptr);
	return 0;
}
