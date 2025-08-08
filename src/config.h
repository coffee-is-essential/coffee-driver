#ifndef COFFEE_DRIVER_CONFIG_H
#define COFFEE_DRIVER_CONFIG_H

/* 
   디스플레이 설정

   display configurations
 */

/**
 * @def COFFEE_DISP_BUF_BLOCKS
 * 
 * @brief lvgl은 디스플레이에 표시할 이미지를 버퍼 크기로 나누어서 표현합니다
 * 
 *        때문에 이 버퍼 블록 크기가 적을 수록 더 부드러운 표현이 가능하지만, 메모리가 부족할 수 있습니다
 * 
 *        실행 중 화면이 흔들리거나 깜빡거리는 현상이 발생하면 이 값을 더 크게 조정하세요
 * 
 *        lvgl represents the image to be shown on the display by dividing it by the buffer size
 * 
 *        so having fewer of these blocks to determine the size of the buffer allows for a smoother representation, but may run out of memory
 * 
 *        if you experience screen shaking or flickering while running, adjust this value to a larger value
 */
#define COFFEE_DISP_BUF_BLOCKS 8

/**
 * @def COFFEE_BRIGHTNESS
 * 
 * @brief 이 값을 수정하여 화면 밝기를 조절할 수 있습니다(0-255)
 * 
 *        screen brightness can be modified by adjusting this value(0-255)
 */
#define COFFEE_BRIGHTNESS 255


/* 
   SD 카드 설정
   
   SD card configurations
 */

/**
 * @def COFFEE_SPI_CLK
 * 
 * @brief ESP32는 SPI 클록을 최대 80MHz까지 지원하지만, 불안정할 수 있습니다
 * 
 *        만약 SD 카드 읽기 / 쓰기가 불안정하다면, 이 값을 40000000으로 바꾸세요
 * 
 *        ESP32 supports SPI clock up to 80MHz, but it can be unstable
 * 
 *        if SD card read / write is unstable, change this value to 40000000
 */
#define COFFEE_SPI_CLK 80000000

/**
 * @def COFFEE_LIST_FILES
 * 
 * @brief SD 카드가 초기화될 때, SD 카드 내 모든 파일 목록을 출력하려면 이 값을 1로 설정합니다
 * 
 *        set this value to 1 to print a list of all files on the SD card when it is initialized
 */
#define COFFEE_LIST_FILES 1

/**
 * @def COFFEE_FS_LETTER
 * 
 * @brief lvgl 드라이버 식별 문자(대문자 알파벳)
 * 
 *        the drive letter(capitalized alphabet) used by lvgl to identify this file system
 */
#define COFFEE_FS_LETTER 'S'


/* 
   터치 스크린 설정
   
   touch screen configurations
 */

/**
 * @def COFFEE_PRINT_TOUCH
 * 
 * @brief 터치 이벤트가 발생할 때마다 터치 위치를 출력하려면 이 값을 1로 설정합니다
 * 
 *        set this value to 1 to print the touch position whenever a touch event occurs
 */
#define COFFEE_PRINT_TOUCH 0


/* 
   Wi-Fi 설정
   
   Wi-Fi configurations
 */

/**
 * @def COFFEE_WIFI_TIMEOUT_MS
 * 
 * @brief Wi-Fi 연결에 사용되는 타임 아웃 시간을 ms 단위로 설정합니다
 * 
 *        sets the timeout duration for Wi-Fi connection in milliseconds
 */
#define COFFEE_WIFI_TIMEOUT_MS 10000
#endif
