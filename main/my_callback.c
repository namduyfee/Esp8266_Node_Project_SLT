
#include "my_callback.h"

void on_data_recv(const uint8_t *mac_addr, const uint8_t *data, int len) 
{
//	if(is_same_macadrr(mac_addr, g_peer_esp32.inf.peer_addr) == true) // && 
	// && data[0] == 's' && data[1] == 't' && data[2] == 'a' && data[3] == 'r' && data[4] == 't'
//	gpio_set_level(PWM_PIN_GPIO2, 1);
	
	if (data[0] == 'S' && data[1] == 'L' && data[2] == 'T')
	{
		set_duty_pwm(1, 756);	
	}
//	ESP_LOGI("ESPNOW", "Received data from " MACSTR ", len=%d", MAC2STR(mac_addr), len);
}

void on_data_sent(const uint8_t *mac_addr, esp_now_send_status_t status) 
{

	g_my_esp_now.can_send = true;
	
	if (status == ESP_NOW_SEND_SUCCESS) {
		
	}
	/*
	if (is_same_macadrr(mac_addr, g_peer_esp32.inf.peer_addr) == true)
	{
			
	}
	*/
	
	//	ESP_LOGI("ESPNOW", "Send to " MACSTR ", status=%d", MAC2STR(mac_addr), status);
//	state_esp_now_send = 1;
}


esp_err_t wifi_event_handler(void *ctx, system_event_t *event)
{
	switch (event->event_id) {
		
	case SYSTEM_EVENT_STA_START: {
		
		break;
	}

	default:
		break;
	}
            
	return ESP_OK;
}
