
#if defined(higgs_ESP32_LILYGO_T_CAMERA_MINI)
	#define PWDN_GPIO_NUM     	-1
	#define RESET_GPIO_NUM    	-1
	#define XCLK_GPIO_NUM     	32
	#define SIOD_GPIO_NUM     	13
	#define SIOC_GPIO_NUM     	12

	#define Y9_GPIO_NUM       	39
	#define Y8_GPIO_NUM       	36
	#define Y7_GPIO_NUM       	38
	#define Y6_GPIO_NUM       	37
	#define Y5_GPIO_NUM       	15
	#define Y4_GPIO_NUM       	4
	#define Y3_GPIO_NUM       	14
	#define Y2_GPIO_NUM       	5
	#define VSYNC_GPIO_NUM    	27
	#define HREF_GPIO_NUM     	25
	#define PCLK_GPIO_NUM		19
#endif

#if defined(higgs_ESPRESSIF_ESP32_S3_EYE)
	#define PWDN_GPIO_NUM 		-1
	#define RESET_GPIO_NUM 		-1
	#define XCLK_GPIO_NUM 		15
	#define SIOD_GPIO_NUM 		4
	#define SIOC_GPIO_NUM 		5

	#define Y2_GPIO_NUM 		11
	#define Y3_GPIO_NUM 		9
	#define Y4_GPIO_NUM 		8
	#define Y5_GPIO_NUM 		10
	#define Y6_GPIO_NUM 		12
	#define Y7_GPIO_NUM 		18
	#define Y8_GPIO_NUM 		17
	#define Y9_GPIO_NUM 		16

	#define VSYNC_GPIO_NUM 		6
	#define HREF_GPIO_NUM 		7
	#define PCLK_GPIO_NUM 		13
#endif

#if defined(higgs_ESP32_LILYGO_T_CAMERA_S3)
	#define PWDN_GPIO_NUM 		-1
	#define RESET_GPIO_NUM 		39
	#define XCLK_GPIO_NUM 		38
	#define SIOD_GPIO_NUM 		5
	#define SIOC_GPIO_NUM 		4

	#define Y2_GPIO_NUM 		14
	#define Y3_GPIO_NUM 		47
	#define Y4_GPIO_NUM 		48
	#define Y5_GPIO_NUM 		21
	#define Y6_GPIO_NUM 		13
	#define Y7_GPIO_NUM 		11
	#define Y8_GPIO_NUM 		10
	#define Y9_GPIO_NUM 		9

	#define VSYNC_GPIO_NUM 		8
	#define HREF_GPIO_NUM 		18
	#define PCLK_GPIO_NUM 		12
#endif