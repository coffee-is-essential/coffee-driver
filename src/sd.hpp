#ifndef COFFEE_SD_HPP
#define COFFEE_SD_HPP

#include <string.h>

#include <Arduino.h>
#include <FS.h>
#include <SD.h>
#include <SPI.h>

#include <lvgl.h>

#include "config.hpp"

#define COFFEE_SD_CS 10
#define COFFEE_SD_MOSI 11
#define COFFEE_SD_SCK 12
#define COFFEE_SD_MISO 13

namespace coffee
{
    /**
     * @brief SD 카드를 초기화합니다
     * 
     *        initializes the SD card
     * 
     * @param fs_letter lvgl 드라이버 식별 문자(대문자 알파벳)
     * 
     *                  the drive letter(capitalized alphabet) used by lvgl to identify this file system
     * 
     * @return SD 카드 초기화 성공 여부
     * 
     *         SD card initialization success
     */
    bool init_sd(char fs_letter);

    /**
     * @brief 파일 시스템 내의 모든 파일을 표시합니다
     * 
     *        lists all files in the file system
     */
    void list_all(void);

    /**
     * @brief 디렉토리 내의 모든 파일들을 표시합니다
     * 
     *        lists all files in a directory
     * 
     * @param root 읽어 들일 파일 시스템 내 디렉토리
     * 
     *             directory in the file system to read
     * 
     * @param dir_name 읽어 들일 디렉토리의 이름
     * 
     *                 directory name to read
     * 
     * @param depth 디렉토리의 깊이
     * 
     *              depth of the directory
     */
    void list_dir(File& root, const char* dir_name, uint8_t depth = 0);
}
#endif
