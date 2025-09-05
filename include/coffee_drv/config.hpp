#ifndef COFFEE_DRV_CONFIG_H
#define COFFEE_DRV_CONFIG_H

/**
 * @def COFFEE_DRV_WIDTH
 * 
 * @def COFFEE_DRV_HEIGHT
 * 
 * @brief LCD 화면의 크기 정보
 * 
 *        dimensions of the LCD display
 */

#define COFFEE_DRV_WIDTH 800
#define COFFEE_DRV_HEIGHT 480

/* 
   디스플레이 설정

   display configurations
 */

/**
 * @def COFFEE_DRV_DISP_BUF_LINES
 * 
 * @brief 이 드라이버는 디스플레이에 표시할 이미지를 버퍼 크기로 나누어 전송합니다
 * 
 *        버퍼에 담을 라인 수가 클수록 화면 갱신이 더 부드러울 수 있지만 RAM 사용량이 증가합니다
 * 
 *        this driver splits the image to be displayed into chunks based on the buffer size
 * 
 *        a larger number of lines per buffer can yield smoother updates, but increases RAM usage
 */
#define COFFEE_DRV_DISP_BUF_LINES 32

/**
 * @def COFFEE_DRV_BRIGHTNESS
 * 
 * @brief 이 값을 수정하여 화면 밝기를 조절할 수 있습니다(0-255)
 * 
 *        screen brightness can be modified by adjusting this value(0-255)
 */
#define COFFEE_DRV_BRIGHTNESS 255


/* 
   SD 카드 설정
   
   SD card configurations
 */

 /**
  * @brief COFFEE_DRV_SD_USE
  * 
  * @brief SD 카드를 사용할 예정이라면 이 값을 1로 바꾸어 SD 초기화를 포함합니다
  * 
  *        set this value to 1 to include SD initialization if an SD card is intended to be used
  */
#define COFFEE_DRV_SD_USE 1

/**
 * @def COFFEE_DRV_SPI_CLK
 * 
 * @brief ESP32는 SPI 클록을 최대 80MHz까지 지원하지만, 불안정할 수 있습니다
 * 
 *        만약 SD 카드 읽기 / 쓰기가 불안정하다면, 이 값을 40000000으로 바꾸세요
 * 
 *        ESP32 supports SPI clock up to 80MHz, but it can be unstable
 * 
 *        if SD card read / write is unstable, change this value to 40000000
 */
#define COFFEE_DRV_SPI_CLK 80000000

/**
 * @def COFFEE_DRV_LIST_FILES
 * 
 * @brief SD 카드가 초기화될 때, SD 카드 내 모든 파일 목록을 출력하려면 이 값을 1로 설정합니다
 * 
 *        set this value to 1 to print a list of all files on the SD card when it is initialized
 */
#define COFFEE_DRV_LIST_FILES 0

/**
 * @def COFFEE_DRV_FS_LETTER
 * 
 * @brief lvgl 드라이버 식별 문자(대문자 알파벳)
 * 
 *        the drive letter(capitalized alphabet) used by lvgl to identify this file system
 */
#define COFFEE_DRV_FS_LETTER 'S'


/* 
   터치 스크린 설정
   
   touch screen configurations
 */

/**
 * @def COFFEE_DRV_PRINT_TOUCH
 * 
 * @brief 터치 이벤트가 발생할 때마다 터치 위치를 출력하려면 이 값을 1로 설정합니다
 * 
 *        set this value to 1 to print the touch position whenever a touch event occurs
 */
#define COFFEE_DRV_PRINT_TOUCH 0


/* 
   Wi-Fi 설정
   
   Wi-Fi configurations
 */

/**
 * @def COFFEE_DRV_WIFI_TIMEOUT_MS
 * 
 * @brief Wi-Fi 연결에 사용되는 타임 아웃 시간을 ms 단위로 설정합니다
 * 
 *        sets the timeout duration for Wi-Fi connection in milliseconds
 */
#define COFFEE_DRV_WIFI_TIMEOUT_MS 10000
#endif
