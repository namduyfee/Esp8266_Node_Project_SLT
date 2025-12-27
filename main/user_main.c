#include "my_lib.h"

#define MIN_DELAY 10

uint8_t data_esp_now[] = "SLT hello"; 
uint32_t len_test_data_esp_now = sizeof(data_esp_now) / sizeof(data_esp_now[0]); 
void task_esp_now(); 

void app_main(void) {
	
	
	nvs_flash_init();
	spiffs_init();
	config_GPIO_OUT();
	config_input_pullup_gpio();

	tcpip_adapter_init();
	start_wifi();
	
	init_espnow();
	start_pwm();
	
	xTaskCreate(task_esp_now, "esp_now_task", 1024, NULL, 4, NULL);
	
	while (1)
	{
		vTaskDelay(pdMS_TO_TICKS(MIN_DELAY));
	}
	
}

void task_esp_now() 
{
	esp_err_t ret; 
	g_my_esp_now.can_send = true; 
	while (1)
	{
		if (g_my_esp_now.can_send == true)
		{

			ret = esp_now_send(g_peer_esp8266.inf_ap.peer_addr, data_esp_now, len_test_data_esp_now);
			while (ret != ESP_OK)
			{
				ret = esp_now_send(g_peer_esp8266.inf_ap.peer_addr, data_esp_now, len_test_data_esp_now);
				vTaskDelay(pdMS_TO_TICKS(10));
			}
			g_my_esp_now.can_send = false;
		}
		vTaskDelay(pdMS_TO_TICKS(100));
	}
}



