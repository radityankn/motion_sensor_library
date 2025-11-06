#include "BMI088_Driver.h"
#include "SPI.h"

int bmi088_spi_init(bmi088_spi_handler_t *handler) {
    SPI.begin(*handler)
}

int bmi088_spi_gyro_init(bmi088_spi_handler_t *handler) {

}

int bmi088_spi_acc_init(bmi088_spi_handler_t *handler) {

}

int bmi088_spi_set_acc_config(bmi088_spi_handler_t *handler, bmi088_spi_acc_config_t config) {

}

int bmi088_spi_get_acc_config(bmi088_spi_handler_t *handler, bmi088_spi_acc_config_t *config) {

}

int bmi088_spi_read_acc_data(bmi088_spi_handler_t *handler) {

}

int bmi088_spi_set_gyro_config(bmi088_spi_handler_t *handler, bmi088_spi_gyro_config_t config) {

}

int bmi088_spi_get_gyro_config(bmi088_spi_handler_t *handler, bmi088_spi_gyro_config_t *config) {

}

int bmi088_spi_read_gyro_data(bmi088_spi_handler_t *handler) {

}

int bmi088_spi_read_register(bmi088_spi_handler_t *handler, uint8_t byte_number, uint8_t data) {

}

int bmi088_spi_write_register(bmi088_spi_handler_t *handler, uint8_t byte_number, uint8_t *data_buffer) {

}

