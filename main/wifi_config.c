
#include "wifi_config.h"

void init_wifi(void)
{
	esp_event_loop_init(wifi_event_handler, NULL);
	wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
	esp_wifi_init(&cfg);
}


void start_wifi(void)
{
	init_wifi();
	esp_wifi_set_mode(WIFI_MODE_STA);
	
	esp_wifi_start();
	esp_wifi_set_channel(CONFIG_ESPNOW_CHANNEL, 0); 
	
}
